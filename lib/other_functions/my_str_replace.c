/*
** EPITECH PROJECT, 2026
** other_functions
** File description:
** my_str_replace - replaces all occurrences of a character with another
*/

#include "other_functions.h"

char *my_str_replace(char *str, char old_char, char new_char)
{
    if (str == NULL)
        return NULL;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == old_char)
            str[i] = new_char;
    }
    return str;
}
