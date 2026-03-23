/*
** EPITECH PROJECT, 2026
** other_functions
** File description:
** my_str_isalnum - checks if string contains only alphanumeric characters
*/

#include "other_functions.h"

static int is_alphanum(char c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
            (c >= '0' && c <= '9'));
}

int my_str_isalnum(char const *str)
{
    if (str == NULL)
        return 0;
    if (str[0] == '\0')
        return 1;
    for (int i = 0; str[i] != '\0'; i++) {
        if (!is_alphanum(str[i]))
            return 0;
    }
    return 1;
}
