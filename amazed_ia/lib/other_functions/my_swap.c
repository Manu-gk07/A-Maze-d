/*
** EPITECH PROJECT, 2026
** other_functions
** File description:
** my_swap - swap two integers
*/

#include "other_functions.h"

void my_swap_int(int *a, int *b)
{
    int temp = *a;

    *a = *b;
    *b = temp;
}
