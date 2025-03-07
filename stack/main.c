#include <stdio.h>
#include <stdlib.h>

typedef struct Stack Stack;
typedef struct StackNode StackNode;

struct Stack
{
    StackNode *first;
    StackNode *last;
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
void traverse_post_order_and_release_nodes(StackNode *node);
void release_stack(Stack *stack);

int peek(Stack *self);
void push(Stack *self, int item);
int pop(Stack *self);
void print_items(Stack *self);
void traverse_pre_order_and_print_nodes(StackNode *node);

int main()
{
    Stack *stack = initialize_stack();

    for (int i = 0; i < 10; i++)
    {
        stack->push(stack, i + 1);
    }

    printf("Printing stack ...\n");
    stack->print_items(stack);

    printf("stack->peek(stack)=%d\n", stack->peek(stack));

    printf("Popping next element ...\n");
    stack->pop(stack);

    printf("stack->peek(stack)=%d\n", stack->peek(stack));

    printf("Printing stack ...\n");
    stack->print_items(stack);

    release_stack(stack);

    return 0;
}

Stack *initialize_stack()
{
    Stack *stack = malloc(sizeof(Stack));

    stack->size = 0;
    stack->first = NULL;
    stack->last = NULL;

    stack->push = &push;
    stack->peek = &peek;
    stack->pop = &pop;
    stack->print_items = &print_items;

    return stack;
}

void traverse_post_order_and_release_nodes(StackNode *node)
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

void release_stack(Stack *stack)
{
    traverse_post_order_and_release_nodes(stack->first);
    free(stack);
};

int peek(Stack *self)
{
    if(self->first == NULL)
    {
        return -1;
    };

    return self->first->item;
}

void push(Stack *self, int item)
{
    StackNode *node = malloc(sizeof(StackNode));
    node->next = self->first;
    node->item = item;
    self->first = node;

    self->size = self->size + 1;
}

int pop(Stack *self)
{
    StackNode *node_to_delete = self->first;
    self->first = self->first->next;
    int item = node_to_delete->item;

    free(node_to_delete);

    self->size = self->size - 1;

    return item;
}

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
