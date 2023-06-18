#include <stdio.h>
#include <stdlib.h>
int factorial(int n);
int recursive_factorial(int n);

int main()
{
    int n = 4;
    int result = factorial(n);
    printf("factorial of %d is %d", n, result);
    return 0;
}

// O(n)
int factorial(int n)
{
    int result = 1;

    // 4! = 4 x 3 x 2 x 1
    for (int i = n; i >= 1; i--)
    {
        result = result * i;
    }

    return result;
}

// For n = 4:
// recursive_factorial(4)
// pending: 4 * recursive_factorial(4 - 1);
// pending: 4 * 6;
// return 24;
// recursive_factorial(4) = 24
//
// For n = 3:
// recursive_factorial(3)
// pending: 3 * recursive_factorial(3 - 1);
// pending: 3 * 2;
// return 6;
// recursive_factorial(3) = 6
// recursive_factorial(4 - 1) = recursive_factorial(3)
//
// For n = 2:
// recursive_factorial(2)
// pending: 2 * recursive_factorial(2 - 1);
// pending: 2 * 1;
// return 2;
// recursive_factorial(2) = 2
// recursive_factorial(3 - 1) = recursive_factorial(2)
//
// For n = 1:
// recursive_factorial(1)
// returns 1;
// recursive_factorial(1) = 1
//
// recursive_factorial(2 - 1) = recursive_factorial(1)
// O(n)
int recursive_factorial(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    // 4! = 4 x 3 x 2 x 1
    return n * recursive_factorial(n - 1);
}