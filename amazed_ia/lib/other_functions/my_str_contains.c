/*
** EPITECH PROJECT, 2026
** other_functions
** File description:
** my_str_contains - checks if a string contains a substring
*/

#include "other_functions.h"

int my_str_contains(char const *str, char const *to_find)
{
    if (str == NULL || to_find == NULL)
        return 0;
    if (my_strstr((char *)str, to_find) != NULL)
        return 1;
    return 0;
}
