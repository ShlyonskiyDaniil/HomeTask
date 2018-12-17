#include<stdio.h>
#include<stdlib.h>

#define INCORRECT 112;

typedef struct Node
{
    int key;
    Node *left;
    Node *right;
    int height;
} Node;

int Max(int a, int b);
int Height(Node*);
Node* NewNode(int);
struct Node* insert(Node*, int);
int GetBalance(Node*);
struct Node *RightRotate(Node*);
struct Node *LeftRotate(Node*);
void traverse (Node*);


int main()
{
    Node *root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    traverse(root);

    return 0;
}

Node *RightRotate(Node* y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = Max(Height(y->left), Height(y->right))+1;
    x->height = Max(Height(x->left), Height(x->right))+1;

    return x;
}


Node *LeftRotate(Node* x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = Max(Height(x->left), Height(x->right))+1;
    y->height = Max(Height(y->left), Height(y->right))+1;

    return y;
}


int GetBalance(Node *N)
{
    if (N == NULL) return INCORRECT;

    return Height(N->left) - Height(N->right);
}


Node* insert(Node* node, int key)
{
    if (node == NULL)
        return (NewNode(key));

    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = 1 + Max(Height(node->left), Height(node->right));


    int balance = GetBalance(node);

    if (balance > 1 && key < node->left->key)
        return RightRotate(node);

    if (balance < -1 && key > node->right->key)
        return LeftRotate(node);

    if (balance > 1 && key > node->left->key)
    {
        node->left =  LeftRotate(node->left);
        return RightRotate(node);
    }

    if (balance < -1 && key < node->right->key)
    {
        node->right = RightRotate(node->right);
        return LeftRotate(node);
    }

    return node;
}


int Height (Node* N)
{
    if (N == NULL) return 0;

    return N->height;
}


int Max (int a, int b)
{
    return (a > b)? a : b;
}


Node* NewNode (int key)
{
    Node* node = (Node*) malloc(sizeof(Node));
    node->key   = key;
    node->left   = NULL;
    node->right  = NULL;
    node->height = 1;
    
    return(node);
}


void traverse (Node* node)
{
    if (node == NULL) return;


    printf("%d ", node->key);

    traverse(node->left);

    traverse(node->right);
}