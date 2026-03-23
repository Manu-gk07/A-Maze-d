/*
** EPITECH PROJECT, 2026
** other_functions
** File description:
** my_strrchr - finds last occurrence of a character in a string
*/

#include "other_functions.h"

char *my_strrchr(char const *str, char c)
{
    int len;
    int i;

    if (str == NULL)
        return NULL;
    len = my_strlen((char *)str);
    if (c == '\0')
        return (char *)&str[len];
    i = len - 1;
    while (i >= 0) {
        if (str[i] == c)
            return (char *)&str[i];
        i--;
    }
    return NULL;
}
