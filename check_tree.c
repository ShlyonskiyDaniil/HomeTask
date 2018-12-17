#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef int Data;

struct Node {
    Data val; // данные в узле
    struct Node * left; // левый ребенок
    struct Node * right; // правый ребенок
};
struct Node * tree_add(struct Node * tree, Data x) {

    if (tree == NULL) {
        tree = (struct Node*)malloc(sizeof(struct Node));
        tree->left = NULL;
        tree->right = NULL;
        tree->val = x;
        return tree;

    }
    if (x < tree->val) {
        tree->left = tree_add(tree->left, x);
    }


    if (x > tree->val) {
        tree->right = tree_add(tree->right, x);
    }


    return tree;
}



int tree_print(struct Node * tree) {
    int r1 = 0, r2 = 0;
    if (tree == NULL)
        return 0;
    if ((tree->left == NULL) && (tree->right == NULL)) {
        return 1;
    }
    else
    {
        if (tree->left != NULL) {
            r1 = tree_print(tree->left);

        }

        if (tree->right != NULL)
            r2 = tree_print(tree->right);

        if (r1 > r2)
            return r1+1;
        else
            return r2+1;
    }
}


void tree_destroy(struct Node * tree) {


    if ((tree->left == NULL) && (tree->right == NULL)) {


        free(tree);

    }
    else
    {
        if (tree->left != NULL) {
            tree_destroy(tree->left);

        }

        if (tree->right != NULL) {
            tree_destroy(tree->right);
        }
        free(tree);
    }

}
//a function that checks if a tree is AVL.
int sbalansed(struct Node * tree) {
    int r = 0;

    if (abs(tree_print(tree->right) - tree_print(tree->left)) > 1) {
        r+=1;

    }

    if (tree->left != NULL) {
        r += sbalansed(tree->left);

    }
    if (tree->right != NULL) {
        r += sbalansed(tree->right);

    }
    return r;

}

int main() {
    int a;
    struct Node * tree = NULL;
    scanf("%d", &a);
    if (a == 0) {
        printf("YES");
        return 0;
    }
    while (a!=0)
    {

        tree = tree_add(tree, a);
        scanf("%d", &a);
    }
    if (0 == sbalansed(tree)) {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
    tree_destroy(tree);
    return 0;
}
