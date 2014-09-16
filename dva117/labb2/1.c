#include <stdio.h>
#include <string.h>

int main(void) {
    
    float avg;
    int current, low, high;
    char ans;
    
    while(1) {

        while(1) {

            printf("Submit a value: ");
            scanf("%i", &current);

            if (current < 0) {
                break;
            }

            else if (!(low) && !(high)) {
                low = current;
                high = current;
            }

            else {
                if ((current > high) && !(current < 0)) {
                    // new highest value detected
                    printf("New high value detected\n");
                    high = current;
                }
                if  ((current < low) && !(current < 0)) {
                    // new lowest value detected
                    printf("New low value detected\n");
                    low = current;
                }
            }
        }

        if (low) {
            printf("Lowest value: %i\n", low);
        }
        if (high) {
            printf("Highest value: %i\n", high);
        }

        if ((high) && (low)) {
            printf("The sum off highest and lowest value are: %i\n", (high+low));
            avg = ((high+low)/2.0);
            printf("Average of lowest and highest value is: %f\n", avg);
        }


        printf("Do you want to try again(y/n)?: ");
        // note the space before %c, start reading the first non space character
        scanf(" %c",&ans);

        if (ans == 'y') {
            continue;
        }
        else {
            break;
        }
    }

    return 0;
}
