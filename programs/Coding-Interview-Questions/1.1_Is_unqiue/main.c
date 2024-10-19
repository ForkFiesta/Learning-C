#include <stdio.h>
#include <string.h>
#include <stdbool.h>


/* Is Unique: Implement an algorithm to determine if a string has all unique characters. What if you
cannot use additional data structures? */

bool check_if_unique(char* s){
    for (int i = 0; i<strlen(s); i++){
        for (int j=i+1; j<strlen(s); j++){
            if(s[i] == s[j]){
                return false;
            }
        }
    }
    return true;
}



int main(int argc, char* argv[]){

    char *s = argv[1];

    printf("The input of: %s", s);
    
    if(check_if_unique(s)){
        printf(", has all unique characters\n");
    }else {
        printf(", does Not have Unique characters\n");
    }

    return 0;


    
}