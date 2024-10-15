#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
    int value;
    struct Node *next;
} Node;

typedef struct LinkedList{
    Node *head;
    int size;
}LinkedList;


LinkedList* createList();
bool is_empty(LinkedList *list);
int size(LinkedList *list);
void push_front(LinkedList *list, int value);
int value_at(LinkedList *list, int index);
int pop_front(LinkedList *list);




LinkedList* create_list(){
    LinkedList* list = malloc(sizeof(LinkedList));
    if (list == NULL){
        exit(1); // Some error
    }
    list->head = NULL;
    list->size = 0;

    return list;
}

int size(LinkedList *list){
    return list->size;
}

bool is_empty(LinkedList *list){
    return list->size == 0;
}


void push_front(LinkedList *list, int item){
    Node *new_node = malloc(sizeof(Node));
    new_node->value = item;
    new_node->next = list->head;
    list->head = new_node;
    list->size++;
}

int value_at(LinkedList *list, int index){
    if (index < 0 || index >= list->size){
        fprintf(stderr, "Index out of bounds.\n");
        return -1;
    }

    Node* current = list->head;
    for (int i = 0; i<index; i++){
        current = current->next;
    }

    return current->value;
}

int pop_front(LinkedList *list){
    if(is_empty(list)){
        printf("List is empty.\n");
        return -1;
    }
    Node *old_head = list->head;
    int value = old_head->value;
    list->head = old_head->next;
    free(old_head);
    list->size--;
    return value;
    
}












int main()
{

    return 0;
}