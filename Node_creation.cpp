#include "Node_creation.h"
#include "Node_safety.h"
#include "Node_service.h"
#pragma



Node* Сreate_node (int data)
{
#ifdef FAST_LIST
    printf("FAST LIST is activated!\n");
#endif
    Node* base_node = new Node [1];

    if (base_node == NULL)
    {
        printf("Allocation fault!\tCreate_node.\n");
        return NULL;
    }

#ifndef FAST_LIST
    base_node->can1 = CAN1;
#endif
    base_node->data = data;
    base_node->prev = NULL;
    base_node->next = NULL;
#ifndef FAST_LIST
    base_node->check_sum = Check_sum (base_node);
    base_node->can2 = CAN2;

    if (Is_ok (base_node) == notOK) return NULL;
#endif

    return base_node;
}



Node* Add_in_start_node (Node* base_node, int data)
{
#ifndef FAST_LIST
    if (Is_ok (base_node) == notOK) return NULL;

    if (base_node == NULL)
    {
        printf("Input fault!\tAdd_in_start_node.\n");
        return NULL;
    }
#endif

    Node* first_node = new Node [1];

    if (first_node == NULL)
    {
        printf("Allocation fault!\n");
        return NULL;
    }

#ifndef FAST_LIST
    first_node->can1 = CAN1;
#endif
    first_node->data = data;
    first_node->prev = NULL;
    first_node->next = base_node;
#ifndef FAST_LIST
    first_node->check_sum = Check_sum (first_node);
    first_node->can2 = CAN2;
#endif

    base_node->prev = first_node;
#ifndef FAST_LIST
    base_node->check_sum = Check_sum (base_node);
#endif

#ifndef FAST_LIST
    if (Is_ok (first_node) == notOK) return NULL;
#endif

    return first_node;
}



Node* Add_in_end_node (Node* end_node, int data)
{
#ifndef FAST_LIST
    if (Is_ok (end_node) == notOK) return NULL;
#endif

    if (end_node == NULL)
    {
        printf("Input fault!\tAdd_in_end_node.\n");
        return NULL;
    }

    Node* last_node = new Node [1];

    if (last_node == NULL)
    {
        printf("Allocation fault!\tAdd_in_end_node.\n");
        return NULL;
    }

#ifndef FAST_LIST
    last_node->can1 = CAN1;
#endif
    last_node->data = data;
    last_node->prev = end_node;
    last_node->next = NULL;
#ifndef FAST_LIST
    last_node->check_sum = Check_sum (last_node);
    last_node->can2 = CAN2;
#endif

    end_node->next = last_node;
#ifndef FAST_LIST
    end_node->check_sum = Check_sum (end_node);
#endif

#ifndef FAST_LIST
    if (Is_ok (last_node) == notOK) return NULL;
#endif

    return last_node;
}



void* Add_node (Node* sup_node, int data, int direction)
{
#ifndef FAST_LIST
    if (Is_ok (sup_node) == notOK) return NULL;

    if (sup_node == NULL)
    {
        printf("Input fault!\tAdd_node.\n");
        return NULL;
    }
#endif

    Node* new_node = new Node [1];

    if (new_node == NULL)
    {
        printf("Allocation fault\tAdd_node.\n");
        return NULL;
    }



    if (direction > 0)
    {
#ifndef FAST_LIST
        if (sup_node->next == NULL )
        {
            printf("Please, use Add_in_end_node instead.\n");
            return NULL;
        }

        if (Is_ok (sup_node) == notOK) return NULL;
#endif

        Node* next_node = sup_node->next;

#ifndef FAST_LIST
        new_node->can1 = CAN1;
#endif
        new_node->data = data;
        new_node->prev = sup_node;
        new_node->next = next_node;
#ifndef FAST_LIST
        new_node->check_sum = Check_sum (new_node);
        new_node->can2 = CAN2;
#endif

        sup_node->next = new_node;
#ifndef FAST_LIST
        sup_node->check_sum = Check_sum (sup_node);
#endif

        next_node->prev = new_node;
#ifndef FAST_LIST
        next_node->check_sum = Check_sum (next_node);
#endif

#ifndef FAST_LIST
        if (Is_ok (new_node) == notOK) return NULL;
        if (Is_ok (sup_node) == notOK) return NULL;
        if (Is_ok (next_node) == notOK) return NULL;
#endif
    }

    if (direction < 0)
    {
#ifndef FAST_LIST
        if (sup_node->prev == NULL )
        {
            printf("Please, use Add_in_start_node instead.\n");
            return NULL;
        }

        if (Is_ok (sup_node) == notOK) return NULL;
#endif

        Node* prev_node = sup_node->prev;

#ifndef FAST_LIST
        new_node->can1 = CAN1;
#endif
        new_node->data = data;
        new_node->prev = prev_node;
        new_node->next = sup_node;
#ifndef FAST_LIST
        new_node->check_sum = Check_sum (new_node);
        new_node->can2 = CAN2;
#endif

        sup_node->prev = new_node;
#ifndef FAST_LIST
        sup_node->check_sum = Check_sum (sup_node);
#endif

        prev_node->next = new_node;
#ifndef FAST_LIST
        prev_node->check_sum = Check_sum (prev_node);

        if (Is_ok (new_node) == notOK) return NULL;
        if (Is_ok (sup_node) == notOK) return NULL;
        if (Is_ok (prev_node) == notOK) return NULL;
#endif
    }
}



void* Delete_node (Node* deleted)
{
#ifndef FAST_LIST
    if (Is_ok (deleted) == notOK) return NULL;

    if (deleted == NULL)
    {
        printf("Input fault!\tDelete_node.\n");
        return NULL;
    }
#endif

    Node* base_node = (Node*) Nseek (deleted, START);

#ifndef FAST_LIST
    if (Is_ok (base_node) == notOK) return NULL;
#endif

    if (deleted->prev == NULL)
    {
        Node* next = deleted->next;
        next->prev = NULL;
#ifndef FAST_LIST
        next->check_sum = Check_sum (next);
#endif

        delete deleted;
        deleted = NULL;

#ifndef FAST_LIST
        if (Is_ok (next) == notOK) return NULL;
#endif

        return next;
    }

    if (deleted->next == NULL)
    {
        Node* prev = deleted->prev;
        prev->next = NULL;
#ifndef FAST_LIST
        prev->check_sum = Check_sum (prev);
#endif

        delete deleted;
        deleted = NULL;

#ifndef FAST_LIST
        if (Is_ok (base_node) == notOK) return NULL;
#endif

        return base_node;
    }

    Node* prev = deleted->prev;
    Node* next = deleted->next;

    delete deleted;
    deleted = NULL;

    next->prev = prev;
#ifndef FAST_LIST
    next->check_sum = Check_sum (next);
#endif

    prev->next = next;
#ifndef FAST_LIST
    prev->check_sum = Check_sum (prev);

    if (Is_ok (base_node) == notOK) return NULL;
#endif

    return base_node;
}
