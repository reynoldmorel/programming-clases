#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#define TOTAL_ELEMENTS 7

int numbers[TOTAL_ELEMENTS] = {10, 100, 105, 30, 80, 40, 500};

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int partition(int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = low - 1;

	for (int j = low; j < high; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}

	swap(&arr[i + 1], &arr[high]);

	return i + 1;
}

void quick_sort(int arr[], int low, int high)
{
	if (low < high)
	{
		int pi = partition(arr, low, high);

		quick_sort(arr, low, pi - 1);
		quick_sort(arr, pi + 1, high);
	}
}

void quick_sort_dynamic_programming(int arr[], int low, int high)
{
	int stack[high - low + 1];

	int top = -1;

	stack[++top] = low;
	stack[++top] = high;

	while (top >= 0)
	{
		high = stack[top--];
		low = stack[top--];

		int pi = partition(arr, low, high);

		if (pi - 1 > low)
		{
			stack[++top] = low;
			stack[++top] = pi - 1;
		}

		if (pi + 1 < high)
		{
			stack[++top] = pi + 1;
			stack[++top] = high;
		}
	}
}

int main(int argc, char **argv)
{

	printf("Sin Ordenar\n");

	for (int i = 0; i < TOTAL_ELEMENTS; i++)
	{
		printf("numbers[%d] = %d\n", i, numbers[i]);
	}

	quick_sort(numbers, 0, TOTAL_ELEMENTS - 1);

	printf("Ordenado\n");

	for (int i = 0; i < TOTAL_ELEMENTS; i++)
	{
		printf("numbers[%d] = %d\n", i, numbers[i]);
	}

	return 0;
}
