#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int value;
	struct Node *left;
	struct Node *right;
	int height;
} Node;

int max(int a, int b)
{
	return a > b ? a : b;
}

int get_height(Node *node)
{
	if (node == NULL)
	{
		return 0;
	}

	return node->height;
}

Node *rightRotate(Node *node)
{
	Node *left_node = node->left;
	Node *left_right_node = left_node->right;

	left_node->right = node;
	node->left = left_right_node;

	node->height = max(get_height(node->left), get_height(node->right)) + 1;
	left_node->height = max(get_height(left_node->left), get_height(left_node->right)) + 1;

	return left_node;
}

Node *leftRotate(Node *node)
{
	Node *right_node = node->right;
	Node *right_left_node = right_node->left;

	right_node->left = node;
	node->right = right_left_node;

	node->height = max(get_height(node->left), get_height(node->right)) + 1;
	right_node->height = max(get_height(right_node->left), get_height(right_node->right)) + 1;

	return right_node;
}

int get_balance(Node *node)
{
	if (node == NULL)
	{
		return 0;
	}

	return get_height(node->left) - get_height(node->right);
}

void traverse_inorder(Node *root)
{
	if (root != NULL)
	{
		traverse_inorder(root->left);
		printf("%d\n", root->value);
		traverse_inorder(root->right);
	}
}

void traverse_preorder(Node *root)
{
	if (root != NULL)
	{
		printf("%d\n", root->value);
		traverse_preorder(root->left);
		traverse_preorder(root->right);
	}
}

void traverse_postorder(Node *root)
{
	if (root != NULL)
	{
		traverse_postorder(root->left);
		traverse_postorder(root->right);
		printf("%d\n", root->value);
	}
}

Node *initialize_node(int val)
{
	Node *node = malloc(sizeof(Node));

	node->value = val;
	node->left = NULL;
	node->right = NULL;
	node->height = 1;

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
		node->left = insert(node->left, val);
	}
	else if (val > node->value)
	{
		node->right = insert(node->right, val);
	}
	else
	{
		return node;
	}

	node->height = 1 + max(get_height(node->left), get_height(node->right));

	int balance = get_balance(node);

	if (balance > 1 && val < node->left->value)
	{
		printf("Right rotation for node:%d\n", node->value);
		return rightRotate(node);
	}

	if (balance < -1 && val > node->right->value)
	{
		printf("Left rotation for node:%d\n", node->value);
		return leftRotate(node);
	}

	if (balance > 1 && val > node->left->value)
	{
		printf("Left and Right rotation for node:%d\n", node->value);
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	if (balance < -1 && val < node->right->value)
	{
		printf("Right and Left rotation for node:%d\n", node->value);
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

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
	root = insert(root, 10);

	root = insert(root, 20);
	root = insert(root, 30);
	root = insert(root, 40);
	root = insert(root, 50);
	root = insert(root, 60);
	root = insert(root, 70);

	Node *node_to_search = search(root, 40);

	printf("Found value: %d\n", node_to_search->value);

	traverse_inorder(root);
	printf("\n");
	traverse_preorder(root);

	return 0;
}