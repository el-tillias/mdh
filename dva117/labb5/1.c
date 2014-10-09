#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Since lab #5.1 and #6.1 is similar we define this with a 
// macro and therefore we can use the same code for both.
// The difference is dynamic memory, and the number of products it can handle.
#define TASK_NUM 5


struct buylist {
    char name;
    char unit;
    float numberof;
};


int check_alpha(char *s) {
    
    int i;

    for (i=0; i<strlen(s); i++) {
        if (isdigit(s[i]) != 0) { return 2; }
    }

    return 1;
}


void r_unit(struct buylist *u, int items) {

    while (1) {
        printf("Product unit: ");
        scanf("%s", &(u+items)->unit);

        char *tocheck = &(u+items)->unit;

        if (check_alpha(tocheck) == 2) {
            printf("Valid units is chars only (e.g. kg, hg). Try again.\n");
        }
        else { 
            break; 
        }
    }
     
}

void r_numberof(struct buylist *no, int items) {

    while (1) {    
        printf("Amount: ");

        if (scanf("%f", &(no+items)->numberof) != 1) {
            printf("Valid amout is digit only (e.g. 1, 1.5). Try again.\n");
        }
        else {
            break;
        }
    }
}



void r_name(struct buylist *n, int items) {
    
    while (1) {
        printf("Product name: ");
        scanf("%s", &(n+items)->name);

        char *tocheck = &(n+items)->name;

        if (check_alpha(tocheck) == 2) {
            printf("Valid names of product is chars only (e.g. oranges). Try again.\n");
        }
        else {
            break;
        }
    }
    
}


int main(void) {

    int items=0;
    struct buylist n[20];

    while (1) {

        if (items > 4) {
            printf("Maximum number of products reached, printing shopping list and exiting..\n\n");
            break;
        }

        r_name(n, items);
        r_unit(n, items);
        r_numberof(n, items);
        printf("Next item in shopping list..\n");
        items++;
    }

    return 0;

}
