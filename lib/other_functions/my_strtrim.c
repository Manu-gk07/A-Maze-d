/*
** EPITECH PROJECT, 2026
** other_functions
** File description:
** my_strtrim - removes whitespace from start and end of string
*/

#include "other_functions.h"

static int is_whitespace(char c)
{
    return (c == ' ' || c == '\t' || c == '\n' || c == '\r');
}

char *my_strtrim(char *str)
{
    int start = 0;
    int end;

    if (str == NULL)
        return NULL;
    while (str[start] && is_whitespace(str[start]))
        start++;
    end = my_strlen(str) - 1;
    while (end >= start && is_whitespace(str[end]))
        end--;
    for (int i = 0; i <= end - start; i++)
        str[i] = str[start + i];
    str[end - start + 1] = '\0';
    return str;
}
