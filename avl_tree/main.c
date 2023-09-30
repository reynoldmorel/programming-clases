#include <stdio.h>
#include <stdlib.h>

typedef struct AvlTree AvlTree;
typedef struct Node Node;

struct Node
{
    int value;
    Node *left;
    Node *right;
    Node *parent;
    int height;
};

struct AvlTree
{
    Node *root;
    int size;
    void (*delete)(AvlTree *self, int item);
    Node *(*get)(AvlTree *self, int item);
    void (*add)(AvlTree *self, int item);
    void (*print_items_postorder)(AvlTree *self);
    void (*print_items_preorder)(AvlTree *self);
    void (*print_items_inorder)(AvlTree *self);
};

AvlTree *initialize_avl_tree();
void release_avl_tree(AvlTree *avl_tree);

void add(AvlTree *self, int item);
Node *get(AvlTree *self, int item);
void print_items_postorder(AvlTree *self);
void print_items_preorder(AvlTree *self);
void print_items_inorder(AvlTree *self);

Node *initialize_node(int item);
void traverse_post_order_and_release_nodes(Node *node);
Node *traverse_and_add(AvlTree *self, Node *node, int item);
Node *traverse_and_get(Node *node, int item);
void traverse_postorder_and_print_nodes(Node *node);
void traverse_preorder_and_print_nodes(Node *node);
void traverse_inorder_and_print_nodes(Node *node);

Node *traverse_and_delete(AvlTree *self, Node *node, int item);
void delete(AvlTree *self, int item);

Node *right_rotate(Node *node);
Node *left_rotate(Node *node);

int get_height(Node *node);
int custom_max(int a, int b);
int get_balance(Node *node);
Node *update_parent(Node *node);

int main()
{
    AvlTree *avl_tree = initialize_avl_tree();

    avl_tree->add(avl_tree, 30);
    avl_tree->add(avl_tree, 5);
    avl_tree->add(avl_tree, 14);
    avl_tree->add(avl_tree, 20);
    avl_tree->add(avl_tree, 50);
    avl_tree->add(avl_tree, 80);
    avl_tree->add(avl_tree, 12);
    avl_tree->add(avl_tree, 9);

    avl_tree->print_items_postorder(avl_tree);
    avl_tree->print_items_preorder(avl_tree);
    avl_tree->print_items_inorder(avl_tree);

    Node *found = avl_tree->get(avl_tree, 5);

    printf("\nThe value found was: %d\n", found->value);

    printf("\nRoot node: %d\n", avl_tree->root->value);
    printf("\nLeft node: %d\n", avl_tree->root->left->value);
    printf("\nRight node: %d\n", avl_tree->root->right->value);
    printf("\nRight Right node: %d\n", avl_tree->root->right->right->value);

    printf("\nAbout to delete: %d\n", 50);
    avl_tree->delete (avl_tree, 50);

    avl_tree->print_items_postorder(avl_tree);
    avl_tree->print_items_preorder(avl_tree);
    avl_tree->print_items_inorder(avl_tree);

    printf("\n\nRoot node: %d\n", avl_tree->root->value);
    printf("\nLeft node: %d\n", avl_tree->root->left->value);
    printf("\nRight node: %d\n", avl_tree->root->right->value);
    printf("\nSize: %d\n", avl_tree->size);

    release_avl_tree(avl_tree);

    return 0;
}

AvlTree *initialize_avl_tree()
{
    AvlTree *avl_tree = malloc(sizeof(AvlTree));

    avl_tree->size = 0;
    avl_tree->root = NULL;

    avl_tree->add = &add;
    avl_tree->print_items_postorder = &print_items_postorder;
    avl_tree->print_items_preorder = &print_items_preorder;
    avl_tree->print_items_inorder = &print_items_inorder;
    avl_tree->get = &get;
    avl_tree->delete = &delete;

    return avl_tree;
}

void release_avl_tree(AvlTree *avl_tree)
{
    traverse_post_order_and_release_nodes(avl_tree->root);
    free(avl_tree);
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
    node->height = 1;

    return node;
}

Node *traverse_and_add(AvlTree *self, Node *node, int item)
{
    if (node == NULL)
    {
        self->size = self->size + 1;
        return initialize_node(item);
    }

    if (item > node->value)
    {
        node->right = traverse_and_add(self, node->right, item);
    }
    else if (item < node->value)
    {
        node->left = traverse_and_add(self, node->left, item);
    }

    node->height = custom_max(get_height(node->right), get_height(node->left)) + 1;

    int balance = get_balance(node);

    if (balance < -1 && item > node->right->value)
    {
        printf("left_rotate\n");
        Node *rotated_node = left_rotate(node);
        return update_parent(rotated_node);
    }
    else if (balance > 1 && item < node->left->value)
    {
        printf("right_rotate\n");
        Node *rotated_node = right_rotate(node);
        return update_parent(rotated_node);
    }
    else if (balance > 1 && item > node->left->value)
    {
        printf("left_rotate -> right_rotate\n");
        node->left = left_rotate(node->left);
        node->left = update_parent(node->left);

        Node *rotated_node = right_rotate(node);
        return update_parent(rotated_node);
    }
    else if (balance < -1 && item < node->right->value)
    {
        printf("right_rotate -> left_rotate\n");
        node->right = right_rotate(node->right);
        node->right = update_parent(node->right);

        Node *rotated_node = left_rotate(node);
        return update_parent(rotated_node);
    }

    return update_parent(node);
}

