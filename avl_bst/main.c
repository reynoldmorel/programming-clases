#include <stdio.h>
#include <stdlib.h>

typedef struct AvlBinarySearchTree AvlBinarySearchTree;
typedef struct AvlBinarySearchTreeNode AvlBinarySearchTreeNode;

struct AvlBinarySearchTree
{
    AvlBinarySearchTreeNode *root;
    int size;
    AvlBinarySearchTreeNode *(*get)(AvlBinarySearchTree *self, int item);
    void (*add)(AvlBinarySearchTree *self, int item);
    void (*print_items)(AvlBinarySearchTree *self);
};

struct AvlBinarySearchTreeNode
{
    AvlBinarySearchTreeNode *left;
    AvlBinarySearchTreeNode *right;
    AvlBinarySearchTreeNode *parent;
    int item;
    int height;
};

AvlBinarySearchTree *initialize_avl_bst();
void traverse_post_order_and_release_nodes(AvlBinarySearchTreeNode *node);
void release_avl_bst(AvlBinarySearchTree *avl_bst);
AvlBinarySearchTreeNode *traverse_and_get(AvlBinarySearchTree *self, AvlBinarySearchTreeNode *node, int item);
AvlBinarySearchTreeNode *traverse_and_add(AvlBinarySearchTree *self, AvlBinarySearchTreeNode *node, int item);
AvlBinarySearchTreeNode *initialize_node(int item);
AvlBinarySearchTreeNode *rotate_right(AvlBinarySearchTreeNode *node);
AvlBinarySearchTreeNode *rotate_left(AvlBinarySearchTreeNode *node);
int get_balance(AvlBinarySearchTreeNode *node);
int get_height(AvlBinarySearchTreeNode *node);
int custom_max(int a, int b);
AvlBinarySearchTreeNode *update_parent(AvlBinarySearchTreeNode *node);

AvlBinarySearchTreeNode *get(AvlBinarySearchTree *self, int item);
void add(AvlBinarySearchTree *self, int item);
void print_items(AvlBinarySearchTree *self);
void traverse_pre_order_and_print_nodes(AvlBinarySearchTreeNode *node);

int main()
{
    AvlBinarySearchTree *avl_bst = initialize_avl_bst();

    // avl_bst->add(avl_bst, 15);
    // avl_bst->add(avl_bst, 8);
    // avl_bst->add(avl_bst, 25);
    // avl_bst->add(avl_bst, 6);
    // avl_bst->add(avl_bst, 11);
    // avl_bst->add(avl_bst, 20);
    // avl_bst->add(avl_bst, 30);
    // avl_bst->add(avl_bst, 9);
    // avl_bst->add(avl_bst, 13);
    // avl_bst->add(avl_bst, 10);

    for (int i = 0; i < 100; i++)
    {
        avl_bst->add(avl_bst, i + 1);
    }

    printf("Root=%d, height=%d\n", avl_bst->root->item, avl_bst->root->height);

    printf("Printing avl_bst ...\n");
    avl_bst->print_items(avl_bst);

    printf("avl_bst->get(avl_bst, 30)=%d\n", avl_bst->get(avl_bst, 30)->item);

    printf("Printing avl_bst ...\n");
    avl_bst->print_items(avl_bst);

    release_avl_bst(avl_bst);

    return 0;
}

AvlBinarySearchTree *initialize_avl_bst()
{
    AvlBinarySearchTree *avl_bst = malloc(sizeof(AvlBinarySearchTree));

    avl_bst->size = 0;
    avl_bst->root = NULL;

    avl_bst->add = &add;
    avl_bst->get = &get;
    avl_bst->print_items = &print_items;

    return avl_bst;
}

void traverse_post_order_and_release_nodes(AvlBinarySearchTreeNode *node)
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

void release_avl_bst(AvlBinarySearchTree *avl_bst)
{
    traverse_post_order_and_release_nodes(avl_bst->root);
    free(avl_bst);
};

AvlBinarySearchTreeNode *traverse_and_get(AvlBinarySearchTree *self, AvlBinarySearchTreeNode *node, int item)
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

