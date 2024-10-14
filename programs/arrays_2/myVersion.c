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
        fprtintf(stderr, "Error: cannot delete an item that is not within bounds of vector size\n");
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




















int main()
{
    return 0;
}