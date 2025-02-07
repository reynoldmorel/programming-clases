#include <stdio.h>
#include <stdlib.h>

typedef struct PersonLaLa Person;

struct PersonLaLa
{
    char *name;
    char *lastname;
    int age;
    void (*print)(Person *person);
    Person *son;
};

void print(Person *person);
int sum(int n1, int n2);
int subtract(int n1, int n2);
int mult(int n1, int n2);
int divide(int n1, int n2);

int main()
{
    int a = 1;
    int b = a;
    int c = b + 4;

    b++;

    printf("a = %d, b = %d, c = %d\n", a, b, c);

    int *d = malloc(sizeof(int));
    int *e = d;
    int *f = e;
    d[0] = 2;
    *e = *d + 2;
    *f = *d + 2;

    printf("d = %d, e = %d, f = %d\n", *d, *e, *f);

    free(d);

    int operation = 0;
    int (*op)(int n1, int n2);

    int n1 = 10;
    int n2 = 5;

    if (operation == 0)
    {
        op = &sum;
    }
    else if (operation == 1)
    {
        op = &subtract;
    }
    else if (operation == 2)
    {
        op = &mult;
    }
    else if (operation == 3)
    {
        op = &divide;
    }

    printf("n1=%d, n2=%d\n", n1, n2);
    printf("op: %d\n", op(n1, n2));
    printf("n1=%d, n2=%d\n", n1, n2);

    int *g = malloc(sizeof(int) * 2);
    g[0] = 1;
    g[1] = 2;

    *g = 3;
    g = g + 1;
    *g = 4;

    g = g - 1;

    printf("g[0] = %d, g[1] = %d\n", g[0], g[1]);

    free(g);

    Person person;
    Person son;

    person.name = "Reynold";
    person.lastname = "Morel";
    person.age = 30;
    person.print = NULL;

    person.son = &son;
    person.son->name = "Reynold Jr.";

    if(person.print == NULL)
    {
        person.print = &print;
    }

    person.print(&person);
    person.print(&person);
    person.age = 15;
    person.print(&person);

    return 0;
}

int sum(int n1, int n2)
{
    n1 = 99;
    return n1 + n2;
}

int subtract(int n1, int n2)
{
    return n1 - n2;
}

int mult(int n1, int n2)
{
    return n1 * n2;
}

int divide(int n1, int n2)
{
    return n1 / n2;
}

void print(Person *person)
{
    printf("name=%s\n", person->name);
    printf("lastname=%s\n", person->lastname);
    printf("age=%d\n", person->age);

    printf("son name=%s\n", person->son->name);

    person->age = 25;
}