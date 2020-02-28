#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    unsigned short port;
    struct sockaddr_in client;
    struct sockaddr_in server;
    int namelen, sockfd, newsockfd;
    char buff[12];

    if (2 > argc){
        printf("Usage : %s <port>\n", argv[0]);
        exit(0);
    }
    port = (unsigned short)(atoi(argv[1]));

    /* Create Stream socket in Internet domain with default protocol */
    sockfd =  socket(AF_INET, SOCK_STREAM, 0);
    if (0 > sockfd){
        printf("socket() failed\n");
        exit(0);
    }

    /* assign server attributes */
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = INADDR_ANY;

    /* Bind socket with the server attributes */
    if (bind(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0){
        printf("bind() failed\n");
        exit(0);
    }
    
    /* Tell the system that you are ready to accept connections */
    if (listen(sockfd, 0) < 0){
        printf("listen() failed\n");
        exit(0);
    }
    namelen = sizeof(client);

    newsockfd = accept(sockfd, (struct sockaddr *)&client, &namelen);
    if (0 > newsockfd){
        printf("accpt failed\n");
        exit(0);
    }
    
    /* receive the messsage */
    if (recv(newsockfd, buff, sizeof(buff), 0) < 0){
        printf("receive failed\n");
        exit(0);
    }
    printf("%s\n", buff);
    strcpy(buff, "client");
    if (send(newsockfd, buff, sizeof(buff), 0) < 0){
        printf("Send failed\n");
        exit(0);
    }
    close(newsockfd);
    close(sockfd);

    printf("Socket closed successfully\n");
    return 0;
}
