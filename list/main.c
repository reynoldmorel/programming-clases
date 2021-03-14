#include <stdio.h>
#include <stdlib.h>

typedef struct List
{
    int *items;
    int size;
    int (*get)(struct List *self, int index);
    void (*add)(struct List *self, int value);
    void (*delete)(struct List *self, int index);
    void (*insert)(struct List *self, int index, int value);
    void (*set)(struct List *self, int index, int value);
    void (*print_items)(struct List *self);
} List;

List *initialize_list(int size);
void realease_list(List *list);
int get(List *self, int index);
void add(List *self, int value);
void set(List *self, int index, int value);
void insert(List *self, int index, int value);
void print_items(List *self);
void delete (List *self, int index);

int main(int argc, char *argv[])
{
    List *list = initialize_list(10);

    for (int i = 0; i < list->size; i++)
    {
        list->set(list, i, i * 10);
    }

    list->print_items(list);
    printf("------------------------------\n");

    list->add(list, 1000);

    list->print_items(list);
    printf("------------------------------\n");

    list->insert(list, 0, 123);

    list->print_items(list);
    printf("------------------------------\n");

    list->delete (list, 0);

    list->print_items(list);

    realease_list(list);
    return 0;
}

List *initialize_list(int size)
{
    List *list = malloc(sizeof(List));

    list->size = size;
    list->items = malloc(list->size * (sizeof(int)));

    list->get = &get;
    list->add = &add;
    list->set = &set;
    list->insert = &insert;
    list->print_items = &print_items;
    list->delete = &delete;

    return list;
}

void realease_list(List *list)
{
    free(list->items);
    free(list);
}

// Time Complexity: O(1)
// Space Complexity: O(1)
int get(List *self, int index)
{
    return self->items[index];
}

// Time Complexity: O(1)
// Space Complexity: O(1)
void add(List *self, int value)
{
    self->size++;
    self->items = realloc(self->items, self->size * sizeof(int));
    self->items[self->size - 1] = value;
}

// Time Complexity: O(1)
// Space Complexity: O(1)
void set(List *self, int index, int value)
{
    self->items[index] = value;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
void insert(List *self, int index, int value)
{
    self->add(self, 0);

    if (index == self->size)
    {
        self->set(self, index, value);
        return;
    }

    for (int i = self->size - 1; i > index; i--)
    {
        self->set(self, i, self->get(self, i - 1));
    }

    self->set(self, index, value);
}

// Time Complexity: O(n)
// Space Complexity: O(1)
void print_items(List *self)
{
    for (int i = 0; i < self->size; i++)
    {
        printf("The element in the index %d is %d\n", i, self->get(self, i));
    }
}

// Time Complexity: O(n)
// Space Complexity: O(1)
void delete (List *self, int index)
{
    for (int i = index + 1; i < self->size; i++)
    {
        self->set(self, i - 1, self->get(self, i));
    }

    self->size--;

    free(&self->items[self->size - 1]);
    self->items = realloc(self->items, self->size * sizeof(int));
}