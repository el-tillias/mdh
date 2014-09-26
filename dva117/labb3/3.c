#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>

int main(void) {

    setlocale(LC_ALL, "");

    char input[50] = {'\0'};
    char input_rev[50] = {'\0'};
    char shogun[50] = {'\0'};
    int c, i, strlength = 0, x = 0;

    printf("Type a word for checking palindrome: ");
    while ((c = getchar()) != '\n') {
        shogun[x] = c;

        if (c != ' ' && c != ',') {
            printf("%c\n", c);
            input[strlength] = tolower(c);
            strlength++;
        }
        x++;
    }

    for ( i = 0; i < strlength; i++) {
        input_rev[strlength - i - 1] = input[i];
    }

    if (strcmp(input_rev, input) == 0) {
       printf ("Palindrome found! (%s)\n",shogun);
    }
    else {
       printf("Palindrome not found. (%s) \n",shogun);
    }

    return 0;
}
