#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int main(void) {

    char input[50] = {'\0'};
    char input_rev[50] = {'\0'};
    int c, i, strlength = 0;

    printf("Type a word for checking palindrome: ");
    while ((c = getchar()) != '\n') {
        if (c != ' ') {
            input[strlength] = tolower(c);
            strlength++;
        }
    }

    for ( i = 0; i < strlength; i++) {
        input_rev[strlength - i - 1] = input[i];
    }

    if (strcmp(input_rev, input) == 0) {
       printf ("Palindrome found! \n");
    }
    else {
       printf("Palindrome not found. \n");
    }

    return 0;
}