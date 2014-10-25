#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "method.h"


int main(void) {

    char incoming_request[100];
    int comm_fd, listen_fd;
    struct sockaddr_in servaddr;
    struct http_req h;

    listen_fd = socket(AF_INET, SOCK_STREAM, 0); 
    bzero( &servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htons(INADDR_ANY);
    servaddr.sin_port = htons(1400);
    bind(listen_fd, (struct sockaddr *) &servaddr, sizeof(servaddr));
    listen(listen_fd, 10);



    while(1) {

        comm_fd = accept(listen_fd, (struct sockaddr*) NULL, NULL);

        while (1) {

            bzero(incoming_request, 1000);
            read(comm_fd,incoming_request,1000);
            parse_http_req(&h, incoming_request);

            printf("method: %s\n", h.method);
            printf("filepath: %s\n", h.fullfilepath);
            printf("http_ver: %s\n", h.http_ver);
        }
    }

    return 0;
}
