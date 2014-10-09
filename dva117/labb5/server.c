/*Required Headers*/
 
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include<string.h>
 
int main()
{
 
    char str[100];
    int listen_fd, comm_fd;
 
    struct sockaddr_in servaddr;
 
    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
 
    bzero( &servaddr, sizeof(servaddr));
 
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htons(INADDR_ANY);
    servaddr.sin_port = htons(22000);
    
    bind(listen_fd, (struct sockaddr *) &servaddr, sizeof(servaddr));
    listen(listen_fd, 10);

    while (1) {

        int i, start_new_session = 0;
        comm_fd = accept(listen_fd, (struct sockaddr*) NULL, NULL);

        while(1) {
 
            bzero( str, 100);
            read(comm_fd,str,100);

            for (i=0; i<1; i++) {
                if (str[i] == '#') {
                    write(comm_fd, "See you later.\n\n", strlen("See you later.")+1);
                    close(comm_fd);
                    bzero( str, 100);
                    start_new_session = 1;
                }
            }

            if (start_new_session == 1) {
                break;
            }

            printf("Echoing back - %s",str);
            write(comm_fd, str, strlen(str)+1);
        }
    }
}
