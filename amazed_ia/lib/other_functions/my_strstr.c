/*
** EPITECH PROJECT, 2026
** other_functions
** File description:
** my_strstr - locate a substring
*/

#include "other_functions.h"

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;
    int j;

    if (to_find[0] == '\0')
        return str;
    while (str[i] != '\0') {
        j = 0;
        while (str[i + j] == to_find[j] && to_find[j] != '\0')
            j++;
        if (to_find[j] == '\0')
            return &str[i];
        i++;
    }
    return NULL;
}
