#include <stdio.h>
#include "headers/hash.h"

int main()
{
    HashTable *table = init_hashtable();

    insert(1, 3, table);
    insert(2, 10, table);
    insert(3, 5, table);
    insert(4, 20, table);
    insert(5, 55, table);
    insert(6, 24, table);
    insert(7, 10, table);
    insert(8, 81, table);
    insert(9, 52, table);
    insert(10, 13, table);

    insert(2, 200, table);

    return 0;
}