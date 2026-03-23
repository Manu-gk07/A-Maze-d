/*
** EPITECH PROJECT, 2026
** other_functions
** File description:
** my_strcpy - copy a string into another
*/

#include "other_functions.h"

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    if (dest == NULL || src == NULL)
        return NULL;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
