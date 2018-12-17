//
// Created by MoYo on 04.12.2018.
//

#include "stack.h"

#include <stdio.h>
#include <assert.h>

//распечатаем односвязный список
void print_list(sNode *p_begin)
{
    sNode *p = p_begin;
    while (p != NULL) {
        printf("%c \t", p->value);
        p = p->next;
    }
}
// удаление списка
void list_delete(sNode *p_begin)
{
    sNode *p = p_begin;
    while (p != NULL) {
        sNode *tmp;
        tmp = p;
        //шагнуть вперед !!!
        p = p->next;
        //удалить память ячейки
        free(tmp);
    }
}

void stack_push(tStack *s, tData value)
{
    sNode *p = (sNode *)malloc(sizeof(sNode));
    p->value = value;
    p->next = s->p_begin;
    s->p_begin = p;
    s->m_size++;
}

tData stack_pop(tStack *s)
{
    sNode *tmp = s->p_begin;
    tData tmp_value = tmp->value;
    s->p_begin = s->p_begin->next;
    s->m_size--;
    free(tmp);
    return tmp_value;
}

tData stack_top(const tStack *s)
{
    return s->p_begin->value;
}

size_t stack_size(const tStack *s)
{
    return s->m_size;
}

void stack_clear(tStack *s)
{
    list_delete(s->p_begin);
    s->p_begin = NULL;
    s->m_size = 0;
}

tStack create_stack()
{
    tStack new_stack = {NULL, 0};
    return new_stack;
}

void stack_print(const tStack *s)
{
    print_list(s->p_begin);
}

int stack_empty(const tStack *s)
{
    return s->m_size == 0;
}
