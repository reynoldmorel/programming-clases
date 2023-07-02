#include <stdio.h>
#include <stdlib.h>
int add(int *n1, int n2);
int multiply(int *n1, int n2);

struct Person
{
    char *name;
    char *lastname;
    int age;
};

int main()
{

    struct Person reynold;
    reynold.name = "Reynold Jesus";
    reynold.lastname = "Morel";
    reynold.age = 50;

    int person_size = sizeof(reynold);

    printf("Hello World!\n");
    int int_size = sizeof(int);
    int *b = malloc(sizeof(int));
    *b = 10;
    int a = 10;
    int result = add(b, 2);
    printf("%d\n", *b);

    int (*operation)(int *n1, int n2) = &add;

    int option = 0;

    if (option == 1)
    {
        operation = &multiply;
    }

    result = operation(b, 2);

    return 0;
}

int add(int *z, int n2)
{
    *z = 20;
    printf("%d\n", *z);
    return *z + n2;
}

int multiply(int *z, int n2)
{
    *z = 20;
    return *z * n2;
}