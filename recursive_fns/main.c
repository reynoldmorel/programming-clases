#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/*
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
*/

int factorial (int n);

int main(int argc, char** argv) {
	int result  = factorial(5);
	printf("The factorial of %d is: %d \n", 5, result);
	return 0;
}

int factorial (int n) {
	if(n == 1) {
		return 1;
	}
	printf("Current factorial -> %d * factorial(%d - 1)\n", n, n);
	int fact_result = factorial(n - 1);
	int result = n * fact_result;
	printf("%d * %d = %d\n", n, fact_result, result);
	return result;
}

/*
factorial(5)

5 * factorial(5 - 1) = 4 * factorial(4 - 1) = 3 * facorial(3 - 1) = 2 * factorial(2 - 1) = 1
2 * 1 = 2
3 * 2 = 6
4 * 6 = 24
5 * 24 = 120
*/