//
// Created by Patryk on 09.01.2022.
//
#include "modbusRtu.h"

void sensor_constructor(RtuConnection* this, char* name){
    this->name = name;
    this->temperatura = -99;
    this->wilgotnosc = -99;
    this->data_ok = false;

    this->modbusExecute = modbusExecute;
}

modbus_t* ModbusInit(){
    modbus_t *ctx;
    ctx = modbus_new_rtu("/dev/ttyUSB0", 9600, 'N', 8, 1);
    if (modbus_connect(ctx)== -1){
        ModbusPrintError();
        exit(1);
    }
    return ctx;
}

void ModbusPrintError(){
    printf("MdBus err.: %s\n", modbus_strerror(errno));
}

uint16_t modbusExecute(RtuConnection* this, modbus_t* ctx){
    if (ctx == NULL){
        this->data_ok = FALSE;
        ModbusPrintError();
        return 1;
    }
    else if(modbus_set_slave(ctx, 8) == -1){
        this->data_ok = FALSE;
        ModbusPrintError();
        return 1;
    }
    else{
        if(modbus_read_input_registers(ctx, 1, 1, &this->temperatura) == 1 &&
           modbus_read_input_registers(ctx, 2, 1, &this->wilgotnosc) == 1) {
            this->data_ok = TRUE;
            printf("%s Temp: %2.1f st.C  Wilg: %2.1f %\n",
                   this->name,
                   ((float) this->temperatura) / 10,
                   (((float) this->wilgotnosc) / 10));
        }
        else{
            this->data_ok = FALSE;
            ModbusPrintError();
        }
        return 2;
    }
}

