#include <stdio.h>
#include <stdlib.h>

typedef struct Queue Queue;
typedef struct QueueNode QueueNode;

struct Queue
{
    QueueNode *first;
    QueueNode *last;
    int size;
    int (*peek)(Queue *self);
    void (*enqueue)(Queue *self, int item);
    int (*dequeue)(Queue *self);
    void (*print_items)(Queue *self);
};

struct QueueNode
{
    QueueNode *next;
    int item;
};

Queue *initialize_queue();
void release_queue(Queue *queue);

int peek(Queue *self);
void enqueue(Queue *self, int item);
int dequeue(Queue *self);
void print_items(Queue *self);

void traverse_post_order_and_realease_nodes(QueueNode *node);
void traverse_pre_order_and_print_nodes(QueueNode *node);

int main()
{
    Queue *queue = initialize_queue();

    for (int i = 0; i < 10; i++)
    {
        queue->enqueue(queue, i * 10);
    }

    queue->print_items(queue);
    printf("\npeek = %d\n", queue->peek(queue));

    printf("\ndequeue = %d\n", queue->dequeue(queue));
    queue->print_items(queue);

    release_queue(queue);

    return 0;
}

Queue *initialize_queue()
{
    Queue *queue = malloc(sizeof(Queue));

    queue->size = 0;
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
    traverse_post_order_and_realease_nodes(queue->first);
    free(queue);
}

void traverse_post_order_and_realease_nodes(QueueNode *node)
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
int peek(Queue *self)
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
void enqueue(Queue *self, int item)
{
    QueueNode *node = malloc(sizeof(QueueNode));
    node->next = NULL;
    node->item = item;

    if (self->first == NULL)
    {
        self->first = node;
        self->last = node;
    } else {
        self->last->next = node;
        self->last = node;
    }

    self->size = self->size + 1;
}

// Time Complexity
// O(1)
// Space Complexity
// O(1)
int dequeue(Queue *self)
{
    QueueNode *node_to_delete = self->first;
    QueueNode *next_node = node_to_delete->next;
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
void print_items(Queue *self)
{
    printf("\n[");

    traverse_pre_order_and_print_nodes(self->first);

    printf("]\n");
}

void traverse_pre_order_and_print_nodes(QueueNode *node)
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
