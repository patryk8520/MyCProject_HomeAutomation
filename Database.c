//
// Created by Patryk on 25.06.2022.
//

#include "database.h"

const char* insert_climate(char* name, uint16_t temperatura, uint16_t wilgotnosc){
    time_t seconds;
    struct tm ts;
    static char str[53]= {};
    char timestamp[21];
    time(&seconds);
    ts = *localtime(&seconds);
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M", &ts);
    char val[3];
    strcpy(str, "INSERT INTO ");
    strcat(str, name);
    strcat(str, " VALUES (");
    sprintf(val, "%d", temperatura);
    strcat(str, val);
    strcat(str, ",");
    sprintf(val, "%d", wilgotnosc);
    strcat(str, val);
    strcat(str, ",'");
    strcat(str, timestamp);
    strcat(str, "');");
    return str;
}