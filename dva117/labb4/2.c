#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int cmpfunc(const void *a, const void *b)
{
       return (*(int*)a - *(int*)b);
}


void print_top(int *sorted, int length)  {

    int top, top_occur, i, z, candidate=0, new_candidate=0, occur=0, new_occur=0;

    candidate=sorted[0];
    for (z=0; z<length; z++) {
        if (candidate == sorted[z]) {
            occur++;
        }
    }

    top_occur=occur;
    top=candidate;

    for (z=0; z<length; z++) {
        new_candidate = sorted[z];
        if (new_candidate != candidate && top != new_candidate) {
            for (i=0; i<length; i++) {
                if (new_candidate == sorted[i]) {
                    new_occur++;
                }
            }
        }

        if (new_occur>occur) {
            top_occur=new_occur;
            top=new_candidate;
        }
        new_occur=0;
    }

    printf("top number: %i, occurrency: %i\n", top, top_occur);
}



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

int main(void) {


    while (1) {

        int input[100];
        int z, c, strlength = 0;

        printf("Type an integer between 1 and 1000, max 100 integers in each run: ");

        while (scanf("%d", &c)) {

            if (c < 0 || strlength > 100) {
                break;
            }
            else if (c > 1000) {
                printf("Valid integers are between 1 and 1000\n");
            }

            else {
                input[strlength] = c;
                strlength++;
            }

            printf("Type another integer: ");
        }

        qsort(input, strlength, sizeof(int), cmpfunc);
        print_top(input, strlength);

        z = again();

        if (z == 1) {
            //memset(input, 0, sizeof(input));
            continue;

        }
        else if (z == 0) {
            break;
        }

    }

    return 0;
}#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int cmpfunc(const void *a, const void *b)
{
       return (*(int*)a - *(int*)b);
}


void print_top(int *sorted, int length)  {

    int top, top_occur, i, z, candidate=0, new_candidate=0, occur=0, new_occur=0;

    candidate=sorted[0];
    for (z=0; z<length; z++) {
        if (candidate == sorted[z]) {
            occur++;
        }
    }

    top_occur=occur;
    top=candidate;

    for (z=0; z<length; z++) {
        new_candidate = sorted[z];
        if (new_candidate != candidate && top != new_candidate) {
            for (i=0; i<length; i++) {
                if (new_candidate == sorted[i]) {
                    new_occur++;
                }
            }
        }

        if (new_occur>occur) {
            top_occur=new_occur;
            top=new_candidate;
        }
        new_occur=0;
    }

    printf("top number: %i, occurrency: %i\n", top, top_occur);
}



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

int main(void) {


    while (1) {

        int input[100];
        int z, c, strlength = 0;

        printf("Type an integer between 1 and 1000, max 100 integers in each run: ");

        while (scanf("%d", &c)) {

            if (c < 0 || strlength > 100) {
                break;
            }
            else if (c > 1000) {
                printf("Valid integers are between 1 and 1000\n");
            }

            else {
                input[strlength] = c;
                strlength++;
            }

            printf("Type another integer: ");
        }

        qsort(input, strlength, sizeof(int), cmpfunc);
        print_top(input, strlength);

        z = again();

        if (z == 1) {
            //memset(input, 0, sizeof(input));
            continue;

        }
        else if (z == 0) {
            break;
        }

    }

    return 0;
}
