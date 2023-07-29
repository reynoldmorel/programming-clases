#include <stdio.h>
#include <stdlib.h>

typedef struct BinarySearchTree BinarySearchTree;
typedef struct Node Node;

struct Node
{
    int value;
    Node *left;
    Node *right;
    Node *parent;
};

struct BinarySearchTree
{
    Node *root;
    int size;
    Node *(*get)(BinarySearchTree *self, int item);
    void (*add)(BinarySearchTree *self, int item);
    void (*print_items_postorder)(BinarySearchTree *self);
    void (*print_items_preorder)(BinarySearchTree *self);
    void (*print_items_inorder)(BinarySearchTree *self);
};

BinarySearchTree *initialize_binary_search_tree();
void release_binary_search_tree(BinarySearchTree *binary_search_tree);

void add(BinarySearchTree *self, int item);
Node *get(BinarySearchTree *self, int item);
void print_items_postorder(BinarySearchTree *self);
void print_items_preorder(BinarySearchTree *self);
void print_items_inorder(BinarySearchTree *self);

Node *initialize_node(int item);
void traverse_post_order_and_release_nodes(Node *node);
Node *traverse_and_add(BinarySearchTree *self, Node *node, int item);
Node *traverse_and_get(Node *node, int item);
void traverse_postorder_and_print_nodes(Node *node);
void traverse_preorder_and_print_nodes(Node *node);
void traverse_inorder_and_print_nodes(Node *node);

int main()
{
    BinarySearchTree *binary_search_tree = initialize_binary_search_tree();

    binary_search_tree->add(binary_search_tree, 50);
    binary_search_tree->add(binary_search_tree, 40);
    binary_search_tree->add(binary_search_tree, 60);
    binary_search_tree->add(binary_search_tree, 600);
    binary_search_tree->add(binary_search_tree, 1);
    binary_search_tree->add(binary_search_tree, 6);
    binary_search_tree->add(binary_search_tree, 500);

    binary_search_tree->print_items_postorder(binary_search_tree);
    binary_search_tree->print_items_preorder(binary_search_tree);
    binary_search_tree->print_items_inorder(binary_search_tree);

    Node *found = binary_search_tree->get(binary_search_tree, 6);

    printf("\nThe value found was: %d\n", found->value);

    release_binary_search_tree(binary_search_tree);

    return 0;
}

BinarySearchTree *initialize_binary_search_tree()
{
    BinarySearchTree *binary_search_tree = malloc(sizeof(BinarySearchTree));

    binary_search_tree->size = 0;
    binary_search_tree->root = NULL;

    binary_search_tree->add = &add;
    binary_search_tree->print_items_postorder = &print_items_postorder;
    binary_search_tree->print_items_preorder = &print_items_preorder;
    binary_search_tree->print_items_inorder = &print_items_inorder;
    binary_search_tree->get = &get;

    return binary_search_tree;
}

void release_binary_search_tree(BinarySearchTree *binary_search_tree)
{
    traverse_post_order_and_release_nodes(binary_search_tree->root);
    free(binary_search_tree);
}

void traverse_post_order_and_release_nodes(Node *node)
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

Node *initialize_node(int item)
{
    Node *node = malloc(sizeof(Node));
    node->value = item;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;

    return node;
}

Node *traverse_and_add(BinarySearchTree *self, Node *node, int item)
{
    if (node == NULL)
    {
        self->size = self->size + 1;
        return initialize_node(item);
    }

    if (item > node->value)
    {
        node->right = traverse_and_add(self, node->right, item);
        node->right->parent = node;
    }
    else if (item < node->value)
    {
        node->left = traverse_and_add(self, node->left, item);
        node->left->parent = node;
    }

    return node;
}

// O(n) = time complexity
void add(BinarySearchTree *self, int item)
{
    self->root = traverse_and_add(self, self->root, item);
}

// O(n) = time complexity
void print_items_postorder(BinarySearchTree *self)
{
    printf("\n------------  BinarySearchTree  POSTORDER  ---------------\n");
    traverse_postorder_and_print_nodes(self->root);
}

// O(n) = time complexity
void print_items_preorder(BinarySearchTree *self)
{
    printf("\n------------  BinarySearchTree  PREORDER  ---------------\n");
    traverse_preorder_and_print_nodes(self->root);
}

// O(n) = time complexity
void print_items_inorder(BinarySearchTree *self)
{
    printf("\n------------  BinarySearchTree  INORDER  ---------------\n");
    traverse_inorder_and_print_nodes(self->root);
}

void traverse_postorder_and_print_nodes(Node *node)
{
    if (node == NULL)
    {
        return;
    }

    if (node->left != NULL)
    {
        traverse_postorder_and_print_nodes(node->left);
    }

    if (node->right != NULL)
    {
        traverse_postorder_and_print_nodes(node->right);
    }

    printf("%d,", node->value);
}

void traverse_preorder_and_print_nodes(Node *node)
{
    if (node == NULL)
    {
        return;
    }

    printf("%d,", node->value);

    if (node->left != NULL)
    {
        traverse_preorder_and_print_nodes(node->left);
    }

    if (node->right != NULL)
    {
        traverse_preorder_and_print_nodes(node->right);
    }
}

void traverse_inorder_and_print_nodes(Node *node)
{
    if (node == NULL)
    {
        return;
    }

    if (node->left != NULL)
    {
        traverse_inorder_and_print_nodes(node->left);
    }

    printf("%d,", node->value);

    if (node->right != NULL)
    {
        traverse_inorder_and_print_nodes(node->right);
    }
}

Node *traverse_and_get(Node *node, int item)
{
    if (node == NULL)
    {
        return NULL;
    }

    if (node->value == item)
    {
        return node;
    }
    else if (item < node->value)
    {
        return traverse_and_get(node->left, item);
    }
    else if (item > node->value)
    {
        return traverse_and_get(node->right, item);
    }
}

// O(n) = time complexity
Node *get(BinarySearchTree *self, int item)
{
    return traverse_and_get(self->root, item);
}

// Add delete process.
