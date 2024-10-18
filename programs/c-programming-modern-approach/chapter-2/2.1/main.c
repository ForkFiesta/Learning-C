#include <stdio.h>

#define INCHES_PER_POUND 166

int main(void){
    int width;
    int height;
    int length;
    // printf("To C, or not to C: that is the question.\n");
    printf("Enter the width of the box (int).: ");
    scanf("%d", &width);
    printf("\nEnter the height of the box (int).: ");
    scanf("%d", &height);
    printf("\nEnter the length of the box (int).: ");
    scanf("%d", &length);


    int volume = length * width * height;
    int weight = (volume + INCHES_PER_POUND - 1) / INCHES_PER_POUND;

    printf("\nThe volume of the box is %d\nThe weight of the box is %d\n", volume, weight);

    
    return 0;
}