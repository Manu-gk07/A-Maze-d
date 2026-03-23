/*
** EPITECH PROJECT, 2026
** my_printf
** File description:
** my_o - transform decimal to octal number
*/

#include "../include/my_printf.h"

int my_o_caller(va_list list)
{
    int nb = va_arg(list, int);

    return my_o(nb);
}

int my_o(int nb)
{
    char octo[] = "01234567";
    int nbcopy;
    int count = 0;

    if (nb >= 8)
        count += my_o(nb / 8);
    nbcopy = nb % 8;
    count += my_c(octo[nbcopy]);
    return count;
}

char *my_o_char_caller(va_list list)
{
    int nb = va_arg(list, int);

    return my_o_char(nb);
}

char *my_o_char(int nb)
{
    char *result = malloc(100);
    char octo[] = "01234567";
    int i = 0;
    int nbcopy;

    do {
        nbcopy = nb % 8;
        result[i] = octo[nbcopy];
        nb /= 8;
        i++;
    } while (nb != 0);
    result[i] = '\0';
    my_revstr(result);
    return result;
}
