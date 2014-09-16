#include <stdio.h>

int main(void) {

    // declare one int since we want angles in integer
    int angle;
    printf("Submit an angle: ");
    scanf("%i", &angle);

    // angle should not be zero and less than 90
    if(angle > 0 && angle < 360 && angle < 90) {
        printf("Angle is pointy!\n");
    }
    // angle should not be zero and bigger than 90
    else if(angle > 0 && angle < 360 && angle > 90) {
        printf("Angle is blunt!\n");
    }
    // angle is zero
    else if(angle == 90) {
        printf("Angle is stright!\n");
    }
    else {
        printf("Not a valid angle.\n");
    }

    return 0;
        
}
