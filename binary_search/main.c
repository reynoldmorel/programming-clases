#include <stdio.h>
#include <stdlib.h>

int number_list_size = 10;
int number_list[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

int search(int number_to_search);
int binary_search(int number_to_search, int lower_bound, int upper_bound);

int main()
{
    int index_found = search(7);
    printf("index_found = %d\n", index_found);
    printf("================================================\n");
    index_found = binary_search(7, 0, number_list_size - 1);
    printf("index_found_with_binary_search = %d\n", index_found);
    printf("-----------------------------------------------\n");

    return 0;
}

// O(n)
int search(int number_to_search)
{
    for (int i = 0; i < number_list_size; i++)
    {
        printf("1 paso 'search'\n");
        if (number_list[i] == number_to_search)
        {
            return i;
        }
    }

    return -1;
}

// f(n) = (b + h + j + l) + (1 / 2 ^ n)(a + c + d + e + f + g + i + k + m + n + o + p + q + r) 
// (b, h, j, l) se ejecuta una operación una vez porque son returns
// f(n) = (b, h, j, l) + log n(a + c + d + e + f + g + i + k + m + n + o + p + q + r)
// Lim f(n) = (b, h, j, l) + log ∞(a + c + d + e + f + g + i + k + m + n + o + p + q + r)
// n -> ∞
// f(∞) = log ∞
// O(log n)	
int binary_search(int number_to_search, int lower_bound_index, int upper_bound_index)
{
    printf("1 paso 'binary_search'\n");

    // 1 paso = a 
    if (lower_bound_index >= upper_bound_index)
    {
        // 1 paso = b
        return -1;
    }

    // 1 paso = c
    int half_index = (lower_bound_index + upper_bound_index) / 2;

    // 1 paso = d
    int lower_bound = number_list[lower_bound_index];
    // 1 paso = e
    int upper_bound = number_list[upper_bound_index];
    // 1 paso = f
    int half = number_list[half_index];

    // 1 paso = g
    if (half == number_to_search)
    {
        // 1 paso = h
        return half_index;
    }

    // 1 paso = i
    if (lower_bound == number_to_search)
    {
        // 1 paso = j
        return lower_bound_index;
    }

    // 1 paso = k
    if (upper_bound == number_to_search)
    {
        // 1 paso = l
        return upper_bound_index;
    }

    // 1 paso = m
    if (number_to_search > half)
    {
        // 1 paso = n
        upper_bound_index = upper_bound_index - 1;
        // 1 paso = o
        lower_bound_index = half_index + 1;
    }
    else
    {
        // 1 paso = p
        upper_bound_index = half_index - 1;
        // 1 paso = q
        lower_bound_index = lower_bound_index + 1;
    }

    // 1 paso = r
    return binary_search(number_to_search, lower_bound_index, upper_bound_index);
}

// Tarea: Hacer un algoritmo para determinar cuantas veces se rotó un
// arreglo ordenado de manera ascendente.
//
// El constraint para la solución es que debe ser O(log n).
//
// Por ejemplo:
// --------
// input [1, 100, 200, 300, 500, 1000, 1010]
// output 0
// --------
// input [1000, 1010, 1, 100, 200, 300, 500]
// output 2
// --------
// input [100, 200, 300, 500, 1000, 1010, 1]
// output 6
//
// Razonamiento:
// la primera rotación:
// [1010, 1, 100, 200, 300, 500, 1000]
// la segunada rotación:
// [1000, 1010, 1, 100, 200, 300, 500]