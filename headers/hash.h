#ifndef HASH
#define HASH

typedef struct
{
    int data;
    int key;
} DataItem;

typedef struct
{
    DataItem *item;
} HashTable;

int hash(int key);

void insert(int key, int data, HashTable *table);

int search(int key, HashTable *table);

void remove_key(int key);

#endif