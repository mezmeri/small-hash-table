#include <stdio.h>
#include "headers/hash.h"
#define MAX_HASH_TABLE_SIZE 100

HashTable *init_hashtable()
{
    HashTable *table = (HashTable *)malloc(sizeof(HashTable));
    if (table == NULL)
    {
        printf("Init memory allocation failed.");
        return NULL;
    }
}

int hash(int key)
{
    // Quick implementation. Might use prime numbers further down the line.
    return key % MAX_HASH_TABLE_SIZE;
}

void insert(int key, int data, HashTable *table)
{
    // Remember to check for collisions!
}

int search(int key, HashTable *table);

void remove_key(int key, HashTable *table)
{
}