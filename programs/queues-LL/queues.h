#ifndef QUEUES_H
#define QUEUES_H

#include <stdbool.h>

typedef struct QueueNode{
    int data;
    struct QueueNode *next;
}QueueNode;

typedef struct Queue{
    QueueNode *head;
    QueueNode *tail;
}Queue;

//Prototypes
Queue* create_queue();
void check_address(void *ptr);
void add(Queue *queue, int item);
int remove_item(Queue *queue);
void check_null(void *ptr);
int peek(Queue *queue);
bool is_empty(Queue *queue);



#endif