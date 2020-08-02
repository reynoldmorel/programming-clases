#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#define TOTAL_ELEMENTS 10

int numbers[TOTAL_ELEMENTS];

int binary_search(int n);

int main(int argc, char** argv) {
	for(int i = 0; i < TOTAL_ELEMENTS; i++) {
		numbers[i] = i + 1;
	}
	
	int result = binary_search(5);
	
	printf("El resultado es: %d", result);
	
	return 0;
}

int binary_search(int n) {
	int low = 0;
	int high = TOTAL_ELEMENTS - 1;
	
	while(low <= high) {
		int mid = (low + high) / 2;
		
		if(numbers[mid] == n) {
			return numbers[mid];
		} else if(n > numbers[mid]) {
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}
	
	return -1;
}

