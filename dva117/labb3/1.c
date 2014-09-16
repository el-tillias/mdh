#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void gen(int *shogun) {

    time_t t;
    int i;
    srand((int) time(&t));

    for (i=0; i < 10; i++) {
        shogun[i] = (rand() % 10);
        printf("Generated number: %i\n", shogun[i]);
    }

}


int count(int ask, int *shogun) {

    int i, counter = 0;
    for (i=0; i<10; i++) {
        if (ask == shogun[i]) {
            counter++;
        }
    }    
    return counter;
}


int main(void) {
    int values[10], ask;
    gen(values);

    printf("Which value should we search for?: ");
    scanf("%i", &ask);
    
    int res = count(ask,values);
    printf("Number of occurences: %i\n", res);

    return 0;
}
