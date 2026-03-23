/*
** EPITECH PROJECT, 2026
** other_functions
** File description:
** my_strlen - get string length
*/

#include "other_functions.h"

int my_strlen(char *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++)
        count++;
    return count;
}
