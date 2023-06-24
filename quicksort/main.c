#include <stdio.h>
#include <stdlib.h>

void bubble_sort();
void swap(int origin_index, int destination_index);
void print_numbers();

int partition_index(int lower_bound_index, int upper_bound_index);
void quicksort(int lower_bound_index, int upper_bound_index);
int select_pivot_index(int lower_bound_index, int upper_bound_index);

// int numbers[] = {1, 20, 300, 45, 15, 6, 77, 28, 9, 100};
int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int numbers_size = 10;

int operations_counter = 0;
int operations_in_general_counter = 0;


int main()
{
    operations_counter = 0;
    operations_in_general_counter = 0;

    /*
    printf("\nBefore sorting");
    print_numbers();
    bubble_sort();
    printf("\nAfter sorting");

    operations_counter = 0;
    operations_in_general_counter = 0;
    */

    
    printf("\nBefore quicksort sorting");
    print_numbers();
    quicksort(0, numbers_size - 1);
    printf("\nAfter quicksort sorting");
    print_numbers();
    
    return 0;
}

// O(n^2)
void bubble_sort()
{
    int swap_ocurred = 0;

    for (int i = 0; i < numbers_size - 1; i++)
    {
        for (int j = 0; j < numbers_size - 1; j++)
        {
            operations_in_general_counter = operations_in_general_counter + 1;
            printf("\n %d - operations\n", operations_in_general_counter);

            int current_number = numbers[j];
            int next_index = j + 1;
            int next_number = numbers[next_index];

            if (current_number > next_number)
            {
                operations_counter = operations_counter + 1;
                printf("\n %d - swap(%d, %d)\n", operations_counter, i, next_index);

                swap_ocurred = 1;
                swap(j, next_index);
            }
        }

        if (!swap_ocurred)
        {
            break;
        }
    }
}

void swap(int origin_index, int destination_index)
{
    int temp = numbers[origin_index];
    numbers[origin_index] = numbers[destination_index];
    numbers[destination_index] = temp;
}

void print_numbers()
{
    printf("\n----------------------------\n");
    for (int i = 0; i < numbers_size; i++)
    {
        printf("%d, ", numbers[i]);
    }
}

int select_pivot_index(int lower_bound_index, int upper_bound_index)
{
    return (lower_bound_index + upper_bound_index) / 2;
}

int partition_index(int lower_bound_index, int upper_bound_index)
{
    int pivot_index = select_pivot_index(lower_bound_index, upper_bound_index);
    int pivot = numbers[pivot_index];
    int last_changed_index = lower_bound_index - 1;

    for (int i = lower_bound_index; i <= upper_bound_index; i++)
    {
        operations_in_general_counter = operations_in_general_counter + 1;
        printf("\n %d - operations\n", operations_in_general_counter);

        int current_number = numbers[i];
        int last_changed_number = numbers[last_changed_index];

        if (current_number < pivot)
        {
            operations_counter = operations_counter + 1;
            printf("\n %d - swap(%d, %d)\n", operations_counter, i, last_changed_index);

            last_changed_index = last_changed_index + 1;

            swap(i, last_changed_index);

            if (last_changed_index == pivot_index)
            {
                pivot_index = i;
            }
        }
    }

    last_changed_index = last_changed_index + 1;

    swap(pivot_index, last_changed_index);

    return last_changed_index;
}
// O(n * n) = O(n ^ 2)
// avg.(n * log n)
void quicksort(int lower_bound_index, int upper_bound_index)
{
    if (upper_bound_index <= lower_bound_index)
    {
        return;
    }

    int pivot_index = partition_index(lower_bound_index, upper_bound_index);

    quicksort(lower_bound_index, pivot_index - 1);
    quicksort(pivot_index + 1, upper_bound_index);
}

// TASK:
// Create an efficient binary search for unsorted elements
// within an array. Make the algorithm be O(n * log n)
// for most of the cases.

