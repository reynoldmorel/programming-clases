#include <stdio.h>
#include <stdlib.h>

int number_list_size = 10;
int number_list[] = {10, 9, 8, 7, 6, 1, 2, 3, 4, 5};

void swap(int prev_index, int current_index);
void bubble_sort_asc();

int main()
{
    printf("Unsorted array\n");
    for (int i = 0; i < number_list_size; i++)
    {
        printf("%d, ", number_list[i]);
    }

    bubble_sort_asc();

    printf("\nSorted array\n");
    for (int i = 0; i < number_list_size; i++)
    {
        printf("%d, ", number_list[i]);
    }

    return 0;
}

void swap(int prev_index, int current_index)
{
    int temp = number_list[prev_index];
    number_list[prev_index] = number_list[current_index];
    number_list[current_index] = temp;
}

// TIME COMPLEXITY
// O(n) * O(n) * O(1) = O(n^2)
void bubble_sort_asc()
{
    if (number_list_size == 1)
    {
        return;
    }

    // O(n)
    for (int i = 0; i < number_list_size; i++)
    {
        int swap_occurred = 0;

        // O(n)
        for (int k = 1; k < number_list_size - i; k++)
        {
            // O(1) operaciones contante conllevan tiempo constante
            // en el pero de los casos
            int prev_index = k - 1;
            int current_index = k;

            if (number_list[prev_index] > number_list[current_index])
            {
                swap_occurred = 1;
                swap(prev_index, current_index);
            }
        }

        if (!swap_occurred)
        {
            break;
        }
    }
}