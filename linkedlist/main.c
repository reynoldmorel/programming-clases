#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedList LinkedList;
typedef struct LinkedListNode LinkedListNode;

struct LinkedList
{
    LinkedListNode *first;
    LinkedListNode *last;
    int size;
    int (*get)(LinkedList *self, int index);
    void (*add)(LinkedList *self, int item);
    void (*delete)(LinkedList *self, int index);
    void (*insert)(LinkedList *self, int index, int item);
    void (*set)(LinkedList *self, int index, int item);
    void (*print_items)(LinkedList *self);
};

struct LinkedListNode
{
    LinkedListNode *next;
    int item;
};

LinkedList *initialize_linkedlist();
void release_linkedlist(LinkedList *linkedlist);

int get(LinkedList *self, int index);
void add(LinkedList *self, int item);
void delete(LinkedList *self, int index);
void insert(LinkedList *self, int index, int item);
void set(LinkedList *self, int index, int item);
void print_items(LinkedList *self);

void traverse_post_order_and_realease_nodes(LinkedListNode *node);
LinkedListNode *traverse_and_get_node_by_index(LinkedListNode *node, int index, int index_count);
void traverse_pre_order_and_print_nodes(LinkedListNode *node);

int main()
{
    LinkedList *linkedlist = initialize_linkedlist();

    for (int i = 0; i < 10; i++)
    {
        linkedlist->add(linkedlist, i * 10);
    }

    linkedlist->print_items(linkedlist);
    printf("\nget(2) = %d\n", linkedlist->get(linkedlist, 2));

    linkedlist->insert(linkedlist, 2, 33);
    printf("\ninsert(2, 33) = %d\n", linkedlist->get(linkedlist, 2));
    linkedlist->print_items(linkedlist);

    linkedlist->set(linkedlist, 2, 44);
    printf("\nset(2, 44) = %d\n", linkedlist->get(linkedlist, 2));
    linkedlist->print_items(linkedlist);

    linkedlist->delete (linkedlist, 2);
    printf("\ndelete(2) = %d\n", linkedlist->get(linkedlist, 2));
    linkedlist->print_items(linkedlist);

    release_linkedlist(linkedlist);

    return 0;
}

LinkedList *initialize_linkedlist()
{
    LinkedList *linkedlist = malloc(sizeof(LinkedList));

    linkedlist->size = 0;
    linkedlist->first = NULL;
    linkedlist->last = NULL;

    linkedlist->get = &get;
    linkedlist->add = &add;
    linkedlist->delete = &delete;
    linkedlist->insert = &insert;
    linkedlist->set = &set;
    linkedlist->print_items = &print_items;

    return linkedlist;
}

void release_linkedlist(LinkedList *linkedlist)
{
    traverse_post_order_and_realease_nodes(linkedlist->first);
    free(linkedlist);
}

void traverse_post_order_and_realease_nodes(LinkedListNode *node)
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
// O(n)
// Space Complexity
// O(1)
int get(LinkedList *self, int index)
{
    LinkedListNode *node_found = traverse_and_get_node_by_index(self->first, index, 0);

    return node_found->item;
}

LinkedListNode *traverse_and_get_node_by_index(LinkedListNode *node, int index, int index_count)
{
    if (node == NULL)
    {
        return NULL;
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

// Time Complexity
// O(1)
// Space Complexity
// O(1)
void add(LinkedList *self, int item)
{
    LinkedListNode *node = malloc(sizeof(LinkedListNode));
    node->next = NULL;
    node->item = item;

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

// Time Complexity
// O(n)
// Space Complexity
// O(1)
void delete(LinkedList *self, int index)
{
    if (index == 0)
    {
        LinkedListNode *node_to_delete = self->first;
        LinkedListNode *next_node = node_to_delete->next;

        self->first = next_node;

        free(node_to_delete);
    }
    else
    {
        LinkedListNode *prev_node = traverse_and_get_node_by_index(self->first, index - 1, 0);
        LinkedListNode *node_to_delete = prev_node->next;

        prev_node->next = node_to_delete->next;

        free(node_to_delete);
    }

    self->size = self->size - 1;
}

// Time Complexity
// O(n)
// Space Complexity
// O(1)
void insert(LinkedList *self, int index, int item)
{
    LinkedListNode *node = malloc(sizeof(LinkedListNode));
    node->next = NULL;
    node->item = item;

    if (index == 0)
    {
        node->next = self->first;
        self->first = node;
    }
    else if (index == self->size)
    {
        self->last->next = node;
        self->last = node;
    }
    else
    {
        LinkedListNode *prev_node = traverse_and_get_node_by_index(self->first, index - 1, 0);
        LinkedListNode *node_replace = prev_node->next;

        node->next = node_replace;
        prev_node->next = node;
    }

    self->size = self->size + 1;
}

// Time Complexity
// O(n)
// Space Complexity
// O(1)
void set(LinkedList *self, int index, int item)
{
    LinkedListNode *node = traverse_and_get_node_by_index(self->first, index, 0);
    node->item = item;
}

// Time Complexity
// O(n)
// Space Complexity
// O(1)
void print_items(LinkedList *self)
{
    printf("\n[");

    traverse_pre_order_and_print_nodes(self->first);

    printf("]\n");
}

void traverse_pre_order_and_print_nodes(LinkedListNode *node)
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
