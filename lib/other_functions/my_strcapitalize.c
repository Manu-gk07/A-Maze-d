/*
** EPITECH PROJECT, 2026
** other_functions
** File description:
** my_strcapitalize - capitalize first letter of each word
*/

#include "other_functions.h"

static int is_alphanumeric(char c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
        (c >= '0' && c <= '9'));
}

static void capitalize_if_needed(char *str, int i, int *new_word)
{
    if (*new_word && str[i] >= 'a' && str[i] <= 'z')
        str[i] = str[i] - 32;
    *new_word = 0;
}

char *my_strcapitalize(char *str)
{
    int i = 0;
    int new_word = 1;

    my_strlowcase(str);
    while (str[i] != '\0') {
        if (is_alphanumeric(str[i]))
            capitalize_if_needed(str, i, &new_word);
        else
            new_word = 1;
        i++;
    }
    return str;
}
