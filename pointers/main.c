#include <stdio.h>
#include <stdlib.h>

void addProduct1(int *total);
void addProduct2(int *total);
void addProduct3(int *total);

void (*addProduct)(int *total);

typedef struct Person
{
	char *name;
	int age;
} Person;

typedef struct Student
{
	Person person;
	int ID;
} Student;

int main(int argc, char **argv)
{
	Person person;
	person.name = "Luigi Cuevas";
	person.age = 28;

	Person *pperson = malloc(sizeof(Person));
	pperson->name = "Luigi Cuevas";
	pperson->age = 28;

	int total = 0;
	int subtotal = 0;
	int *tmp = total > 5 ? &subtotal : &total;

	addProduct = &addProduct1;
	addProduct(&total);

	addProduct = &addProduct2;
	addProduct(&total);

	addProduct = &addProduct3;
	addProduct(tmp);

	printf("El total es %d\n", total);

	printf("sizeof(int) %d\n", sizeof(int));
	printf("sizeof(char) %d\n", sizeof(char));
	printf("sizeof(long) %d\n", sizeof(long));
	printf("sizeof(unsigned long long) %d\n", sizeof(unsigned long long));

	int *pnum1 = NULL;

	int **arr = malloc(sizeof(int) * 10);

	for (int i = 0; i < 10; i++)
	{
		arr[i] = malloc(sizeof(int) * 10);
	}

	for (int i = 0; i < 10; i++)
	{
		for (int y = 0; y < 10; y++)
		{
			arr[i][y] = 0;
		}
	}

	for (int i = 0; i < 10; i++)
	{
		free(arr[i]);
	}

	free(arr);

	return 0;
}

void addProduct1(int *total)
{
	*total = *total + 10;
}
void addProduct2(int *total)
{
	*total = *total + 20;
}
void addProduct3(int *total)
{
	*total = *total + 30;
}
