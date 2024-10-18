#include <stdio.h>
#include <string.h>


int main(void){




    int temp = 12345;
    char* string1 = temp;

    
    int number = temp;
    int counter = 0;
    while(temp > 0){
        temp /= 10;
        counter++;
    }

    int myArray[counter];

    int temp_counter = counter-1;

    while(number>0){
        int digit = number % 10;
        myArray[temp_counter] = digit;
        number /= 10;
        temp_counter--;

    }


    for(int i = 0; i< counter; i++){
        int largest = 0;
        int largest_index;
        for (int j = i+1; j< counter; j++){
            
            if (myArray[j]>largest){
                largest = myArray[j];
                largest_index = j;
            }

            

        }
        if(largest>myArray[i]){
                int temp_swap = largest;
                myArray[largest_index] = myArray[i];
                myArray[i] = temp_swap;
                break;
            }
    }

    int final_number = 0;

    for (int i = 0; i< counter; i++){
        final_number = final_number * 10 + myArray[i];
    }

    printf("%d\n", final_number);






}