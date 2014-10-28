#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *response_ok() {
    return "HTTP/1.1 200 OK\r\n\r\n";
}

char *non_valid_method() {
    return "Not a valid method. ";
}

char *directory_traversal() {
    return "Directory traversal detected. ";
}

char *end_err() {
    return "</strong>\r\n\r\n";
}
