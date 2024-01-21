#include <stdio.h>
#include <stdlib.h>

int factorial(int n);
int test_n2_algo(int n);
int test_n_log_algo(int n);
int test_n_log_algo2(int n);
int test_log_algo(int n);
int test_fib_algo(int n);

int counter_fib = 0;

int main()
{
    // factorial(10);
    // printf("------------------\n");
    // test_log_algo(10);
    // printf("------------------\n");
    // test_n_log_algo(10);
    // printf("------------------\n");
    // test_n2_algo(5);
    // printf("------------------\n");
    test_fib_algo(5);
    printf("counter_fib=%d\n", counter_fib);
    return 0;
}

// O(1) = Tiempo constante
/*
int compute1(int a) {
    retun sen(a);
}

int compute2(int a) {
    retun a * a;
}

Users compute3(char[] criteria) {
    O(1)
    retun db.sql(SELECT * FROM USERS);
}
*/

// O(log n) = Tiempo logaritmico
/*
int compute1(int n) {
    for (int k = n; k > 0; k = k / 2)
    {
        // 1 ciclo máq.
        printf("(%d, %d), ", i, k);
    }
}
*/

// O(n) = Tiempo lineal
/*
  factorial()
*/

// O(nlog n) = Tiempo lineal logaritmico (Me lon estoy inventado)
/*
  test_n_log_algo()
*/

// O(n^2) = Tiempo cuadrático
/*
  test_n2_algo()
*/

// O(2^n) = Tiempo exponencial
/*
  test_fib_algo()
*/

// k = a + 1 = 1 + a // operaciones que ejecuta la funcion
// f(n) = k + k + k + k.......... // k operaciones se ejecutan n veces
// f(n) = (1 + a) + (1 + a) + (1 + a) .......
// por ejemplo para f(3) la cantidad de operaciones
// que se van a ejecutar es 3k = 3(1 + a)
// f(3) = 3k = 3(1 + a)
// Por lo que se puede decir que el algoritmo cumple con el modelo
// de:
// f(n) = n(1 + a)
// Lim f(n) = Lim n(1 + a) = Lim n + an = ∞ + a∞ = ∞ = n
// n-> ∞      n-> ∞          n-> ∞
// O(n)
// SPACE COMPLEXITY (RAM)
// Lim f(n) = Lim (3) = Lim 3 = 3
// n-> ∞      n-> ∞     n-> ∞
// O(1)
int factorial(int number)
{
    // a = {1,2} ciclos máquinas
    if (number == 0)
    {
        return 1;
    }

    // 1 ciclo máquina
    return number * factorial(number - 1);
}

// TIME COMPLEXITY
// La función ejecuta d, n veces, por lo que:
// f(n) = 1 + nd = 1 + n(n(a + (1 + c))) = 1 + n(n(a + 1 + b + 1))
// f(n) = 1 + 2n^2 + an^2 + bn^2
// Lim f(n) = Lim (1 + 2n^2 + an^2 + bn^2) = Lim (1 + 2∞^2 + a∞^2 + b∞^2)
// n-> ∞      n-> ∞                          n-> ∞
// = ∞^2 + ∞^2 + ∞^2 = 3∞^2 = ∞^2 = n^2
// O(n^2)
int test_n2_algo(int n)
{
    // 1 ciclo máquina para inicializar i.
    // Mientras está dentro del for:
    // 1 ciclo máquina evaluar i < n
    // 2 ciclo máquinas para i++ (ya que tiene que sumar 1 y luego reasignar i)
    // Para salir afuera del for:
    // 2 ciclo máquina para i++ (ya que tiene que sumar 1 y luego reasignar i)
    // 2 ciclos máquina saltar i < n, porque ya terminó el for
    // por lo que:
    // a = {3, 4}
    // d serán todas las tareas que tiene que ejecutar el for
    // por lo que:
    // d = n(a + (1 + c))
    for (int i = 0; i < n; i++)
    {
        // 1 ciclo máquina para inicializar k.
        // Mientras está dentro del for:
        // 1 ciclo máquina evaluar k < n
        // 2 ciclo máquinas para k++ (ya que tiene que sumar 1 y luego reasignar k)
        // Para salir afuera del for:
        // 2 ciclo máquina para k++ (ya que tiene que sumar 1 y luego reasignar k)
        // 2 ciclos máquina saltar k < n, porque ya terminó el for
        // por lo que:
        // b = {3, 4}
        // c serán todas las tareas que tiene que ejecutar el for
        // por lo que:
        // c = b + 1
        for (int k = 0; k < n; k++)
        {
            // 1 ciclo máq.
            printf("(%d, %d), ", i, k);
        }
    }

    return 0;
}

