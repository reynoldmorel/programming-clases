#include <stdio.h>
#include <stdlib.h>

unsigned long compute_fact(int num1);
unsigned long compute_fact2(int num1);

int main()
{
    unsigned long result = compute_fact(1);
    printf("\n\nThe result factorial of 1 is %u", result);

    result = compute_fact(2);
    printf("\n\nThe result factorial of 2 is %u", result);

    result = compute_fact(3);
    printf("\n\nThe result factorial of 3 is %u", result);

    result = compute_fact(4);
    printf("\n\nThe result factorial of 4 is %u", result);

    result = compute_fact(5);
    printf("\n\nThe result factorial of 5 is %u", result);

    result = compute_fact2(4);
    printf("\n\nThe result factorial2 of 4 is %u", result);

    result = compute_fact2(5);
    printf("\n\nThe result factorial2 of 5 is %u", result);

    return 0;
}

// Time complexity O(n)
// Space complexity O(n)
unsigned long compute_fact(int num1)
{
    if (num1 == 1)
    {
        return num1;
    }

    return num1 * compute_fact(num1 - 1);
}

// Time complexity O(n)
// Space complexity O(1)
unsigned long compute_fact2(int num1)
{
    unsigned long result = 1;

    for (int i = 2; i <= num1; i++)
    {
        result = result * i;
    }

    return result;
}
