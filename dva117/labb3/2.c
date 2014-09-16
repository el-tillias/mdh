#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void write(int no) {

    int i;
    char one[1][6];
    char two[1][6];
    char three[3][6];
    char four[2][6];
    char five[3][6];
    char six[3][6];

    strcpy(one[0], "  *  ");
    strcpy(two[0], "*   *");
    strcpy(three[0], "*   ");
    strcpy(three[1], "  *");
    strcpy(three[2], "    *");
    strcpy(four[0], "*   *");
    strcpy(four[1], "*   *");
    strcpy(five[0], "*   *");
    strcpy(five[1], "  * ");
    strcpy(five[2], "*   *");
    strcpy(six[0], "*   *");
    strcpy(six[1], "*   *");
    strcpy(six[2], "*   *");

    if (no == 1) {
        printf("%s\n", one[0]);
        printf("----------\n");
    }

    if (no == 2) {
        printf("%s\n", two[0]);
        printf("----------\n");
    }

    if (no == 3) {
        for(i=0; i<3; i++) {
            printf("%s\n", three[i]);
        }
        printf("----------\n");
    }

    if (no == 4) {
        for(i=0; i<2; i++) {
            printf("%s\n\n", four[i]);
        }
        printf("----------\n");
    }

    if (no == 5) {
        for(i=0; i<3; i++) {
            printf("%s\n", five[i]);
        }
        printf("----------\n");
    }

    if (no == 6) {
        for(i=0; i<3; i++) {
            printf("%s\n", six[i]);
        }
        printf("----------\n");
    }

}


int count(int *n) {

    int i, sum=0;

    for (i=0; i<6; i++) {
        sum += n[i];
    }

    return sum;

}

void count_pairs(int *ans) {

    int oc1=0, oc2=0, oc3=0, oc4=0, oc5=0, oc6=0;
    int val, pairs=0;

    for (val=0; val<6; val++) {
        if (ans[val] == 1) {
            oc1++;
        }
        else if (ans[val] == 2) {
            oc2++;
        }
        else if (ans[val] == 3) {
            oc3++;
        }
        else if (ans[val] == 4) {
            oc4++;
        }
        else if (ans[val] == 5) {
            oc5++;
        }
        else if (ans[val] == 6) {
            oc6++;
        }

    }


    if (oc1 % 2 == 0) {
        pairs+=(oc1/2);
    }

    if (oc2 % 2 == 0) {
        pairs+=(oc2/2);
    }

    if (oc3 % 2 == 0) {
        pairs+=(oc3/2);
    }

    if (oc4 % 2 == 0) {
        pairs+=(oc4/2);
    }

    if (oc5 % 2 == 0) {
        pairs+=(oc5/2);
    }

    if (oc6 % 2 == 0) {
        pairs+=(oc6/2);
    }

    // debug
    //printf("ones: %i, twos: %i, threes: %i, fours: %i, fives: %i, sixes: %i\n", oc1, oc2, oc3, oc4, oc5, oc6);
    printf("Pairs: %i\n", pairs);

}


int read_input(void) {

    char c;
    int i;
    printf("If you want to roll again press space, else quit with 'q': ");

    while ((c = getchar())){
        if (c == ' ') {
            i=1;
            break;
        }
        else if (c == 'q') {
            i=0;
            break;
        }
    }
    return i;
}

int main(void) {

    time_t t;
    int val, ans[7], sumof, ret;
    srand((int) time(&t));

    while (1) {    
        for (val=0; val<6; val++) {
            ans[val] = (rand() % 6 + 1);
            write(ans[val]);
        }

        count_pairs(ans); 
        sumof = count(ans);
        printf("Sum of all dices: %i\n", sumof);
        ret = read_input();
    
        if (ret == 1) {
            continue;
        }
        else {
            break;
        }
    }
    return 0;
}
