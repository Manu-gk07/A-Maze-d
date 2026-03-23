/*
** EPITECH PROJECT, 2026
** other_functions
** File description:
** my_strchr - finds first occurrence of a character in a string
*/

#include "other_functions.h"

char *my_strchr(char const *str, char c)
{
    if (str == NULL)
        return NULL;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c)
            return (char *)&str[i];
    }
    if (c == '\0')
        return (char *)&str[my_strlen((char *)str)];
    return NULL;
}
