#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#define TOTAL_ELEMENTS 1000000

int numbers[TOTAL_ELEMENTS];

int binary_search(int n);

int main(int argc, char** argv) {
	// Create branch under the following convention: feature/task-username.
	
	// Create an algorithm that searches for a specific element in an int array
	// Example: create an array with the following elements: 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20.
	// Create a function number_exists(int n). This function will return 1 if the number exists and 0 if doesn't.
	
	// Task 1: Using binary-search. Create a function that allows to know if there is a child in a club by finding persons by age.
	// The function will be named as find_minor(int n). 
	// The array of names will be: "John", "María", "Kelvin", "Diana", "Reynold", "José".
	// The array of ages to the corresponding person is: 25, 30, 15, 18, 13, 60
	// The lowest age to get in the club is 18 years.
	
	// Task 2: Read about sorting algorithms: Quicksort and Bubblesort.
	
	// Task 3: Create a function that given an array of integers, returns an array of sums of previous integers to the current one.
	// if we have the following array: [1,2,3,4] the result must be: [1,3,6,10] = [(1), (1+2), (1+2+3), (1+2+3+4)]
	
	for(int i = 0; i < TOTAL_ELEMENTS; i++) {
		numbers[i] = i + 1;
	}
	
	int result = binary_search(1000000);
	
	printf("El resultado es: %d", result);
	
	return 0;
}

int binary_search(int n) {
	return 0;
}

