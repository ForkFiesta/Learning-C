#include <stdio.h>

int main()
{
    int c;

    c = getchar(); // get first character from input
    while (c != EOF){ //start loop
        putchar(c); //print character
        c = getchar(); // get character
    }
}