#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define TABLE_SIZE 10

typedef struct Hash_Entry{
    char* key;
    char* value;
    struct Hash_Entry *next
}Hash_Entry;

typedef struct Hash_Table{
    Hash_Entry **table;
    int size;
}Hash_Table;


Hash_Table* create_hashtable(int size){
    Hash_Table *hashtable = malloc(sizeof(Hash_Table));
    check_address(hashtable);
    hashtable->table=malloc(sizeof(Hash_Entry)*size);
    hashtable->size = size;
    for (int i = 0; i<size; i++){
        hashtable->table[i]=NULL;
    }
    return hashtable;
}

int hash(const char *key, int table_size){
    unsigned long hash = 0;
    while(*key){
        hash = hash * 31 + *key++;
    }

    return hash % table_size;
}

void insert(Hash_Table *hashtable, const char *key, const char *value){
    int index = hash(key, hashtable->size);
    
    Hash_Entry *hashentry = get(hashtable, key);
    if (hashentry != NULL){
        free(hashentry->value);
        hashentry->value=strdup(value);
        return;
    }
    hashentry = malloc(sizeof(Hash_Entry));
    hashentry->key = strdup(key);
    hashentry->value = strdup(value);



}

char* delete(Hash_Table *hashtable, const char *key){
    int index = hash(key, hashtable->size);
    Hash_Entry *current = hashtable->table[index];
    Hash_Entry *prev = NULL;

    while(current != NULL){
        if (strcmp(current->key, key) == 0){
            if (prev == NULL){
                hashtable->table[index] = current->next;
            }else {
                prev->next = current->next;
            }
            free(current->key);
            free(current->value);
            free(current);
            printf("Item Deleted");
            return;
        }
        prev = current;
        current = current->next;
    }

}

Hash_Entry* get(Hash_Table *hashtable, const char *key){
    int index = hash(key, hashtable->size);
    Hash_Entry *hashentry = hashtable->table[index];
    
    while (hashentry){
        if (strcmp(hashentry->key, key) == 0){
            return hashentry;
        }

        hashentry = hashentry->next;
    }
    return NULL;
}



void check_address(void *ptr){
    if(ptr==NULL){
        printf("Failure to allocate memory.\n Exiting Program.\n");
        exit(EXIT_FAILURE);
    }
}