#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct LinkedList {
    Node* head;
    int size;
} LinkedList;






// 1. size() - returns the number of data elements in the list


int size(LinkedList* list) {
    return list->size;
}

// 2. empty() - returns true if empty
bool empty(LinkedList* list) {
    return list->size == 0;
}

// 3. value_at(index) - returns the value of the nth item (starting at 0 for first)
int value_at(LinkedList* list, int index) {
    if (index < 0 || index >= list->size) {
        printf("Index out of bounds.\n");
        return -1; // Or handle as appropriate
    }
    Node* current = list->head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->data;
}

// 4. push_front(value) - adds an item to the front of the list
void push_front(LinkedList* list, int value) {
    Node* new_node = malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = list->head;
    list->head = new_node;
    list->size++;
}

// 5. pop_front() - removes the front item and returns its value
int pop_front(LinkedList* list) {
    if (empty(list)) {
        printf("List is empty.\n");
        return -1;
    }
    Node* old_head = list->head;
    int value = old_head->data;
    list->head = old_head->next;
    free(old_head);
    list->size--;
    return value;
}

// 6. push_back(value) - adds an item at the end
void push_back(LinkedList* list, int value) {
    Node* new_node = malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = NULL;

    if (empty(list)) {
        list->head = new_node;
    } else {
        Node* current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
    list->size++;
}

// 7. pop_back() - removes end item and returns its value
int pop_back(LinkedList* list) {
    if (empty(list)) {
        printf("List is empty.\n");
        return -1;
    }
    Node* current = list->head;
    if (list->size == 1) {
        int value = current->data;
        free(current);
        list->head = NULL;
        list->size--;
        return value;
    }

    while (current->next->next != NULL) {
        current = current->next;
    }
    int value = current->next->data;
    free(current->next);
    current->next = NULL;
    list->size--;
    return value;
}

// 8. front() - get the value of the front item
int front(LinkedList* list) {
    if (empty(list)) {
        printf("List is empty.\n");
        return -1;
    }
    return list->head->data;
}

// 9. back() - get the value of the end item
int back(LinkedList* list) {
    if (empty(list)) {
        printf("List is empty.\n");
        return -1;
    }
    Node* current = list->head;
    while (current->next != NULL) {
        current = current->next;
    }
    return current->data;
}

// 10. insert(index, value) - insert value at index
void insert(LinkedList* list, int index, int value) {
    if (index < 0 || index > list->size) {
        printf("Index out of bounds.\n");
        return;
    }

    if (index == 0) {
        push_front(list, value);
        return;
    }

    Node* new_node = malloc(sizeof(Node));
    new_node->data = value;

    Node* current = list->head;
    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    }

    new_node->next = current->next;
    current->next = new_node;
    list->size++;
}

// 11. erase(index) - removes node at given index
void erase(LinkedList* list, int index) {
    if (index < 0 || index >= list->size) {
        printf("Index out of bounds.\n");
        return;
    }

    if (index == 0) {
        pop_front(list);
        return;
    }

    Node* current = list->head;
    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    }

    Node* temp = current->next;
    current->next = temp->next;
    free(temp);
    list->size--;
}

// 12. value_n_from_end(n) - returns the value of the node at the nth position from the end
int value_n_from_end(LinkedList* list, int n) {
    int index_from_start = list->size - n - 1;
    return value_at(list, index_from_start);
}

// 13. reverse() - reverses the list
void reverse(LinkedList* list) {
    Node* prev = NULL;
    Node* current = list->head;
    Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    list->head = prev;
}

// 14. remove_value(value) - removes the first item in the list with this value
void remove_value(LinkedList* list, int value) {
    if (empty(list)) return;

    if (list->head->data == value) {
        pop_front(list);
        return;
    }

    Node* current = list->head;
    while (current->next != NULL && current->next->data != value) {
        current = current->next;
    }

    if (current->next != NULL) {
        Node* temp = current->next;
        current->next = temp->next;
        free(temp);
        list->size--;
    }
}
