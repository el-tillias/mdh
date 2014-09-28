    

    /*
    *********************************************
    *       Programmet löser uppgift 6.1                   *
    *       DVA117 – Programmering                                        *
    *       Namn: Henrik Grankvist                                  *
    *       AnvdID: hgt10001                                                *
    *       Pnr: 901007-2198                                                *
    *                                                                                       *
    *       Beskrivning: Programmet låter                  *
    *       användaren skriva en inköpslista med  *
    *       valfritt antal artiklar och kan välja  *
    *       att avsluta programmet när som helst.  *
    *********************************************
    */
     
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
     
    struct product {
            char name[30];
            float amount;
            char unit[20];
    };
     
    void scanAndCheckIfAmountIsNumber(int counterInMain, struct product *pShoppingList) {
            _Bool isANumber;
            int number;
           
            while(1) {
                    isANumber = (scanf("%f", &(pShoppingList+counterInMain)->amount) == 1); //      Scanf är 1 om det man skrev in är en float(/int).
                    if (isANumber != 1) {
                            printf("-> Fel format p\x86 inmatning, f\x94rs\x94k igen! <-\n");
                            printf("Antal: ");
                            isANumber = 1;
                            fflush(stdin);
                    }
                    else {
                            break;
                    }
            }
    }
     
    void scanAndTestNameIfAlpha(int counterInMain, struct product *pShoppingList) {
            int i;
            int ifNotZeroTheLoopStops = 0;
           
            do {
                    printf("Namn p\x86 vara %d: ", counterInMain+1);
                    scanf("%s", &(pShoppingList+counterInMain)->name);
                   
                    int len = strlen((pShoppingList+counterInMain)->name);
                    char *saveTheStructAsString = (pShoppingList+counterInMain)->name;      //      Sparar namnet i en sträng.
                   
                    for (i = 0; i < len; i++) {
                            //if (isalpha(saveTheStructAsString[i]) == 0) { //      Kollar att det är en bokstav, dock fungerar inte detta med åäö.
                            if (isdigit(saveTheStructAsString[i]) != 0) {   //      Kollar om det inte är en siffra.
                                    printf("-> Fel format p\x86 inmatning, f\x94rs\x94k igen! <-\n");
                                    ifNotZeroTheLoopStops = 0;
                                    break;          //      Bryter ut ur for-loopen för att komma till do-while-loopen som ställer om frågan.
                            }
                            else {
                                    ifNotZeroTheLoopStops = 1;
                            }
                    }
            }
            while (!ifNotZeroTheLoopStops);         //      Fortsätter tills ifNotZero är något annat än 1, vilket den kommer att bli om allt var bokstäver.
    }
     
    void scanAndTestUnitIfAlpha(int counterInMain, struct product *pShoppingList) {
            int i;
            int ifNotZeroTheLoopStops = 0;
           
            do {
                    printf("Enhet: ", counterInMain+1);
                    scanf("%s", &(pShoppingList+counterInMain)->unit);
                   
                    int len = strlen((pShoppingList+counterInMain)->unit);
                    char *saveTheStructAsString = (pShoppingList+counterInMain)->unit;
                   
                    for (i = 0; i < len; i++) {
                            //if (isalpha(saveTheStructAsString[i]) == 0) { //      Kollar att det är en bokstav, dock fungerar inte detta med åäö.
                            if (isdigit(saveTheStructAsString[i]) != 0) {   //      Kollar om det inte är en siffra.
                                    printf("-> Fel format p\x86 inmatning, f\x94rs\x94k igen! <-\n");
                                    break;
                            }
                            else {
                                    ifNotZeroTheLoopStops = 1;
                            }
                    }
            }
            while (!ifNotZeroTheLoopStops);         //      Fortsätter tills ifNotZero är något annat än 1, vilket den kommer att bli om allt var bokstäver.
    }
     
    int enterMoreOrExit(void) {
            printf("\nTryck p\x86 [V] f\x94r att mata in en till vara eller [X] f\x94r att avsluta.");
            while (1) {     //      Tills den har fått ett giltigt svar.
                    char quitOrRerun = tolower(getch());
                    if (quitOrRerun == 'x') {       //      Stäng programmet.
                            printf(" ");
                            return 0;
                    }
                    else if (quitOrRerun == 'v') {  //      Skriv in en till produkt.
                            printf(" ");    //      Om inte denna finns så stängs programmet av.
                            printf("\n");
                            return 1;
                    }
            }
    }
     
    int enterMoreOrList(void) {
            printf("\nTryck p\x86 [V] f\x94r att mata in en till vara eller [L] f\x94r att skriva ut listan.\n");
            while (1) {     //      Tills den har fått ett giltigt svar.
                    char quitOrRerun = tolower(getch());
                    if (quitOrRerun == 'l') {       //      Lista varor
                            return 0;
                    }
                    else if (quitOrRerun == 'v') {  //      Skriv in en till produkt.
                            printf("\n");
                            return 1;
                    }
            }
    }
     
    int main(void) {
            int j=0,i;
            struct product *pShoppingList;
            pShoppingList = (struct product *) malloc(sizeof(struct product));              //      Måste fixa så att den här ändrar till en större storlek när fler saker skrivs in.
           
            do {
                do {
                    pShoppingList = (struct product *) realloc(pShoppingList, (j+1) * sizeof(struct product));
                    scanAndTestNameIfAlpha(j, pShoppingList);
                   
                            printf("Antal: ");
                    scanAndCheckIfAmountIsNumber(j, pShoppingList);
                   
                    scanAndTestUnitIfAlpha(j, pShoppingList);
                    j++;    //      Räkna antalet produkter.
                } while (enterMoreOrList());
                    printf("\n\nInk\x94pslistan:\n");
                    printf("%s\t%s\t%s\n", "Namn", "Antal", "Enhet");
                   
                    for(i=0; i < j; i++){
                            printf("%s\t%g\t%s\n", (pShoppingList+i)->name, (pShoppingList+i)->amount, (pShoppingList+i)->unit);
                    }
            } while (enterMoreOrExit());
           
            free(pShoppingList);    //      Avallokera minnet.
            return 0;
    }


