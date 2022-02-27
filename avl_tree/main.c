#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
typedef struct AvlTree AvlTree;

struct Node
{
    Node *left;
    Node *right;
    int value;
    int height;
};

struct AvlTree
{
    Node *root;
    int size;
    Node *(*search)(AvlTree *self, int value_to_search);
    void (*insert)(AvlTree *self, int item);
    void (*print_inorder_items)(AvlTree *self);
    void (*print_pre_order_items)(AvlTree *self);
    void (*print_post_order_items)(AvlTree *self);
};

AvlTree *initialize_tree();
void release_tree(AvlTree *tree);
Node *search(AvlTree *self, int value_to_search);
void insert(AvlTree *self, int item);
void print_inorder_items(AvlTree *self);
void print_pre_order_items(AvlTree *self);
void print_post_order_items(AvlTree *self);

void traverse_post_order_and_release_nodes(Node *node);
Node *initialize_node(int value);
Node *insert_node(Node *node, int item);
Node *search_node(Node *node, int value_to_search);
int get_height(Node *node);
int get_balance(Node *node);
Node *rightRotate(Node *node);
Node *leftRotate(Node *node);
int custom_max(int a, int b);

int main(int argc, char **argv)
{
    AvlTree *tree = initialize_tree();

    printf("\n-------- Adding 8 items -------");

    tree->insert(tree, 5);
    tree->insert(tree, 13);
    tree->insert(tree, 3);
    tree->insert(tree, 10);
    tree->insert(tree, 6);
    tree->insert(tree, 8);
    tree->insert(tree, 16);
    tree->insert(tree, 15);

    tree->print_inorder_items(tree);
    printf("\n");
    tree->print_post_order_items(tree);
    printf("\n");
    tree->print_pre_order_items(tree);
    printf("\n");

    printf("\n-------- Search an item -------\n");

    Node *item_found = tree->search(tree, 5);
    printf("node = %d\n", item_found->value);
    printf("left = %d\n", item_found->left->value);
    printf("right = %d\n", item_found->right->value);

    release_tree(tree);
    return 0;
}

AvlTree *initialize_tree()
{
    AvlTree *tree = malloc(sizeof(AvlTree));

    tree->size = 0;

    tree->root = NULL;

    tree->insert = &insert;
    tree->print_pre_order_items = &print_pre_order_items;
    tree->print_post_order_items = &print_post_order_items;
    tree->print_inorder_items = &print_inorder_items;
    tree->search = &search;

    return tree;
}

void traverse_post_order_and_release_nodes(Node *node)
{
    if (node->left != NULL)
    {
        traverse_post_order_and_release_nodes(node->left);
        node->left = NULL;
    }

    if (node->right != NULL)
    {
        traverse_post_order_and_release_nodes(node->right);
        node->right = NULL;
    }

    free(node);
}

void release_tree(AvlTree *tree)
{
    if (tree->root != NULL)
    {
        traverse_post_order_and_release_nodes(tree->root);
        tree->root = NULL;
    }

    free(tree);
}

Node *initialize_node(int value)
{
    Node *node = malloc(sizeof(Node));

    node->value = value;
    node->left = NULL;
    node->right = NULL;
    node->height = 0;

    return node;
}

int get_height(Node *node)
{
    return node == NULL ? 0 : node->height;
}

int get_balance(Node *node)
{
    if (node == NULL)
    {
        return 0;
    }

    return get_height(node->left) - get_height(node->right);
}

Node *rightRotate(Node *node)
{
    Node *left_node = node->left;
    Node *left_right_node = left_node->right;

    left_node->right = node;
    node->left = left_right_node;

    node->height = custom_max(get_height(node->left), get_height(node->right)) + 1;
    left_node->height = custom_max(get_height(left_node->left), get_height(left_node->right)) + 1;

    return left_node;
}

Node *leftRotate(Node *node)
{
    Node *right_node = node->right;
    Node *right_left_node = right_node->left;

    right_node->left = node;
    node->right = right_left_node;

    node->height = custom_max(get_height(node->left), get_height(node->right)) + 1;
    right_node->height = custom_max(get_height(right_node->left), get_height(right_node->right)) + 1;

    return right_node;
}

int custom_max(int a, int b)
{
    return a > b ? a : b;
}

Node *insert_node(Node *node, int item)
{
    if (node == NULL)
    {
        return initialize_node(item);
    }

    if (item < node->value)
    {
        node->left = insert_node(node->left, item);
    }
    else if (item > node->value)
    {
        node->right = insert_node(node->right, item);
    }
    else
    {
        return node;
    }

    node->height = 1 + custom_max(get_height(node->left), get_height(node->right));

    int balance = get_balance(node);

    if (balance > 1 && item < node->left->value)
    {
        printf("Right rotation for node:%d\n", node->value);
        return rightRotate(node);
    }
    else if (balance < -1 && item > node->right->value)
    {
        printf("Left rotation for node:%d\n", node->value);
        return leftRotate(node);
    }
    else if (balance > 1 && item > node->left->value)
    {
        printf("Left and Right rotation for node:%d\n", node->value);
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    else if (balance < -1 && item < node->right->value)
    {
        printf("Right and Left rotation for node:%d\n", node->value);
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Time complexity: O(log n)
// Space complexity O(1) para el heap
void insert(AvlTree *self, int item)
{
    self->root = self->root == NULL ? initialize_node(item) : insert_node(self->root, item);
}

void traverse_inorder_and_printf_nodes(Node *node)
{
    if (node->left != NULL)
    {
        traverse_inorder_and_printf_nodes(node->left);
    }

    printf("%d, ", node->value);

    if (node->right != NULL)
    {
        traverse_inorder_and_printf_nodes(node->right);
    }
}

void print_inorder_items(AvlTree *self)
{
    printf("\n-------- Binary Search Tree Inorder Items -------\n");
    printf("[");
    traverse_inorder_and_printf_nodes(self->root);
    printf("]");
}

void traverse_pre_order_and_printf_nodes(Node *node)
{
    printf("%d, ", node->value);

    if (node->left != NULL)
    {
        traverse_pre_order_and_printf_nodes(node->left);
    }
    if (node->right != NULL)
    {
        traverse_pre_order_and_printf_nodes(node->right);
    }
}

void print_pre_order_items(AvlTree *self)
{
    printf("\n-------- Binary Search Tree Pre-Order Items -------\n");
    printf("[");
    traverse_pre_order_and_printf_nodes(self->root);
    printf("]");
}

void traverse_post_order_and_printf_nodes(Node *node)
{
    if (node->left != NULL)
    {
        traverse_post_order_and_printf_nodes(node->left);
    }
    if (node->right != NULL)
    {
        traverse_post_order_and_printf_nodes(node->right);
    }

    printf("%d, ", node->value);
}

void print_post_order_items(AvlTree *self)
{
    printf("\n-------- Binary Search Tree Post-Order Items -------\n");
    printf("[");
    traverse_post_order_and_printf_nodes(self->root);
    printf("]");
}

// Time complexity: O(log n)
// Space complexity O(1) para el heap
Node *search_node(Node *node, int value_to_search)
{
    if (node == NULL)
    {
        return NULL;
    }

    if (value_to_search == node->value)
    {
        return node;
    }
    else if (value_to_search > node->value)
    {
        return search_node(node->right, value_to_search);
    }
    else if (value_to_search < node->value)
    {
        return search_node(node->left, value_to_search);
    }
}

Node *search(AvlTree *self, int value_to_search)
{
    return search_node(self->root, value_to_search);
}