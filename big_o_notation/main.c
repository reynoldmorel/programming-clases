#include <stdio.h>
#include <stdlib.h>

int factorial(int n);
int test_n2_algo(int n);
int test_log_algo(int n);

int main()
{
    // 1 paso =  a
    int a = 1;
    // 1 paso =  b
    int b = 2;
    // 1 paso =  c
    int c = a + b;
    // 1 paso =  d
    printf("a = %d, b = %d, a + b = %d", a, b, c);
    // 1 paso =  e

    printf("\n------------------------------------\n");
    factorial(10);
    printf("\n------------------------------------\n");
    test_n2_algo(10);
    printf("\n------------------------------------\n");
    test_log_algo(10);
    return 0;

    // f(x) = a + b + c + d + e
    // Lim f(x) = a + b + c + d + e = 1 + 1 + 1 + 1 + 1 = 5
    // x -> ∞
    // O(1)
}

// n = 2
// factorial(2) = 2
// 2 * (factorial(1) = 1)

// n = 1
// factorial(1)
// 1 * (factorial(0) = 1)

// 0! = 1
// 2! = 2 * 1 = 2,
// 3! = 3 * 2 * 1 = 6,
// 4! = 4 * 3 * 2 * 1 = 24

// f(n) = (a + c) + (a + c) + .... + (a + b)
// f(n) = (n - 1)(a + c) + (a + b)
// Lim f(n) = (∞ - 1) (a + c) + (a + b) = (∞)(a + c) + (a + b) = ∞ + (a + b) = ∞
// n -> ∞
// Lim f(n) = ∞
// n -> ∞
// O(n)
int factorial(int n)
{
    printf("\nfactorial\n");

    // 1 paso = a
    if (n <= 1)
    {
        // 1 paso = b
        return 1;
    }

    // 1 paso = c
    return n * factorial(n - 1);
}

// f(n) = a + n(b + c + H(n)) + i
// Lim f(n) = a + ∞(b + c + H(∞)) + i
// n -> ∞
// Lim f(n) = a + ∞(b + c + e + ∞(f + g + h)) + i
// n -> ∞
// Lim f(n) = a + ∞(b + c + e + ∞) + i
// n -> ∞
// Lim f(n) = a + n(n) + i
// n -> ∞
// Lim f(n) = a + ∞^2 + i
// n -> ∞
// Lim f(n) = ∞^2
// n -> ∞
// O(n^2)
int test_n2_algo(int n)
{
    // int i = 0 => a
    // i < n => b
    // i++ => c
    // G(n) = a + n(b + c + H(n))
    for (int i = 0; i < n; i++)
    {
        // int k = 0 => e
        // k < n => f
        // k++ => g
        // H(n) = e + n(f + g + h)
        for (int k = 0; k < n; k++)
        {
            // 1 paso = h
            // printf("(%d, %d), ", i, k);
            printf("test_n2_algo\n");
        }
    }

    // 1 paso = i
    return 0;
}

// f(n) = a + (1 / 2 ^ n)(b + c + d) + e
// Lim f(n) = a + (1 / 2 ^ ∞)(b + c + d) + e
// n -> ∞
// Aislando el término predominante o que más influye en el algoritmo
// Lim f(n) = (1 / 2 ^ n)
// n -> ∞
// Cuando n tiende a infinito, las operaciones tienden a A, usemos A para denotar las operaciones dentro del ciclo
// A(1 / 2 ^ n) = 1
// A = 2 ^ n
// Tomanddo en cuenta como funcionan los logaritmos
// 2^3 = 8
// log2(8) = 3
//
// log2(A) = n
//
// Esto nos indica que el n número de operaciones que se realizan en el ciclo es logarítmico,
// por ende volviendo arriba
//
// Lim f(n) = a + (log n(b + c + d)) + e
// n -> ∞
// Lim f(n) = log ∞
// n -> ∞
// O(log n)
int test_log_algo(int n)
{
    // int k = n => a
    // k > 0 => b
    // k = k / 2 => c

    // a + n(b + c + d) + e

    // ...... analizar d solamente
    // 12 = 12 / 2 = 6 / 2 = 3 / 2 = 1 / 2 = 0
    // (d / 2 / 2 / 2)
    // d(((1 / 2) / 2) / 2)
    // d(1 / 2 ^ n)
    // (2 / 1) / (2 / 1) / (2 / 1) / (2 / 1) / (2 / 1) / (2 / 1)
    //  k / 2 * (1 / 2) * (1 / 2) * (1 / 2)* (1 / 2)
    for (int k = n; k > 0; k = k / 2)
    {
        // 1 paso = d
        printf("test_log_algo\n");
    }

    // 1 paso = e
    return 0;
}

// f(n) = (n (log n)) + (n (log n))
// Lim f(n) = (n (log n)) + (n (log n))
// n -> ∞
// Lim f(n) = (∞ (log ∞)) + (∞ (log ∞)) = O(n log n)
// n -> ∞
// Asumamos que (n (log n)) = m
// Lim f(n) = m + m = 2m = 2(n (log n)) = O(n log n)
// n -> ∞
int test_n_log_algo2(int n)
{
    int counter = 0;

    for (int i = 0; i < n; i++)
    {
        printf("-------------------\n");
        for (int k = i; k > 0; k = k / 2)
        {
            // 1 ciclo máq.
            // printf("(%d, %d), ", i, k);
            counter = counter + 1;
            printf("un ciclo maquina 1\n");
        }
    }

    printf("counter=%d\n", counter);
    printf("======================\n");

    counter = 0;

    for (int i = 0; i < n; i++)
    {
        printf("-------------------\n");
        for (int k = n; k > 0; k = k / 2)
        {
            // 1 ciclo máq.
            // printf("(%d, %d), ", i, k);
            counter = counter + 1;
            printf("un ciclo maquina 2\n");
        }
    }

    printf("counter=%d\n", counter);

    return 0;
}

// f(n) = n^2 + (n (log n)) + (n (log n))
// Lim f(n) = n^2 + (n (log n)) + (n (log n))
// n -> ∞
// Lim f(n) = ∞^2 + (∞ (log ∞)) + (∞ (log ∞)) = O(n^2)
// n -> ∞
// Asumamos que (n (log n)) = m
// Lim f(n) = n^2 + m + m = n^2 + 2m = n^2 + 2(n (log n)) = O(n^2)
// n -> ∞
int test_n_log_algo3(int n)
{
    int counter = 0;

    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < n; k++)
        {
            printf("test_n2_algo\n");
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("-------------------\n");
        for (int k = i; k > 0; k = k / 2)
        {
            counter = counter + 1;
            printf("un ciclo maquina 1\n");
        }
    }

    printf("counter=%d\n", counter);
    printf("======================\n");

    counter = 0;

    for (int i = 0; i < n; i++)
    {
        printf("-------------------\n");
        for (int k = n; k > 0; k = k / 2)
        {
            counter = counter + 1;
            printf("un ciclo maquina 2\n");
        }
    }

    printf("counter=%d\n", counter);

    return 0;
}