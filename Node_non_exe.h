#ifndef UNTITLED_NODE_NON_EXE_H
#define UNTITLED_NODE_NON_EXE_H

#define LEFT -1
#define RIGHT +1

#define START -1
#define END +1

#ifndef FAST_LIST
int const isOK = 1234;
int const notOK = -1;
int const CAN1 = 2;
int const CAN2 = -2;
#endif
int const NULLFAULT = 32123;
int const IFAULT = 12321;

typedef struct Node
{
#ifndef FAST_LIST
    int can1;
#endif
    int data;
    struct Node* prev;
    struct Node* next;
#ifndef FAST_LIST
    int check_sum ;
    int can2;
#endif
}Node;

#endif
