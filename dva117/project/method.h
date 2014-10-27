struct http_req {
    char *ip;
    char *method;
    char *fullfilepath;
    char *http_ver;
};  


char *skip_character(char **buf, const char *d) {

    char *p, *w_begin, *w_end, *d_end;
    
    w_begin = *buf;
    w_end = w_begin + strcspn(w_begin, d);
    d_end = w_end + strspn(w_end, d);

    for (p = w_end; p < d_end; p++) {
        *p = '\0';
    }

    *buf = d_end;

    return w_begin;

}


int parse_http_req(struct http_req *n, char *http_string) {

    int i, pos, x=0;
    int request_length = strlen(http_string);
    http_string[request_length+2] = '\0';

    while (*http_string != '\0' && isspace(* (unsigned char *) http_string)) {
        http_string++;
    }

    n->method = skip_character(&http_string, " ");
    n->fullfilepath = skip_character(&http_string, " ");
    n->http_ver = skip_character(&http_string, "\r\n");

}


int validate_method(char *method) {

    int response=21;

    if ((strncmp(method, "GET", 20) == 0) ||
        (strncmp(method, "HEAD", 20) == 0) ||
        (strncmp(method, "OPTIONS", 20)) == 0) {
            response=20;
    }
    
    return response;
}















