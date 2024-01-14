#include <stdio.h>
#include <stdlib.h>

int factorial(int n);
int test_n2_algo(int n);
int test_log_algo(int n);

int main()
{
    return 0;
}

// TIME COMPLEXITY
// f(n) = {1, 2} + f(n - 1)
// f(3) = {1,2} + {1,2} + {1, 2} ....
// a = {1, 2}
// f(3) = a + a + a
// f(3) = 4a
// f(4) = 5a ...
// f(n) = (n + 1)a
// Lim f(n) = Lim (n + 1)a = Lim na + a = ∞a + a = ∞
// n-> ∞      n-> ∞          n-> ∞
// O(n)
// SPACE COMPLEXITY
// Lim f(n) = Lim (b + 1)a = Lim ba + a = ba + a = ba + a
// n-> ∞      n-> ∞          n-> ∞
// O(1)
int factorial(int n)
{
    // n = 3
    // n = 2
    // n = 1
    // n = 0
    if (n == 0)
    {
        return 1;
    }

    // 3 * factorial( 3 - 1 = 2) = 3 * 2 = 6
    // 2 * factorial( 2 - 1 = 1) = 2 * 1 = 2
    // 1 * factorial( 1 - 1 = 0) = 1 * 1 = 1
    // 1
    return n * factorial(n - 1);
}

// TIME COMPLEXITY
// a = {2, 3, 4}
// f(n) = 1 + n(a + g(n))
// g(n) =  1 + n(a + 1)
// f(n) = 1 + n(a + 1 + n(a + 1))
// f(n) = 1 + an + n + an^2 + n^2
// Lim f(n) = Lim 1 + an + n + an^2 + n^2 = 1 + ∞ + a∞ + a∞^2 + ∞^2
// n-> ∞      n-> ∞
// = ∞^2 + ∞^2 = 2∞^2 = ∞^2 = n^2
// O(n^2)
int test_n2_algo(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < n; k++)
        {
            // 1 ciclo máq.
            printf("(%d, %d), ", i, k);
        }
    }
}

// TIME COMPLEXITY
// a = {2, 3, 4}
// f(n) = 1 + n(a + g(n))
// g(n) = 1 + k(a + 1)
// f(n) = 1 + n(a + 1 + k(a + 1))
// f(n) = 1 + an + n + akn + kn
// k = log n
// f(n) = 1 + an + n + a(log n)(n) + (log n)(n)
// O(n logn)
int test_log_algo(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int k = i; k > 0; k = k / 2)
        {
            // 1 ciclo máq.
            printf("(%d, %d), ", i, k);
        }
    }
}
