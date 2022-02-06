#include <stdio.h>
#include <stdlib.h>

typedef struct List List;

struct List
{
    int *items;
    int size;
    int (*get)(List *self, int index);
    void (*add)(List *self, int item);
    void (*delete)(List *self, int index);
    void (*insert)(List *self, int index, int item);
    int (*set)(List *self, int index, int item);
    void (*print_items)(List *self);
};

List *initialize_list(int size);
void release_list(List *list);
int get(List *self, int index);
void add(List *self, int item);
void delete (List *self, int index);
void insert(List *self, int index, int item);
int set(List *self, int index, int item);
void print_items(List *self);

int main(int argc, char **argv)
{
    List *list = initialize_list(10);

    for (int i = 0; i < list->size; i++)
    {
        list->set(list, i, i * 10);
    }

    list->print_items(list);

    printf("\n-------- Adding an item -------");

    list->add(list, 100);
    list->print_items(list);

    printf("\n-------- Getting an item -------\n");

    int item_5 = list->get(list, 5);

    printf("%d", item_5);

    printf("\n-------- Inserting an item -------");

    list->insert(list, 0, 200);
    list->print_items(list);

    printf("\n-------- Deleting an item -------");

    list->delete (list, 0);
    list->print_items(list);

    release_list(list);

    return 0;
}

List *initialize_list(int size)
{
    List *list = malloc(sizeof(List));

    list->size = size;
    list->items = malloc(list->size * (sizeof(int)));

    list->set = &set;
    list->print_items = &print_items;
    list->add = &add;
    list->get = &get;
    list->insert = &insert;
    list->delete = &delete;

    return list;
}

void release_list(List *list)
{
    free(list->items);
    free(list);
}

// Space Complexity: O(1)
// Time Complexity: O(1)
int set(List *self, int index, int item)
{
    self->items[index] = item;
}

// Space Complexity: O(1)
// Time Complexity: O(1)
void add(List *self, int item)
{
    int new_size = self->size + 1;
    self->items = realloc(self->items, new_size * (sizeof(int)));
    self->items[new_size - 1] = item;
    self->size = new_size;
}

// Space Complexity: O(1)
// Time Complexity: O(1)
int get(List *self, int index)
{
    return self->items[index];
}

// Space Complexity: O(1)
// Time Complexity: O(n)
void insert(List *self, int index, int item)
{
    self->add(self, 0);

    for (int i = self->size - 1; i > index; i--)
    {
        self->set(self, i, self->get(self, i - 1));
    }

    self->set(self, index, item);
}

// Space Complexity: O(1)
// Time Complexity: O(n)
void delete (List *self, int index)
{
    int new_size = self->size - 1;

    for (int i = index + 1; i < self->size; i++)
    {
        self->set(self, i - 1, self->get(self, i));
    }

    free(&self->items[new_size]);
    self->items = realloc(self->items, new_size * (sizeof(int)));

    self->size = new_size;
}

// Space Complexity: O(1)
// Time Complexity: O(n)
void print_items(List *self)
{
    printf("\n-------- List Items -------\n");
    printf("[");
    for (int i = 0; i < self->size; i++)
    {
        printf("%d, ", self->items[i]);
    }
    printf("]");
}