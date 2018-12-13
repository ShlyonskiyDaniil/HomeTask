#include "HashTable.h"


size_t Hash1 (int key)
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

void HashTable::Registrate (int key)
{
    size_t hash = this->Hash(key);

    Node *node = list[hash].head;

    char* number = (char*) Convert(key);

    while (node != NULL)
    {
        if (strcmp(number, node->data) == 0)
        {
            return;
        }

        node = node->next;
    }

    Node* new_node = new Node [1];
    new_node->data = number;

    new_node->prev = NULL;
    new_node->next = list[hash].head;

    list[hash].head = new_node;
    list[hash].size++;
    size++;
}


void* HashTable::Find (int key)
{
    size_t hash = this->Hash(key);

    Node* node = this->list[hash].head;

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


void HashTable::Delete (int key)
{
    Node* node = (Node*) this->Find(key);

    size_t hash = this->Hash(key);

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

        this->list[hash].head = NULL;
        this->list[hash].size--;
        this->size--;
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

    this->list[hash].size--;
    this->size--;
}


size_t NumGenerate ()
{
    size_t num = (rand() % 89999) + 10000;

    printf("%zu\n", num);

    return num;
}


void HashTable::DumpTo ()
{
    FILE* gistagram = fopen("../Data/HashTableGistagram.csv", "w");

    for (int i = 0; i < TABLEHEIGHT; i++)
    {
        fprintf(gistagram, "%zu", this->list[i].size);
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