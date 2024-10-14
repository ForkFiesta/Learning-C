#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *data;       // pointer to the array's data
    int size;        // number of items in the array
    int capacity;    // total capacity of the array
} Vector;

// Function Prototypes
Vector* create_vector(int initial_capacity);
int size(Vector *vector);
int capacity(Vector *vector);
bool is_empty(Vector *vector);
int at(Vector *vector, int index);
void push(Vector *vector, int item);
void insert(Vector *vector, int index, int item);
void prepend(Vector *vector, int item);
int pop(Vector *vector);
void delete(Vector *vector, int index);
void remove_item(Vector *vector, int item);
int find(Vector *vector, int item);
void resize(Vector *vector, int new_capacity);

// Create vector with initial capacity (power of 2, at least 16)
Vector* create_vector(int initial_capacity) {
    Vector *vector = malloc(sizeof(Vector));
    vector->size = 0;
    vector->capacity = (initial_capacity < 16) ? 16 : initial_capacity;
    vector->data = malloc(vector->capacity * sizeof(int));
    return vector;
}

int size(Vector *vector) {
    return vector->size;
}

int capacity(Vector *vector) {
    return vector->capacity;
}

bool is_empty(Vector *vector) {
    return vector->size == 0;
}

int at(Vector *vector, int index) {
    if (index < 0 || index >= vector->size) {
        fprintf(stderr, "Index out of bounds\n");
        exit(1);  // you might want to handle errors differently
    }
    return *(vector->data + index); // Pointer math to access the element
}

void push(Vector *vector, int item) {
    if (vector->size == vector->capacity) {
        resize(vector, vector->capacity * 2);
    }
    vector->data[vector->size++] = item;
}

void insert(Vector *vector, int index, int item) {
    if (index < 0 || index > vector->size) {
        fprintf(stderr, "Index out of bounds\n");
        exit(1);
    }
    if (vector->size == vector->capacity) {
        resize(vector, vector->capacity * 2);
    }
    for (int i = vector->size; i > index; i--) {
        vector->data[i] = vector->data[i - 1];
    }
    vector->data[index] = item;
    vector->size++;
}

void prepend(Vector *vector, int item) {
    insert(vector, 0, item);
}

int pop(Vector *vector) {
    if (is_empty(vector)) {
        fprintf(stderr, "Vector is empty\n");
        exit(1);
    }
    int item = vector->data[--vector->size];
    if (vector->size > 0 && vector->size == vector->capacity / 4) {
        resize(vector, vector->capacity / 2);
    }
    return item;
}

void delete(Vector *vector, int index) {
    if (index < 0 || index >= vector->size) {
        fprintf(stderr, "Index out of bounds\n");
        exit(1);
    }
    for (int i = index; i < vector->size - 1; i++) {
        vector->data[i] = vector->data[i + 1];
    }
    vector->size--;
    if (vector->size > 0 && vector->size == vector->capacity / 4) {
        resize(vector, vector->capacity / 2);
    }
}

void remove_item(Vector *vector, int item) {
    for (int i = 0; i < vector->size; i++) {
        if (vector->data[i] == item) {
            delete(vector, i);
            i--; // check the new item at this index
        }
    }
}

int find(Vector *vector, int item) {
    for (int i = 0; i < vector->size; i++) {
        if (vector->data[i] == item) {
            return i;
        }
    }
    return -1;
}

// Resize the underlying array (private function)
void resize(Vector *vector, int new_capacity) {
    vector->capacity = new_capacity;
    vector->data = realloc(vector->data, vector->capacity * sizeof(int));
}

int main() {
    Vector *vector = create_vector(16);

    // Example usage
    push(vector, 10);
    push(vector, 20);
    push(vector, 30);
    insert(vector, 1, 15);
    prepend(vector, 5);
    printf("Item at index 2: %d\n", at(vector, 2));
    printf("Pop: %d\n", pop(vector));
    printf("Find 20: %d\n", find(vector, 20));

    // Clean up
    free(vector->data);
    free(vector);

    return 0;
}
