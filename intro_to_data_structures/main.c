#include <stdio.h>
#include <stdlib.h>

int add(int a, int b);
int subtract(int a, int b);

typedef struct Person Person;

struct Person
{
    char *name;
    char *lastName;
    int age;
    int *height;
    int (*run_operation)(int a, int b);
};

int main()
{
    int a = 5;
    int b = a;
    b++;

    int *c = &a;
    *c = 3;

    printf("a = %d, b = %d, *c = %d, c = %llu, &a = %llu, &b = %llu", a, b, *c, c, &a, &b);

    int *d;
    d[0] = 3;
    d[1] = 4;
    printf("\nd = %llu, d[0] = %d, d[1] = %d, &d[0] = %llu, &d[1] = %llu", d, d[0], d[1], &d[0], &d[1]);

    int *e = malloc(sizeof(int) * 4);

    e[0] = 10;
    e[1] = 11;
    e[2] = 12;
    e[3] = 13;
    printf("\ne = %llu, e[0] = %llu, e[1] = %llu, e[2] = %llu, e[3] = %llu", e, &e[0], &e[1], &e[2], &e[3]);

    free(e);

    Person person;

    printf("\nperson size = %d", sizeof(Person));

    person.age = 10;
    person.name = "Reynold";
    person.lastName = "Morel";
    person.height = c;

    printf("\nname =%s, last name = %s, age = %d, height = %llu", person.name, person.lastName, person.age, person.height);

    Person *person2 = malloc(sizeof(Person));

    person2->age = 10;
    person2->name = "Jose";
    person2->lastName = "Haddad";
    person2->height = c;
    person2->run_operation = &add;

    int person_result = person2->run_operation(5, 10);

    printf("\nname =%s, last name = %s, age = %d, height = %llu, person_result = %d", person2->name, person2->lastName, person2->age, person2->height, person_result);

    free(person2);

    int option = 1;
    int (*run_operation)(int a, int b);

    if (option == 0)
    {
        run_operation = &add;
    }

    if (option == 1)
    {
        run_operation = &subtract;
    }
    
    printf("\nro = %llu, add = %llu", &run_operation, &add);

    int result = run_operation(1, 1);

    printf("\nresult = %d", result);

    return 0;
}

int add(int a, int b)
{
    return a + b;
}

int subtract(int a, int b)
{
    return a - b;
}