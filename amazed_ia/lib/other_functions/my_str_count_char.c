/*
** EPITECH PROJECT, 2026
** other_functions
** File description:
** my_str_count_char - counts occurrences of a character in a string
*/

#include "other_functions.h"

int my_str_count_char(char const *str, char c)
{
    int count = 0;

    if (str == NULL)
        return 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c)
            count++;
    }
    return count;
}
