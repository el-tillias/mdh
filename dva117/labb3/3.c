#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char remove_chars(char *rem) {

    int i;
    char rmed[50] = {'\0'};
    for(i=0; rmed[i] != '\0'; i++) {
        if (rmed[i] == '\s') {
            continue;
        }
        else {
            rmed[i] = rem[i];
            printf("Char: %d\n", rmed[i]);
        }
    }

    return rmed;

}
    


int main(void) {

    char input[25], rmed[50];
    int i, strlength = 0;

    printf("Type a word for checking palindrome: ");
    scanf("%s", input);

    rmed = remove_chars(input);

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
