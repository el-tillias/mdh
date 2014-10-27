const char *response_ok() {
    return "HTTP/1.1 200 OK\r\n\r\n";
}

const char *non_valid_method() {
    return "400 Not valid method.\r\n\r\n";
}
