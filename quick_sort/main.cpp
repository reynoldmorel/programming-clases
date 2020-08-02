#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#define TOTAL_ELEMENTS 7

int numbers[TOTAL_ELEMENTS] = {10,  100, 105, 30, 80, 40, 500};

void quick_sort(int from_index, int to_index);
int locate_pivot(int from_index, int to_index);

int main(int argc, char** argv) {
	
	printf("Sin Ordenar\n");
	
	for(int i = 0; i < TOTAL_ELEMENTS; i++) {
		printf("numbers[%d] = %d\n", i, numbers[i]);
	}
	
	quick_sort(0, TOTAL_ELEMENTS - 1);
	
	printf("Ordenado\n");
	
	for(int i = 0; i < TOTAL_ELEMENTS; i++) {
		printf("numbers[%d] = %d\n", i, numbers[i]);
	}
	
	return 0;
}

void quick_sort(int from_index, int to_index) {	
	if(from_index < to_index) {
		int pivot_index = locate_pivot(from_index, to_index);
		
		quick_sort(from_index, pivot_index - 1);
		quick_sort(pivot_index + 1, to_index);
	}
}

int locate_pivot(int from_index, int to_index) {
	int piv = numbers[to_index];
	int i = from_index - 1;
	
	for(int j = from_index; j <= to_index - 1; j++) {
		if(piv > numbers[j]) {
			i++;
			
			int temp = numbers[j];
			numbers[j] = numbers[i];
			numbers[i] = temp;
		}
	}
	
	int temp = numbers[i + 1];
	numbers[i + 1] = piv;
	numbers[to_index] = temp;
	
	return i + 1;
}








