#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
typedef struct LinkedList LinkedList;

struct Node
{
    Node *next;
    int value;
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

LinkedList *initialize_list();
void release_list(LinkedList *list);
Node *get(LinkedList *self, int index);
void add(LinkedList *self, int item);
void delete (LinkedList *self, int index);
void insert(LinkedList *self, int index, int item);
void set(LinkedList *self, int index, int item);
void print_items(LinkedList *self);

void traverse_post_order_and_release_nodes(Node *node);
void traverse_pre_order_and_printf_nodes(Node *node);
Node *traverse_and_get_node_by_index(Node *node, int index, int index_count);

// 1 -> 2 -> 3 -> NULL

int main(int argc, char **argv)
{
    LinkedList *list = initialize_list();

    printf("\n-------- Adding 5 items -------");

    list->add(list, 1);
    list->add(list, 2);
    list->add(list, 3);
    list->add(list, 4);
    list->add(list, 5);
    list->print_items(list);

    printf("\n-------- Getting an item -------\n");

    Node *node_3 = list->get(list, 3);
    printf("%d", node_3->value);

    printf("\n-------- Inserting an item -------");

    list->insert(list, 3, 200);
    list->print_items(list);

    printf("\n-------- Deleting an item -------");

    list->delete (list, 3);
    list->print_items(list);

    release_list(list);
    return 0;
}

LinkedList *initialize_list()
{
    LinkedList *list = malloc(sizeof(LinkedList));

    list->size = 0;

    list->first = NULL;
    list->last = NULL;
    list->set = &set;
    list->print_items = &print_items;
    list->add = &add;
    list->get = &get;
    list->insert = &insert;
    list->delete = &delete;

    return list;
}

void traverse_post_order_and_release_nodes(Node *node)
{
    if (node->next != NULL)
    {
        traverse_post_order_and_release_nodes(node->next);
    }

    free(node);
}

void release_list(LinkedList *list)
{
    traverse_post_order_and_release_nodes(list->first);
    free(list);
}

// Time Complexity: O(1)
// Space Complexity: O(1)
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

Node *traverse_and_get_node_by_index(Node *node, int index, int index_count)
{
    if (index == index_count)
    {
        return node;
    }

    return traverse_and_get_node_by_index(node->next, index, index_count + 1);
}

// Time Complexity: O(n)
// Space Complexity: O(1)
Node *get(LinkedList *self, int index)
{
    return traverse_and_get_node_by_index(self->first, index, 0);
}

// Time Complexity: O(n)
// Space Complexity: O(1)
void insert(LinkedList *self, int index, int item)
{
    if (self->size > 0 && index < self->size - 1)
    {
        Node *node = malloc(sizeof(Node));
        node->next = NULL;
        node->value = item;

        if (index > 0)
        {
            Node *prev_node = self->get(self, index - 1);
            Node *current_node = prev_node->next;

            prev_node->next = node;
            node->next = current_node;
        }
        else
        {
            node->next = self->first;
            self->first = node;
        }

        self->size = self->size + 1;
    }
    else
    {
        self->add(self, item);
    }
}

// Time Complexity: O(n)
// Space Complexity: O(1)
void set(LinkedList *self, int index, int item)
{
    Node *node = self->get(self, index);
    node->value = item;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
void delete (LinkedList *self, int index)
{
    Node *node_to_delete = NULL;

    if (self->size > 0 && index < self->size - 1)
    {
        if (index > 0)
        {
            Node *prev_node = self->get(self, index - 1);
            Node *current_node = prev_node->next;
            Node *next_node = current_node->next;

            node_to_delete = current_node;

            prev_node->next = next_node;
        }
        else
        {
            Node *current_node = self->first;
            Node *next_node = current_node->next;

            node_to_delete = current_node;

            self->first = next_node;
        }
    }
    else
    {
        Node *prev_node = self->get(self, index - 1);
        Node *current_node = self->last;

        node_to_delete = current_node;

        self->last = prev_node;
        prev_node->next = NULL;
    }

    self->size = self->size - 1;

    free(node_to_delete);
}

void traverse_pre_order_and_printf_nodes(Node *node)
{
    printf("%d, ", node->value);

    if (node->next != NULL)
    {
        traverse_pre_order_and_printf_nodes(node->next);
    }
}

void print_items(LinkedList *self)
{
    printf("\n-------- LinkedList Items -------\n");
    printf("[");
    traverse_pre_order_and_printf_nodes(self->first);
    printf("]");
}
