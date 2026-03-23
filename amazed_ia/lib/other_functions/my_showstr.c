/*
** EPITECH PROJECT, 2026
** other_functions
** File description:
** my_showstr - print string with non-printable chars as hex
*/

#include "other_functions.h"

static int is_printable(char c)
{
    return (c >= 32 && c <= 126);
}

int my_showstr(char const *str)
{
    int i = 0;

    if (str == NULL)
        return 84;
    while (str[i] != '\0') {
        if (is_printable(str[i]))
            my_printf("%c", str[i]);
        else
            my_printf("\\%02x", (unsigned char)str[i]);
        i++;
    }
    return 0;
}
