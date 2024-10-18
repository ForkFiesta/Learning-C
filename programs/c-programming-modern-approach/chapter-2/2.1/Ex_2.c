#include <stdio.h>


int main(void){

    float pi = 3.14;
    int radius = 10;
    float volume = 4/3*pi*(radius * radius * radius);
    printf("The volume of the sphere is %.2f", volume);
}