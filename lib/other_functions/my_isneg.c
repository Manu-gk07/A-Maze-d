/*
** EPITECH PROJECT, 2026
** other_functions
** File description:
** my_isneg - display N if negative, P if positive or null
*/

#include "other_functions.h"

int my_isneg(int n)
{
    if (n < 0)
        my_printf("N");
    else
        my_printf("P");
    return 0;
}
