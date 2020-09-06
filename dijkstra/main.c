#include <stdio.h>
#include <stdlib.h>

typedef struct Country
{
	char *name;
	int weight;
	int visited;
	int id;
} Country;

Country **countries;
int countriesSize;

int **distance_matrix;

typedef struct Route
{
	Country *country;
	struct Route *next;
	int total_weight;
	int total_distance;
} Route;

typedef struct Node
{
	int value;
	Route *route;
	struct Node *left;
	struct Node *right;
	int height;
} Node;

Route *initialize_route(Country *country)
{
	Route *route = malloc(sizeof(Route));
	route->next = NULL;
	route->country = country;
	route->total_weight = country->weight;
	route->total_distance = 0;
	return route;
}

Country *initialize_country(char *name, int weight)
{
	Country *country = malloc(sizeof(Country));

	country->name = name;
	country->weight = weight;
	country->visited = 0;
	country->id = countriesSize + 1;

	return country;
}

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

		printf("Distancia Total: %d\n", root->route->total_distance);
		printf("Peso Total: %d\n", root->route->total_weight);
		Route *route = root->route;

		while (route != NULL)
		{
			printf("Pais: %s -> ", route->country->name);
			route = route->next;
		}

		printf("Fin\n\n");

		traverse_inorder(root->right);
	}
}

Node *initialize_node(Route *route)
{
	Node *node = malloc(sizeof(Node));

	node->value = route->total_distance + route->total_weight;
	node->route = route;
	node->left = NULL;
	node->right = NULL;
	node->height = 1;

	return node;
}

Node *insert(Node *node, Route *route)
{
	if (node == NULL)
	{
		return initialize_node(route);
	}

	int val = route->total_distance + route->total_weight;

	if (val < node->value)
	{
		node->left = insert(node->left, route);
	}
	else if (val > node->value)
	{
		node->right = insert(node->right, route);
	}
	else
	{
		return node;
	}

	node->height = 1 + max(get_height(node->left), get_height(node->right));

	int balance = get_balance(node);

	if (balance > 1 && val < node->left->value)
	{
		return rightRotate(node);
	}

	if (balance < -1 && val > node->right->value)
	{
		return leftRotate(node);
	}

	if (balance > 1 && val > node->left->value)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	if (balance < -1 && val < node->right->value)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	return node;
}

Route *clone_route(Route *route)
{
	Route *new = initialize_route(route->country);

	new->total_distance = route->total_distance;
	new->total_weight = route->total_weight;

	if (route->next != NULL)
	{
		Route *cloned_route = clone_route(route->next);

		new->next = cloned_route;
	}

	return new;
}

void fill_distance_matrix()
{
	distance_matrix = malloc(sizeof(int) * countriesSize);

	for (int i = 0; i < countriesSize; i++)
	{
		distance_matrix[i] = malloc(sizeof(int) * countriesSize);

		for (int j = 0; j < countriesSize; j++)
		{
			distance_matrix[i][j] = -1;
		}
	}
}

void add_country_to_countries(Country *country)
{
	if (countriesSize == 0)
	{
		countries = malloc(sizeof(Country));
	}
	else
	{
		countries = realloc(countries, sizeof(Country) * countriesSize + 1);
	}

	countriesSize++;

	countries[countriesSize - 1] = country;
}

void revert_route(Route *route)
{
	Route *next_route = route->next;

	next_route->country->visited = 0;
	route->next = NULL;
}

void add_distance(Country *origin, Country *destiny, int distance)
{
	distance_matrix[origin->id - 1][destiny->id - 1] = distance;
	distance_matrix[destiny->id - 1][origin->id - 1] = distance;
}

Node *build_shortest_routes(Country *origin, Country *destiny, Route *main_route, Route *route, Node *root)
{
	int link_index = route->country->id - 1;

	for (int i = 0; i < countriesSize; i++)
	{
		int distance = distance_matrix[link_index][i];

		if (distance > -1)
		{
			Country *nearest_destiny = countries[i];

			if (nearest_destiny->visited != 0)
			{
				continue;
			}

			Route *next_route = initialize_route(nearest_destiny);

			main_route->total_distance = main_route->total_distance + distance;
			main_route->total_weight = main_route->total_weight + nearest_destiny->weight;

			route->country->visited = 1;

			route->next = next_route;

			if (nearest_destiny->id == destiny->id)
			{
				Route *cloned_route = clone_route(main_route);

				root = insert(root, cloned_route);
			}
			else
			{
				root = build_shortest_routes(origin, destiny, main_route, next_route, root);
			}

			revert_route(route);

			main_route->total_distance = main_route->total_distance - distance;
			main_route->total_weight = main_route->total_weight - nearest_destiny->weight;
		}
	}

	return root;
}

int main(int argc, char *argv[])
{
	Country *cuba = initialize_country("Cuba", 50);
	add_country_to_countries(cuba);

	Country *chile = initialize_country("Chile", 20);
	add_country_to_countries(chile);

	Country *china = initialize_country("China", 30);
	add_country_to_countries(china);

	Country *japon = initialize_country("Japón", 10);
	add_country_to_countries(japon);

	fill_distance_matrix();

	add_distance(cuba, chile, 600);
	add_distance(cuba, china, 500);
	add_distance(chile, china, 800);
	add_distance(chile, japon, 1000);
	add_distance(china, japon, 200);

	Route *route = initialize_route(cuba);

	Node *root = NULL;

	root = build_shortest_routes(cuba, japon, route, route, root);

	traverse_inorder(root);

	return 0;
}