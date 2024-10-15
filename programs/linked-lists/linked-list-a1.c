#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct Node{
    int data;
    struct Node *next;
}Node;

typedef struct LinkedList{
    Node *head;
    int size;
}LinkedList;




LinkedList* create_list();
int size(LinkedList *list);
bool empty(LinkedList *list);
int value_at(LinkedList *list, int index);
void push_front(LinkedList *list, int value);
int pop_front(LinkedList *list);
void push_back(LinkedList *list, int value);
int pop_back(LinkedList *list);
int front(LinkedList *list);
int back(LinkedList *list);
void insert (LinkedList *list, int index, int value);
void erase(LinkedList *list, int index);
int value_n_from_end(LinkedList *list, int n);
void reverse(LinkedList *list);
void remove_value(LinkedList *list, int value);   



LinkedList* create_list(){
    LinkedList *list = malloc(sizeof(LinkedList));
    list->head = NULL;
    list->size = 0;
    return list;
}

int size(LinkedList *list){
    return list->size;
}

bool empty(LinkedList *list){
    return list->size==0;
}

int value_at(LinkedList *list, int index){
    if(empty(list) || index < 0 || index>= list->size){
        return -1;
    }
    Node *current = list->head;
    for(int i = 0; i < index; i++){
        current = current->next;
    }
    return current->data;
}


void push_front(LinkedList *list, int value){
    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL){
        return;
    }

    new_node->data=value;
    new_node->next=list->head;
    list->head = new_node;
    list->size++;
}

int pop_front(LinkedList *list){
    if(empty(list)){
        return -1;
    }
    Node *old_head = list->head;
    list->head = old_head->next;
    int removed_value = old_head->data;
    free(old_head);
    list->size--;
    return removed_value;
}

void push_back(LinkedList *list, int value){
    if(empty(list)){
        push_front(list, value);
        return;
    }
    Node *new_node = malloc(sizeof(Node));
    if(new_node == NULL){
        return;
    }
    new_node->data=value;
    new_node->next=NULL;

    Node *current = list->head;

    while(current->next!=NULL){ //gets to last item
        current = current->next;
    }
    current->next = new_node;
    list->size++;

}

int pop_back(LinkedList *list){
    if(empty(list)){
        return -1;
    }else if(list->size==1){
       return pop_front(list);
    }

    Node *current = list->head;
    while(current->next->next != NULL){
        current = current->next; 
    } // pointing n-1 index

    Node *old_node = current->next;
    int return_value = old_node->data;
    current->next = NULL;
    free(old_node);
    list->size--;
    return return_value;
}

int front(LinkedList *list){
    if(empty(list)){
        return -1;
    }
    return list->head->data;
}

int back(LinkedList *list){
    if(empty(list)){
        return -1;
    }
    Node *current = list->head;
    while(current->next!=NULL){
        current = current->next;
    }
    return current->data;
}

void insert (LinkedList *list, int index, int value){
    if(index < 0 || index> list->size){
        return;
    }

    if (index == 0){
        push_front(list, value);
        return;
    }

    Node *new_node = malloc(sizeof(Node));
    new_node->data = value;
    if(new_node == NULL){
        return;
    }
    Node *current = list->head;
    for(int i = 0; i<index-1; i++){
        current = current->next;
    }
    new_node->next = current->next;
    current->next = new_node;
    list->size++;
}

void erase(LinkedList *list, int index){
    if(empty(list)){
        return;
    }else if(index<0 || index>=list->size){
        return;
    }

    Node *current = list->head;
    for(int i = 0; i<index-1; i++){
        current = current->next;
    }
    Node *removed_node = current->next;
    current->next=removed_node->next;
    free(removed_node);
    list->size--;
}

int value_n_from_end(LinkedList *list, int n){

    if(empty(list)){
        return -1;
    }else if(n>=list->size){
        return -1;
    }

    int index = list->size - n - 1;
    return value_at(list, index);

}

void reverse(LinkedList *list){
    if(empty(list) || list->size==1){
        return;
    }

    Node *next = NULL;
    Node *prev = NULL;
    Node *current = list->head;
    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;

    }
    list->head = prev;
}

void remove_value(LinkedList *list, int value){
    if(empty(list)){
        return;
    }else if(list->size == 1){
        if(list->head->data==value){
            pop_front(list);
            return;
        }
    }
    Node *current = list->head;
    while(current->next != NULL && current->next->data != value){
        current = current->next;
    }

    if(current->next != NULL){
        Node *removed_value = current->next;
        current->next= removed_value->next;
        free(removed_value);
        list->size--;

    }
}    




int main() {
    LinkedList* list = create_list();

    push_front(list, 10);
    push_back(list, 20);
    insert(list, 1, 15);

    printf("Front element: %d\n", front(list));
    printf("Back element: %d\n", back(list));
    printf("Value at index 1: %d\n", value_at(list, 1));
    printf("List size: %d\n", size(list));

    reverse(list);
    printf("Front element after reversing: %d\n", front(list));

    return 0;
}
