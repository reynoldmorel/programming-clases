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

    index_found = search(5);
    printf("index_found = %d\n", index_found);
    printf("================================================\n");
    index_found = binary_search(5, 0, number_list_size - 1);
    printf("index_found_with_binary_search = %d\n", index_found);
    printf("-----------------------------------------------\n");

    index_found = search(4);
    printf("index_found = %d\n", index_found);
    printf("================================================\n");
    index_found = binary_search(4, 0, number_list_size - 1);
    printf("index_found_with_binary_search = %d\n", index_found);
    printf("-----------------------------------------------\n");

    index_found = search(1);
    printf("index_found = %d\n", index_found);
    printf("================================================\n");
    index_found = binary_search(1, 0, number_list_size - 1);
    printf("index_found_with_binary_search = %d\n", index_found);
    printf("-----------------------------------------------\n");

    index_found = search(3);
    printf("index_found = %d\n", index_found);
    printf("================================================\n");
    index_found = binary_search(3, 0, number_list_size - 1);
    printf("index_found_with_binary_search = %d\n", index_found);
    printf("-----------------------------------------------\n");

    index_found = search(100);
    printf("index_found = %d\n", index_found);
    printf("================================================\n");
    index_found = binary_search(100, 0, number_list_size - 1);
    printf("index_found_with_binary_search = %d\n", index_found);
    printf("-----------------------------------------------\n");

    return 0;
}

// f(n) = 1 + n(a + b)
// TIME COMPLEXITY
// O(n)
int search(int number_to_search)
{
    // b = {3, 4}
    for (int i = 0; i < number_list_size; i++)
    {
        printf("ciclo maquina 'search'\n");
        // a = {1, 2}
        if (number_list[i] == number_to_search)
        {
            return i;
        }
    }

    return -1;
}

// f(n) = log n(a + b + c + d + e + f + 3)
// O(log n)
int binary_search(int number_to_search, int lower_bound_index, int upper_bound_index)
{
    printf("ciclo maquina 'binary_search'\n");
    // a = {1,2}
    if (lower_bound_index >= upper_bound_index)
    {
        return -1;
    }

    // 0 + 10 -> 10 / 2 = 5
    // si me voy a la derecha -> 6 + 10 -> 16 / 2 = 8
    // si me voy a la izquierda -> 0 + 4 -> 4 / 2 = 2
    // b = 3
    int half_index = (lower_bound_index + upper_bound_index) / 2;

    // 1 ciclo maq.
    int lower_bound_element = number_list[lower_bound_index];
    // 1 ciclo maq.
    int upper_bound_element = number_list[upper_bound_index];
    // 1 ciclo maq.
    int middle_element = number_list[half_index];

    // c = {1, 2}
    if (lower_bound_element == number_to_search)
    {
        return lower_bound_index;
    }

    // d = {1, 2}
    if (upper_bound_element == number_to_search)
    {
        return upper_bound_index;
    }

    // e = {1, 2}
    if (middle_element == number_to_search)
    {
        return half_index;
    }

    // f = {5, 6}
    if (number_to_search > middle_element)
    {
        upper_bound_index = upper_bound_index - 1;
        lower_bound_index = half_index + 1;
    }
    else
    {
        upper_bound_index = half_index - 1;
        lower_bound_index = lower_bound_index + 1;
    }

    // Repetir las operaciones en un factor n / 2
    // si repetimos varias veces las operaciones se verian
    // de esta forma:
    // f(n) = n / 2 / 2 / 2 / 2 -> la mitad de la mitad hasta
    // que encontremos el elemento, si acaso existe.
    // f(n) = (n / 2) / (2 / 1) / (2 / 1) / (2 / 1) / (2 / 1) / (2 / 1)
    // f(n) = (n / 2) * (1 / 2) * (1 / 2) * (1 / 2) * (1 / 2) * (1 / 2)
    // f(n) = n / (2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2)
    // f(n) = n / (2 ^ (1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1))
    // f(n) = n / (2 ^ k)
    // asumiendo que al menos para usar el binary_search
    // ejecuto una operacion entonces:
    // 1 = n / (2 ^ k)
    // 2^k = n
    // ln n = k  ejemplo: 2^3 = 8 entonces: ln 8 = 3 
    // Asumiendo que log base 10 y loga base 2 son constantes
    // en el analisis de big o notation, cualquiera de los 2 que usemos
    // son irrelevantes, pero para mantener la convencion y consistencia
    // usaremos log base 10, lo cual convertiria lo de arriba en:
    // log n = k
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
//
// Razonamiento:
// la primera rotación:
// [1010, 1, 100, 200, 300, 500, 1000]
// la segunada rotación:
// [1000, 1010, 1, 100, 200, 300, 500]
