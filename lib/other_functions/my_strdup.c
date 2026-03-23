/*
** EPITECH PROJECT, 2026
** other_functions
** File description:
** my_strdup - duplicate a string
*/

#include "other_functions.h"

char *my_strdup(char const *src)
{
    int len = 0;
    char *dest;

    if (src == NULL)
        return NULL;
    while (src[len])
        len++;
    dest = malloc(sizeof(char) * (len + 1));
    if (dest == NULL)
        return NULL;
    for (int i = 0; i <= len; i++)
        dest[i] = src[i];
    return dest;
}
