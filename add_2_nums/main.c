#include <stdio.h>
#include <stdlib.h>
int add(int n1, int n2);

int main()
{
    printf("Hello World!");
    int result = add(1, 2);
    return 0;
}

int add(int n1, int n2)
{
    return n1 + n2;
}