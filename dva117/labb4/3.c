#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <ctype.h>

void convert(char *input, char *wordpointers) {

    int i=0, z=0, x=0;
    wordpointers[z++] = &input[0];
    for(i=1; i<strlen(input); i++) {
        if (input[i] == ' ') {
            wordpointers[z++] = &input[i+1];
        }
    }

    for (i=0; i<z; i++) {
        printf("pointer of %i: %x.", i, &wordpointers[i]);
        for (z=0; z<strlen(wordpointers); z++) {
            printf("Contains: %c", wordpointers[z]);
        }
    }

}



int main(void) {

    char input[200];
    char *wordpointers[300];

    printf("Write a word: ");
    fgets(input, sizeof(input), stdin);

    convert(input, wordpointers);

    return 0;
    

}
