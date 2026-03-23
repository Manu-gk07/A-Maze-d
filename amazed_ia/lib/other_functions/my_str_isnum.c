/*
** EPITECH PROJECT, 2026
** other_functions
** File description:
** my_str_isnum - check if string contains only digits
*/

#include "other_functions.h"

int my_str_isnum(char const *str)
{
    int i = 0;

    if (str[0] == '\0')
        return 1;
    while (str[i] != '\0') {
        if (!(str[i] >= '0' && str[i] <= '9'))
            return 0;
        i++;
    }
    return 1;
}
