#include <stdio.h>
#include <stdlib.h>
int search(int number_to_find);
int binary_search(int number_to_find, int lower_bound_index, int upper_bound_index);

int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int numbers_size = 10;

int main()
{
    printf("\n------------Normal search-----------------\n");

    printf("\nsearch 3\n");
    int number_to_find = 3;
    int found = search(number_to_find);

    printf("\nsearch(%d) = %d", number_to_find, found);

    printf("\nsearch 9\n");
    number_to_find = 9;
    found = search(number_to_find);

    printf("\nsearch(%d) = %d", number_to_find, found);

    printf("\nsearch 90\n");
    number_to_find = 90;
    found = search(number_to_find);

    printf("\nsearch(%d) = %d", number_to_find, found);

    printf("\n------------Binary search-----------------\n");

    printf("\nsearch 3\n");
    number_to_find = 3;
    found = binary_search(number_to_find, 0, numbers_size - 1);

    printf("\nbinary_search(%d) = %d", number_to_find, found);

    printf("\nsearch 9\n");
    number_to_find = 9;
    found = binary_search(number_to_find, 0, numbers_size - 1);

    printf("\nbinary_search(%d) = %d", number_to_find, found);

    printf("\nsearch 90\n");
    number_to_find = 90;
    found = binary_search(number_to_find, 0, numbers_size - 1);

    printf("\nbinary_search(%d) = %d", number_to_find, found);

    return 0;
}

// O(n)
int search(int number_to_find)
{
    for (int i = 0; i < numbers_size; i++)
    {
        printf("\n\t\tsearch, iteration number %d", i);
        if (numbers[i] == number_to_find)
        {
            return i;
        }
    }

    return -1;
}

// O(log n)
int binary_search(int number_to_find, int lower_bound_index, int upper_bound_index)
{
    printf("\n\t\tbinary_search, bounds %d - %d", lower_bound_index, upper_bound_index);

    // Limiting the recursive search until
    // bounds overlap or are the same.
    if (lower_bound_index >= upper_bound_index)
    {
        return -1;
    }

    int left_most_number = numbers[lower_bound_index];
    int right_most_number = numbers[upper_bound_index];
    int half_index = (lower_bound_index + upper_bound_index) / 2;

    // Compare if the number to find is one of:
    // 1. Left most number
    // 2. Right most number
    // 3. Half number
    if (number_to_find == left_most_number)
    {
        return lower_bound_index;
    }

    if (number_to_find == right_most_number)
    {
        return upper_bound_index;
    }

    if (numbers[half_index] == number_to_find)
    {
        return half_index;
    }

    // f(n) = ((n / 2) / 2) / 2
    // f(n) = n / 2 ^ k
    // 1 = n / 2 ^ k
    // 2 ^ k = n
    // ln n = k
    // Since log 2 is constant
    // log n = k
    // Split list depending on the location
    // of the number to find
    if (number_to_find > numbers[half_index])
    {
        // It's located at the right
        // so lower bound needs to be
        // after the half index
        upper_bound_index = upper_bound_index - 1;
        lower_bound_index = half_index + 1;
    }
    else
    {
        // It's located at the left
        // so upper bound needs to be
        // before the half index
        upper_bound_index = half_index - 1;
        lower_bound_index = lower_bound_index + 1;
    }

    return binary_search(number_to_find, lower_bound_index, upper_bound_index);
}


// TASK:
// You have the following list of person ids:
// int person_ids[] = {1000, 1002, 1003, 1004, 1005, 1076, 1125, 1230, 2431, 3465}
// int person_ages_in_years[] = {6, 8, 10, 12, 15, 18, 19, 20, 26, 44}
// Each index of the person_ids belongs to each index of the person_ages_in_years.

// Excersice:
// 1- What is the index of the person with 20 years?
// 2- What is the index of the age of the person id 1125?
// 3- Does this person id exist 3322?
