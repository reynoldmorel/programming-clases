#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int factorial (int n);
int iterative_factorial (int n);

int main(int argc, char** argv) {
	int result = factorial(5);
	int iterative_result = iterative_factorial(5);
	
	printf("El resultado: %d", result);
	printf("El resultado iterativo: %d", iterative_result);
	return 0;
}

int factorial (int n) {
	if(n == 1){
		return 1;
	}
	
	return n * factorial(n - 1);
}

int iterative_factorial (int n) {
	int result = 1;
	
	for(int i = 1; i  <= n; i++) {
		result *= i;
	}
	
	return result;
}
