#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cmpfunc(const void *a, const void *b)
{
       return (*(int*)a - *(int*)b);
}


void print_top(int *sorted, int length)  {

    int i, z, candidate, new_candidate, occur=0, new_occur=0;

    for(i=0; i<length; i++) {
        new_candidate=sorted[i];
        for(z=0; z<length; z++) {
            if(sorted[z] == new_candidate) {
                candidate=new_candidate;
                new_occur++;
    }

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

    int input[100];
    int x, z, c, strlength = 0;


    while (1) {

        printf("Type an integer between 1 and 1000, max 100 integers in each run: ");

        while (scanf("%i", &c)) {

            if (c < 0 || strlength > 100) {
                break;
            }
            else if (c > 1000) {
                printf("Valid integers are between 1 and 1000\n");
            }

            else {
                input[strlength] = c;
                printf("bajs: %i\n", input[strlength]);
                strlength++;
            }

            printf("Type another integer: ");
        }

        qsort(input, strlength, sizeof(int), cmpfunc);
        print_top(input, strlength);


        z = again();

        if (z == 1) {
            memset(input, 0, sizeof(input));
            continue;

        }
        else if (z == 0) {
            break;
        }

    }

    return 0;
}
