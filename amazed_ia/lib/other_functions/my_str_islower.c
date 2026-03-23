/*
** EPITECH PROJECT, 2026
** other_functions
** File description:
** my_str_islower - check if string contains only lowercase characters
*/

#include "other_functions.h"

int my_str_islower(char const *str)
{
    int i = 0;

    if (str[0] == '\0')
        return 1;
    while (str[i] != '\0') {
        if (!(str[i] >= 'a' && str[i] <= 'z'))
            return 0;
        i++;
    }
    return 1;
}
