#include <stdio.h>

int main() {

    int input[] = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int size = 10;
    int counter = 1;






    //left only shifts when a new element is detected
    for(int *leftPtr=&input[1], *rightPtr = &input[1]; rightPtr<&input[size]; rightPtr++){
        if(*rightPtr != *(rightPtr-1)){
            *leftPtr = *rightPtr;
            leftPtr++;
            counter++;
        }

    }
    
    printf("[");
    for(int i = 0; i<size; i++){
        printf("%d, ", input[i]);
    }
    printf("]");



    return 0;
}
