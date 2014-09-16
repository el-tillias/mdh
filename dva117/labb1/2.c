#include <stdio.h>

int main(void) {

    // declare two ints since we expect no decimals
    int one, two;
    printf("Submit a number: ");

    // read the input and put the values in variables below
    scanf("%i", &one);
    printf("Submit another number: ");
    scanf("%i", &two);

    // calculating sum for the two numbers in one go, no need to declare a new variable.
    printf("\nSumma: %i\n", one + two);

    return 0;
        
}
