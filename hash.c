#include <stdio.h>
#include <stdlib.h>
#include "headers/hash.h"

#define MAX_HASH_TABLE_SIZE 15

HashTable *init_hashtable()
{
    HashTable *table = (HashTable *)malloc(sizeof(HashTable));
    if (table == NULL)
    {
        printf("Init memory allocation failed.");
        return NULL;
    }

    // This might be overkill idk
    for (unsigned int i = 0; i < MAX_HASH_TABLE_SIZE; i++)
    {
        table->itemArray[i] = NULL;
    }
}

int hash(int key)
{
    return key % MAX_HASH_TABLE_SIZE;
}

void insert(int key, int data, HashTable *table)
{
    int hashIndex = hash(key);

    DataItem *item = (DataItem *)malloc(sizeof(DataItem));
    if (item == NULL)
    {
        printf("Insert item memory allocation failed.");
        return;
    }
    else
    {
        item->key = key;
        item->data = data;
    }

    // Check to see if the key exists first (and if the slot is occcupied)
    if (table->itemArray[hashIndex] == NULL)
    {
        table->itemArray[hashIndex] = item;
    }
    else
    {
        // Begin probing the hash table
        while (table->itemArray[hashIndex] != NULL)
        {
            if (table->itemArray[hashIndex]->key == key && table->itemArray[hashIndex] != NULL)
            {
                free(item);
                table->itemArray[hashIndex]->data = data;
                break;
            }

            hashIndex = (hashIndex + 1) % MAX_HASH_TABLE_SIZE;

            if (table->itemArray[hashIndex] == NULL)
            {
                table->itemArray[hashIndex] = item;
                break;
            }
        }
    }
}

DataItem *search(int key, HashTable *table)
{
}

void remove_key(int key, HashTable *table)
{
}