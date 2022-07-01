#include "Definitions.h"
#include "Socket.h"
#include "button.h"
#include "dht11.h"
#include "modbusRtu.h"
#include "database.h"

//Global variables
// Child
modbus_t *ctx;
RtuConnection* sht20;
Dht11* dht11;
uint64_t tTimer1, tTimer2, tTimer3, tTimer4;
uint64_t debugTime;
uint64_t EndPrgTime_us;
uint16_t ret;
DataConn* db;

// Parent
Button* button;

// Common
uint64_t Curr_time_ms, Curr_time_us;
pid_t cpid;
bool CMS_qOnce = true;

int main() {
    if(!bcm2835_init()) exit(1);


    cpid = fork();
    if (cpid == -1) {
        printf("FORK ERROR");
        exit(EXIT_FAILURE);
    }
    // SOCKET PID
    if (cpid > 0) {
        printf("Child created, cpid: %d, ", cpid);

        // SOCKET INITIALIZATION //
        initSocket();

        // Bind the host address using bind() call.  //
        if (bind(sockfd, (struct sockaddr *) &serveraddr, sizeof(serveraddr)) < 0) {
            perror("Error binding to socket, exiting.");
            exit(1);
        }

        //  wait for an incoming connection   //
        listen(sockfd,5);
        clilen = sizeof(cli_addr);
        loopsock();
    }

    cpid = fork();
    if (cpid == -1) {
        printf("FORK ERROR");
        exit(EXIT_FAILURE);
    }

    // Interface PID
    if (cpid > 0) {
        printf("Parent created, cpid: %d\n", cpid);
        // Init Outputs
        bcm2835_gpio_fsel(outKUCHNIA, BCM2835_GPIO_FSEL_OUTP);
        bcm2835_gpio_fsel(outLAZIENKA, BCM2835_GPIO_FSEL_OUTP);

        button = calloc(12, sizeof(struct sButton));

        button_constructor(&button[KUCHNIA], inKUCHNIA1, outKUCHNIA);
        button_constructor(&button[LAZIENKA], inKUCHNIA2, outKUCHNIA);
        button_constructor(&button[SALON], inLAZIENKA1, outLAZIENKA);

        while(1){
            Curr_time_us = bcm2835_st_read();   // Read current time
            Curr_time_ms = Curr_time_us / 1000;

            (&button[KUCHNIA])->getInput(&button[KUCHNIA], Curr_time_ms);
            (&button[KUCHNIA])->toggle(&button[KUCHNIA]);
            (&button[LAZIENKA])->getInput(&button[LAZIENKA], Curr_time_ms);
            (&button[LAZIENKA])->toggle(&button[LAZIENKA]);
            (&button[SALON])->getInput(&button[SALON], Curr_time_ms);
            (&button[SALON])->toggle(&button[SALON]);

            if(CMS_qOnce){
                CMS_qOnce = false;
            }
        }
        // Should be never reached
        exit(1);
    }

    // External devices PID
    else if (cpid == 0) {
        printf("Child created, cpid: %d\n", cpid);
        //ModbusRtu Initialization
        ctx = ModbusInit();

        //OOP SHT20 ModbusComm init
        sht20 = calloc(1, sizeof(struct sRtuConnection));
        sensor_constructor((RtuConnection*)sht20, "SHT20");

        //OOP DHT11 initialization
        dht11 = calloc(1, sizeof(struct sDht11));
        dht11_constructor((Dht11*)dht11, "DHT11", DHT_PIN);

        //Db connection initialization
        db = calloc(1, sizeof(struct sDatabase));
        dataConn_constructor((DataConn*)db);
        dataConnInit(db);

        // init Timers
        debugTime = 500;
        Curr_time_us = bcm2835_st_read();   // Read current time
        Curr_time_ms = Curr_time_us / 1000;
        tTimer1 = tTimer2 = tTimer3 = tTimer4 = Curr_time_ms;

        while(1){
            Curr_time_us = bcm2835_st_read();   // Read current time
            Curr_time_ms = Curr_time_us / 1000;

            // Read DHT
            if(Curr_time_ms > tTimer1 + debugTime + 6000) {
                dht11->readData(dht11);
                tTimer1 = bcm2835_st_read() / 1000;
            }

            // Read SHT Modbus
            if(Curr_time_ms > tTimer2 + debugTime + 6000){
                ret = sht20->modbusExecute(sht20, ctx);

                if( ret == 1) debugTime = 6000000;
                tTimer2 = bcm2835_st_read() / 1000;
            }

            //Record to database
            if(Curr_time_ms > tTimer4 + debugTime + 12000) {
                char str[53];
                if (sht20->data_ok == true) {
                    strcpy(str, insert_climate(sht20->name,
                                               sht20->temperatura,
                                               sht20->wilgotnosc));
                }
                if (dht11->data_ok == true) {
                    strcpy(str, insert_climate(dht11->name,
                                               dht11->temperatura,
                                               dht11->wilgotnosc));
                }
                db->doDatabase(db);

                tTimer4 = bcm2835_st_read() / 1000;
            }

            // Read current time and calculate prg time
            EndPrgTime_us = bcm2835_st_read();
        }
        closeDatabase(db);
        // Should be never reached
        exit(1);
    }
}