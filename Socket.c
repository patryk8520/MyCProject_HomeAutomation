//
// Created by Patryk on 07.03.2022.
//

#include "Socket.h"


// socket
int sockfd, newsockfd, clilen, on;				// Socket stuff
pid_t pid2; 										// child process id
struct sockaddr_in serveraddr, cli_addr;

void initSocket(){
    sockfd = socket(AF_INET, SOCK_STREAM, 0);		// initialize new socket
    if (sockfd < 0)
    {
        perror("Could not create socket\n");
        exit(1);
    }
    printf("Socket created\n");

    // Enable address reuse //
    on = 1;
    if (setsockopt( sockfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on)) < 0) {
        perror("Error setting socket options, exiting.");
        exit(1);
    }

    // Allow connections to PORT from any available interface  //
    memset(&serveraddr, '0', sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = htonl( INADDR_ANY );
    serveraddr.sin_port = htons(PORT);
}


/* This function is where the actual processing of information takes place */
void forkmain(int sock) {
    int rwstatus;
    char buffer[MAXMSGLENGTH];						// Message content

    memset(&buffer, 0, sizeof(buffer));
    rwstatus = read(sock,buffer,MAXMSGLENGTH);
    if (rwstatus < 0) {
        perror("Error reading from socket");
        close(sock);
        return;
    }

    printf("Here is the message: %s\n",buffer);
    printf("Here is the message: %d\n",atoi(buffer));
    bcm2835_gpio_write(outKUCHNIA, atoi(buffer));

    rwstatus = write(sock,"RPi: Data OK......",18);
    printf("%u\n",rwstatus);
    if (rwstatus < 0) {
        perror("Error writing to socket");
        close(sock);
        return;
    }
}

void loopsock(){
    while(1){
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
        if (newsockfd < 0) {
            perror("Error on client connection. Abort.");
            exit(1);
        }
        puts("Connection accepted");

        pid2 = fork();

        /* Error */
        if (pid2 < 0) {
            perror("Error creating child process. Abort.");
            exit(1);
        }

        /* Server child */
        if (pid2 == 0) {
            close(sockfd);
            forkmain(newsockfd);
            close(newsockfd);
            puts("Client connection terminated.");
            exit(0);
        }

        /* Close connection */
        else {
            close(newsockfd);
        }
    }
}