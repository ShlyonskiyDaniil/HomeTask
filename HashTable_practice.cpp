#include "HashTable.h"


int main()
{
    srand(time(NULL));

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
}
