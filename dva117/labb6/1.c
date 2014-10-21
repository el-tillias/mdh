#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Since lab #5.1 and #6.1 is similar we define this with a 
// macro and therefore we can use the same code for both.
// The difference is dynamic memory, and the number of products it can handle.
#define TASK_NUM 5


struct buylist {
    char name[20];
    char unit[5];
    float numberof;
};


int check_alpha(char *s) {
    
    int i;

    for (i=0; i<strlen(s); i++) {
        if (isdigit(s[i]) != 0) { 
            return 2; 
        }
    }

    return 1;
}


void r_unit(struct buylist *u, int items) {

    while (1) {
        printf("Product unit: ");
        scanf("%s", (u+items)->unit);

        char *tocheck = (u+items)->unit;

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

void print_shoppinglist(struct buylist *p, int items) {

    int i;
    // this prints the first char in struct->name and everything in struct->unit.
    // should only print struct->name, and all of it!
    printf("Product    Amount        Unit\n");
    printf("-----------------------------\n");
    for(i=0; i <=items; i++){
        printf("%-10s%3g%15s\n", (p+i)->name, (p+i)->numberof, (p+i)->unit);
    }
}



void r_name(struct buylist *n, int items) {
    
    while (1) {
        printf("Product name: ");
        scanf("%s", (n+items)->name);

        char *tocheck = (n+items)->name;

        if (check_alpha(tocheck) == 2) {
            printf("Valid names of product is chars only (e.g. oranges). Try again.\n");
        }
        else {
            break;
        }
    }
    
}

void print_options(char *option) {

    printf("[e] Enter a new product, [p] Print the shopping list, [q] for quit: ");
    scanf(" %c", option);
}


int main(void) {

    int items=0;
    struct buylist *n;
    char option[2];
    n = (struct buylist *) malloc(sizeof(struct buylist));

    while (1) {

        n = (struct buylist *) realloc(n, (items+1) * sizeof(struct buylist));

        r_name(n, items);
        r_unit(n, items);
        r_numberof(n, items);

        while (1) {
            print_options(option);

            if (*option == 'e') {
                break;
            }
            else if (*option == 'p') {
                print_shoppinglist(n, items);
            }
            else if (*option == 'q') {
                return 0;
            }
            else {
                print_options(option);
            }
        }

        printf("Next item in shopping list..\n");
        items++;
    }

    free(n);
    return 0;

}