// TIME COMPLEXITY
// La función ejecuta d, n veces, por lo que:
// f(n) = 1 + nd = 1 + n(1 + log n(b + 1)) = 1 + n + n log(nb + n)
// f(n) = 1 + n + n log(nb + n)
// Lim f(n) = Lim (1 + n + n log(nb + n))
// n-> ∞      n-> ∞
// = 1 + ∞ + ∞ log(∞b + ∞) = ∞ log(∞) = n log n
// O(n log n)
int test_n_log_algo(int n)
{

    // 1 ciclo máquina para inicializar i.
    // Mientras está dentro del for:
    // 1 ciclo máquina evaluar i < n
    // 2 ciclo máquinas para i++ (ya que tiene que sumar 1 y luego reasignar i)
    // Para salir afuera del for:
    // 2 ciclo máquina para i++ (ya que tiene que sumar 1 y luego reasignar i)
    // 2 ciclos máquina saltar i < n, porque ya terminó el for
    // por lo que:
    // a = {3, 4}
    // d serán todas las tareas que tiene que ejecutar el for
    // por lo que:
    // - La cantidad mínima de operaciones que tiene que ejecutar el for donde k > 0
    //   es al menos 1.
    // Por cada iteración del for, las siguientes iteraciones se reducen a la mitad.
    // 1 = (b + 1) / 2 / 2 / 2 / 2 ....
    // Para ver mas fácil esa división reptitiva, se puede reescribir como:
    // [(b + 1) / 2] / [2 / 1] / [2 / 1] ....
    // que es lo mismo que:
    // [(b + 1) / 2] * [1 / 2] * [1 / 2] ....
    // 1 = (b + 1) / 2 ^ k
    // 2 ^ (k) = (b + 1)
    // log (b + 1) = k
    // log (b + 1) = k
    // donde (b + 1) son las operaciones dentro del for
    // y donde k es el número de operaciones totales ejecutadas por el for
    // por lo que:
    // d =  1 + log n(b + 1)
    for (int i = 0; i < n; i++)
    {
        // 1 ciclo máquina para inicializar k.
        // Mientras está dentro del for:
        // 1 ciclo máquina evaluar k > 0
        // 2 ciclo máquinas para k = k / 2 (ya que tiene que dividir entre 2 y luego reasignar k)
        // Para salir afuera del for:
        // 2 ciclo máquina para k = k / 2 (ya que tiene que dividir entre 2 y luego reasignar k)
        // 2 ciclos máquina saltar k > 0, porque ya terminó el for
        // por lo que:
        // b = {3, 4}
        for (int k = n; k > 0; k = k / 2)
        {
            // 1 ciclo máq.
            printf("(%d, %d), ", i, k);
        }
    }

    return 0;
}

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

int test_log_algo(int n)
{
    for (int k = n; k > 0; k = k / 2)
    {
        // 1 ciclo máq.
        printf("un ciclo maquina\n");
    }

    for (int k = n; k > 0; k = k / 2)
    {
        // 1 ciclo máq.
        printf("un ciclo maquina\n");
    }

    return 0;
}

// O(2^n) = Tiempo exponencial
int test_fib_algo(int n)
{
    counter_fib++;
    printf("un ciclo maquina\n");
    if (n == 0)
    {
        return 0;
    }

    if (n == 1)
    {
        return 1;
    }

    return test_fib_algo(n - 1) + test_fib_algo(n - 2);
}

// La función ejecuta h, n veces, por lo que:
// f(n) = 1 + nh
// f(n) = 1 + n(a + c + e)
// f(n) = 1 + an + cn + en
// Lim f(n) = Lim (1 + an + cn + en)
// n-> ∞      n-> ∞
// = 1 + a∞ + c∞ + e∞ = ∞ + ∞ + ∞ = ∞ = n
// O(n)
int test_on_algo(int n)
{
    // 1 ciclo máquina para inicializar i.
    // Mientras está dentro del for:
    // 1 ciclo máquina evaluar i < n
    // 2 ciclo máquinas para i++ (ya que tiene que sumar 1 y luego reasignar i)
    // Para salir afuera del for:
    // 2 ciclo máquina para i++ (ya que tiene que sumar 1 y luego reasignar i)
    // 2 ciclos máquina saltar i < n, porque ya terminó el for
    // por lo que:
    // e = {3, 4}
    // h serán todas las tareas que tiene que ejecutar el for
    // por lo que:
    // h = a + c + e
    for (int i = 0; i < n; i++)
    {
        // a = {1 + b, 2}
        if (n % 2 == 0)
        {
            // b = {1, 2}
            if (n % 10 == 0)
            {
                printf("Que tal\n");
            }
        }

        // c = {1 + d, 2}
        if (n % 3 == 0)
        {
            // d = {1, 2}
            if (n % 10 == 0)
            {
                printf("Hola\n");
            }
        }
    }
}
