//
// Created by Patryk on 09.01.2022.
//
#include "modbusRtu.h"

RtuConnection* sensor_constructor(RtuConnection* sensor, char* name){
    sensor->name = name;
    sensor->temperatura = -99;
    sensor->wilgotnosc = -99;
    sensor->data_ok = false;

    sensor->modbusExecute = modbusExecute;
}

void ModbusPrintError(){
    printf("MdBus err.: %s\n", modbus_strerror(errno));
}

uint16_t modbusExecute(RtuConnection* sensor, modbus_t* ctx){
    if (ctx == NULL){
        sensor->data_ok = FALSE;
        ModbusPrintError();
        return 1;
    }
    else if(modbus_set_slave(ctx, 8) == -1){
        sensor->data_ok = FALSE;
        ModbusPrintError();
        return 1;
    }
    else{
        if(modbus_read_input_registers(ctx, 1, 1, &sensor->temperatura) == 1 &&
           modbus_read_input_registers(ctx, 2, 1, &sensor->wilgotnosc) == 1) {
            sensor->data_ok = TRUE;
            printf("%s Temp: %2.1f st.C  Wilg: %2.1f %\n",
                   sensor->name,
                   ((float) sensor->temperatura) / 10,
                   (((float) sensor->wilgotnosc) / 10));
        }
        else{
            sensor->data_ok = FALSE;
            ModbusPrintError();
        }
        return 2;
    }
}

