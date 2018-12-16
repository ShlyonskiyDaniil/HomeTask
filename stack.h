

#include <stdlib.h>

typedef char tData;

typedef struct Node{
    tData value;
    struct Node *next;
} sNode;

typedef struct{
    sNode *p_begin;
    size_t m_size;
} tStack;

void stack_push(tStack *s, tData value);
tData stack_pop(tStack *s);
tData stack_top(const tStack *s);
size_t stack_size(const tStack *s);
void stack_clear(tStack *s);
tStack create_stack();
void stack_print(const tStack *s);
int stack_empty(const tStack *s);

