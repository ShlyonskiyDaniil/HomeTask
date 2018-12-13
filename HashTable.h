#ifndef UNTITLED1_HASHTABLE_H
#define UNTITLED1_HASHTABLE_H

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <math.h>
#include <mm_malloc.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

#define TABLEHEIGHT 45
#define ERROR 112


typedef struct Node
{
    char* data;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct List
{
    Node* head;
    size_t size;
} List;

typedef struct HashTable
{
    List list[TABLEHEIGHT];
    size_t size;
public:
    void Registrate (int);
    void* Find (int);
    void Delete (int);
    void DumpTo ();
    size_t (*Hash) (int);
    HashTable (size_t (*Hash_) (int))
    {
        Hash = Hash_;

        for (int i = 0; i < TABLEHEIGHT; i++)
        {
            list[i].size = 0;
            list[i].head = NULL;
        }
    }
} HashTable;

size_t Hash2 (int);
size_t Hash1 (int);
size_t NumGenerate ();
void* Convert (int);

#include "HashTable.cpp"
#endif