AvlBinarySearchTreeNode *get(AvlBinarySearchTree *self, int item)
{
    AvlBinarySearchTreeNode *found = traverse_and_get(self, self->root, item);

    return found;
}

AvlBinarySearchTreeNode *initialize_node(int item)
{
    AvlBinarySearchTreeNode *node = malloc(sizeof(AvlBinarySearchTreeNode));
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    node->item = item;
    node->height = 0;

    return node;
}

AvlBinarySearchTreeNode *rotate_right(AvlBinarySearchTreeNode *node)
{
    //
    // node= 8 ----- 3                                  5
    //      / \                                         / \
    //      5  NULL ---- 2-----------> 5  --------->   3   8
    //    /  \                         /\                 /
    //  3     6 ---- 1               3    8              6
    AvlBinarySearchTreeNode *left_node = node->left;
    AvlBinarySearchTreeNode *left_right_node = left_node->right;

    left_node->right = node;
    node->left = left_right_node;

    node->height = custom_max(get_height(node->left), get_height(node->right)) + 1;

    return left_node;
}

AvlBinarySearchTreeNode *rotate_left(AvlBinarySearchTreeNode *node)
{
    //
    // node= 8 ----- 3                                  10
    //      / \                                         / \
    //  NULL   10   ---- 2----------->  10  --------->  8  15
    //        /  \                      /\               \  
    //       9   15 ---- 1             8  15              9
    AvlBinarySearchTreeNode *right_node = node->right;
    AvlBinarySearchTreeNode *right_left_node = right_node->left;

    right_node->left = node;
    node->right = right_left_node;

    node->height = custom_max(get_height(node->left), get_height(node->right)) + 1;

    return right_node;
}

int get_balance(AvlBinarySearchTreeNode *node)
{
    if (node == NULL)
    {
        return 0;
    }

    return get_height(node->left) - get_height(node->right);
}

int get_height(AvlBinarySearchTreeNode *node)
{
    if (node == NULL)
    {
        return 0;
    }

    return node->height;
}

int custom_max(int a, int b)
{
    return a > b ? a : b;
}

AvlBinarySearchTreeNode *update_parent(AvlBinarySearchTreeNode *node)
{
    if (node == NULL)
    {
        return NULL;
    }

    if (node->left != NULL)
    {
        node->left->parent = node;
    }

    if (node->right != NULL)
    {
        node->right->parent = node;
    }

    return node;
}

AvlBinarySearchTreeNode *traverse_and_add(AvlBinarySearchTree *self, AvlBinarySearchTreeNode *node, int item)
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

    node->height = custom_max(get_height(node->left), get_height(node->right)) + 1;

    int balance = get_balance(node);

    if (balance > 1 && item < node->left->item)
    {
        printf("Rotating right\n");
        AvlBinarySearchTreeNode *rotated_node = rotate_right(node);
        return update_parent(rotated_node);
    }
    else if (balance < -1 && item > node->right->item)
    {
        printf("Rotating left\n");
        AvlBinarySearchTreeNode *rotated_node = rotate_left(node);
        return update_parent(rotated_node);
    }
    else if (balance > 1 && item > node->left->item)
    {
        printf("Rotating left right\n");
        node->left = rotate_left(node->left);
        node->left = update_parent(node->left);

        AvlBinarySearchTreeNode *rotated_node = rotate_right(node);
        return update_parent(rotated_node);
    }
    else if (balance < -1 && item < node->right->item)
    {
        printf("Rotating right left\n");
        node->right = rotate_right(node->right);
        node->right = update_parent(node->right);

        AvlBinarySearchTreeNode *rotated_node = rotate_left(node);
        return update_parent(rotated_node);
    }

    return node;
}

void add(AvlBinarySearchTree *self, int item)
{
    self->root = traverse_and_add(self, self->root, item);
    self->root->parent = NULL;
}

void print_items(AvlBinarySearchTree *self)
{
    printf("\n[");
    traverse_pre_order_and_print_nodes(self->root);
    printf("]\n");
}

void traverse_pre_order_and_print_nodes(AvlBinarySearchTreeNode *node)
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