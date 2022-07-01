//
// Created by Patryk on 25.06.2022.
//

#ifndef MYCPROJECT_DATABASE_H
#define MYCPROJECT_DATABASE_H
#include "Definitions.h"
#include <mysql/mysql.h>

typedef struct sDatabase{
    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;

    char *host;
    char *user;
    char *pass;
    char *dbname;

    unsigned int port;
    char *unix_socket;
    unsigned int flag;

    void (*doDatabase)(struct sDatabase*);
    void (*dataConnInit)(struct sDatabase*);
    void (*closeDatabase)(struct sDatabase*);
} DataConn;

void dataConn_constructor(DataConn*);
void dataConnInit(DataConn*);
void doDatabase(DataConn*);
void closeDatabase(DataConn*);
const char* insert_climate(char* name, uint16_t temperatura, uint16_t wilgotnosc);

#endif //MYCPROJECT_DATABASE_H
