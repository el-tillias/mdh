#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <ctype.h>

void convert(char *input, char *wordpointers) {

    int i, z=0;
    for(i=0; i<strlen(input); i++) {
        //printf("%c\n", input[i]);
        //printf("%c", wordpointers[i]);

        if (input[i] == ' ') {
            wordpointers[z++] = &input[i];
        }
    }

    //printf("size: %zu", sizeof(wordpointers));

    for (i=1; i<sizeof(wordpointers); i++) {
        printf("%c\n", wordpointers[i]);
    }

}



int main(void) {

    char input[200];
    char wordpointers = {'\0'};

    printf("Write a word: ");
    fgets(input, sizeof(input), stdin);

    convert(input, &wordpointers);

    return 0;
    

}
