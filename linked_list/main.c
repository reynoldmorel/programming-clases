#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	struct Node *next;
	struct Node *previous;
	int val;
} Node;

typedef struct LinkedList
{
	Node *last;
	Node *first;
	int size;
	Node *(*get)(struct LinkedList *self, int index);
	void (*add)(struct LinkedList *self, int val);
	void (*delete)(struct LinkedList *self, int index);
	void (*insert)(struct LinkedList *self, int index, int val);
	void (*set)(struct LinkedList *self, int index, int val);
	void (*print_items)(struct LinkedList *self);
} LinkedList;

Node *find_node(Node *node, int current_index, int index_to_find)
{
	if (current_index == index_to_find)
	{
		return node;
	}
	else if (node == NULL)
	{
		return NULL;
	}

	return find_node(node->next, current_index + 1, index_to_find);
}

void traverse_and_print(Node *node)
{
	if (node == NULL)
	{
		return;
	}

	if (node->next == NULL)
	{
		printf("%d", node->val);
	}
	else
	{
		printf("%d,", node->val);
	}

	traverse_and_print(node->next);
}

void traverse_and_free(Node *node)
{
	if (node != NULL)
	{
		traverse_and_free(node->next);
		free(node);
	}
}

// Time Complexity = O(n)
Node *get(LinkedList *self, int index)
{
	return find_node(self->first, 0, index);
}

// Time Complexity = O(1)
void add(LinkedList *self, int val)
{
	Node *node = malloc(sizeof(Node));
	node->next = NULL;
	node->previous = NULL;
	node->val = val;

	if (self->first == NULL)
	{
		self->first = node;
		self->last = node;
	}
	else
	{
		self->last->next = node;
		node->previous = self->last;
		self->last = node;
	}

	self->size++;
}

void delete (LinkedList *self, int index)
{
	Node *node_to_delete;

	if (index > 0 && index < self->size)
	{
		node_to_delete = find_node(self->first, 0, index);
		Node *previous_node = node_to_delete->previous;

		previous_node->next = node_to_delete->next;
	}
	else if (index == 0)
	{
		node_to_delete = self->first;
		self->first = self->first->next;
	}
	else
	{
		node_to_delete = self->last;
		Node *previous_node = node_to_delete->previous;
		previous_node->next = NULL;
	}

	free(node_to_delete);
	self->size--;
}

void insert(LinkedList *self, int index, int val)
{
	Node *node = malloc(sizeof(Node));
	node->next = NULL;

	if (index > 0 && index < self->size)
	{
		node->val = val;
		Node *node_to_be_replaced = find_node(self->first, 0, index);

		node->next = node_to_be_replaced;
		node->previous = node_to_be_replaced->previous;
		node_to_be_replaced->previous = node;
	}
	else if (index == 0)
	{
		node->val = val;
		node->next = self->first;
		self->first->previous = node;
		self->first = node;
	}
	else
	{
		add(self, val);
	}

	self->size++;
}

void set(LinkedList *self, int index, int val)
{
	Node *node = find_node(self->first, 0, index);
	node->val = val;
}

void print_items(LinkedList *self)
{
	printf("items = [");
	traverse_and_print(self->first);
	printf("]\n\n");
}

LinkedList *list;

LinkedList *initialize_list()
{
	LinkedList *list = malloc(sizeof(LinkedList));

	list->size = 0;

	list->first = NULL;
	list->last = NULL;

	list->get = get;
	list->add = add;
	list->delete = delete;
	list->insert = insert;
	list->set = set;
	list->print_items = print_items;

	return list;
}

void *release_list(LinkedList *list)
{
	traverse_and_free(list->first);
	free(list);
}

int main(int argc, char *argv[])
{
	list = initialize_list();

	for (int i = 0; i < 10; i++)
	{
		list->add(list, i);
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