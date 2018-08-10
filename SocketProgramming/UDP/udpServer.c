#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>

int main()
{
    int s, namelen, client_address_size;
    struct sockaddr_in client, server;
    char buf[32];

    /*
     * Create a datagram socket in the internet domain and use the
     * default protocol (UDP).
     */
    if ((s = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        printf("socket()");
        exit(1);
    }
    server.sin_family      = AF_INET;  /* Server is in Internet Domain */
    server.sin_port        = 0;         /* Use any available port      */
    server.sin_addr.s_addr = INADDR_ANY;/* Server's Internet Address   */
    if (bind(s, (struct sockaddr *)&server, sizeof(server)) < 0) {
        printf("bind()");
    exit(2);
    }

    namelen = sizeof(server);
    if (getsockname(s, (struct sockaddr *) &server, &namelen) < 0) {
        printf("getsockname()");
        exit(3);
    }

    printf("Port assigned is %d\n", ntohs(server.sin_port));
    client_address_size = sizeof(client);
    if(recvfrom(s, buf, sizeof(buf), 0, (struct sockaddr *) &client,
                &client_address_size) <0) {
        printf("recvfrom()");
        exit(4);
    }
    printf("Received message %s from domain %s port %d internet\
            address %s\n", buf,
            (client.sin_family == AF_INET?"AF_INET":"UNKNOWN"),
            ntohs(client.sin_port),
            inet_ntoa(client.sin_addr));
    close(s);
}
