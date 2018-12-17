#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node * left;
    struct node * right;
} node;

typedef struct tree
{
    struct node * root;   // указатель на корень дерева
    int count;            // количество узлов в дереве
} tree;
// создание дерева
struct tree * create_tree(void)
{
    struct tree * new_tree = malloc(sizeof * new_tree);
    if (new_tree == NULL) return NULL;
    new_tree->root = NULL;
    new_tree->count = 0;
    return new_tree;
}
// поиск узла в дереве
int bin_search(const struct tree * search_tree, int item)
{
    const struct node * search_node;
    search_node = search_tree->root;
    for(;;)
    {
        if (search_node == NULL) return 0;
        else if (item == search_node->value) return 1;
        else if (item > search_node->value) search_node = search_node->right;
        else search_node = search_node->left;
    }
}
// вставка узла в дерево
int insert(struct tree * search_tree, int item)
{
    struct node * search_node, **new;

    new = &search_tree->root;
    search_node = search_tree->root;

    for(;;)
    {
        if(search_node == NULL)
        {
            search_node = *new = malloc(sizeof * search_node);
            if(search_node != NULL)
            {
                search_node->value = item;
                search_node->left = search_node->right = NULL;
                search_tree->count++;
                return 1;
            }
            else return 0;
        }
        else if(item == search_node->value) return 2;
        else if(item > search_node->value)
        {
            new = &search_node->right;
            search_node = search_node->right;
        }
        else
        {
            new = &search_node->left;
            search_node = search_node->left;
        }
    }
}
// удаление узла из дерева
int delete(struct tree * search_tree, int ** item)
{
    struct node ** a,*b;

    a = &search_tree->root;
    b = search_tree->root;
    //поиск удаляемого элемента
    for(;;)
    {
        if(a == NULL) return 0;
        else if(item == (int **)b->value) break;
        else if(item > (int **)b->value)
        {
            a = &b->right;
            b = b->right;
        }
        else
        {
            a = &b->left;
            b = b->left;
        }
    }

    // удаление элемента
    if(b->right == NULL) *a = b->left;
    else
    {
        struct node * y = b->right;
        if(y->left == NULL)
        {
            y->left = b->left;
            *a-y;
        }
        else
        {
            struct node * x=y->left;
            while(x->left != NULL)
            {
                y = x;
                x = y->left;
            }
            y->left = x->right;
            x->left = b->left;
            x->right = b->right;
            *a = x;
        }
    }

    search_tree->count --;
    free(b);
    return 1;
}
//функция для распечатки фрагмента дерева с любого узла
static void walk(const struct node * search_node)
{
    struct node * node1;
    if(node1 == NULL) return;
    walk(node1->left);
    printf("%d ", search_node->value);
    walk(node1->right);
}

//функция для распечатки дерева целиком (с корня)
void walk1(const struct tree * my_tree)
{
    walk(my_tree->root);
}
//функция для удаления отдельного узла дерева и его потомков
static void destroy(struct node * search_node)
{
    if(search_node == NULL) return;
    destroy(search_node->left);
    destroy(search_node->right);
    free(search_node);
}

//функция для полного удаления дерева
void destroy_tree(struct tree * search_tree)
{
    destroy(search_tree->root);
    free(search_tree);
}



void traverse (node*);

int main()
{
    // tree* my_tree = create_tree();
    // insert(my_tree, 7);
    // insert(my_tree, 8);
    // insert(my_tree, 0);
    // walk1(my_tree);
    /// walk1 & walk  не работает при подаче коректных данных. (Segmentation fault)

    // tree* my_tree = create_tree();
    // insert(my_tree, 7);
    // insert(my_tree, 8);
    // insert(my_tree, 0);
    // destroy_tree(my_tree);
    // destroy_tree(NULL);
    // destroy_tree(7);
    /// При подаче в destroy_tree некорректных данных -- Segmentation fault.

    // tree* my_tree = create_tree();
    // insert(my_tree, 7);
    // insert(my_tree, 8);
    // insert(my_tree, 0);
    // destroy(my_tree->root->left);
    // destroy(my_tree->root->left);
    // destroy(my_tree->root->3);
    // node* root = my_tree->root;
    // destroy(root);
    // printf("%d", root->value);
    /// При подаче в destroy некорректных данных -- Segmentation fault. При удалении корня почему-то имеется возможность
    /// распечатать значение, которое в нём хранилось.

    // tree* my_tree = create_tree();
    // printf("%d", my_tree->root->value);
    /// При печати значения корня возникает Segmentation fault.

    // tree* my_tree = create_tree();
    // insert(my_tree, 7);
    // insert(my_tree, 8);
    // insert(my_tree, 0);
    // traverse(my_tree->root);
    /// Traverse function using.

     return 0;
}

void traverse (node* node)
{
    if (node == NULL) return;

    printf("%d ", node->value);

    traverse(node->left);

    traverse(node->right);
}
