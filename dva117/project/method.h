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

void parse_http_req(char *http_string) {

    struct http_req {
        char *ip;
        char *method;
        char *file;
        char *filepath;
        char *http_ver;
    };

    struct http_req *n;

    n = (struct http_req *) malloc(sizeof(struct http_req));

    int request_length = strlen(http_string);
    http_string[request_length-1] = '\0';

    while (*http_string != '\0' && isspace(* (unsigned char *) http_string)) {
        http_string++;
    }

    n->method = skip_character(&http_string, " ");
    n->filepath = skip_character(&http_string, " ");
    n->http_ver = skip_character(&http_string, "\r\n");

    printf("method: %s\n", n->method);
    printf("filepath: %s\n", n->filepath);
    printf("http_ver: %s\n", n->http_ver);
}
