#include <stdio.h>
#include <stdlib.h>

typedef struct Queue Queue;
typedef struct Node Node;

struct Node
{
    int value;
    Node *next;
};

struct Queue
{
    Node *first;
    Node *last;
    int size;
    int max_capacity;
    Node *(*peek)(Queue *self);
    void (*enqueue)(Queue *self, int item);
    Node *(*dequeue)(Queue *self);
    void (*print_items)(Queue *self);
};

Queue *initialize_queue(int max_capacity);
void release_queue(Queue *queue);

Node *peek(Queue *self);
void enqueue(Queue *self, int item);
Node *dequeue(Queue *self);
void print_items(Queue *self);

void traverse_post_order_and_release_nodes(Node *node);
void traverse_pre_order_and_print_nodes(Node *node);

int main()
{
    Queue *queue = initialize_queue(10);

    for (int i = 0; i < 5; i++)
    {
        queue->enqueue(queue, i * 2);
    }

    queue->print_items(queue);

    Node *node = queue->peek(queue);

    printf("\nNext element to dequeue: %d", node->value);

    node = queue->dequeue(queue);

    printf("\nElement dequeued: %d", node->value);

    queue->print_items(queue);

    release_queue(queue);

    return 0;
}

Queue *initialize_queue(int max_capacity)
{
    Queue *queue = malloc(sizeof(Queue));

    queue->size = 0;
    queue->max_capacity = max_capacity;
    queue->first = NULL;
    queue->last = NULL;

    queue->peek = &peek;
    queue->enqueue = &enqueue;
    queue->dequeue = &dequeue;
    queue->print_items = &print_items;

    return queue;
}

void release_queue(Queue *queue)
{
    traverse_post_order_and_release_nodes(queue->first);
    free(queue);
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

void print_items(Queue *self)
{
    printf("\n ----- QUEUE -------\n");
    traverse_pre_order_and_print_nodes(self->first);
}

void enqueue(Queue *self, int item)
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
        self->last->next = node;
        self->last = node;
    }

    self->size = self->size + 1;
}

Node *dequeue(Queue *self)
{
    if (self->first == NULL)
    {
        return NULL;
    }

    Node *node_to_dequeue = self->first;
    self->first = node_to_dequeue->next;

    self->size = self->size - 1;

    return node_to_dequeue;
}

Node *peek(Queue *self)
{
    return self->first;
}

// Implement this using an arraY instead of a linked list
// and compare the complexity
