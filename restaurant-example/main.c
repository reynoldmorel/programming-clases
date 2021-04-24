#include <stdio.h>
#include <stdlib.h>

/*
This will represents the products sold by the restaurant.

Example: 
	A simple product could be: pizza, tacos, beer...
*/
typedef struct Product
{
	int id;
	char *name;
	char *description;
} Product;


typedef struct Stock
{
	int id;
	char *name;
	char *description;
	Product *products
} Stock;

int main(int argc, char *argv[])
{
	return 0;
}