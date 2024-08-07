#include <stdio.h>
#include "headers/hash.h"

int main()
{
    HashTable *table = init_hashtable();

    printf("%d", sizeof(HashTable));

    return 0;
}