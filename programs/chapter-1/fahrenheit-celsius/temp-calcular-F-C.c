#include <stdio.h>


int main()
{
    int fahr;
    int cels;

    printf("celsius\tfahr\n");
    for (cels = -200; cels<=200; cels+= 20)
    {
        printf("%d %6.1f\n", cels, cels+32*(9.0/5));
    }


}