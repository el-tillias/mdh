#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <ctype.h>

int convert(char *input, char **wordpointers) {

    int i=0, z=0, x=1;
    wordpointers[z++] = &input[i];
    for(i=0; i<strlen(input); i++) {
        if (input[i] == ' ') {
            wordpointers[z++] = &input[i+1];
            x++;
        }
        else if (input[i] == '\n') {
            break;
        }
    }

    return x;
}



int main(void) {

    char input[200];
    char *wordpointers[200];
    int i, count;

    printf("Write a word: ");
    fgets(input, sizeof(input), stdin);

    count = convert(input, wordpointers);

    for (i=0; i<count; i++) {
        if (*wordpointers[i] == ' ') {
            continue;
        }
        else if (*wordpointers[i] == '\n') {
            break;
        }
        else {
            printf("word: %s\n", wordpointers[i]);
        }
    }

    return 0;
    

}
