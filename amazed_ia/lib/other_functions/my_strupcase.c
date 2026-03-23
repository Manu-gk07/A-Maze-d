/*
** EPITECH PROJECT, 2026
** other_functions
** File description:
** my_strupcase - convert string to uppercase
*/

#include "other_functions.h"

char *my_strupcase(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = str[i] - 32;
        i++;
    }
    return str;
}
