/*
** EPITECH PROJECT, 2026
** other_functions
** File description:
** my_strcmp - compare two strings
*/

#include "other_functions.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    if (s1 == NULL || s2 == NULL)
        return -1;
    while (s1[i] && s2[i] && s1[i] == s2[i])
        i++;
    return s1[i] - s2[i];
}
