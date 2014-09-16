#include <stdio.h>
#define VAL 9.2f

float read(void) {
    float amount;
    printf("\nNumber of SEK that should be converted in to EUR: ");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Not a valid amount\n");
        return 0;
    }
    else {
        return amount;
    }

}


float convert(float sk) {
    return ((sk) / (VAL));

}


void print_res(float eur) {
    printf("\nValue in EUR: %f\n", eur);
}


int main(void) {
    float amount = read();
    if (amount != 0 ) {
        float res = convert(amount);
        print_res(res);
    }

    return 0;
}

