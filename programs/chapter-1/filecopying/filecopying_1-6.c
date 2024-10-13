#include <stdio.h>

int main()
{

    if ((getchar() != EOF) == 0){
        printf("My value is 0\n");
    }else if ((getchar() != EOF) == 1){
        printf("My value is 1\n");
    }
}