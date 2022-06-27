//
// Created by Patryk on 16.01.2022.
//
#include "Definitions.h"

uint8_t Parent_init(){
    printf("Parent created, cpid: %d\n", cpid);

    // Start Program
    if(!bcm2835_init()) return 1;

    // Init Outputs
    bcm2835_gpio_fsel(LED, BCM2835_GPIO_FSEL_OUTP);
    bcm2835_gpio_fsel(OUT1, BCM2835_GPIO_FSEL_OUTP);
}

uint8_t Child_init(){
    printf("Child created, cpid: %d\n", cpid);
    //SQLITE
    sqlite3_open("myDb.db", &db);
    rc = sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS "
                          "SHT20(temp INT, wilg INT, timestamp varchar(55));",
                      NULL, NULL, &err);
    if (rc != SQLITE_OK) printf("error %s", err);
    rc = sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS "
                          "DHT11(temp INT, wilg INT, timestamp varchar(55));",
                      NULL, NULL, &err);
    if (rc != SQLITE_OK) printf("error %s", err);
    //printf("sqlite3 version %s\n", sqlite3_libversion());
    // Bcm2835 Init
    if(!bcm2835_init()) return 1;
    // Modbus Variable
    ctx = modbus_new_rtu("/dev/ttyUSB0", 9600, 'N', 8, 1);
    if (modbus_connect(ctx)== -1){
        ModbusPrintError();
        return 1;
    }
}