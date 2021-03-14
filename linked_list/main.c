#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	struct Node *next;
	int value;
} Node;

typedef struct LinkedList
{
	struct Node *first;
	struct Node *last;
	int size;
	int (*get)(struct LinkedList *self, int index);
	void (*add)(struct LinkedList *self, int value);
	void (*delete)(struct LinkedList *self, int index);
	void (*insert)(struct LinkedList *self, int index, int value);
	void (*set)(struct LinkedList *self, int index, int value);
	void (*print_items)(struct LinkedList *self);
} LinkedList;

LinkedList *initialize_list();
void traverse_and_realease(Node *node);
void realease_list(LinkedList *list);
void add(LinkedList *self, int value);
Node *traverse_and_get(Node *node, int current_index, int index);
int get(LinkedList *self, int index);
void set(LinkedList *self, int index, int value);
void insert(LinkedList *self, int index, int value);
void delete (LinkedList *self, int index);
void traverse_and_print(Node *node, int index);
void print_items(LinkedList *self);

int main(int argc, char *argv[])
{
	LinkedList *list = initialize_list();

	for (int i = 0; i < 10; i++)
	{
		list->add(list, i * 10);
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

LinkedList *initialize_list()
{
	LinkedList *list = malloc(sizeof(LinkedList));

	list->size = 0;
	list->first = NULL;

	list->get = &get;
	list->add = &add;
	list->set = &set;
	list->insert = &insert;
	list->delete = &delete;
	list->print_items = &print_items;

	return list;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
void traverse_and_realease(Node *node)
{
	if (node != NULL)
	{
		traverse_and_realease(node->next);
		free(node);
	}
}

void realease_list(LinkedList *list)
{
	traverse_and_realease(list->first);
	free(list);
}

// Time Complexity: O(1)
// Space Complexity: O(1)
void add(LinkedList *self, int value)
{
	Node *node = malloc(sizeof(Node));
	node->next = NULL;
	node->value = value;

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

	self->size++;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
Node *traverse_and_get(Node *node, int current_index, int index)
{
	if (current_index == index)
	{
		return node;
	}

	return traverse_and_get(node->next, current_index + 1, index);
}

// Time Complexity: O(n)
// Space Complexity: O(1)
int get(LinkedList *self, int index)
{
	Node *found_node = traverse_and_get(self->first, 0, index);
	return found_node->value;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
void set(LinkedList *self, int index, int value)
{
	Node *found_node = traverse_and_get(self->first, 0, index);
	found_node->value = value;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
void insert(LinkedList *self, int index, int value)
{
	Node *node = malloc(sizeof(Node));
	node->next = NULL;
	node->value = value;

	if (index > 0 && index < self->size)
	{
		Node *prev_node_to_replace = traverse_and_get(self->first, 0, index - 1);
		Node *node_to_replace = prev_node_to_replace->next;

		node->next = node_to_replace;
		prev_node_to_replace->next = node;
		self->size++;
	}
	else if (index == 0)
	{
		Node *node_to_replace = self->first;

		node->next = node_to_replace;
		self->first = node;
		self->size++;
	}
	else if (index == self->size)
	{
		self->add(self, value);
	}
}

// Time Complexity: O(n)
// Space Complexity: O(1)
void delete (LinkedList *self, int index)
{
	Node *node_to_delete;

	if (index > 0)
	{
		Node *prev_node_to_delete = traverse_and_get(self->first, 0, index - 1);

		node_to_delete = prev_node_to_delete->next;
		prev_node_to_delete->next = prev_node_to_delete->next->next;
	}
	else
	{
		node_to_delete = self->first;
		self->first = self->first->next;
	}

	free(node_to_delete);
	self->size--;
}

void traverse_and_print(Node *node, int index)
{
	if (node != NULL)
	{
		printf("The element in the index %d is %d\n", index, node->value);
		traverse_and_print(node->next, index + 1);
	}
}

void print_items(LinkedList *self)
{
	traverse_and_print(self->first, 0);
}