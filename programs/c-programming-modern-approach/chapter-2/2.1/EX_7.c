#include <stdio.h>



int main(void){
    printf("Enter a dollar amount: ");
    int dollars;
    scanf("%d", &dollars);
    int bills_20 = dollars / 20;
    
    int bills_10 = (dollars % 20) / 10;

    int bills_5 = ((dollars % 20) % 10) /5;
    int bills_1= (((dollars % 20) % 10) % 5);

    printf("$20 bills: %d\n", bills_20);
    printf("$10 bills: %d\n", bills_10);
    printf(" $5 bills: %d\n", bills_5);
    printf(" $1 bills: %d\n", bills_1);

    
}