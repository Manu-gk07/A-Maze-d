/*
** EPITECH PROJECT, 2026
** other_functions
** File description:
** my_str_isalpha - check if string contains only alphabetical characters
*/

#include "other_functions.h"

int my_str_isalpha(char const *str)
{
    int i = 0;

    if (str[0] == '\0')
        return 1;
    while (str[i] != '\0') {
        if (!((str[i] >= 'a' && str[i] <= 'z') ||
            (str[i] >= 'A' && str[i] <= 'Z')))
            return 0;
        i++;
    }
    return 1;
}
