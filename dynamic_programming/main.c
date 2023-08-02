#include <stdio.h>
#include <stdlib.h>

// ------------- STACK ------------//

typedef struct Stack Stack;
typedef struct Node Node;

struct Node
{
    int value;
    int lower_bound_index;
    int upper_bound_index;
    Node *next;
};

struct Stack
{
    Node *first;
    Node *last;
    int size;
    int max_capacity;
    Node *(*peek)(Stack *self);
    void (*push)(Stack *self, Node *node);
    Node *(*pop)(Stack *self);
    void (*print_items)(Stack *self);
};

Stack *initialize_stack(int max_capacity);
void release_stack(Stack *stack);

Node *peek(Stack *self);
void push(Stack *self, Node *item);
Node *pop(Stack *self);
void print_items(Stack *self);

void traverse_post_order_and_release_nodes(Node *node);
void traverse_pre_order_and_print_nodes(Node *node);

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

void push(Stack *self, Node *node)
{
    if (self->size >= self->max_capacity)
    {
        return;
    }

    node->next = NULL;

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

// ------------- QUICKSORT ------------//

void swap(int origin_index, int destination_index);
void print_numbers();

int partition_index(int lower_bound_index, int upper_bound_index);
void quicksort(Stack *stack, int lower_bound_index, int upper_bound_index);
int select_pivot_index(int lower_bound_index, int upper_bound_index);

int numbers[] = {1, 20, 300, 45, 15, 6, 77, 28, 9, 100};
// int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int numbers_size = 10;

int operations_counter = 0;
int operations_in_general_counter = 0;

int main()
{
    Stack *stack = initialize_stack(100);
    operations_counter = 0;
    operations_in_general_counter = 0;

    printf("\nBefore quicksort sorting");
    print_numbers();
    quicksort(stack, 0, numbers_size - 1);
    printf("\nAfter quicksort sorting");
    print_numbers();

    return 0;
}

void swap(int origin_index, int destination_index)
{
    int temp = numbers[origin_index];
    numbers[origin_index] = numbers[destination_index];
    numbers[destination_index] = temp;
}

void print_numbers()
{
    printf("\n----------------------------\n");
    for (int i = 0; i < numbers_size; i++)
    {
        printf("%d, ", numbers[i]);
    }
}

int select_pivot_index(int lower_bound_index, int upper_bound_index)
{
    return (lower_bound_index + upper_bound_index) / 2;
}

int partition_index(int lower_bound_index, int upper_bound_index)
{
    int pivot_index = select_pivot_index(lower_bound_index, upper_bound_index);
    int pivot = numbers[pivot_index];
    int last_changed_index = lower_bound_index - 1;

    for (int i = lower_bound_index; i <= upper_bound_index; i++)
    {
        operations_in_general_counter = operations_in_general_counter + 1;

        int current_number = numbers[i];
        int last_changed_number = numbers[last_changed_index];

        if (current_number < pivot)
        {
            operations_counter = operations_counter + 1;

            last_changed_index = last_changed_index + 1;

            swap(i, last_changed_index);

            if (last_changed_index == pivot_index)
            {
                pivot_index = i;
            }
        }
    }

    last_changed_index = last_changed_index + 1;

    swap(pivot_index, last_changed_index);

    return last_changed_index;
}
// O(n * n) = O(n ^ 2)
// avg.(n * log n)
void quicksort(Stack *stack, int lower_bound_index, int upper_bound_index)
{
    Node *node = malloc(sizeof(Node));
    node->value = stack->size + 1;
    node->lower_bound_index = lower_bound_index;
    node->upper_bound_index = upper_bound_index;

    stack->push(stack, node);

    while (stack->size > 0)
    {
        Node *current_args = stack->pop(stack);

        if (current_args->upper_bound_index <= current_args->lower_bound_index)
        {
            continue;
        }

        int pivot_index = partition_index(current_args->lower_bound_index, current_args->upper_bound_index);

        Node *right_array_elements_node = malloc(sizeof(Node));
        right_array_elements_node->value = stack->size + 1;
        right_array_elements_node->lower_bound_index = pivot_index + 1;
        right_array_elements_node->upper_bound_index = current_args->upper_bound_index;

        stack->push(stack, right_array_elements_node);

        Node *left_array_elements_node = malloc(sizeof(Node));
        left_array_elements_node->value = stack->size + 1;
        left_array_elements_node->lower_bound_index = current_args->lower_bound_index;
        left_array_elements_node->upper_bound_index = pivot_index - 1;

        stack->push(stack, left_array_elements_node);

        free(current_args);
    }

    // quicksort(lower_bound_index, pivot_index - 1);
    // quicksort(pivot_index + 1, upper_bound_index);
}
