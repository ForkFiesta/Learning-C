#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int capacity;
    int size;
} Vector;


//Prototypes
Vector* create_vector(int initial_capacity);
int initialize_capacity(int initial_capacity);
int size(Vector *vector);
int capacity(Vector *vector);
void check_if_resize(Vector *vector);
static void downsize(Vector *vector);
static void upsize(Vector *vector);
void push(Vector *vector, int item);
int pop(Vector *vector);
bool is_empty(Vector *vector);
int at(Vector *vector, int index);
void insert(Vector *vector, int index, int item);
void prepend(Vector *vector, int item);
int delete(Vector *vector, int index);
int remove_item(Vector *vector, int item);
int find(Vector *vector, int item);


//functions
Vector* create_vector(int initial_capacity){
    Vector *vector = malloc(sizeof(Vector));
    if (vector == NULL){
        fprintf(stderr, "Error: Failed to allocate memory for vector\n");
        exit(1);
    }
    vector->size = 0;
    vector->capacity = initialize_capacity(initial_capacity);
    vector->data = malloc(sizeof(int) * vector->capacity);

    return vector;
}

int initialize_capacity(int initial_capacity){
    initial_capacity < 16 ? initial_capacity=16 : initial_capacity;
    return initial_capacity;
}

bool is_empty(Vector *vector){
    return vector->size == 0;
}

int size(Vector *vector){
    return vector->size;
}

int capacity(Vector *vector){
    return vector->capacity;
}

void check_if_resize(Vector *vector){
    if (vector->size < vector->capacity / 4 && vector->capacity > 16){ // does not get smaller than 16
        downsize(vector);
    }
    else if(vector->size==vector->capacity){
        upsize(vector);
    }else if (vector->size > vector->capacity){
        fprintf(stderr, "Failure: Vector Size is greater than it's capacity\n");
        exit(1);
    }
}

static void downsize(Vector *vector){
    int new_capacity = vector->capacity / 2;
    int *new_data = malloc(sizeof(int)*new_capacity);
    if (new_data == NULL){
        fprintf(stderr, "Failure: Program was not able to allocate memory for new smaller array\n");
        exit(1);
    }

    for (int i = 0; i < vector->size; i++){
        new_data[i] = vector->data[i];
    }
    free(vector->data);
    vector->data = new_data;
    vector->capacity = new_capacity;

}

static void upsize(Vector *vector){ //works correctly
    int new_capacity = vector->capacity * 2;
    int *new_data = malloc(sizeof(int)*new_capacity);
    if (new_data == NULL){
        fprintf(stderr, "Failure: Program was not able to allocate memory for new larger array\n");
        exit(1);
    }

    for (int i = 0; i < vector->size; i++){
        new_data[i] = vector->data[i];
    }
    free(vector->data);
    vector->data = new_data;
    vector->capacity = new_capacity;
}

void push(Vector *vector, int item){ //works correctly
    vector->data[vector->size] = item;
    vector->size++;
    check_if_resize(vector);
}

int pop(Vector *vector){ //Works correctly
    if(vector->size == 0){
        printf("Cannot pop from vector of size 0");
        exit(1);
    }
    int removed_item = vector->data[vector->size-1];
    vector->size--;
    check_if_resize(vector);
    return removed_item;

}
int at(Vector *vector, int index){ // works correctly
    if (is_empty(vector)){
        fprintf(stderr, "Cannot index empty vector\n");
        exit(1);
    }else if (index < 0 || index >= vector->size){
        fprintf(stderr,"Cannot index outside of Vector size\n");
        exit(1);
    }

    return vector->data[index];
}

void insert(Vector *vector, int index, int item){ //works correctly
    if(index < 0 || index > vector->size){
        fprintf(stderr, "Error: cannot index outside of vector size\n");
        exit(1);
    }

    for (int i = vector->size; i>index; i--){
        vector->data[i] = vector->data[i-1];
    }
    vector->data[index]=item;
    vector->size++;
    check_if_resize(vector);
}

void prepend(Vector *vector, int item){
    if(is_empty(vector)){
        push(vector, item);
    }
    insert(vector, 0, item);
}



int delete(Vector *vector, int index){
    if (is_empty(vector)){
        fprintf(stderr, "Error: Cannot delete item for empty vector");
        exit(1);
    }

    if (index < 0 || index > vector->size){
        fprintf(stderr, "Error: cannot delete item from index out of range for vector");
    }

    int deleted_item = vector->data[index];

    for (int i=index; i < vector->size-1; i++){
        vector->data[i] = vector->data[i+1];
    }

    vector->size--;
    check_if_resize(vector);
    return deleted_item;
}



int remove_item(Vector *vector, int item){
    int counter = 0;

    for (int i = 0; i<vector->size; i++){
        if (vector->data[i]==item){
            counter++;
            delete(vector, i);
            i--;
        }
    }
    return counter;
}

int find (Vector *vector, int item){
    if (is_empty(vector)){
        fprintf(stderr, "cannot index empty vector\n");
    }

    for (int i=0; i<vector->size; i++){
        if (vector->data[i]==item){
            return i;
        }
    }

    return -1;
}














int main(void){
    Vector *myVector = create_vector(16);
    printf("Bool is currently empty %d\n", is_empty(myVector)); // should print 1
    push(myVector, 2);
    push(myVector, 8);
    push(myVector, 12);
    push(myVector, 85);
    push(myVector, 8);
    insert(myVector, 3, 8);
    int find8 = find(myVector, 8);
    printf("Item 8 found at index: %d\n", find8); //should be found at index 1
    int nums_removed = remove_item(myVector, 8);
    printf("8 was removed %d times.\n", nums_removed); //should print 3 times


    // int index = at(myVector, 0); 
    // printf("Item at Index 0 is: %d\n", index); //should print 2
    // prepend(myVector, 92);
    // index = at(myVector, 0);
    // printf("Item at Index 0 is: %d\n", index); //should print 92
    // // pop(myVector);
    // int tempSize = size(myVector);
    // int tempCapacity = capacity(myVector);
    // index = at(myVector, 1);
    // printf("Item at Index 1 is: %d\n", index); //should print 2


    // tempSize = size(myVector);
    // tempCapacity = capacity(myVector);
    // printf("Current Size: %d\n", tempSize); // Should print 2
    // printf("Current Capacity: %d\n", tempCapacity); // should print 16


    // for (int i = 0; i<16; i++){
    //     push(myVector, i);
    // }
    // tempSize = size(myVector);
    // tempCapacity = capacity(myVector);
    // printf("Current Size: %d\n", tempSize); // should print 18
    // printf("Current Capcacity: %d\n", tempCapacity); // should print 32

    // for(int i = 0; i<11; i++){
    //     pop(myVector);
    // }

    // tempSize = size(myVector);
    // tempCapacity = capacity(myVector);
    // printf("Current Size: %d\n", tempSize); // should print 7
    // printf("Current Capcacity: %d\n", tempCapacity); // should print 16



    return 0;
}