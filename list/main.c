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
    void (*set)(List *self, int index, int item);
    void (*print_items)(List *self);
};

List *initialize_list(int size);
void release_list(List *list);

void add(List *self, int item);
int get(List *self, int index);
void print_items(List *self);
void insert(List *self, int index, int item);
void delete(List *self, int index);
void set(List *self, int index, int item);

int main()
{

    List *list = initialize_list(0);

    for (int i = 0; i < 5; i++)
    {
        list->add(list, i * 2);
    }

    printf("Element in pos. %d: %d", 3, list->get(list, 3));

    list->insert(list, 2, 10);

    list->print_items(list);

    list->delete (list, 2);

    list->print_items(list);

    list->set(list, 2, 10);

    list->print_items(list);

    release_list(list);

    return 0;
}

List *initialize_list(int size)
{
    List *list = malloc(sizeof(List));

    list->size = size;
    list->items = malloc(list->size * sizeof(int));

    list->add = &add;
    list->get = &get;
    list->print_items = &print_items;
    list->insert = &insert;
    list->delete = &delete;
    list->set = &set;

    return list;
}

void release_list(List *list)
{
    free(list->items);
    free(list);
}

// O(1) = time complexity
void add(List *self, int item)
{
    int new_size = self->size + 1;

    self->items = realloc(self->items, new_size * sizeof(int));
    self->items[new_size - 1] = item;
    self->size = new_size;
}

// O(1) = time complexity
int get(List *self, int index)
{
    return self->items[index];
}

// O(n) = time complexity
void insert(List *self, int index, int item)
{
    self->add(self, 0);

    for (int i = self->size - 1; i > index; i--)
    {
        self->items[i] = self->items[i - 1];
    }

    self->items[index] = item;
}

// O(n) = time complexity
void delete(List *self, int index)
{
    int new_size = self->size - 1;

    for (int i = index + 1; i < self->size; i++)
    {
        self->items[i - 1] = self->items[i];
    }

    free(&self->items[new_size]);
    self->items = realloc(self->items, new_size * sizeof(int));

    self->size = new_size;
}

// O(1) = time complexity
void set(List *self, int index, int item)
{
    self->items[index] = item;
}

// O(n) = time complexity
void print_items(List *self)
{
    printf("\n ----- LIST -------\n");
    for (int i = 0; i < self->size; i++)
    {
        printf("%d, ", self->items[i]);
    }
}

// Implement binary search using a list.
// If you feel strong, use a Person struct having id, name, lastname
// and make it find persons by id.