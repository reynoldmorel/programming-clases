#include <stdio.h>
#include <stdlib.h>

typedef struct List List;

// Space: O(n) ---> items
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
        list->add(list, i + 1);
    }

    printf("Printing list ...\n");
    list->print_items(list);

    printf("list->get(list, 5)=%d\n", list->get(list, 5));

    printf("Deleting position 5 ...\n");
    list->delete(list, 5);

    printf("list->get(list, 5)=%d\n", list->get(list, 5));

    printf("Inserting 50 in position 4 ...\n");
    list->insert(list, 4, 50);

    printf("list->get(list, 5)=%d\n", list->get(list, 5));
    printf("list->get(list, 4)=%d\n", list->get(list, 4));

    printf("Update position 4 to 100 ...\n");
    list->set(list, 4, 100);

    printf("Printing list ...\n");
    list->print_items(list);

    release_list(list);

    return 0;
}

// Time: O(1)
// Space: O(1)
List *initialize_list(int size)
{
    List *list = malloc(sizeof(List));

    list->size = size;
    list->items = malloc(sizeof(int) * size);

    list->add = &add;
    list->get = &get;
    list->delete = &delete;
    list->insert = &insert;
    list->set = &set;
    list->print_items = &print_items;

    return list;
}

// Time: O(1)
// Space: O(1)
void release_list(List *list)
{
    free(list->items);
    free(list);
};

// Time: O(1)
// Space: O(1)
int get(List *self, int index)
{
    return self->items[index];
}

// Time: O(1)
// Space: O(1)
void add(List *self, int item)
{
    int new_size = self->size + 1;

    self->items = realloc(self->items, sizeof(int) * new_size);
    self->items[self->size] = item;
    self->size = new_size;
}

// Time: O(n)
// Space: O(1)
void delete(List *self, int index)
{
    int new_size = self->size - 1;

    for (int i = index + 1; i < self->size; i++)
    {
        self->items[i - 1] = self->items[i];
    }

    self->items = realloc(self->items, sizeof(int) * new_size);
    self->size = new_size;
}

// Time: O(n)
// Space: O(1)
void insert(List *self, int index, int item)
{
    int new_size = self->size + 1;

    self->items = realloc(self->items, sizeof(int) * new_size);

    for (int i = new_size - 1; i > index; i--)
    {
        self->items[i] = self->items[i - 1];
    }

    self->items[index] = item;

    self->size = new_size;
}

// Time: O(1)
// Space: O(1)
void set(List *self, int index, int item)
{
    self->items[index] = item;
}

// Time: O(n)
// Space: O(1)
void print_items(List *self)
{
    for (int i = 0; i < self->size; i++)
    {
        printf("%d, ", self->items[i]);
    }

    printf("\n");
}

/*
Tomar la lista que hicimos y permitir manejar un "initial capacity". Actualmente si no inicializamos la lista en 0 (List *list = initialize_list(0);), la aplicación no aprovecha los recursos apropiadamente.

1. La lista ddebería agregar elementos en los espacios libres aún estén definidos.
2. La lista deberíá poder borrar esos espacios definidos aún no tengan un valor guardado.
3. El insert por igual debería tomar en cuenta estos espacios predefinidos antes de reservar espacios de memorias nuevos.

Estos puntos deberían mejorar considerablemente la Time Complexity en el caso promedio a que el tiempo de escritura no utilice tanto realloc.

4. Agregar un binary search, ofeciendo sufienciente flexibilidad como para permitir que el dev decida que valor evaluar, para partir el array en dos.

Ejemplo del punto 4:

```
int compute_half(int lower_bound. int upper_bound) {
 ......
}

[1,2,3,4,10,20,21,22,33,44]

list->binary_search(list, 10, &compute_half);
```
*/