// No, this code is not good looking. Should be using functions and shit.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 
int main()
{
    char file_name[25], word[100], temp[1000];
    int line_counter = 1, i=0, x, found_line[1000];
    FILE *fp;

    while (1) {
        printf("File to search: ");
        scanf("%s", file_name);

        fp = fopen(file_name,"r");
        if (fp == NULL) {
            perror("Error while opening the file. Check the filename again.\n");
        }
        else {
            break;
        }
    }
    
    while (1) {


        if (strcmp(file_name, "#q") == 0) {
            printf("Exiting.\n");
            return 0;
        }

        printf("Word to search for: ");
        scanf("%s", word);

        if (strcmp(word, "#q") == 0) {
            printf("Exiting.\n");
            return 0;
        }


        while(fgets(temp, 1000, fp) != NULL) {
            if((strstr(temp, word)) != NULL) {
                found_line[i] = line_counter;
                i++;
            }
            line_counter++;
        }

        if (i == 0) {
            printf("The word \"%s\" could not be found.\n", word);
        }
        else {
            printf("The word \"%s\" is found on line(s): ", word);
            for (x=0; x<i; x++) {
                printf("%i ", found_line[x]);
            }
        }
        line_counter = 1;
        i=0;
        printf("\n");
        rewind(fp);
    }

    fclose(fp);
    return 0;
}
