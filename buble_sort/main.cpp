#include <iostream>

#define TOTAL_ELEMENTS 7

int numbers[TOTAL_ELEMENTS] = {105,  100, 50, 30, 20, 10, 5};

void bubble_sort();

int main(int argc, char** argv) {
	
	printf("Sin Ordenar\n");
	
	for(int i = 0; i < TOTAL_ELEMENTS; i++) {
		printf("numbers[%d] = %d\n", i, numbers[i]);
	}
	
	bubble_sort();
	
	printf("Ordenado\n");
	
	for(int i = 0; i < TOTAL_ELEMENTS; i++) {
		printf("numbers[%d] = %d\n", i, numbers[i]);
	}
	
	return 0;
}
// Time: Worst Case O(n^2)
// Time: Average Case O(n log n)
// Time: Best Case O(n)
// Space: Worst Case O(4)
void bubble_sort() {
	for(int i = 0; i < TOTAL_ELEMENTS; i++) {
		int swaped = 0;
		
		for(int j = 0; j < TOTAL_ELEMENTS - 1; j++) {
			if(numbers[j] > numbers[j + 1]) {
				swaped = 1;
				
				int temp = numbers[j + 1];
				numbers[j + 1] = numbers[j];
				numbers[j] = temp;
			}
		}
		
		if(swaped == 0) {
			return;
		}
	}
}
