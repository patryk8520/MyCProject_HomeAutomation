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

    uint16_t (*modbusExecute)(struct sRtuConnection*, modbus_t* ctx);
} RtuConnection;

void sensor_constructor(RtuConnection*, char* name);

uint16_t modbusExecute(RtuConnection*, modbus_t* ctx);
void ModbusPrintError();
modbus_t* ModbusInit();


#endif //MYCPROJECT_MODBUSRTU_H
