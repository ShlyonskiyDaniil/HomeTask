#include "Node_safety.h"


int Check_sum (Node* node)
{
    return (int) (271 * (long int) node->prev + 828 * (long int) node->next) % 12341;
}


int Is_ok (Node* node)
{
    if (node ==  NULL)
    {
        printf ("Input fault!\tIs_ok.\n");
        return IFAULT;
    }

    if ((Check_sum (node) == node->check_sum))
    {
        if (node->can1 == CAN1 && node->can2 == CAN2)
        {
            return isOK;
        }

        printf ("CanFault!\n");
        return notOK;
    }

    printf ("%d\n", Check_sum(node));
    printf ("ChecksumFault\n");
    return notOK;
}



