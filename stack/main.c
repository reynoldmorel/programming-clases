#include <stdio.h>
#include <stdlib.h>

typedef struct Stack Stack;
typedef struct StackNode StackNode;

struct Stack
{
    StackNode *first;
    int size;
    int (*peek)(Stack *self);
    void (*push)(Stack *self, int item);
    int (*pop)(Stack *self);
    void (*print_items)(Stack *self);
};

struct StackNode
{
    StackNode *next;
    int item;
};

Stack *initialize_stack();
void release_stack(Stack *stack);

int peek(Stack *self);
void push(Stack *self, int item);
int pop(Stack *self);
void print_items(Stack *self);

void traverse_post_order_and_realease_nodes(StackNode *node);
void traverse_pre_order_and_print_nodes(StackNode *node);

int main()
{
    Stack *stack = initialize_stack();

    for (int i = 0; i < 10; i++)
    {
        stack->push(stack, i * 10);
    }

    stack->print_items(stack);
    printf("\npeek = %d\n", stack->peek(stack));

    printf("\npop = %d\n", stack->pop(stack));
    stack->print_items(stack);

    release_stack(stack);

    return 0;
}

Stack *initialize_stack()
{
    Stack *stack = malloc(sizeof(Stack));

    stack->size = 0;
    stack->first = NULL;

    stack->peek = &peek;
    stack->push = &push;
    stack->pop = &pop;
    stack->print_items = &print_items;

    return stack;
}

void release_stack(Stack *stack)
{
    traverse_post_order_and_realease_nodes(stack->first);
    free(stack);
}

void traverse_post_order_and_realease_nodes(StackNode *node)
{
    if (node == NULL)
    {
        return;
    }

    if (node->next != NULL)
    {
        traverse_post_order_and_realease_nodes(node->next);
    }

    free(node);
}

// Time Complexity
// O(1)
// Space Complexity
// O(1)
int peek(Stack *self)
{
    if (self->first == NULL)
    {
        return -1;
    }

    return self->first->item;
}

// Time Complexity
// O(1)
// Space Complexity
// O(1)
void push(Stack *self, int item)
{
    StackNode *node = malloc(sizeof(StackNode));
    node->next = self->first;
    node->item = item;

    self->first = node;

    self->size = self->size + 1;
}

// Time Complexity
// O(1)
// Space Complexity
// O(1)
int pop(Stack *self)
{
    StackNode *node_to_delete = self->first;
    StackNode *next_node = node_to_delete->next;
    int item = node_to_delete->item;

    self->first = next_node;

    free(node_to_delete);

    self->size = self->size - 1;

    return item;
}

// Time Complexity
// O(n)
// Space Complexity
// O(1)
void print_items(Stack *self)
{
    printf("\n[");

    traverse_pre_order_and_print_nodes(self->first);

    printf("]\n");
}

void traverse_pre_order_and_print_nodes(StackNode *node)
{
    if (node == NULL)
    {
        return;
    }

    printf("%d, ", node->item);

    if (node->next != NULL)
    {
        traverse_pre_order_and_print_nodes(node->next);
    }
}
