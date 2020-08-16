#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct List
{
	int *items;
	int size;
	int (*get)(struct List *self, int index);
	void (*add)(struct List *self, int val);
	void (*delete)(struct List *self, int index);
	void (*insert)(struct List *self, int index, int val);
	void (*set)(struct List *self, int index, int val);
	void (*print_items)(struct List *self);
} List;

int get(List *self, int index)
{
	return self->items[index];
}

void add(List *self, int val)
{
	self->size++;
	self->items = realloc(self->items, self->size * sizeof(int));
	self->items[self->size - 1] = val;
}

void delete (List *self, int index)
{
	for (int i = index + 1; i < self->size - 1; i++)
	{
		self->items[i - 1] = self->items[i];
	}

	self->size--;
	int *tmp = malloc(self->size * sizeof(int));
	memcpy(tmp, self->items, self->size * sizeof(int));

	free(self->items);

	self->items = tmp;
}

void insert(List *self, int index, int val)
{
	self->add(self, 0);

	for (int i = self->size - 1; i > index; i--)
	{
		self->items[i] = self->items[i - 1];
	}

	self->items[index] = val;
}

void set(List *self, int index, int val)
{
	self->items[index] = val;
}

void print_items(List *self)
{
	printf("items = [");
	for (int i = 0; i < self->size - 1; i++)
	{
		printf("%d,", self->items[i]);
	}

	printf("%d]\n\n", self->items[self->size - 1]);
}

List *list;

List *initialize_list(int size)
{
	List *list = malloc(sizeof(List));

	list->size = size;
	list->items = malloc(list->size * sizeof(int));

	list->get = get;
	list->add = add;
	list->delete = delete;
	list->insert = insert;
	list->set = set;
	list->print_items = print_items;

	return list;
}

void *release_list(List *list)
{
	free(list->items);
	free(list);
}

int main(int argc, char *argv[])
{
	list = initialize_list(10);

	for (int i = 0; i < list->size; i++)
	{
		list->items[i] = i;
	}

	list->print_items(list);
	printf("Adding Element 10...\n");
	list->add(list, 10);
	list->print_items(list);
	printf("Deleting Element 10...\n");
	list->delete (list, 10);
	list->print_items(list);
	printf("Inserting Element 10 in the 1st position...\n");
	list->insert(list, 0, 10);
	list->print_items(list);
	printf("Setting Element 10 to be 20...\n");
	list->set(list, 0, 20);
	list->print_items(list);

	release_list(list);

	return 0;
}