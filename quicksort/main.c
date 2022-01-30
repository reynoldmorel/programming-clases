#include <stdio.h>
#include <stdlib.h>

#define TOTAL_ELEMENTS 3
int numbers_to_use_quick_sort[] = {2, 9, 5};

// 2, 1, 3,10, 10 10 

void quick_sort(int low, int high);
int partition(int low, int high);

int main(int argc, char **argv)
{
    printf("\n------- Unsorted array (quick sort) --------\n");

    for (int i = 0; i < TOTAL_ELEMENTS; i++)
    {
        printf("%d, ", numbers_to_use_quick_sort[i]);
    }

    printf("\n---------------\n");

    quick_sort(0, TOTAL_ELEMENTS - 1);

    printf("\n------- Sorted array (quick sort) --------\n");

    for (int i = 0; i < TOTAL_ELEMENTS; i++)
    {
        printf("%d, ", numbers_to_use_quick_sort[i]);
    }
    return 0;
}

/// 2, 3, 4, 5, 6

// Time complexity: O(n * log(n))
void quick_sort(int low, int high)
{
    if (low < high)
    {
        int pivot = partition(low, high);

        quick_sort(low, pivot - 1);
        quick_sort(pivot + 1, high);
    }
}

int partition(int low, int high)
{
    int pivot = numbers_to_use_quick_sort[high];
    
    /*
    printf("\n------------ SORTING ----------\n");
    printf("\nPivot %d\n", pivot);
    printf("\nlow %d high %d\n", low, high);
    */

    int j = (low - 1);
    int i = low;

    for (; i <= high - 1; i++)
    {
        if (numbers_to_use_quick_sort[i] < pivot)
        {
            j++;
            // printf("Swaping %d with %d\n", numbers_to_use_quick_sort[j], numbers_to_use_quick_sort[i]);
            int tmp = numbers_to_use_quick_sort[j];
            numbers_to_use_quick_sort[j] = numbers_to_use_quick_sort[i];
            numbers_to_use_quick_sort[i] = tmp;
        }
    }

    j++;
    // printf("\nSwaping %d with %d\n", numbers_to_use_quick_sort[j], numbers_to_use_quick_sort[i]);
    int tmp = numbers_to_use_quick_sort[j];
    numbers_to_use_quick_sort[j] = numbers_to_use_quick_sort[i];
    numbers_to_use_quick_sort[i] = tmp;

    /*
    printf("\n------- Sort Result --------\n");

    for (int i = 0; i < TOTAL_ELEMENTS; i++)
    {
        printf("%d, ", numbers_to_use_quick_sort[i]);
    }

    printf("\n--------------\n");
    */

    return j;
}
