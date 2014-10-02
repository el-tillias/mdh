#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <ctype.h>

int again(void) {

    char again;

    while(1) {

        printf("Run again? (y/n): ");
        scanf(" %c", &again);
        if (again == 'y') {
            return 1;
        }
        else if (again == 'n') {
            return 0;
        }
        else {
            printf("\nAnswer with 'y' or 'n'");
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

    while(1) {
        char input[200];
        char *wordpointers[200];
        int i, count, z, y;

        printf("Write a word: ");
        fgets(input, sizeof(input), stdin);

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
