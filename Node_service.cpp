#include "Node_non_exe.h"
#include "Node_safety.h"


Node* Search_node (int data, Node* start_search)
{
#ifndef FAST_LIST
    if (Is_ok(start_search) == notOK) return NULL;
#endif

    if (start_search == NULL)
    {
        printf("Input fault!\tSearch_node.\n");
        return NULL;
    }

    Node* cur_ptr = start_search;

    while (cur_ptr != NULL)
    {
        if (cur_ptr->data == data)
        {
            return cur_ptr;
        }

        cur_ptr = cur_ptr->next;
    }
#ifndef FAST_LIST
    if (Is_ok(start_search) == notOK) return NULL;
#endif

    printf("There is no such number!\tSearch_node.\n");
    return NULL;
}



void* Print_node (Node* base_node)
{
#ifndef FAST_LIST
    if (Is_ok (base_node) == notOK) return NULL;

    if (base_node == NULL)
    {
        printf("Input fault!\tPrint_node.\n");
        return NULL;
    }
#endif

    do
    {
        printf("%d\n", base_node->data);

#ifndef FAST_LIST
        if (Is_ok(base_node) == notOK) return NULL;
#endif

        base_node = base_node->next;

    }while (base_node != NULL);
}



void* Nseek (Node* sup_node, int direction)
{
#ifndef FAST_LIST
    if (Is_ok(sup_node) == notOK) return NULL;

    if (sup_node == NULL)
    {
        printf("Input fault!\tNseek.\n");
        return NULL;
    }
#endif

    if (direction != START && direction !=END)
    {
        printf("You are on the same node.");
        return sup_node;
    }

    if (direction < 0)
    {
        while (sup_node->prev != NULL)
        {
            sup_node = sup_node->prev;
        }
        printf("You are on the first node.");
    }

    if (direction > 0)
    {
        while (sup_node->next != NULL)
        {
            sup_node = sup_node->next;
        }
        printf("You are on the last node.");

    }

#ifndef FAST_LIST
    if (Is_ok (sup_node) == notOK) return NULL;
#endif

    return sup_node;
}



void* Swap (Node* node1, Node* node2)
{
#ifndef FAST_LIST
    if (Is_ok (node1) == notOK) return NULL;
    if (Is_ok (node2) == notOK) return NULL;

    if (node1 == NULL || node2 == NULL)
    {
        printf("Input fault!\tSwap.\n");
        return NULL;
    }
#endif

    int tmp = node1->data;

    node1->data = node2->data;
    node2->data = tmp;
#ifndef FAST_LIST
    if (Is_ok(node1) == notOK) return NULL;
    if (Is_ok(node2) == notOK) return NULL;
#endif
}



