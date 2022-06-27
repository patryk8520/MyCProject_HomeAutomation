//
// Created by Patryk on 09.01.2022.
//

#ifndef UNTITLED_DEFINITIONS_H
#define UNTITLED_DEFINITIONS_H
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <inttypes.h>
#include <stdbool.h>
#include <bcm2835.h>
#include <string.h>
#include <time.h>
#include <pthread.h>
#include <modbus.h>
#include "sqlite/sqlite3.h"
#include <errno.h>
#include <modbus.h>
#include <fcntl.h>
#include <netinet/in.h>		// inet_addr
#include <sys/socket.h>
#include <sys/types.h>


#define BTN1        RPI_BPLUS_GPIO_J8_07
#define BTN2        RPI_BPLUS_GPIO_J8_11
#define BTN3        RPI_BPLUS_GPIO_J8_13
#define BTN4        RPI_BPLUS_GPIO_J8_15
#define BTN5        RPI_BPLUS_GPIO_J8_19
#define BTN6        RPI_BPLUS_GPIO_J8_21
#define BTN7        RPI_BPLUS_GPIO_J8_23
#define BTN8        RPI_BPLUS_GPIO_J8_29
#define BTN9        RPI_BPLUS_GPIO_J8_31
#define BTN10       RPI_BPLUS_GPIO_J8_33
#define BTN11       RPI_BPLUS_GPIO_J8_35
#define BTN12       RPI_BPLUS_GPIO_J8_37

#define LED         RPI_BPLUS_GPIO_J8_12
#define OUT1        RPI_BPLUS_GPIO_J8_16
#define OUT2        RPI_BPLUS_GPIO_J8_18
#define OUT3        RPI_BPLUS_GPIO_J8_22
#define OUT4        RPI_BPLUS_GPIO_J8_24
#define OUT5        RPI_BPLUS_GPIO_J8_26
#define OUT6        RPI_BPLUS_GPIO_J8_32
#define OUT7        RPI_BPLUS_GPIO_J8_36
#define OUT8        RPI_BPLUS_GPIO_J8_38
#define OUT9        RPI_BPLUS_GPIO_J8_40

#define DHT_PIN		RPI_BPLUS_GPIO_J8_08

#define PORT 5001
#define MAXMSGLENGTH 1024

// CLIMATE Functions
const char* insert_climate(char* name, uint16_t temperatura, uint16_t wilgotnosc);


// Init functions
uint8_t Parent_init();
uint8_t Child_init();

//Global variables
extern modbus_t *ctx;
extern sqlite3 *db;

//pipe do not needed now
//extern int pipefd[2];
//Fork
extern pid_t cpid;

//SQLITE rc
extern int rc;
extern char *err;

void ModbusPrintError();
#endif //UNTITLED_DEFINITIONS_H
