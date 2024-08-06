#include <stdio.h>
#include "headers/hash.h"
#define MAX_HASH_TABLE_SIZE 100

DataItem *initialize_hashtable()
{
    DataItem *hash_table = malloc(sizeof(DataItem));
    if (hash_table == NULL)
    {
        printf("Memory allocation failed.");
    }
}

int hash(int key)
{
    // Quick implementation. Might use prime numbers further down the line.
    return key % MAX_HASH_TABLE_SIZE;
}

void insert(int key, int data)
{
    // Remember to check for collisions!
}

int search(int key);

void remove(int key);