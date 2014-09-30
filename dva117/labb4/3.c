#include <string.h>
#include <stdlib.h>
#include <stdio.h>


int shogun(char *string, char *string_array) {

    int i, nwords = 0;
    char *strpointer=string;

    for(i=0; i<strlen(string); i++) {
        if (string[i] == ' ') {
            strpointer++;
        }

        else if (string[i] == '\0') {
            break;
        }

        string_array[nwords++] = strpointer;
    }

    return nwords;
}


int main(void) {


    char w[200];
    int words, i;
    char str_array[200] = {'\0'};

    printf("Write a word: ");
    fgets(w, 200, stdin);

    words=shogun(w, str_array);

    for(i = 0; i < words; i++) {
        printf("%s\n", str_array[i]);
    }

    return 0;
    

}
