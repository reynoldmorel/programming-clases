#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int value;
	struct Node next;
};

struct Node linked_list = {.value = 10};
struct Node last_node;

int main(int argc, char *argv[])
{
	last_node = linked_list;

	add(20);
}

void add(int val)
{
	struct Node new_node = {.value = val};

	last_node.next = new_node;
	last_node = new_node;
}

void insert(int val)
{
	struct Node new_node = {.value = val};

	new_node.next = linked_list;
	linked_list = new_node;
}

void delete_first_elemet(int val)
{
	linked_list = linked_list.next;
}

// O(n)
void get(int val)
{
	find_and_traverse(val, linked_list);
}

struct Node find_and_traverse(int val, struct Node node)
{
	if (node.value == val)
	{
		return node;
	}
	else if (node == NULL)
	{
		struct Node n;
		return n;
	}

	return find_and_traverse(val, node.next);
}