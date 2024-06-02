#include <stdio.h>
#include <stdlib.h>

typedef struct BinarySearchTree BinarySearchTree;
typedef struct Node Node;

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

struct Node
{
    Node *left;
    Node *right;
    Node *parent;
    int item;
};

BinarySearchTree *initialize_binary_search_tree();
void release_binary_search_tree(BinarySearchTree *binary_search_tree);

Node *get(BinarySearchTree *self, int item);
void add(BinarySearchTree *self, int item);
void print_items_postorder(BinarySearchTree *self);
void print_items_preorder(BinarySearchTree *self);
void print_items_inorder(BinarySearchTree *self);

void traverse_post_order_and_realease_nodes(Node *node);
Node *initialize_node(int item);
Node *traverse_and_add(BinarySearchTree *self, Node *node, int item);
Node *traverse_and_get(BinarySearchTree *self, Node *node, int item);
void traverse_and_print_items_postorder(Node *node);
void traverse_and_print_items_preorder(Node *node);
void traverse_and_print_items_inorder(Node *node);

int main()
{
    BinarySearchTree *binary_search_tree = initialize_binary_search_tree();

    binary_search_tree->add(binary_search_tree, 20);
    binary_search_tree->add(binary_search_tree, 10);
    binary_search_tree->add(binary_search_tree, 30);
    binary_search_tree->add(binary_search_tree, 15);
    binary_search_tree->add(binary_search_tree, 25);
    binary_search_tree->add(binary_search_tree, 3);
    binary_search_tree->add(binary_search_tree, 1);
    binary_search_tree->add(binary_search_tree, 18);
    binary_search_tree->add(binary_search_tree, 27);
    binary_search_tree->add(binary_search_tree, 14);
    binary_search_tree->add(binary_search_tree, 24);

    binary_search_tree->print_items_postorder(binary_search_tree);
    binary_search_tree->print_items_preorder(binary_search_tree);
    binary_search_tree->print_items_inorder(binary_search_tree);

    Node *node_found = binary_search_tree->get(binary_search_tree, 27);
    printf("\nnode_found = %d", node_found->item);

    release_binary_search_tree(binary_search_tree);

    return 0;
}

BinarySearchTree *initialize_binary_search_tree()
{
    BinarySearchTree *binary_search_tree = malloc(sizeof(BinarySearchTree));

    binary_search_tree->size = 0;
    binary_search_tree->root = NULL;

    binary_search_tree->get = &get;
    binary_search_tree->add = &add;
    binary_search_tree->print_items_postorder = &print_items_postorder;
    binary_search_tree->print_items_preorder = &print_items_preorder;
    binary_search_tree->print_items_inorder = &print_items_inorder;

    return binary_search_tree;
}

void release_binary_search_tree(BinarySearchTree *binary_search_tree)
{
    traverse_post_order_and_realease_nodes(binary_search_tree->root);
    free(binary_search_tree);
}

void traverse_post_order_and_realease_nodes(Node *node)
{
    if (node == NULL)
    {
        return;
    }

    if (node->left != NULL)
    {
        traverse_post_order_and_realease_nodes(node->left);
    }

    if (node->right != NULL)
    {
        traverse_post_order_and_realease_nodes(node->right);
    }

    free(node);
}

Node *initialize_node(int item)
{
    Node *node = malloc(sizeof(Node));

    node->item = item;
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

Node *traverse_and_get(BinarySearchTree *self, Node *node, int item)
{
    if (node == NULL)
    {
        return NULL;
    }

    if (item > node->item)
    {
        return traverse_and_get(self, node->right, item);
    }
    else if (item < node->item)
    {
        return traverse_and_get(self, node->left, item);
    }

    return node;
}

Node *get(BinarySearchTree *self, int item)
{
    return traverse_and_get(self, self->root, item);
}

void traverse_and_print_items_postorder(Node *node)
{
    if (node == NULL)
    {
        return;
    }

    if (node->left != NULL)
    {
        traverse_and_print_items_postorder(node->left);
    }

    if (node->right != NULL)
    {
        traverse_and_print_items_postorder(node->right);
    }

    printf("%d,", node->item);
}

void traverse_and_print_items_preorder(Node *node)
{
    if (node == NULL)
    {
        return;
    }

    printf("%d,", node->item);

    if (node->left != NULL)
    {
        traverse_and_print_items_preorder(node->left);
    }

    if (node->right != NULL)
    {
        traverse_and_print_items_preorder(node->right);
    }
}

void traverse_and_print_items_inorder(Node *node)
{
    if (node == NULL)
    {
        return;
    }

    if (node->left != NULL)
    {
        traverse_and_print_items_inorder(node->left);
    }

    printf("%d,", node->item);

    if (node->right != NULL)
    {
        traverse_and_print_items_inorder(node->right);
    }
}

void print_items_postorder(BinarySearchTree *self)
{
    printf("\n------------- Binary Search Tree POST-ORDER -------------------\n");
    traverse_and_print_items_postorder(self->root);
}
void print_items_preorder(BinarySearchTree *self)
{
    printf("\n------------- Binary Search Tree PRE-ORDER -------------------\n");
    traverse_and_print_items_preorder(self->root);
}
void print_items_inorder(BinarySearchTree *self)
{
    printf("\n------------- Binary Search Tree IN-ORDER -------------------\n");
    traverse_and_print_items_inorder(self->root);
}