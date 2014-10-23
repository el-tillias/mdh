/*Required Headers*/
 
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "method.h"


struct http_req {
    char *ip;
    char *method;
    char *file;
    char *filepath;
    char *http_ver;
};

struct sockaddr_in servaddr;


int main(void)
{

    int listen_fd, comm_fd, i, x, z, m, n, k=0;
    struct sockaddr_in servaddr;
    char incoming_request[100];

    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    bzero( &servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htons(INADDR_ANY);
    servaddr.sin_port = htons(22000);
    bind(listen_fd, (struct sockaddr *) &servaddr, sizeof(servaddr));
    listen(listen_fd, 10);


    while (1) {

        int y, i = 0, start_new_session = 0;
        comm_fd = accept(listen_fd, (struct sockaddr*) NULL, NULL);

        while(1) {
 
            bzero(incoming_request, 1000);
            read(comm_fd,incoming_request,1000);
            parse_http_req(incoming_request);

        }
    }
}
