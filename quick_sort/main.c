#include <stdio.h>
#include <stdlib.h>

#define TOTAL_ELEMENTS 11
int numbers[]  = {200, 1, 5, 6, 100, 25, 13, 7, 9, 3, 4};
int numbers_to_use_quick_sort[] = {200, 1, 5, 6, 100, 25, 13, 7, 4, 3, 9};

void bubble_sort();
void quick_sort(int low, int high);
int partition(int low, int high);

int main(int argc, char ** argv)
{
    printf("------- Original array --------\n");
    for(int i = 0; i < TOTAL_ELEMENTS; i++) {
        printf("%d, ", numbers[i]);
    }

    bubble_sort();

    printf("\n------- Sorted array (bubble sort) --------\n");

    for(int i = 0; i < TOTAL_ELEMENTS; i++) {
        printf("%d, ", numbers[i]);
    }

    quick_sort(0, TOTAL_ELEMENTS - 1);

    printf("\n------- Sorted array (quick sort) --------\n");

    for(int i = 0; i < TOTAL_ELEMENTS; i++) {
        printf("%d, ", numbers_to_use_quick_sort[i]);
    }
    return 0;
}

// Time complexity: O(n^2)
void bubble_sort()
{
    printf("\n------- Sorting process --------\n");
    for(int i = 0; i < TOTAL_ELEMENTS; i++) {
        int not_sorted = 0;
        printf("------- Iterating again --------\n");
        for(int j = 0; j < (TOTAL_ELEMENTS - 1); j++) {
            if(numbers[j] > numbers[j + 1]) {
                printf("Swaping %d with %d\n", numbers[j], numbers[j + 1]);
                not_sorted     = 1;
                int tmp        = numbers[j];
                numbers[j]     = numbers[j + 1];
                numbers[j + 1] = tmp;
            }
        }

        if(not_sorted == 0) {
            break;
        }
    }
}

// Time complexity: O(n * log(n))
void quick_sort(int low, int high)
{
    if(low < high) {
        int pivot = partition(low, high);

        quick_sort(low, pivot - 1);
        quick_sort(pivot + 1, high);
    }
}

int partition(int low, int high)
{
    int pivot = numbers_to_use_quick_sort[high];
    int j     = (low - 1);
    int i     = low;

    for(; i <= high - 1; i++) {
        if(numbers_to_use_quick_sort[i] < pivot) {
            printf("Swaping %d with %d\n", numbers_to_use_quick_sort[j], numbers_to_use_quick_sort[i]);
            j++;
            int tmp    = numbers_to_use_quick_sort[j];
            numbers_to_use_quick_sort[j] = numbers_to_use_quick_sort[i];
            numbers_to_use_quick_sort[i] = tmp;
        }
    }

    j++;
    int tmp    = numbers_to_use_quick_sort[j];
    numbers_to_use_quick_sort[j] = numbers_to_use_quick_sort[i];
    numbers_to_use_quick_sort[i] = tmp;

    return j;
}