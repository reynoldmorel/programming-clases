#include <stdio.h>
#include <stdlib.h>

int add_2_nums(int num1, int num2);

int main() {
    // 3 steps
    // 2 for jumping when calling the function
    // 1 due to assignment
    int result = add_2_nums(1, 1);

    // 1 step to assume the job printf does
    printf("\n\nThe sum of 1 + 1 is %d", result);

    // 3 steps
    // 2 for jumping when calling the function
    // 1 due to assignment
    result = add_2_nums(10, 5);

    // 1 step to assume the job printf does
    printf("\n\nThe sum of 10 + 5 is %d", result);

    return 0;
}

// Time complexity O(1)
// Space complexity O(1)
int add_2_nums(int num1, int num2) {
    // 2 steps
    int result = num1 + num2;
    // 2 steps due to jump when returning the value
    return result;
}