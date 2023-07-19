#include <stdio.h>
#include <stdlib.h>

typedef struct Stack Stack;
typedef struct Node Node;

struct Node
{
    int value;
    Node *next;
};

struct Stack
{
    Node *first;
    Node *last;
    int size;
    int max_capacity;
    Node *(*peek)(Stack *self);
    void (*push)(Stack *self, int item);
    Node *(*pop)(Stack *self);
    void (*print_items)(Stack *self);
};

Stack *initialize_stack(int max_capacity);
void release_stack(Stack *stack);

Node *peek(Stack *self);
void push(Stack *self, int item);
Node *pop(Stack *self);
void print_items(Stack *self);

void traverse_post_order_and_release_nodes(Node *node);
void traverse_pre_order_and_print_nodes(Node *node);

int main()
{
    Stack *stack = initialize_stack(10);

    for (int i = 0; i < 5; i++)
    {
        stack->push(stack, i * 2);
    }

    stack->print_items(stack);

    Node *node = stack->peek(stack);

    printf("\nNext element to pop: %d", node->value);

    node = stack->pop(stack);

    printf("\nElement popped: %d", node->value);

    stack->print_items(stack);

    release_stack(stack);

    return 0;
}

Stack *initialize_stack(int max_capacity)
{
    Stack *stack = malloc(sizeof(Stack));

    stack->size = 0;
    stack->max_capacity = max_capacity;
    stack->first = NULL;
    stack->last = NULL;

    stack->peek = &peek;
    stack->push = &push;
    stack->pop = &pop;
    stack->print_items = &print_items;

    return stack;
}

void release_stack(Stack *stack)
{
    traverse_post_order_and_release_nodes(stack->first);
    free(stack);
}

void traverse_post_order_and_release_nodes(Node *node)
{
    if (node == NULL)
    {
        return;
    }

    if (node->next != NULL)
    {
        traverse_post_order_and_release_nodes(node->next);
    }

    free(node);
}

void traverse_pre_order_and_print_nodes(Node *node)
{
    if (node == NULL)
    {
        return;
    }

    printf("%d,", node->value);

    if (node->next != NULL)
    {
        traverse_pre_order_and_print_nodes(node->next);
    }
}

void print_items(Stack *self)
{
    printf("\n ----- STACK -------\n");
    traverse_pre_order_and_print_nodes(self->first);
}

void push(Stack *self, int item)
{
    if (self->size >= self->max_capacity)
    {
        return;
    }

    Node *node = malloc(sizeof(Node));
    node->next = NULL;
    node->value = item;

    if (self->first == NULL)
    {
        self->first = node;
        self->last = node;
    }
    else
    {
        node->next = self->first;
        self->first = node;
    }

    self->size = self->size + 1;
}

Node *pop(Stack *self)
{
    if (self->first == NULL)
    {
        return NULL;
    }

    Node *node_to_pop = self->first;
    self->first = node_to_pop->next;

    self->size = self->size - 1;

    return node_to_pop;
}

Node *peek(Stack *self)
{
    return self->first;
}

// Implement this using an arraY instead of a linked list
// and compare the complexity
