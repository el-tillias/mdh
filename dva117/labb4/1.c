#include <stdio.h>
#include <stdlib.h>



void swap(int *a, int *b) 
{
    int temp;
         
    temp = *b; 
    *b   = *a; 
    *a   = temp;   
}


void sort(int *a, int *b, int *c) {

    while(1) {
        if (*a >= *b && *b >= *c) { 
            break;
        }
        else {
            if (*a < *b) {
                swap(a, b);
            }
            if (*b < *c) {
                swap(b, c);
            }
            continue;
        }
    }   
}


int main(void) {

    int x,y;
    int n,m,o;

    printf("Submit two integers seperated by space: ");
    scanf("%d %d", &x, &y);

    swap(&x, &y);

    printf("Submit three integers to sort separated by space: ");
    scanf("%d %d %d", &m, &n, &o);

    sort(&m, &n, &o);
    printf("Swapped: %d %d\n", x, y);
    printf("Sorted: %d %d %d\n", m, n, o);
 
    return 0;
}
