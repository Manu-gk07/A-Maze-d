/*
** EPITECH PROJECT, 2026
** other_functions
** File description:
** my_str_isupper - check if string contains only uppercase characters
*/

#include "other_functions.h"

int my_str_isupper(char const *str)
{
    int i = 0;

    if (str[0] == '\0')
        return 1;
    while (str[i] != '\0') {
        if (!(str[i] >= 'A' && str[i] <= 'Z'))
            return 0;
        i++;
    }
    return 1;
}
