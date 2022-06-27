//
// Created by Patryk on 07.03.2022.
//

#ifndef MYCPROJECT_SOCKET_H
#define MYCPROJECT_SOCKET_H
#include "Definitions.h"


//Socket variables
extern int sockfd, newsockfd, clilen, on;				// Socket stuff
extern pid_t pid2;
extern struct sockaddr_in serveraddr, cli_addr;

void forkmain(int sock);
void loopsock();
void initSocket();

#endif //MYCPROJECT_SOCKET_H
