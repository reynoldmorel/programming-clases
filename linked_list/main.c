#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedList LinkedList;
typedef struct Node Node;

struct Node
{
    int value;
    Node *next;
};

struct LinkedList
{
    Node *first;
    Node *last;
    int size;
    Node *(*get)(LinkedList *self, int index);
    void (*add)(LinkedList *self, int item);
    void (*delete)(LinkedList *self, int index);
    void (*insert)(LinkedList *self, int index, int item);
    void (*set)(LinkedList *self, int index, int item);
    void (*print_items)(LinkedList *self);
};

LinkedList *initialize_linked_list();
void release_linked_list(LinkedList *linked_list);

void add(LinkedList *self, int item);
Node *get(LinkedList *self, int index);
void print_items(LinkedList *self);
void insert(LinkedList *self, int index, int item);
void delete(LinkedList *self, int index);
void set(LinkedList *self, int index, int item);

void traverse_post_order_and_release_nodes(Node *node);
void traverse_pre_order_and_print_nodes(Node *node);
Node *traverse_and_get_node_by_index(Node *node, int index, int index_count);

int main()
{
    LinkedList *linked_list = initialize_linked_list();

    for (int i = 0; i < 5; i++)
    {
        linked_list->add(linked_list, i * 2);
    }

    linked_list->print_items(linked_list);

    Node *node = linked_list->get(linked_list, 3);

    printf("\nElement in pos. %d: %d", 3, node->value);

    linked_list->insert(linked_list, 2, 10);

    linked_list->print_items(linked_list);

    linked_list->delete (linked_list, 2);

    linked_list->print_items(linked_list);

    linked_list->set(linked_list, 2, 10);

    linked_list->print_items(linked_list);

    release_linked_list(linked_list);

    return 0;
}

LinkedList *initialize_linked_list()
{
    LinkedList *linked_list = malloc(sizeof(LinkedList));

    linked_list->size = 0;
    linked_list->first = NULL;
    linked_list->last = NULL;

    linked_list->add = &add;
    linked_list->get = &get;
    linked_list->print_items = &print_items;
    linked_list->insert = &insert;
    linked_list->delete = &delete;
    linked_list->set = &set;

    return linked_list;
}

void release_linked_list(LinkedList *linked_list)
{
    traverse_post_order_and_release_nodes(linked_list->first);
    free(linked_list);
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

// O(1) = time complexity
void add(LinkedList *self, int item)
{
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

void print_items(LinkedList *self)
{
    printf("\n ----- LINKED LIST -------\n");
    traverse_pre_order_and_print_nodes(self->first);
}

Node *traverse_and_get_node_by_index(Node *node, int index, int index_count)
{
    if (node == NULL)
    {
        return;
    }

    if (index == index_count)
    {
        return node;
    }

    if (node->next == NULL)
    {
        return NULL;
    }

    return traverse_and_get_node_by_index(node->next, index, index_count + 1);
}

// O(n) = time complexity
Node *get(LinkedList *self, int index)
{
    return traverse_and_get_node_by_index(self->first, index, 0);
}

void insert(LinkedList *self, int index, int item)
{
    if (index > self->size - 1 || index < 0)
    {
        return;
    }

    if (self->size == 0 || index == self->size - 1)
    {
        self->add(self, item);
    }
    else
    {
        Node *node = malloc(sizeof(Node));
        node->next = NULL;
        node->value = item;

        Node *previous_node = self->get(self, index - 1);
        Node *current_node = previous_node->next;

        previous_node->next = node;
        node->next = current_node;

        self->size = self->size + 1;
    }
}

// O(n) = time complexity
void delete(LinkedList *self, int index)
{
    if (index > self->size - 1 || index < 0)
    {
        return;
    }

    if (self->size == 0)
    {
        Node *previous_node = self->first;
        Node *second_node = self->first->next;

        self->first = second_node;

        free(previous_node);
    }
    else
    {
        Node *previous_node = self->get(self, index - 1);
        Node *node_to_delete = previous_node->next;
        Node *next_node = node_to_delete->next;

        previous_node->next = next_node;

        free(node_to_delete);
    }

    self->size = self->size - 1;
}

// O(n) = time complexity
void set(LinkedList *self, int index, int item)
{
    Node *node = self->get(self, index);
    node->value = item;
}

// Implement a doubly-linked list. Compare binary search using a linked list and a list. Which is faster and why?