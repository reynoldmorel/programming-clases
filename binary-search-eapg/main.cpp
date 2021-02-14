#include <stdio.h>
 
int binarySearch(int Arr[], int n, int x)
{

    int low = 0, high = n - 1;
 
    while (low <= high)
    {

        int mid = (low + high)/2;  

        if (x == Arr[mid]) {
            return mid;
        }

        else if (x < Arr[mid]) {
            high = mid - 1;
        }

        else {
            low = mid + 1;
        }
    }

    return -1;
}
 
int main(void)
{
    int Arr[] = { 2, 5, 6, 8, 9, 10 };
    int target = 2;
 
    int n = sizeof(Arr)/sizeof(Arr[0]);
    int index = binarySearch(Arr, n, target);
 
    if (index != -1) {
        printf("Element found at index %d", index);
    }
    else {
        printf("Element not found in the array");
    }
 
    return 0;
}