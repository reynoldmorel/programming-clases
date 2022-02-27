#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
typedef struct BinarySearchTree BinarySearchTree;

struct Node
{
    Node *left;
    Node *right;
    int value;
};

struct BinarySearchTree
{
    Node *root;
    int size;
    Node *(*search)(BinarySearchTree *self, int value_to_search);
    void (*insert)(BinarySearchTree *self, int item);
    void (*print_inorder_items)(BinarySearchTree *self);
    void (*print_pre_order_items)(BinarySearchTree *self);
    void (*print_post_order_items)(BinarySearchTree *self);
};

BinarySearchTree *initialize_tree();
void release_tree(BinarySearchTree *tree);
Node *search(BinarySearchTree *self, int value_to_search);
void insert(BinarySearchTree *self, int item);
void print_inorder_items(BinarySearchTree *self);
void print_pre_order_items(BinarySearchTree *self);
void print_post_order_items(BinarySearchTree *self);

void traverse_post_order_and_release_nodes(Node *node);
Node *initialize_node(int value);
void insert_node(Node *node, int item);
Node *search_node(Node *node, int value_to_search);

int main(int argc, char **argv)
{
    BinarySearchTree *tree = initialize_tree();

    printf("\n-------- Adding 8 items -------");

    tree->insert(tree, 10);
    tree->insert(tree, 5);
    tree->insert(tree, 15);
    tree->insert(tree, 13);
    tree->insert(tree, 16);
    tree->insert(tree, 3);
    tree->insert(tree, 6);
    tree->insert(tree, 8);

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

BinarySearchTree *initialize_tree()
{
    BinarySearchTree *tree = malloc(sizeof(BinarySearchTree));

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

void release_tree(BinarySearchTree *tree)
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

    return node;
}

void insert_node(Node *node, int item)
{
    if (item > node->value)
    {
        if (node->right == NULL)
        {
            node->right = initialize_node(item);
        }
        else
        {
            insert_node(node->right, item);
        }
    }
    else if (item < node->value)
    {
        if (node->left == NULL)
        {
            node->left = initialize_node(item);
        }
        else
        {
            insert_node(node->left, item);
        }
    }
}

// Time complexity: O(log n)
// Space complexity O(1) para el heap
void insert(BinarySearchTree *self, int item)
{
    if (self->root == NULL)
    {
        self->root = initialize_node(item);
    }
    else
    {
        insert_node(self->root, item);
    }
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

void print_inorder_items(BinarySearchTree *self)
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

void print_pre_order_items(BinarySearchTree *self)
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

void print_post_order_items(BinarySearchTree *self)
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

Node *search(BinarySearchTree *self, int value_to_search)
{
    return search_node(self->root, value_to_search);
}