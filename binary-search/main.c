#include <stdio.h>
#include <stdlib.h>

#define TOTAL_ELEMENTS 10
int numbers[] = {10, 20, 35, 80, 100, 110, 120, 121, 136, 150};

int search(int val_to_find);
int binary_search(int val_to_find, int lower_bound, int higher_bound, int half);

int main(int argc, char ** argv)
{
    int val_to_find = 10;
    printf("-----------search()--------------\n");
    int index_found = search(val_to_find);
    printf("index_found = %d\n", index_found);
    printf("-----------binary_search()--------------\n");
    int index_found_by_binary_search = binary_search(val_to_find, 0, TOTAL_ELEMENTS - 1, (TOTAL_ELEMENTS - 1) / 2);
    printf("index_found_by_binary_search = %d\n", index_found_by_binary_search);
    return 0;
}

int search(int val_to_find)
{
    if(val_to_find == numbers[TOTAL_ELEMENTS - 1]) {
        return TOTAL_ELEMENTS - 1;
    }

    for(int i = 0; i < TOTAL_ELEMENTS; i++) {
        printf("i = %d\n", i);
        if(numbers[i] == val_to_find) {
            return i;
        }
    }

    return -1;
}

int binary_search(int val_to_find, int lower_bound, int higher_bound, int half)
{
    printf("half = %d\n", half);
    if(half < lower_bound || half > higher_bound) {
        return -1;
    }

    if(val_to_find == numbers[half]) {
        return half;
    } else if(val_to_find > numbers[half]) {
        lower_bound = half + 1;
        return binary_search(val_to_find, lower_bound, higher_bound, (higher_bound + lower_bound) / 2);
    } else if(val_to_find < numbers[half]) {
        higher_bound = half - 1;
        return binary_search(val_to_find, lower_bound, higher_bound, (higher_bound + lower_bound) / 2);
    }
}