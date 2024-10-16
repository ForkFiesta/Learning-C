#include "queues.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

Queue* create_queue(){
    Queue *queue = malloc(sizeof(Queue));
    queue->head= NULL;
    queue->tail=NULL;
    return queue;
}

void add(Queue *queue, int item){
    QueueNode *new_item = malloc(sizeof(QueueNode));
    check_address(new_item);
    new_item->data = item;
    new_item->next = queue->head;
    if (queue->tail != NULL){
        queue->tail->next = new_item;
    }
    queue->tail = new_item;
    if (queue->head == NULL){
        queue->head = new_item;
    }
}

int remove_item(Queue *queue){
    check_null(queue->head);
    QueueNode *old_node = queue->head;
    int data = old_node->data;

    queue->head = old_node->next;
    if (queue->head == NULL){
        queue->tail = NULL;
    }
    return data;
}

int peek(Queue *queue){
    check_null(queue->head);
    return queue->head->data;
}

bool is_empty(Queue *queue){
    return queue->head==NULL;
}


void check_null(void *ptr){
    if (ptr == NULL){
        printf("Error: No such element.\n");
        exit(EXIT_FAILURE);
    }
}

void check_address(void *ptr){
    if (ptr == NULL){
        fprintf(stderr, "Unable to allocate memory\n");
        exit(EXIT_FAILURE);
    }

}