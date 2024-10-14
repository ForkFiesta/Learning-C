### Self-guided walkthrough for creating a vector (mutable and reziable array in C)

1. Create a struct for the vector it must hold the following
   - pointer to data
   - size
   - capacity
2. Create function prototypes for the following:
   - size
     - returns the number of items in the vector
       -capacity
     - returns the capcity of the vector (number of items it can hold)
   - is

- `int at(Vector *vector, int index);`  
  Returns the item at a given index. Exits if the index is out of bounds.

- `void push(Vector *vector, int item);`  
  Adds an item to the end of the vector. Resizes if capacity is reached.

- `void insert(Vector *vector, int index, int item);`  
  Inserts an item at the specified index, shifting elements to the right.

- `void prepend(Vector *vector, int item);`  
  Inserts an item at the beginning of the vector. Uses `insert` with index 0.

- `int pop(Vector *vector);`  
  Removes and returns the last item from the vector. Resizes if necessary.

- `void delete(Vector *vector, int index);`  
  Removes an item at the specified index, shifting elements to the left.

- `void remove_item(Vector *vector, int item);`  
  Searches for the item and removes all occurrences from the vector.

- `int find(Vector *vector, int item);`  
  Finds and returns the index of the first occurrence of the item. Returns -1 if not found.

- `void resize(Vector *vector, int new_capacity);`  
  Resizes the vector to the specified new capacity. This is a private function used by other functions to manage capacity changes.
