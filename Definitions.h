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
#include <errno.h>
#include <modbus.h>
#include <fcntl.h>
#include <netinet/in.h>		// inet_addr
#include <sys/socket.h>
#include <sys/types.h>
#include <mysql/mysql.h>


#define BTN4        RPI_BPLUS_GPIO_J8_15
#define BTN5        RPI_BPLUS_GPIO_J8_19
#define BTN6        RPI_BPLUS_GPIO_J8_21
#define BTN7        RPI_BPLUS_GPIO_J8_23
#define BTN8        RPI_BPLUS_GPIO_J8_29
#define BTN9        RPI_BPLUS_GPIO_J8_31
#define BTN10       RPI_BPLUS_GPIO_J8_33
#define BTN11       RPI_BPLUS_GPIO_J8_35
#define BTN12       RPI_BPLUS_GPIO_J8_37

#define OUT2        RPI_BPLUS_GPIO_J8_18
#define OUT3        RPI_BPLUS_GPIO_J8_22
#define OUT4        RPI_BPLUS_GPIO_J8_24
#define OUT5        RPI_BPLUS_GPIO_J8_26
#define OUT6        RPI_BPLUS_GPIO_J8_32
#define OUT7        RPI_BPLUS_GPIO_J8_36
#define OUT8        RPI_BPLUS_GPIO_J8_38
#define OUT9        RPI_BPLUS_GPIO_J8_40

enum buttons{KUCHNIA, LAZIENKA, SALON};
enum inputs{
    inKUCHNIA1 = RPI_BPLUS_GPIO_J8_07,
    inKUCHNIA2 = RPI_BPLUS_GPIO_J8_11,
    inLAZIENKA1 = RPI_BPLUS_GPIO_J8_13
};
enum outputs{
    outKUCHNIA = RPI_BPLUS_GPIO_J8_12,
    outLAZIENKA = RPI_BPLUS_GPIO_J8_16
};

#define DHT_PIN		RPI_BPLUS_GPIO_J8_08

#define PORT 5001
#define MAXMSGLENGTH 1024

#endif //UNTITLED_DEFINITIONS_H
