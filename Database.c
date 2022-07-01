//
// Created by Patryk on 25.06.2022.
//

#include "database.h"

void dataConn_constructor(DataConn* this){
    this->conn = mysql_init(NULL);

    this->host = "192.168.0.15";
    this->user = "pi";
    this->pass = "raspberry";
    this->dbname = "ptaki";

    this->port = 3306;
    this->unix_socket = NULL;
    this->flag = 0;

    this->dataConnInit = dataConnInit;
    this->doDatabase = doDatabase;
    this->closeDatabase = closeDatabase;
}

void dataConnInit(DataConn* this){
    if(!(mysql_real_connect(this->conn, this->host, this->user, this->pass,
                            this->dbname, this->port, this->unix_socket, this->flag))){
        fprintf(stderr, "\nError: %s [%d]\n", mysql_error(this->conn),
                mysql_errno(this->conn));
        exit(1);
    }
    else
        printf("SUCCESS\n");
}

void doDatabase(DataConn* this){
    mysql_query(this->conn, "SELECT * FROM gatunki");
    this-> res = mysql_store_result(this->conn);

    while(this->row = mysql_fetch_row(this->res)){
        printf("id: %s\tnazwa: %s\tlacina: %s\n", this->row[0],
               this->row[1], this->row[2]);
    }
}

void closeDatabase(DataConn* this){
    mysql_close(this->conn);
}

const char* insert_climate(char* name, uint16_t temperatura, uint16_t wilgotnosc){
    time_t seconds;
    struct tm ts;
    static char str[53]= {};
    char timestamp[21];
    time(&seconds);
    ts = *localtime(&seconds);
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M", &ts);
    char val[3];
    strcpy(str, "INSERT INTO "); strcat(str, name);
    strcat(str, " VALUES (");
    sprintf(val, "%d", temperatura);
    strcat(str, val);  strcat(str, ",");
    sprintf(val, "%d", wilgotnosc); strcat(str, val);
    strcat(str, ",'"); strcat(str, timestamp);
    strcat(str, "');");
    return str;
}