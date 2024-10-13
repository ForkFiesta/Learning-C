#include <stdio.h>

int main() {

    int c;
    while((c=getchar()) != EOF){
        if(c != ' '){
            putchar(c);
        }
        
    }

    return 0;  // Return 0 to indicate successful completion
}
