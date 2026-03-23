/*
** EPITECH PROJECT, 2026
** other_functions
** File description:
** my_sort_int_array - sort an integer array in ascending order
*/

#include "other_functions.h"

static void swap_values(int *array, int i, int min_idx)
{
    int temp = array[i];

    array[i] = array[min_idx];
    array[min_idx] = temp;
}

static int find_min_index(int *array, int start, int size)
{
    int j;
    int min_idx = start;

    for (j = start + 1; j < size; j++) {
        if (array[j] < array[min_idx])
            min_idx = j;
    }
    return min_idx;
}

void my_sort_int_array(int *array, int size)
{
    int i;
    int min_idx;

    if (array == NULL || size <= 0)
        return;
    for (i = 0; i < size - 1; i++) {
        min_idx = find_min_index(array, i, size);
        if (min_idx != i)
            swap_values(array, i, min_idx);
    }
}
