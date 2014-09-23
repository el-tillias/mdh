#include <stdio.h>
#include <string.h>

int main(void) {
    
    float avg = 0.0;
    int current, low, high, sum = 0;
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

            // calulate sum and average
            sum = sum + current;
            avg++;
        }

        if (low) {
            printf("Lowest value: %i\n", low);
        }
        if (high) {
            printf("Highest value: %i\n", high);
        }

        if ((high) && (low)) {
            printf("The sum off all values are: %i\n", sum);
            printf("Average of all values are: %.2f\n", sum/avg);
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
