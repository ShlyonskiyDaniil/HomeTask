#include "HashTable.h"


int main()
{

    srand(time(NULL));

    // Hashtable with using Hash1 function.
    printf("Hashtable with using Hash1 function.\n");

    HashTable hash_table1(Hash1);

    for (int i = 0; i < 100; i++)
    {
        hash_table1.Registrate(NumGenerate());
    }

    for (int i = 0; i < TABLEHEIGHT; i++)
    {
        printf("%zu\n", hash_table1.list[i].size);
    }

    printf("%zu\n", hash_table1.size);

    hash_table1.DumpTo();

    // Hashtable with using Hash2 function.
    printf("\nHashtable with using Hash2 function.\n");
    HashTable hash_table2(Hash2);

    for (int i = 0; i < 100; i++)
    {
        hash_table2.Registrate(NumGenerate());
    }

    for (int i = 0; i < TABLEHEIGHT; i++)
    {
        printf("%zu\n", hash_table2.list[i].size);
    }

    printf("%zu\n", hash_table2.size);

    hash_table2.DumpTo();
}
