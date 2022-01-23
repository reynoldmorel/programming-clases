#include <stdio.h>
#include <stdlib.h>

int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
const int NUMBERS_SIZE = 10;

int binary_search(int num_to_search);
int binary_search2(int num_to_search);
int binary_search21(int num_to_search, int current_index);
int binary_search3(int num_to_search);
int binary_search31(int num_to_search, int lower_bound, int upper_bound);

int main()
{
    int num_index = binary_search(1);
    printf("\n\nThe index of the num we are looking for is %d", num_index);

    num_index = binary_search(2);
    printf("\n\nThe index of the num we are looking for is %d", num_index);

    num_index = binary_search(9);
    printf("\n\nThe index of the num we are looking for is %d", num_index);

    num_index = binary_search(19);
    printf("\n\nThe index of the num we are looking for is %d", num_index);

    printf("*******************************************************\n\n\n");

    num_index = binary_search2(9);
    printf("\n\n2The index of the num we are looking for is %d", num_index);

    num_index = binary_search2(19);
    printf("\n\n2The index of the num we are looking for is %d", num_index);

    printf("*******************************************************\n\n\n");

    num_index = binary_search3(9);
    printf("\n\n3The index of the num we are looking for is %d", num_index);

    num_index = binary_search3(19);
    printf("\n\n3The index of the num we are looking for is %d", num_index);
    printf("\n\n*******************************************************\n");

    return 0;
}

// Time complexity O(n)
// Space complexity O(1)
int binary_search(int num_to_search)
{
    for (int i = 0; i < NUMBERS_SIZE; i++)
    {
        if (num_to_search == numbers[i])
        {
            return i;
        }
    }

    return -1;
}

// Time complexity O(1)
// Space complexity O(1)
int binary_search2(int num_to_search)
{
    return binary_search21(num_to_search, 0);
}

// Time complexity O(n)
// Space complexity O(n)
int binary_search21(int num_to_search, int current_index)
{
    printf("binary_search21\n");
    if (current_index > NUMBERS_SIZE - 1)
    {
        return -1;
    }
    else if (num_to_search == numbers[current_index])
    {
        return current_index;
    }

    return binary_search21(num_to_search, current_index + 1);
}

// Time complexity O(1)
// Space complexity O(1)
int binary_search3(int num_to_search)
{
    return binary_search31(num_to_search, 0, NUMBERS_SIZE - 1);
}

// Time complexity O(log n)
// Space complexity O(log n)
int binary_search31(int num_to_search, int lower_bound, int upper_bound)
{
    printf("binary_search31\n");
    int half = (lower_bound + upper_bound) / 2;

    if (lower_bound >= upper_bound)
    {
        return -1;
    }
    else if (num_to_search == numbers[half])
    {
        return half;
    }
    else if (num_to_search == numbers[lower_bound])
    {
        return lower_bound;
    }
    else if (num_to_search == numbers[upper_bound])
    {
        return upper_bound;
    }

    if (num_to_search > numbers[half])
    {
        lower_bound = half + 1;
    }
    else
    {
        upper_bound = half - 1;
    }

    return binary_search31(num_to_search, lower_bound, upper_bound);
}