#include <stdio.h>
#include "queues.h"
#include <stdbool.h>




//Function Declarations




int main(){


    Queue *newQueue = create_queue();

    for(int i = 0; i< 100; i++){

        add(newQueue, i);
    }

    for(int i = 0; i<50; i++){
        printf("Item removed: %d\n", remove_item(newQueue));
    }

    free(newQueue);

    return 0;
}