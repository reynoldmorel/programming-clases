#include <stdio.h>
#include <stdlib.h>

#define TOTAL_ELEMENTS 10

// Variables and functions declarations
int newBinarySearch(int valToFind, int array[TOTAL_ELEMENTS]);
int numbers[TOTAL_ELEMENTS];
int searchIndex;
int valToFind;
void checkResult(int result);

// Main function
int main()
{
    for (int i = 0; i < TOTAL_ELEMENTS; i++)
    {
        numbers[i] = i;
    }

    valToFind = 2;
    searchIndex = newBinarySearch(valToFind, numbers);

    checkResult(searchIndex);

    return 0;
}

// New Binary Search function
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

// Check Result function
void checkResult(int result)
{
    if (result >- 0)
    {
        printf("El valor se encuentra en la posición: %d\n\n", result);
    }
    else
    {
        printf("El valor no se encuentra en el arreglo dado.\n\n");
    }
}
