#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedList LinkedList;
typedef struct LinkedListNode LinkedListNode;

// Space: O(n) ---> items
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
void traverse_post_order_and_release_nodes(LinkedListNode *node);
void release_linkedlist(LinkedList *linkedlist);

LinkedListNode *traverse_and_get_node_by_index(LinkedListNode *node, int index, int index_count);
int get(LinkedList *self, int index);
void add(LinkedList *self, int item);
void delete(LinkedList *self, int index);
void insert(LinkedList *self, int index, int item);
void set(LinkedList *self, int index, int item);
void print_items(LinkedList *self);
void traverse_pre_order_and_print_nodes(LinkedListNode *node);

int main()
{
    LinkedList *linkedlist = initialize_linkedlist();

    for (int i = 0; i < 10; i++)
    {
        linkedlist->add(linkedlist, i + 1);
    }

    printf("Printing linkedlist ...\n");
    linkedlist->print_items(linkedlist);

    printf("linkedlist->get(linkedlist, 5)=%d\n", linkedlist->get(linkedlist, 5));

    printf("Deleting position 5 ...\n");
    linkedlist->delete(linkedlist, 5);

    printf("linkedlist->get(linkedlist, 5)=%d\n", linkedlist->get(linkedlist, 5));

    printf("Inserting 50 in position 4 ...\n");
    linkedlist->insert(linkedlist, 4, 50);

    printf("linkedlist->get(linkedlist, 5)=%d\n", linkedlist->get(linkedlist, 5));
    printf("linkedlist->get(linkedlist, 4)=%d\n", linkedlist->get(linkedlist, 4));

    printf("Update position 4 to 100 ...\n");
    linkedlist->set(linkedlist, 4, 100);

    printf("Printing linkedlist ...\n");
    linkedlist->print_items(linkedlist);

    release_linkedlist(linkedlist);

    return 0;
}

// Time: O(1)
// Space: O(1)
LinkedList *initialize_linkedlist()
{
    LinkedList *linkedlist = malloc(sizeof(LinkedList));

    linkedlist->size = 0;
    linkedlist->first = NULL;
    linkedlist->last = NULL;

    linkedlist->add = &add;
    linkedlist->get = &get;
    linkedlist->delete = &delete;
    linkedlist->insert = &insert;
    linkedlist->set = &set;
    linkedlist->print_items = &print_items;

    return linkedlist;
}

void traverse_post_order_and_release_nodes(LinkedListNode *node)
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

void release_linkedlist(LinkedList *linkedlist)
{
    traverse_post_order_and_release_nodes(linkedlist->first);
    free(linkedlist);
};

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

int get(LinkedList *self, int index)
{
    LinkedListNode *found = traverse_and_get_node_by_index(self->first, index, 0);

    return found->item;
}

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

void delete(LinkedList *self, int index)
{
    if (index == 0)
    {
        LinkedListNode *node_to_delete = self->first;
        self->first = self->first->next;
        free(node_to_delete);
    }
    else
    {
        LinkedListNode *previous = traverse_and_get_node_by_index(self->first, index - 1, 0);
        LinkedListNode *node_to_delete = previous->next;
        previous->next = node_to_delete->next;
        free(node_to_delete);
    }

    self->size = self->size - 1;
}

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
    else if(index == self->size)
    {
        self->last->next = node;
        self->last = node;
    }
    else
    {
        LinkedListNode *previous = traverse_and_get_node_by_index(self->first, index - 1, 0);
        LinkedListNode *node_to_replace = previous->next;
        
        node->next = node_to_replace;
        previous->next = node;
    }

    self->size = self->size + 1;
}

void set(LinkedList *self, int index, int item)
{
    LinkedListNode *found = traverse_and_get_node_by_index(self->first, index, 0);

    found->item =  item;
}

// Time: O(n)
// Space: O(1)
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

/*
La tarea para de este clase es implementar un doubly-linked list.

Establecer diferencias entre el binary search con un List y uno con el Linked List
*/