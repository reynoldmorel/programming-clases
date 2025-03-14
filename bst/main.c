#include <stdio.h>
#include <stdlib.h>

typedef struct BinarySearchTree BinarySearchTree;
typedef struct BinarySearchTreeNode BinarySearchTreeNode;

struct BinarySearchTree
{
    BinarySearchTreeNode *root;
    int size;
    BinarySearchTreeNode *(*get)(BinarySearchTree *self, int item);
    void (*add)(BinarySearchTree *self, int item);
    void (*print_items)(BinarySearchTree *self);
};

struct BinarySearchTreeNode
{
    BinarySearchTreeNode *left;
    BinarySearchTreeNode *right;
    BinarySearchTreeNode *parent;
    int item;
};

BinarySearchTree *initialize_bst();
void traverse_post_order_and_release_nodes(BinarySearchTreeNode *node);
void release_bst(BinarySearchTree *bst);
BinarySearchTreeNode *traverse_and_get(BinarySearchTree *self, BinarySearchTreeNode *node, int item);
BinarySearchTreeNode *traverse_and_add(BinarySearchTree *self, BinarySearchTreeNode *node, int item);
BinarySearchTreeNode *initialize_node(int item);

BinarySearchTreeNode *get(BinarySearchTree *self, int item);
void add(BinarySearchTree *self, int item);
void print_items(BinarySearchTree *self);
void traverse_pre_order_and_print_nodes(BinarySearchTreeNode *node);

int main()
{
    BinarySearchTree *bst = initialize_bst();

    bst->add(bst, 50);
    bst->add(bst, 2);
    bst->add(bst, 2);
    bst->add(bst, 2);
    bst->add(bst, 20);
    bst->add(bst, 40);
    bst->add(bst, 1);
    bst->add(bst, 2);
    bst->add(bst, 2);
    bst->add(bst, 2);
    bst->add(bst, 3);
    bst->add(bst, 4);

    printf("Printing bst ...\n");
    bst->print_items(bst);

    printf("bst->get(bst, 1)=%d\n", bst->get(bst, 1)->item);

    printf("Printing bst ...\n");
    bst->print_items(bst);

    release_bst(bst);

    return 0;
}

BinarySearchTree *initialize_bst()
{
    BinarySearchTree *bst = malloc(sizeof(BinarySearchTree));

    bst->size = 0;
    bst->root = NULL;

    bst->add = &add;
    bst->get = &get;
    bst->print_items = &print_items;

    return bst;
}

void traverse_post_order_and_release_nodes(BinarySearchTreeNode *node)
{
    if (node == NULL)
    {
        return;
    }

    if (node->left != NULL)
    {
        traverse_post_order_and_release_nodes(node->left);
    }

    if (node->right != NULL)
    {
        traverse_post_order_and_release_nodes(node->right);
    }

    free(node);
}

void release_bst(BinarySearchTree *bst)
{
    traverse_post_order_and_release_nodes(bst->root);
    free(bst);
};

BinarySearchTreeNode *traverse_and_get(BinarySearchTree *self, BinarySearchTreeNode *node, int item)
{
    if (node == NULL)
    {
        return NULL;
    }

    if (item > node->item)
    {
        return traverse_and_get(self, node->right, item);
    }

    if (item < node->item)
    {
        return traverse_and_get(self, node->left, item);
    }

    return node;
}

BinarySearchTreeNode *get(BinarySearchTree *self, int item)
{
    BinarySearchTreeNode *found = traverse_and_get(self, self->root, item);

    return found;
}

BinarySearchTreeNode *initialize_node(int item)
{
    BinarySearchTreeNode *node = malloc(sizeof(BinarySearchTreeNode));
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    node->item = item;

    return node;
}

BinarySearchTreeNode *traverse_and_add(BinarySearchTree *self, BinarySearchTreeNode *node, int item)
{
    if (node == NULL)
    {
        self->size = self->size + 1;
        return initialize_node(item);
    }

    if (item > node->item)
    {
        node->right = traverse_and_add(self, node->right, item);
        node->right->parent = node;
    }
    else if (item < node->item)
    {
        node->left = traverse_and_add(self, node->left, item);
        node->left->parent = node;
    }

    return node;
}

void add(BinarySearchTree *self, int item)
{
    self->root = traverse_and_add(self, self->root, item);
}

void print_items(BinarySearchTree *self)
{
    printf("\n[");
    traverse_pre_order_and_print_nodes(self->root);
    printf("]\n");
}

void traverse_pre_order_and_print_nodes(BinarySearchTreeNode *node)
{
    if (node == NULL)
    {
        return;
    }

    if (node->left != NULL)
    {
        traverse_pre_order_and_print_nodes(node->left);
    }

    printf("%d, ", node->item);

    if (node->right != NULL)
    {
        traverse_pre_order_and_print_nodes(node->right);
    }
}

/*
La tarea para de este clase es implementar el delete en time complexity de log n.

Recordar determninar el big o notation de cada operación en tiempo y espacio.
*/