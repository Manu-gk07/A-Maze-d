/*
** EPITECH PROJECT, 2026
** other_functions
** File description:
** my_strlowcase - convert string to lowercase
*/

#include "other_functions.h"

char *my_strlowcase(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] + 32;
        i++;
    }
    return str;
}
