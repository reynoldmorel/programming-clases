#include <stdio.h>
#include <stdlib.h>

int number_list_size = 10;
int number_list[] = {10, 9, 8, 7, 6, 1, 2, 3, 4, 5};

void swap(int prev_index, int current_index);
int partition_index_asc(int lower_bound_index, int upper_bound_index);
void quick_sort_asc(int lower_bound_index, int upper_bound_index);
int select_pivot_index(int lower_bound_index, int upper_bound_index);

int main()
{
    printf("Unsorted array\n");
    for (int i = 0; i < number_list_size; i++)
    {
        printf("%d, ", number_list[i]);
    }

    quick_sort_asc(0, number_list_size - 1);

    printf("\nSorted array\n");
    for (int i = 0; i < number_list_size; i++)
    {
        printf("%d, ", number_list[i]);
    }

    return 0;
}

void swap(int prev_index, int current_index)
{
    int temp = number_list[prev_index];
    number_list[prev_index] = number_list[current_index];
    number_list[current_index] = temp;
}

int select_pivot_index(int lower_bound_index, int upper_bound_index)
{
    return (lower_bound_index + upper_bound_index) / 2;
}

int partition_index_asc(int lower_bound_index, int upper_bound_index)
{
    int pivot_index = select_pivot_index(lower_bound_index, upper_bound_index);
    int pivot = number_list[pivot_index];
    // i = last_changed_index y sirven para representar el último swap en el ordenamiento.
    // se crearon estas 2 variables para asemejarlas al ejemplo que hicimos en paint.
    // Definitivamente se puede elimninar una variable o la otra, en caso de confusión.
    int last_changed_index = lower_bound_index - 1;
    int i = last_changed_index;

    // Inicialmente el partition_index_asc va a evaluar todos los elementos
    // entonces su TIME COMPLEXITY es O(n).
    // Entonces dependiendo de la selección del pivote, en el pero de los
    // casos el que se elija el peor piovote, entonces siempre se van a revisar
    // TODOS los elementos que se van a ordenar aún estén ordenados.
    // Lo que hace que el TIME COMPLEXITY para cada selcción de pivote sea O(n).
    for (int current_index = lower_bound_index; current_index <= upper_bound_index; current_index++)
    {
        // O(1) operaciones contante conllevan tiempo constante
        // en el pero de los casos
        int j = current_index;
        int current_number = number_list[j];

        if (current_number < pivot)
        {

            last_changed_index = last_changed_index + 1;
            i = i + 1;

            swap(i, j);

            if (i == pivot_index)
            {
                pivot_index = j;
            }
        }
    }

    last_changed_index = last_changed_index + 1;
    i = i + 1;

    swap(pivot_index, i);

    return i;
}

// En el peor de los caso que se tome siempre el peor pivot_index
// el TIME COMPLEXITY sería O(n) * O(n) * O(1) = O(n^2)
// Pero es muy díficil que aún utilizando selección aleatoria del pivot_index
// TODOS los pivotes sean malos. Lo que significa, que dividir las tareas de ordenamiento
// en un factor definido por pivot_index (k), lo promedio o común es que la cantidad de operaciones
// disminuyan por cada partition. Dejando el algoritmo con un TIME COMPLEXITY average de
// O(n log n).
void quick_sort_asc(int lower_bound_index, int upper_bound_index)
{
    if (upper_bound_index <= lower_bound_index)
    {
        return;
    }

    int pivot_index = partition_index_asc(lower_bound_index, upper_bound_index);

    // Esta es la parte que impacta en análisi computacional en tiempo
    // porque si el pivote es bueno, puede dividir el arreglo a la mitad
    // y seccionar la tarea ordenamiento en 2. Lo que lo convertiría en O(n log n),
    // de lo contrario, podría iterar todos los elementos en un solo lado sin dividirlo correctamente
    // haciendo que el algoritmo sea O(n^2)
    quick_sort_asc(lower_bound_index, pivot_index - 1);
    quick_sort_asc(pivot_index + 1, upper_bound_index);
}

// TAREA: Hacer un algoritmo que pueda buscar el menor número en la posición x en un tiempo máximo de O(n log n) en caso promedio.
// Reducir lo más que se pueda la ocurrencia del peor de los casos en O(n^2).

// Ejemplo:
// Input Del arreglo [30, 60, 80, 100, 10, 20, 70] buscar el 3er menor número. 
// Output: el 3er menor número del arreglo anterior es 30.
