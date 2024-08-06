#ifndef HASH
#define HASH

typedef struct
{
    int data;
    int key;
} DataItem;

int hash(int key);

void insert(int key, int data);

int search(int key);

void remove(int key);

#endif