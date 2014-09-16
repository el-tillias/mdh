#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int again(void) {

    char again;

    while(1) {

        printf("Play again? (y/n): ");
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


int game(void) {

    time_t t;
    int val, ans;
    srand((int) time(&t));
    ans = (rand() % 100);

    while (1) {

        printf("%i", ans);
        printf("\nGuess a number between 1 and 100: ");
        scanf("%i", &val);

        if (ans > val) {
            printf("\nYou are guessing too low, try again.");
        }
        else if(ans < val) {
            printf("\nYou are guessing too high, try again.");
        }
        else {
            printf("\nCorrect answer!\n");
            break;
        }

    }
    return 0;
}   

int main(void) {

    while(1) {
        game();
        int answ = again();
    
        if (answ == 1 ) {
            continue;
        }
        else {
            break;
        }
    }

    return 0;

}
