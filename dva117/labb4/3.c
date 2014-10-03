#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <ctype.h>

int again(void) {

    char a;

    while (1) {
        printf("Try again? (y/n): ");
        scanf("%c", &a);
        if (a == 'y') {
            return 1;
        }
        else if (a == 'n') {
            return 0;
        }
        else {
            continue;
        }
    }
    return 0;
}



int convert(char *input, char **wordpointers) {

    int i=0, z=0, x=1;
    wordpointers[z++] = &input[i];
    for(i=0; i<strlen(input); i++) {
        if (input[i] == ' ') {
            input[i] = '0';
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
    char bajs;
    char *wordpointers[200];
    int i, count, z, y;


    while(1) {
        printf("Write a word: ");
        fgets(input, 200, stdin);

        count = convert(input, wordpointers);

        for (i=0; i<count; i++) {
            printf("Word %i (ptr: %p): ", i, &wordpointers[i]);
            for (z=0; z<strlen(wordpointers[i]); z++) {
                if (wordpointers[i][z] == '0') {
                    printf("\n");
                    break;
                }
                else {
                    printf("%c", wordpointers[i][z]);
                }
            }
        }

        y = again();

        if (y == 1) {
            continue;

        }
        else if (y == 0) {
            break;
        }
    }

    return 0;

}
