#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TOTAL_ELEMENTS 11

int numbers_RQS[] = {200, 1, 5, 6, 100, 25, 13, 7, 9, 3, 4};
int userValue;
int valueInArray;

void printArray();
void swap(int a, int b);
void randomizedQuickSort(int low, int high);
int partition(int low, int high, int print);
void checkResult(int result);


int main(int argc, char ** argv)
{
    srand((unsigned)time(NULL));

    printf("\n------------ Original array ------------\n");
    printArray();
    printf("------------------------------------------\n");

    printf( "\nIntroduzca una edad que desee buscar en la lista: ");
    scanf("%d", &userValue);

    printf("\n----------- Sorting process (randomized quick sort) ------------\n");
    randomizedQuickSort(0, TOTAL_ELEMENTS - 1);
    printf("\n----------------------------------------------------------------\n");

    printf("\n--------- Final State of array (randomized quick sort) ---------\n");
    printArray();
    printf("------------------------------------------------------------------\n");

    checkResult(valueInArray);

    return 0;
}

void printArray()
{
    printf("[ %d", numbers_RQS[0]);
    for(int i = 1; i < TOTAL_ELEMENTS; i++) 
    {
        printf(", %d", numbers_RQS[i]);
    }
    printf("]\n");
}

void swap(int a, int b)
{
    int tmp = numbers_RQS[a];
    numbers_RQS[a] = numbers_RQS[b];
    numbers_RQS[b] = tmp;
}

void randomizedQuickSort(int low, int high)
{
    if(low < high) 
    {   
        int randomIndex = (rand() % (high - low + 1)) + low;
        printf(">> Random pivot : %d\n", numbers_RQS[randomIndex]);
        swap(randomIndex, high);

        int pivot = partition(low, high, 1);

        if (valueInArray == 1)
        {
            return;
        }

        randomizedQuickSort(low, pivot - 1);
        randomizedQuickSort(pivot + 1, high);
    }
}

int partition(int low, int high, int print)
{
    int pivot = numbers_RQS[high];
    int j     = (low - 1);
    int i     = low;

    if (numbers_RQS[high] == userValue)
        {
            return valueInArray = 1;
        }

    for(; i <= high - 1; i++) {
        if (numbers_RQS[i] == userValue)
        {
            return valueInArray = 1;
        }
        else if (numbers_RQS[i] < pivot)
        {
            if (print)
            {
                printf("Swaping %d with %d\n", numbers_RQS[j], numbers_RQS[i]);
            }

            j++;
            int tmp    = numbers_RQS[j];
            numbers_RQS[j] = numbers_RQS[i];
            numbers_RQS[i] = tmp;
        }
    }

    j++;
    int tmp    = numbers_RQS[j];
    numbers_RQS[j] = numbers_RQS[i];
    numbers_RQS[i] = tmp;

    return j;
}

void checkResult(int result)
{
    if (result > 0)
    {
        printf("\n[~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~]");
        printf("\n| La edad se encuentra en la lista de datos. |");
        printf("\n[~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~]\n\n");
    }
    else
    {
        printf("\n[~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~]");
        printf("\n| La edad NO se encuentra en la lista de datos. |");
        printf("\n[~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~]\n\n");
    }
}
