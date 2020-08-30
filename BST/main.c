#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int value;
	struct Node *left;
	struct Node *right;
} Node;

void traverse_inorder(Node *root)
{
	if (root != NULL)
	{
		traverse_inorder(root->left);
		printf("%d\n", root->value);
		traverse_inorder(root->right);
	}
}

Node *initialize_node(int val)
{
	Node *node = malloc(sizeof(Node));

	node->value = val;
	node->left = NULL;
	node->right = NULL;

	return node;
}

Node *insert(Node *node, int val)
{
	if (node == NULL)
	{
		return initialize_node(val);
	}

	if (val < node->value)
	{
		printf("Hacia la izquierda\n");
		node->left = insert(node->left, val);
	}
	else if (val > node->value)
	{
		printf("Hacia la derecha\n");
		node->right = insert(node->right, val);
	}

	traverse_inorder(node);
	printf("\n");
	return node;
}

Node *search(Node *root, int val_to_search)
{
	if (root == NULL || root->value == val_to_search)
	{
		return root;
	}

	if (root->value < val_to_search)
	{
		return search(root->right, val_to_search);
	}

	return search(root->left, val_to_search);
}

int main(int argc, char *argv[])
{
	Node *root = NULL;
	root = insert(root, 80);

	insert(root, 90);
	insert(root, 130);
	insert(root, 40);
	insert(root, 100);
	insert(root, 30);
	insert(root, 35);

	Node *node_to_search = search(root, 35);

	printf("Found value: %d\n", node_to_search->value);

	traverse_inorder(root);

	return 0;
}