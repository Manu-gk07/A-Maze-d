/*
** EPITECH PROJECT, 2026
** other_functions
** File description:
** my_strcat - concatenate two strings
*/

#include "other_functions.h"

char *my_strcat(char *dest, char const *src)
{
    int lenght = my_strlen(dest);
    int i = 0;

    for (; src[i] != '\0'; i++) {
        dest[i + lenght] = src[i];
    }
    dest[i + lenght] = '\0';
    return dest;
}
