//
// Created by Patryk on 18.06.2022.
//

#ifndef MYCPROJECT_DHT11_H
#define MYCPROJECT_DHT11_H
#include <stdint.h>
#include <stdbool.h>

typedef struct sDht11{
    uint8_t GPIOnum;
    char *name;
    uint16_t temperatura;
    uint16_t wilgotnosc;
    bool data_ok;
    uint8_t(*readData)(struct sDht11* self);
} Dht11;

Dht11* dht11_constructor(Dht11* dht11, char* name, uint8_t GPIOnum);

uint8_t readData(Dht11* dht11);

#endif //MYCPROJECT_DHT11_H
