#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TOTAL_ELEMENTS 11

int numbers_RQS[] = {200, 1, 5, 6, 100, 25, 13, 7, 9, 3, 4};
int userValue;

void printArray();
int randomSelection(int low, int high, int orderStatistic);
void swap(int a, int b);
void randomizedQuickSort(int low, int high);
int partition(int low, int high, int print);
int newBinarySearch(int valToFind, int array[TOTAL_ELEMENTS]);
void checkResult(int result);


int main(int argc, char ** argv)
{
    srand((unsigned)time(NULL));

    printf("\n------------ Original array ------------\n");
    printArray();
    printf("----------------------------------------\n");

    //userValue = 15;
    printf( "\nIntroduzca una edad que desee buscar en la lista: ");
    scanf("%d", &userValue);

    printf("\n------- Sorting process (randomized quick sort) --------\n");
    randomizedQuickSort(0, TOTAL_ELEMENTS - 1);
    printf("\n--------------------------------------------------------\n");

    printf("\n--------- Sorted array (randomized quick sort) ---------\n");
    printArray();
    printf("--------------------------------------------------------\n");

    checkResult(newBinarySearch(userValue, numbers_RQS));

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

int newBinarySearch(int valToFind, int array[TOTAL_ELEMENTS])
{
    int lowerBound = 0;
    int higherBound = TOTAL_ELEMENTS - 1;
    int half = (higherBound + lowerBound) / 2;

    while(half >= lowerBound && half <= higherBound)
    {   
        //printf("Value in array: %d    index: %d\n", array[half], half); /* Just for test purpuses */
        if (valToFind == array[half])
        {
            return half;
        }
        else if ( valToFind > array[half])
        {
            lowerBound = half + 1;
        }
        else if (valToFind < array[half])
        {
            higherBound = half - 1;
        }
        else
        {
            return -1;
        }

        half = (higherBound + lowerBound) / 2;
    }
    return -1;
}

void swap(int a, int b)
{
    int tmp = numbers_RQS[a];
    numbers_RQS[a] = numbers_RQS[b];
    numbers_RQS[b] = tmp;
}

int randomSelection(int low, int high, int orderStatistic)
{
    if (low < high)
    {
        // randomized selection
        int randomIndex = (rand() % (high - low + 1)) + low;

        // moving pivot to the end of the array
        swap(randomIndex, high);

        int pivotIndex = partition(low, high, 0);

        //printf("\nValue: %d, index: %d\n", numbers_RQS[pivotIndex], pivotIndex); // test

        if (pivotIndex == orderStatistic) return pivotIndex;
        else if (pivotIndex > orderStatistic)
        {
            return randomSelection(low, pivotIndex - 1, orderStatistic);
        }
        else if (pivotIndex < orderStatistic)
        {
            return randomSelection(pivotIndex + 1, high, orderStatistic);
        }
    }
    else
    {
        return low;        
    } 
}

void randomizedQuickSort(int low, int high)
{
    int orderStatistic;
    if ((high - low + 1) % 2)   // Si cantidad total de elementos es impar
        {
            orderStatistic = ((((high - low + 1) + 1) / 2) - 1) + low;
        }
        else                        // Si cantidad total de elementos es par
        {
            orderStatistic = (((high - low + 1) / 2) - 1) + low;
        }

    if(low < high) 
    {   
        int medianPivot = randomSelection(low, high, orderStatistic);

        printf(">> Median pivot : %d\n", numbers_RQS[medianPivot]);

        swap(medianPivot, high);

        int pivot = partition(low, high, 1);

        randomizedQuickSort(low, pivot - 1);
        randomizedQuickSort(pivot + 1, high);
    }
}

int partition(int low, int high, int print)
{
    int pivot = numbers_RQS[high];
    int j     = (low - 1);
    int i     = low;

    for(; i <= high - 1; i++) {
        if(numbers_RQS[i] < pivot)
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
    if (result >= 0)
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
