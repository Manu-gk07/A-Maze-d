/*
** EPITECH PROJECT, 2026
** other_functions
** File description:
** my_revstr - reverse a string
*/

#include "other_functions.h"

void my_swap1(char *a, char *b)
{
    int temp = *a;

    *a = *b;
    *b = temp;
}

char *my_revstr(char *str)
{
    int count = my_strlen(str) - 1;

    for (int i = 0; i < count; i++) {
        my_swap1(&str[i], &str[count]);
        count--;
    }
    return str;
}
