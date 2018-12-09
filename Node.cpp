#include "Node.h"

// Node.cpp Node.h Node_service.h Node_creation.h Node_safety.h
int main()
{
    Node* base_node = Сreate_node (7);
    Node* last_node = Add_in_end_node( base_node, 12);
    Add_node(last_node, 1, LEFT);
    Print_node(base_node);

    printf("\n");

    Swap(base_node, last_node);
    Print_node(base_node);

    printf("\n");

    base_node = (Node*) Delete_node(Search_node (7, base_node));//
    Print_node(base_node);

    printf("\n");

    base_node = Add_in_start_node (NULL, 7);
    Print_node(base_node);

    Add_node(last_node, 7, RIGHT);
}