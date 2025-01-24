#include <stdio.h>
#include <stdlib.h>

int number_list_size = 10;
int number_list[] = {10, 2, 7, 5, 4, 6, 3, 8, 9, 1};
int swap_count = 0;

void swap(int index1, int index2);
int select_pivot_index(int lower_bound_index, int upper_bound_index);
void quick_sort_asc(int lower_bound_index, int upper_bound_index);
int partion_index_asc(int pivot_index, int lower_bound_index, int upper_bound_index);

int main()
{
    printf("Unsorted array\n");
    for (int i = 0; i < number_list_size; i++)
    {
        printf("%d, ", number_list[i]);
    }

    printf("\n");

    quick_sort_asc(0, number_list_size - 1);

    printf("\nSorted array\n");
    for (int i = 0; i < number_list_size; i++)
    {
        printf("%d, ", number_list[i]);
    }

    printf("\nswap_count=%d\n", swap_count);

    return 0;
}

void swap(int index1, int index2)
{
    int temp = number_list[index1];
    number_list[index1] = number_list[index2];
    number_list[index2] = temp;

    printf("swap(%d, %d)\n", index1, index2);
    swap_count = swap_count + 1;
}

int select_pivot_index(int lower_bound_index, int upper_bound_index)
{
    return (lower_bound_index + upper_bound_index) / 2;
}

int partion_index_asc(int pivot_index, int lower_bound_index, int upper_bound_index)
{
    int pivot_value = number_list[pivot_index];
    int last_swapped_index = lower_bound_index - 1;

    for (int current_index = lower_bound_index; current_index <= upper_bound_index; current_index++)
    {
        int current_number = number_list[current_index];

        if (current_number < pivot_value)
        {
            last_swapped_index = last_swapped_index + 1;

            swap(last_swapped_index, current_index);

            if (last_swapped_index == pivot_index)
            {
                pivot_index = current_index;
            }
        }
    }

    last_swapped_index = last_swapped_index + 1;

    swap(pivot_index, last_swapped_index);

    return last_swapped_index;
}

void quick_sort_asc(int lower_bound_index, int upper_bound_index)
{
    if (upper_bound_index <= lower_bound_index)
    {
        return;
    }

    int pivot_index = select_pivot_index(lower_bound_index, upper_bound_index);

    int partition_index = partion_index_asc(pivot_index, lower_bound_index, upper_bound_index);

    quick_sort_asc(lower_bound_index, partition_index - 1);
    quick_sort_asc(partition_index + 1, upper_bound_index);
}

// TAREA: Hacer un algoritmo que pueda buscar el menor número en la posición x en un tiempo máximo de O(n log n) en caso promedio.
// Reducir lo más que se pueda la ocurrencia del peor de los casos en O(n^2).

// Ejemplo:
// Input Del arreglo [30, 60, 80, 100, 10, 20, 70] buscar el 3er menor número. 
// Output: el 3er menor número del arreglo anterior es 30.