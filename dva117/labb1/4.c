#include <string.h>
#include <stdio.h>

int main(void){

    int number;
    char ans;

    struct morse {
        char zero[6];
        char one[6];
        char two[6];
        char three[6];
        char four[6];
        char five[6];
    };

    struct morse m;

    trcpy(m.zero, "-----");
    strcpy(m.one, ".----");
    strcpy(m.two, "..---");
    strcpy(m.three, "...--");
    strcpy(m.four, "....-");
    strcpy(m.five, ".....");

    

    while(1) {

        printf("\nSubmit a number and turn it into morse code: ");
        scanf("%i", &number);

        switch(number) {

            case 0:
                printf("\nMorse: %s", m.zero);
                break;
            case 1:
                printf("\nMorse: %s", m.one);
                break;
            case 2:
                printf("\nMorse: %s", m.two);
                break;
            case 3:
                printf("\nMorse: %s", m.three);
                break;
            case 4:
                printf("\nMorse: %s", m.four);
                break;
            case 5:
                printf("\nMorse: %s", m.five);
                break;
            default:
                printf("\nValid numbers are between 0-5");
                break;

        }

        printf("\nDo you want to try again(y/n)?: ");
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
