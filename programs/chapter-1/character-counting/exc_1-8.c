#include <stdio.h>

int main() {
    int c;
    int counter = 0;  // Initialize counter

    for (; (c = getchar()) != EOF; ) {  // No need to reinitialize counter here
        if (c == ' ' || c == '\t' || c == '\n') {
            counter++;
        }
    }

    printf("Count: %d\n", counter);  // Print the counter value
    return 0;  // Return 0 to indicate successful completion
}
