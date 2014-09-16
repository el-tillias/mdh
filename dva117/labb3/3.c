#include <string.h>
#include <stdio.h>
#include <stdlib.h>


int main(void) {

    char input[25];
    int i, strlength = 0;

    printf("Type a word for checking palindrome: ");
    scanf("%s", input);

    //calculate stringlength of input
    for (i = 0; input[i] != '\0'; i++)
    {
        strlength++;
    }

    char input_rev[50] = {'\0'};

    for (i = strlength; i >= 0; i--) {
        // we start at the end if input array which contains a \0.
        // we ommmit this by starting copying that into input_rev[-1]
        input_rev[strlength - i - 1] = input[i];
    }

    if (strcmp(input_rev, input) == 0) {
       printf ("%s is a palindrome. \n", input_rev);
    }
    else {
       printf("%s is not a palindrome. \n", input);
    }

    return 0;
}
