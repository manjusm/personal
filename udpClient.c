#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int sockfd;
    unsigned short port;
    struct sockaddr_in server;
    char buff[32];
    
    if(3 != argc){
        printf("Usage : %s <host name> <port>\n", argv[0]);
        exit(0);
    }
    port = htons(atoi(argv[2]));
    /* Create Datagram socket in the Internet domain.
     * Select Default protocol.
     */
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (0 > sockfd){
        printf("Error in creating socket\n");
        exit(0);
    }
    /* Setup the server */
    server.sin_family = AF_INET;                /* Internet Domain */
    server.sin_port = port;                     /* Server port */
    server.sin_addr.s_addr = inet_addr(argv[1]);/* Server address */

    strcpy(buff, "Hello");

    if (sendto(sockfd, buff, (strlen(buff)+1), 0,
                (struct sockaddr *)&server, sizeof(server)) < 0){
        printf("Error in sendto()\n");
        exit(0);
    }
    close(sockfd);
    return 0;
}
