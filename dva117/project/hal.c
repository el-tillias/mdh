#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include "hal.h"
#include "request.c"
#include "response.c"



void *request_handler(void *http_socket) {

    int comm_fd = *(int*)http_socket;
    char incoming_request[1000];
    struct http_req h;
    int method_response, string_response;
    char err_response[60];
    char *temp;

    bzero(incoming_request, 1000);
    read(comm_fd,incoming_request,1000);
    parse_http_req(&h, incoming_request);
    method_response = validate_method(h.method);
    string_response = validate_reqstring(h.fullfilepath);

    if (method_response == 0 || string_response == 0) {
        temp = begin_response();
        strcat(err_response, temp);
    }

    if (method_response == 0) {
        temp = non_valid_method();
        strcat(err_response, temp); 
    }

    if (string_response == 0) {
        temp = directory_traversal();
        strcat(err_response, temp);
    }

    if (string_response == 1 && method_response == 1) {
        write(comm_fd, response_ok(), strlen(response_ok()));
        write(comm_fd, "OK", strlen("OK"));
    }

    else {
        temp = end_response();
        strcat(err_response, temp);
        write(comm_fd, response_ok(), strlen(response_ok()));
        write(comm_fd, err_response, strlen(err_response));
    }

    close(comm_fd);
    bzero(incoming_request,1000);
}


int main(void) {

    int comm, listen_fd;
    struct sockaddr_in servaddr;
    pthread_t thread_id;

    listen_fd = socket(AF_INET, SOCK_STREAM, 0); 
    bzero( &servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htons(INADDR_ANY);
    servaddr.sin_port = htons(1400);
    bind(listen_fd, (struct sockaddr *) &servaddr, sizeof(servaddr));
    listen(listen_fd, 10);

    while(1) {
        comm = accept(listen_fd, (struct sockaddr*) NULL, NULL);
        if ( pthread_create( &thread_id , NULL ,  request_handler , (void*) &comm) < 0) {
            printf("Could not create thread.\n");
        }
    }
    
    return 0;
   
}
