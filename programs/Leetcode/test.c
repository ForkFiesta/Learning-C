#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int hash(const char *key, int table_size){
    unsigned long hash = 0;

    while(*key){
        hash = (hash << 5) + *key++;
    }
    return hash % 16;
}





int main(){
    printf("The hash is: %d for the word Raul in a table size of 16\n", hash("Raul", 16));



    return 0;
}