// O(log n) = time complexity
void add(AvlTree *self, int item)
{
    self->root = traverse_and_add(self, self->root, item);
    self->root->parent = NULL;
}

Node *traverse_and_delete(AvlTree *self, Node *node, int item)
{
    if (node == NULL)
    {
        return node;
    }

    // Normal BST delete
    if (node->value == item)
    {
        Node *node_to_replace = NULL;

        if (node->right != NULL && node->left != NULL)
        {

            node_to_replace = node->right;

            while (node_to_replace->left != NULL)
            {
                node_to_replace = node_to_replace->left;
            }

            node->value = node_to_replace->value;

            // Delete min node and update heights
            node->right = traverse_and_delete(self, node->right, node_to_replace->value);
        }
        else if (node->right == NULL || node->left == NULL)
        {
            if (node->right == NULL && node->left != NULL)
            {
                node->left->parent = node->parent;

                node_to_replace = node->left;
            }
            else if (node->right != NULL && node->left == NULL)
            {
                node->right->parent = node->parent;

                node_to_replace = node->right;
            }

            free(node);

            self->size = self->size - 1;

            node = node_to_replace;
        }
    }
    else if (item < node->value && node->left != NULL)
    {
        node->left = traverse_and_delete(self, node->left, item);
    }
    else if (item > node->value && node->right != NULL)
    {
        node->right = traverse_and_delete(self, node->right, item);
    }

    if (node == NULL)
    {
        return node;
    }

    // Propagate changes to upper nodes and update heights
    node->height = custom_max(get_height(node->right), get_height(node->left)) + 1;

    int balance = get_balance(node);

    if (balance < -1 && get_balance(node->right) <= 0)
    {
        printf("left_rotate\n");
        Node *rotated_node = left_rotate(node);
        return update_parent(rotated_node);
    }
    else if (balance > 1 && get_balance(node->left) >= 0)
    {
        printf("right_rotate\n");
        Node *rotated_node = right_rotate(node);
        return update_parent(rotated_node);
    }
    else if (balance > 1 && get_balance(node->left) < 0)
    {
        printf("left_rotate -> right_rotate\n");
        node->left = left_rotate(node->left);
        node->left = update_parent(node->left);

        Node *rotated_node = right_rotate(node);
        return update_parent(rotated_node);
    }
    else if (balance < -1 && get_balance(node->right) > 0)
    {
        printf("right_rotate -> left_rotate\n");
        node->right = right_rotate(node->right);
        node->right = update_parent(node->right);

        Node *rotated_node = left_rotate(node);
        return update_parent(rotated_node);
    }

    return update_parent(node);
}

// O(log n) = time complexity
void delete(AvlTree *self, int item)
{
    self->root = traverse_and_delete(self, self->root, item);
    self->root->parent = NULL;
}

// O(n) = time complexity
void print_items_postorder(AvlTree *self)
{
    printf("\n------------  AvlTree  POSTORDER  ---------------\n");
    traverse_postorder_and_print_nodes(self->root);
}

// O(n) = time complexity
void print_items_preorder(AvlTree *self)
{
    printf("\n------------  AvlTree  PREORDER  ---------------\n");
    traverse_preorder_and_print_nodes(self->root);
}

// O(n) = time complexity
void print_items_inorder(AvlTree *self)
{
    printf("\n------------  AvlTree  INORDER  ---------------\n");
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

// O(log n) = time complexity
Node *get(AvlTree *self, int item)
{
    return traverse_and_get(self->root, item);
}

Node *right_rotate(Node *node)
{
    Node *leftNode = node->left;
    Node *leftRightNode = leftNode->right;

    leftNode->right = node;
    node->left = leftRightNode;

    node->height = custom_max(get_height(node->right), get_height(node->left)) + 1;
    leftNode->height = custom_max(get_height(leftNode->right), get_height(leftNode->left)) + 1;

    return leftNode;
}

Node *left_rotate(Node *node)
{
    Node *rightNode = node->right;
    Node *rightLeftNode = rightNode->left;

    rightNode->left = node;
    node->right = rightLeftNode;

    node->height = custom_max(get_height(node->right), get_height(node->left)) + 1;
    rightNode->height = custom_max(get_height(rightNode->right), get_height(rightNode->left)) + 1;

    return rightNode;
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

// Add delete process.