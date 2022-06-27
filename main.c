#include "Definitions.h"
#include "Socket.h"
#include "button.h"
#include "dht11.h"
#include "modbusRtu.h"
#include "database.h"


//Global variables
modbus_t *ctx;
sqlite3 *db;
//Fork and pipe
//int pipefd[2];
pid_t cpid;
//SQLITE rc
int rc;
char *err;
bool CMS_qOnce = true;


int main() {

    cpid = fork();
    if (cpid == -1) {
        printf("FORK ERROR");
        exit(EXIT_FAILURE);
    }
    // SOCKET PID
    if (cpid > 0) {
        printf("Child created, cpid: %d, ", cpid);
        if(!bcm2835_init()) return 1;

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

    uint64_t Curr_time_ms, Curr_time_us;
    uint64_t tTimer1, tTimer2, tTimer3, tTimer4;
    uint64_t timevalue = 500;
    uint64_t EndPrgTime_us;
    uint16_t ret;

    //OOP SHT20 ModbusComm init
    RtuConnection* sht20 = calloc(1, sizeof(struct sRtuConnection));
    sensor_constructor((RtuConnection*)sht20, "SHT20");

    //OOP DHT11 initialization
    Dht11* dht11 = calloc(1, sizeof(struct sDht11));
    dht11_constructor((Dht11*)dht11, "DHT11", DHT_PIN);

    /*  CREATING PIPE - NOT NEEDED FOR NOW
    if (pipe(pipefd) == -1) {
        printf("PIPE ERROR");
        exit(EXIT_FAILURE);
    }
    */

    cpid = fork();
    if (cpid == -1) {
        printf("FORK ERROR");
        exit(EXIT_FAILURE);
    }

    if (cpid > 0) Parent_init();
    else if (cpid == 0) Child_init();

    Curr_time_us = bcm2835_st_read();                       // Read current time
    Curr_time_ms = Curr_time_us / 1000;                     // Calculate ms curr time
    tTimer1 = tTimer2 = tTimer3 = tTimer4 = Curr_time_ms;   // init Timers


    Button* butt1 = calloc(1, sizeof(struct sButton));
    button_constructor((Button*)butt1, BTN1, LED);
    Button* butt2 = calloc(1, sizeof(struct sButton));
    button_constructor((Button*)butt2, BTN2, OUT1);
    Button* butt3 = calloc(1, sizeof(struct sButton));
    button_constructor((Button*)butt3, BTN3, LED);
    Button* butt4 = calloc(1, sizeof(struct sButton));
    button_constructor((Button*)butt4, BTN4, LED);
    Button* butt5 = calloc(1, sizeof(struct sButton));
    button_constructor((Button*)butt5, BTN5, LED);
    Button* butt6 = calloc(1, sizeof(struct sButton));
    button_constructor((Button*)butt6, BTN6, LED);
    Button* butt7 = calloc(1, sizeof(struct sButton));
    button_constructor((Button*)butt7, BTN7, LED);
    Button* butt8 = calloc(1, sizeof(struct sButton));
    button_constructor((Button*)butt8, BTN8, LED);
    Button* butt9 = calloc(1, sizeof(struct sButton));
    button_constructor((Button*)butt9, BTN9, LED);
    Button* butt10 = calloc(1, sizeof(struct sButton));
    button_constructor((Button*)butt10, BTN10, LED);
    Button* butt11 = calloc(1, sizeof(struct sButton));
    button_constructor((Button*)butt11, BTN11, LED);
    Button* butt12 = calloc(1, sizeof(struct sButton));
    button_constructor((Button*)butt12, BTN12, LED);

    while(1){
        Curr_time_us = bcm2835_st_read();   // Read current time
        Curr_time_ms = Curr_time_us / 1000;
        // Parent program
        if(cpid > 0){
            butt1->getInput(butt1, Curr_time_ms);
            butt1->toggle(butt1);
            butt2->getInput(butt2, Curr_time_ms);
            butt2->toggle(butt2);
            butt3->getInput(butt3, Curr_time_ms);
            butt3->toggle(butt3);
            butt4->getInput(butt4, Curr_time_ms);
            butt4->toggle(butt4);
            butt5->getInput(butt5, Curr_time_ms);
            butt5->toggle(butt5);
            butt6->getInput(butt6, Curr_time_ms);
            butt6->toggle(butt6);
            butt7->getInput(butt7, Curr_time_ms);
            butt7->toggle(butt7);
            butt8->getInput(butt8, Curr_time_ms);
            butt8->toggle(butt8);

            if(CMS_qOnce){
                CMS_qOnce = false;
            }
        }

        // Child program
        // Sensors, database
        if(cpid == 0){
            // Read DHT
            if(Curr_time_ms > tTimer1 + timevalue + 60000000) {
                dht11->readData(dht11);
                tTimer1 = bcm2835_st_read() / 1000;
            }
            // Read SHT Modbus
            if(Curr_time_ms > tTimer2 + timevalue + 60000000){
                ret = sht20->modbusExecute(sht20, ctx);
                if( ret == 1) timevalue = 6000000;
                tTimer2 = bcm2835_st_read() / 1000;
            }
            //Record to database
            if(Curr_time_ms > tTimer4 + timevalue + 700000){
                char str[53];
                if(sht20->data_ok == true){
                    strcpy(str, insert_climate(sht20->name,
                                                sht20->temperatura,
                                                sht20->wilgotnosc));
                    rc = sqlite3_exec(db, str, NULL, NULL, &err);
                    if (rc != SQLITE_OK) printf("error SHT20 %s\n", *err);
                }
                if(dht11->data_ok == true){
                    //strcpy(str, insert_climate(dht11_1));
                    rc = sqlite3_exec(db, str, NULL, NULL, &err);
                    if (rc != SQLITE_OK) printf("error DHT11 %s\n", *err);
                }
                tTimer4 = bcm2835_st_read() / 1000;
            }
        }

        // Read current time and calculate prg time
        EndPrgTime_us = bcm2835_st_read();
        if(EndPrgTime_us > tTimer3){
            if(cpid == 0) {
               /* if (EndPrgTime_us - Curr_time_us > maxtime) {
                    maxtime = EndPrgTime_us - Curr_time_us;
                    printf("\033[2J");
                    printf("   Parent Prg Cycle time: %lld us \n", EndPrgTime_us - Curr_time_us);
                }*/
               ;
            }
            else {
                ;
            }
            tTimer3 = bcm2835_st_read();
        }
    }
}