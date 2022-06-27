//
// Created by Patryk on 23.06.2022.
//

#ifndef MYCPROJECT_MODBUSRTU_H
#define MYCPROJECT_MODBUSRTU_H
#include "Definitions.h"

typedef struct sRtuConnection{
    char *name;
    uint16_t temperatura;
    uint16_t wilgotnosc;
    bool data_ok;

    uint16_t (*modbusExecute)(struct sRtuConnection* self, modbus_t* ctx);
} RtuConnection;

RtuConnection* sensor_constructor(RtuConnection* sensor, char* name);

uint16_t modbusExecute(RtuConnection* sensor, modbus_t* ctx);



#endif //MYCPROJECT_MODBUSRTU_H
