#include <stdio.h>
#include <stdlib.h>

typedef struct List List;

// Space Complexity
// O(n)
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

int get(List *self, int index);
void add(List *self, int item);
void delete(List *self, int index);
void insert(List *self, int index, int item);
void set(List *self, int index, int item);
void print_items(List *self);

int main()
{
    List *list = initialize_list(0);

    for (int i = 0; i < 10; i++)
    {
        list->add(list, i * 10);
    }

    list->print_items(list);
    printf("\nget(2) = %d\n", list->get(list, 2));

    list->insert(list, 2, 33);
    printf("\ninsert(2, 33) = %d\n", list->get(list, 2));
    list->print_items(list);

    list->set(list, 2, 44);
    printf("\nset(2, 44) = %d\n", list->get(list, 2));
    list->print_items(list);

    list->delete(list, 2);
    printf("\ndelete(2) = %d\n", list->get(list, 2));
    list->print_items(list);

    release_list(list);

    return 0;
}

List *initialize_list(int size)
{
    List *list = malloc(sizeof(List));

    list->size = size;
    list->items = malloc(list->size * sizeof(int));

    list->get = &get;
    list->add = &add;
    list->delete = &delete;
    list->insert = &insert;
    list->set = &set;
    list->print_items = &print_items;

    return list;
}

void release_list(List *list)
{
    free(list->items);
    free(list);
}

// Time Complexity
// O(1)
// Space Complexity
// O(1)
int get(List *self, int index)
{
    return self->items[index];
}

// Time Complexity
// O(1)
// Space Complexity
// O(1)
void add(List *self, int item)
{
    int new_size = self->size + 1;

    self->items = realloc(self->items, new_size * sizeof(int));
    self->items[new_size - 1] = item;
    self->size = new_size;
}

// Time Complexity
// O(n)
// Space Complexity
// O(1)
void delete(List *self, int index)
{
    int new_size = self->size - 1;

    for (int i = index + 1; i < self->size; i++)
    {
        self->items[i - 1] = self->items[i];
    }

    self->items = realloc(self->items, new_size * sizeof(int));

    self->size = new_size;
}

// Time Complexity
// O(n)
// Space Complexity
// O(1)
void insert(List *self, int index, int item)
{
    int new_size = self->size + 1;

    self->items = realloc(self->items, new_size * sizeof(int));

    for (int i = new_size - 1; i > index; i--)
    {
        self->items[i] = self->items[i - 1];
    }

    self->items[index] = item;

    self->size = new_size;
}

// Time Complexity
// O(1)
// Space Complexity
// O(1)
void set(List *self, int index, int item)
{
    self->items[index] = item;
}

// Time Complexity
// O(n)
// Space Complexity
// O(1)
void print_items(List *self)
{
    printf("\n[");

    for (int i = 0; i < self->size; i++)
    {

        printf("%d, ", self->items[i]);
    }

    printf("]\n");
}
