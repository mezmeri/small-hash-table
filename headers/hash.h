
#define SIZE 100
#ifndef HASH
#define HASH

typedef struct
{
    int data;
    int key;
} DataItem;

typedef struct
{
    DataItem *itemArray[SIZE];
} HashTable;

HashTable *init_hashtable();

int hash(int key);

void insert(int key, int data, HashTable *table);

DataItem *search(int key, HashTable *table);

void remove_key(int key, HashTable *table);

#endif