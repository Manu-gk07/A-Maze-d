/*
** EPITECH PROJECT, 2026
** other_functions
** File description:
** my_array_len - calculates the length of a string array
*/

#include "other_functions.h"

int my_array_len(char **array)
{
    int count = 0;

    if (array == NULL)
        return 0;
    while (array[count] != NULL)
        count++;
    return count;
}
