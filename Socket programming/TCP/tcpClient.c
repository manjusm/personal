#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    unsigned short port;
    char buff[12];
    struct sockaddr_in server;
    struct hostent *hostnm;
    int sock_fd;

    if (3 > argc){
        printf("Usage : %s <host name> <port>\n", argv[0]);
        exit(0);
    }

    /* Host name is the first argument. Get the server address. */
    hostnm = gethostbyname(argv[1]);
    if (NULL == hostnm){
        printf("Gethostbyname failed \n");
        exit(0);
    }
    /* Port is the second argument */

    port = (unsigned short) atoi(argv[2]);

    /* Put message into the buffer */
    strcpy(buff, "Hello");

    /* Server information */
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = *((unsigned long *)(hostnm->h_addr));

    /* Create stream socket */
    /* Internet Domain with Stream socket. Default protocol TCP */
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (0 > sock_fd){
        printf("socket create failed\n");
        exit(0);
    }
    
    /* Connect to the server */
    if (connect(sock_fd, (struct sockaddr *)&server, sizeof(server)) < 0){
        printf("Connect failed\n");
        exit(0);
    }
    
    /* Send the message to server */
    if (send(sock_fd, buff, strlen(buff)+1, 0) < 0){
        printf("Send() failed\n");
        exit(0);
    }
    printf("%s\n", buff);
    /* Server sends back the same message */
    if (recv(sock_fd, buff, sizeof(buff), 0) < 0){
        printf("recv() failed\n");
        exit(0);
    }
        
    printf("%s\n", buff);
    close(sock_fd);
    printf("Client ended sucessfully\n");
    
    return 0;
} 
