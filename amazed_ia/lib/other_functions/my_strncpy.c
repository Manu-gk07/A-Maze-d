/*
** EPITECH PROJECT, 2026
** other_functions
** File description:
** my_strncpy - copy n characters from a string into another
*/

#include "other_functions.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    while (i < n && src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    while (i < n) {
        dest[i] = '\0';
        i++;
    }
    return dest;
}
