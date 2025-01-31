#include <stdio.h>
#include <stdlib.h>

int number_list_size = 10;
int number_list[] = {10, 9, 7, 5, 4, 6, 3, 8, 2, 1};
int swap_count = 0;

void swap(int index1, int index2);
void bubble_sort_asc();

int main()
{
    printf("Unsorted array\n");
    for (int i = 0; i < number_list_size; i++)
    {
        printf("%d, ", number_list[i]);
    }

    printf("\n");

    bubble_sort_asc(0, number_list_size - 1);

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

// O(n^2)
void bubble_sort_asc()
{

    // O(n * g)
    for (int i = 0; i < number_list_size; i++)
    {
        int swap_occured = 0;
        // g = O(n)
        for (int j = 0; j < number_list_size - 1; j++)
        {
            if (number_list[j] > number_list[j + 1])
            {
                swap_occured = 1;
                swap(j, j + 1);
            }
        }

        if (!swap_occured)
        {
            break;
        }
    }
}