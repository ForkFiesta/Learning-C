#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Queue{
    int *data;
    int size;
    int capacity;
    int first;
    int last;

}Queue;


Queue* create_queue(int capacity);
void enqueue(Queue *queue, int item);
int dequeue(Queue *queue);
void check_address(void *ptr);
bool is_empty(Queue *queue);
bool is_full(Queue *queue);



Queue* create_queue(int capacity){
    Queue *queue = malloc(sizeof(Queue));
    check_address(queue);
    queue->size = 0;
    queue->capacity=capacity;
    queue->data = malloc(sizeof(int) * queue->capacity);
    check_address(queue->data);
    queue->first = 0;
    queue->last = -1;
    return queue;
}

void enqueue(Queue *queue, int item){
    if (is_full(queue)){
        fprintf(stderr, "Queue is full. Cannot enque new items.\n");
        return;
    }
    queue->last = (queue->last+1) % queue->capacity;
    queue->data[queue->last] = item;
    queue->size++;
}

int dequeue(Queue *queue) {
    if (is_empty(queue)) {
        fprintf(stderr, "Queue is empty. Cannot dequeue item.\n");
        exit(EXIT_FAILURE); // Exit to indicate error
    }
    int item = queue->data[queue->first];
    queue->first = (queue->first + 1) % queue->capacity;
    queue->size--;
    return item;
}



void check_address(void *ptr){
    if (ptr == NULL){
        fprintf(stderr, "Failed to allocate memory.\n");
        exit(EXIT_FAILURE);
    }
}

bool is_empty(Queue *queue){
    return (queue->size == 0);
}

bool is_full(Queue *queue){
    return (queue->size == queue->capacity);
}


int main() {
    Queue *queue = create_queue(5);

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);

    printf("Dequeued: %d\n", dequeue(queue));
    printf("Dequeued: %d\n", dequeue(queue));

    enqueue(queue, 60);
    enqueue(queue, 70);

    while (!is_empty(queue)) {
        printf("Dequeued: %d\n", dequeue(queue));
    }

    free(queue->data);
    free(queue);

    return 0;
}