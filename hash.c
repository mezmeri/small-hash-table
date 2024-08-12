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
        // Probe the array until an available slot is found
        while (table->itemArray[hashIndex] != NULL)
        {
            // If the element exists, update the data and keep the key
            if (table->itemArray[hashIndex]->key == key && table->itemArray[hashIndex] != NULL)
            {
                free(item);
                table->itemArray[hashIndex]->data = data;
                break;
            }

            hashIndex = (hashIndex + 1) % MAX_HASH_TABLE_SIZE;

            if (table->itemArray[hashIndex]->isTombstone == true)
            {
                table->itemArray[hashIndex] = item;
            }

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
    int hashIndex = hash(key);

    // Check for NULL-entry
    if (table->itemArray[hashIndex] == NULL)
    {
        printf("NULL ENTRY. Entry not found.");
        return NULL;
    }

    if (table->itemArray[hashIndex]->key == key)
    {
        return table->itemArray[hashIndex];
    }
    else
    {
        while (table->itemArray[hashIndex]->key != key)
        {
            int startingIndex = hashIndex;
            hashIndex = (hashIndex + 1) % MAX_HASH_TABLE_SIZE;
            if (table->itemArray[hashIndex] == NULL)
            {
                printf("NULL ENTRY. Entry not found.");
                return NULL;
            }

            if (hashIndex == startingIndex)
            {
                break;
            }

            if (table->itemArray[hashIndex]->key == key)
            {
                return table->itemArray[hashIndex];
            }
        }

        return NULL;
    }
}

void remove_key(int key, HashTable *table)
{
    int hashIndex = hash(key);
    if (table->itemArray[hashIndex] == NULL)
    {
        printf("NULL ENTRY. Entry not found.");
        return NULL;
    }

    if (table->itemArray[hashIndex]->key == key)
    {
        table->itemArray[hashIndex]->isTombstone = true;
    }
}