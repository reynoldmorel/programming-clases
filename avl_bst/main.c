#include <stdio.h>
#include <stdlib.h>

typedef struct AvlBinarySearchTree AvlBinarySearchTree;
typedef struct Node Node;

struct AvlBinarySearchTree
{
    Node *root;
    int size;
    Node *(*get)(AvlBinarySearchTree *self, int item);
    void (*add)(AvlBinarySearchTree *self, int item);
    void (*print_items_postorder)(AvlBinarySearchTree *self);
    void (*print_items_preorder)(AvlBinarySearchTree *self);
    void (*print_items_inorder)(AvlBinarySearchTree *self);
};

struct Node
{
    Node *left;
    Node *right;
    Node *parent;
    int item;
    int height;
};

AvlBinarySearchTree *initialize_avl_binary_search_tree();
void release_avl_binary_search_tree(AvlBinarySearchTree *avl_binary_search_tree);

Node *get(AvlBinarySearchTree *self, int item);
void add(AvlBinarySearchTree *self, int item);
void print_items_postorder(AvlBinarySearchTree *self);
void print_items_preorder(AvlBinarySearchTree *self);
void print_items_inorder(AvlBinarySearchTree *self);

void traverse_post_order_and_realease_nodes(Node *node);
Node *initialize_node(int item);
Node *traverse_and_add(AvlBinarySearchTree *self, Node *node, int item);
Node *traverse_and_get(AvlBinarySearchTree *self, Node *node, int item);
void traverse_and_print_items_postorder(Node *node);
void traverse_and_print_items_preorder(Node *node);
void traverse_and_print_items_inorder(Node *node);

Node *rotate_right(Node *node);
Node *rotate_left(Node *node);
int get_balance(Node *node);
int get_height(Node *node);
int custom_max(int a, int b);
Node *update_parent(Node *node);

int main()
{
    AvlBinarySearchTree *avl_binary_search_tree = initialize_avl_binary_search_tree();

    avl_binary_search_tree->add(avl_binary_search_tree, 75);
    avl_binary_search_tree->add(avl_binary_search_tree, 42);
    avl_binary_search_tree->add(avl_binary_search_tree, 76);
    avl_binary_search_tree->add(avl_binary_search_tree, 30);
    avl_binary_search_tree->add(avl_binary_search_tree, 43);
    avl_binary_search_tree->add(avl_binary_search_tree, 26);
    avl_binary_search_tree->add(avl_binary_search_tree, 50);
    avl_binary_search_tree->add(avl_binary_search_tree, 500);
    avl_binary_search_tree->add(avl_binary_search_tree, 150);
    avl_binary_search_tree->add(avl_binary_search_tree, 80);
    avl_binary_search_tree->add(avl_binary_search_tree, 45);

    avl_binary_search_tree->print_items_postorder(avl_binary_search_tree);
    avl_binary_search_tree->print_items_preorder(avl_binary_search_tree);
    avl_binary_search_tree->print_items_inorder(avl_binary_search_tree);

    Node *node_found = avl_binary_search_tree->get(avl_binary_search_tree, 26);
    printf("\nnode_found = %d", node_found->item);

    release_avl_binary_search_tree(avl_binary_search_tree);

    return 0;
}

AvlBinarySearchTree *initialize_avl_binary_search_tree()
{
    AvlBinarySearchTree *avl_binary_search_tree = malloc(sizeof(AvlBinarySearchTree));

    avl_binary_search_tree->size = 0;
    avl_binary_search_tree->root = NULL;

    avl_binary_search_tree->get = &get;
    avl_binary_search_tree->add = &add;
    avl_binary_search_tree->print_items_postorder = &print_items_postorder;
    avl_binary_search_tree->print_items_preorder = &print_items_preorder;
    avl_binary_search_tree->print_items_inorder = &print_items_inorder;

    return avl_binary_search_tree;
}

void release_avl_binary_search_tree(AvlBinarySearchTree *avl_binary_search_tree)
{
    traverse_post_order_and_realease_nodes(avl_binary_search_tree->root);
    free(avl_binary_search_tree);
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
    node->height = 1;

    return node;
}

Node *traverse_and_add(AvlBinarySearchTree *self, Node *node, int item)
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

    printf("\n -------- height = %d ----------- \n", node->height);

    if (balance > 1 && item < node->left->item)
    {
        printf("rotate_right \n");
        Node *rotated_node = rotate_right(node);
        return update_parent(rotated_node);
    }
    else if (balance < -1 && item > node->right->item)
    {
        printf("rotate_left \n");
        Node *rotated_node = rotate_left(node);
        return update_parent(rotated_node);
    }
    else if (balance > 1 && item > node->left->item)
    {
        printf("rotate_left_right \n");
        node->left = rotate_left(node->left);
        node->left = update_parent(node->left);

        Node *rotated_node = rotate_right(node);
        return update_parent(rotated_node);
    }
    else if (balance < -1 && item < node->right->item)
    {
        printf("rotate_right_left \n");
        node->right = rotate_right(node->right);
        node->right = update_parent(node->right);

        Node *rotated_node = rotate_left(node);
        return update_parent(rotated_node);
    }

    return node;
}

void add(AvlBinarySearchTree *self, int item)
{
    self->root = traverse_and_add(self, self->root, item);
    self->root->parent = NULL;
}

Node *traverse_and_get(AvlBinarySearchTree *self, Node *node, int item)
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

Node *get(AvlBinarySearchTree *self, int item)
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

void print_items_postorder(AvlBinarySearchTree *self)
{
    printf("\n------------- Binary Search Tree POST-ORDER -------------------\n");
    traverse_and_print_items_postorder(self->root);
}
void print_items_preorder(AvlBinarySearchTree *self)
{
    printf("\n------------- Binary Search Tree PRE-ORDER -------------------\n");
    traverse_and_print_items_preorder(self->root);
}
void print_items_inorder(AvlBinarySearchTree *self)
{
    printf("\n------------- Binary Search Tree IN-ORDER -------------------\n");
    traverse_and_print_items_inorder(self->root);
}

int get_height(Node *node)
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

int get_balance(Node *node)
{
    if (node == NULL)
    {
        return 0;
    }

    return get_height(node->left) - get_height(node->right);
}

Node *update_parent(Node *node)
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

Node *rotate_right(Node *node)
{
    Node *left_node = node->left;
    Node *left_right_node = left_node->right;

    left_node->right = node;
    node->left = left_right_node;

    node->height = custom_max(get_height(node->left), get_height(node->right)) + 1;

    return left_node;
}

Node *rotate_left(Node *node)
{
    Node *right_node = node->right;
    Node *right_left_node = right_node->left;

    right_node->left = node;
    node->right = right_left_node;

    node->height = custom_max(get_height(node->left), get_height(node->right)) + 1;

    return right_node;
}