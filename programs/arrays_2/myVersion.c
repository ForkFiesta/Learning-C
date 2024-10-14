#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Vector
{
    int *data;
    int size;
    int capacity;
    
} Vector;

Vector* create_vector(int initial_capacity);
int size(Vector *vector);
int capacity(Vector *vector);
bool is_empty(Vector *vector);
int at(Vector *vector, int index);
void checkIfResize(Vector *vector);
static void upsize(Vector *vector);
static void downsize(Vector *vector);
void push(Vector *vector, int item);
int pop(Vector *vector);
void insert(Vector *vector, int item, int index);
void prepend(Vector *vector, int item);
void delete(Vector *vector, int index);
int remove_item(Vector *vector, int item);
int find(Vector *vector, int item);



Vector* create_vector(int initial_capacity){
    Vector *vector = malloc(sizeof(Vector));
    vector->size = 0;
    vector->capacity = (initial_capacity < 16) ? 16: initial_capacity;
    vector->data = malloc(sizeof(int)*vector->capacity);
    if(vector->data == NULL){
        free(vector);
        exit(1);
    
    }
    return vector;
}

int size(Vector *vector){
    return vector->size;
}

int capacity(Vector *vector){
    return vector->capacity;
}

void checkIfResize(Vector *vector){
    if (vector->size < vector->capacity/4){
        downsize(vector); //returns 2 for downsize;
    }else if (vector->size == vector->capacity){
        upsize(vector);
    }else if( vector->size > vector->capacity){
        fprintf(stderr, "You've done something wrong. Vector size is already greater than its capacity\n");
    }
}

bool is_empty(Vector *vector){
    return (vector->size==0) ? true: false;
}

int at(Vector *vector, int index){
    if (index < 0 || index >= vector->size){
        fprintf(stderr, "Index out of bounds\n");
        free(vector);
        exit(1);
    }
    else{
        return *(vector->data+index); //returns the value that's why it's dereferenced
    }

}


static void upsize(Vector *vector){
    int new_capacity = vector->capacity * 2;

    int *new_data = malloc(sizeof(int)*new_capacity);

    if (new_data == NULL){
        free(new_data);
        free(vector);
        exit(1);
    }

    for (int i = 0; i<vector->size; i++){
        new_data[i] = vector->data[i];
    }

    free(vector->data);
    vector->data = new_data;
    vector->capacity = new_capacity;
}

static void downsize(Vector *vector){
    int new_capacity = vector->capacity/2;
    int *new_data = malloc(sizeof(int)*new_capacity);

    if (new_data == NULL){
        free(new_data);
        free(vector);
        exit(1);
    }

    for(int i = 0; i<vector->size; i++){
        new_data[i] = vector->data[i];
    }

    free(vector->data);

    vector->data = new_data;
    vector->capacity = new_capacity;
}

void push(Vector *vector, int item){
    
    vector->data[vector->size] = item;
    vector->size++;
    checkIfResize(vector);
}

int pop(Vector *vector){
    if (vector->size == 0){
        fprintf(stderr, "Error: Cannot pop from an empty vector.\n");
        free(vector);
        exit(1);
    }
    int item = vector->data[vector->size-1];
    vector->size--;
    checkIfResize(vector);
    return item;
}

void insert(Vector *vector, int item, int index){
   if (index < 0 || index > vector->size){
    fprintf(stderr, "Error: Index out of bounds\n");
   }

   for(int i = vector->size; i>index; i--){
    vector->data[i] = vector->data[i-1];
   }

   vector->data[index] = item;
   vector->size++;

   checkIfResize(vector);

}

void prepend(Vector *vector, int item){
    
    for (int i = vector->size; i>0; i--){
        vector->data[i] = vector->data[i-1];
    }

    vector->data[0] = item;
    vector->size++;
    checkIfResize(vector);
}

void delete(Vector *vector, int index)
{
    if (index < 0|| index >= vector->size){
        fprintf(stderr, "Error: cannot delete an item that is not within bounds of vector size\n");
        free(vector);
        exit(1);
    }
    for (int i = index; i< vector->size-1; i++){
        vector->data[i] = vector->data[i+1];
    }

    vector->size--;
    checkIfResize(vector);

}

int remove_item(Vector *vector, int item){
    int removed_count = 0;
    for (int i = 0; i<vector->size; i++){
        if (vector->data[i] == item){
            delete(vector, i);
            removed_count++;
            i--; //Decrement i to re-check the current index after deleting a value

        }
    }
    return removed_count;
}

int find(Vector *vector, int item){
    for (int i = 0; i<vector->size; i++){
        if (vector->data[i] == item){
            return i;
        }
    }
    return -1;
}




















int main() {
    // Create a new vector with initial capacity 16
    Vector *vector = create_vector(16);

    // Test: is_empty should be true initially
    printf("Is empty: %s\n", is_empty(vector) ? "true" : "false");

    // Test: push items and check size
    push(vector, 10);
    push(vector, 20);
    push(vector, 30);
    printf("After pushing 3 items, size: %d\n", size(vector));

    // Test: at function
    printf("Item at index 1: %d\n", at(vector, 1)); // Should print 20

    // Test: pop function
    int popped = pop(vector);
    printf("Popped item: %d\n", popped); // Should print 30
    printf("Size after pop: %d\n", size(vector)); // Should be 2

    // Test: insert function
    insert(vector, 15, 1);
    printf("Item at index 1 after inserting 15: %d\n", at(vector, 1)); // Should print 15

    // Test: prepend function
    prepend(vector, 5);
    printf("Item at index 0 after prepending 5: %d\n", at(vector, 0)); // Should print 5
    printf("Size after prepend: %d\n", size(vector)); // Should be 4

    // Test: delete function
    delete(vector, 1); // Should delete the item 10
    printf("Size after deleting item at index 1: %d\n", size(vector)); // Should be 3
    printf("Item now at index 1: %d\n", at(vector, 1)); // Should print 15

    // Test: remove_item function
    push(vector, 15); // Push another 15 to test remove_item
    int removed_count = remove_item(vector, 15);
    printf("Number of items removed: %d\n", removed_count); // Should print 2
    printf("Size after removing all 15s: %d\n", size(vector)); // Should be 2

    // Test: find function
    push(vector, 40);
    int index_of_40 = find(vector, 40);
    printf("Index of 40: %d\n", index_of_40); // Should print 2

    // Test: capacity and resizing
    printf("Initial capacity: %d\n", capacity(vector));
    for (int i = 0; i < 20; i++) {
        push(vector, i);
    }
    printf("Size after pushing 20 more items: %d\n", size(vector));
    printf("Capacity after pushing 20 more items: %d\n", capacity(vector));

    // Free vector
    free(vector->data);
    free(vector);

    return 0;
}

