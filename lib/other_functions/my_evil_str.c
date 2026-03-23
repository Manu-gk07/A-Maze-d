/*
** EPITECH PROJECT, 2026
** other_functions
** File description:
** my_evil_str - reverse a string by swapping characters
*/

#include "other_functions.h"

char *my_evil_str(char *str)
{
    int len = my_strlen(str);
    int i = 0;
    char temp;

    while (i < len / 2) {
        temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
        i++;
    }
    return str;
}
