#include "HashTable.h"


size_t HashTable::Hash1 (int key)
{
    const double len_of_number = pow(10, 5);

    if (key / (int) len_of_number <= 9 && key / (int) len_of_number >= 0)
    {
        size_t hash = 0;

        for (int i = 0; i < 5; i++)
        {
            hash += key % 10;
            key = key / 10;
        }

        return hash;
    }

    return ERROR;
}


size_t HashTable::Hash2 (int key)
{
    return (size_t) key % TABLEHEIGHT;
}


void HashTable::Registrate (int key, HashTable* hash_table)
{
    size_t hash = hash_table->Hash2(key);

    Node *node = hash_table->list[hash].head;

    while (node != NULL)
    {
        if (strcmp((char*) Convert(key), node->data) == 0)
        {
            return;
        }

        node = node->next;
    }

    Node* new_node = new Node [1];
    new_node->data = (char*) Convert(key);

    new_node->prev = NULL;
    new_node->next = hash_table->list[hash].head;

    hash_table->list[hash].head = new_node;
    hash_table->list[hash].size++;
    hash_table->size++;
}


void* HashTable::Find (int key, HashTable* hash_table)
{
    size_t hash = hash_table->Hash2(key);

    Node* node = hash_table->list[hash].head;

    if (node == NULL)
    {
        printf("Error! The list is empty - nothing to find!\n");
        return NULL;
    }

    while (node != NULL)
    {
        if (strcmp((char*) Convert(key), node->data) == 0)
        {
            return node;
        }

        node = node->next;
    }

    printf("There is no such value.");
    return NULL;
}


void HashTable::Delete (int key, HashTable* hash_table)
{
    Node* node = (Node*) hash_table->Find(key, hash_table);

    size_t hash = hash_table->Hash2(key);

    if (node == NULL)
    {
        return;
    }

    Node* next = node->next;
    Node* prev = node->prev;

    if (prev == NULL && next == NULL)
    {
        delete node;
        node = NULL;

        hash_table->list[hash].head = NULL;
        hash_table->list[hash].size--;
        hash_table->size--;
    }
    else if (prev == NULL)
    {
        next->prev = NULL;
    }
    else if (next == NULL)
    {
        prev->next = NULL;
    }
    else
    {
        next->prev = prev;
        prev->next = next;
    }


    delete node;
    node = NULL;

    hash_table->list[hash].size--;
    hash_table->size--;
}


size_t NumGenerate ()
{
    size_t num = (rand() % 89999) + 10000;

    printf("%zu\n", num);

    return num;
}


void HashTable::DumpTo (HashTable* hash_table)
{
    FILE* gistagram = fopen("../Data/HashTableGistagram.csv", "w");

    for (int i = 0; i < TABLEHEIGHT; i++)
    {
        fprintf(gistagram, "%zu", hash_table->list[i].size);
        fprintf(gistagram, ";");
        fprintf(gistagram, "%d\n", i + 1);
    }

    fclose(gistagram);
}


void* Convert (int num)
{
    int size = 0;
    int tmp = num;
    while (tmp != 0)
    {
        tmp /= 10;
        size++;
    }

    char* string = new char [size + 1];
    string[size - 1] = '\0';

    for (int j = 0; j < size; j++)
    {
        string[j] = ((num % (int) (pow(10, (double)(size - j) ))) / (int) pow(10, (double)(size - j - 1))) + '0';
    }

    return string;
}