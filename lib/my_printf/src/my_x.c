/*
** EPITECH PROJECT, 2026
** my_printf
** File description:
** my_x - transform decimal to hexadecimal (lowercase)
*/

#include "../include/my_printf.h"

int my_x_caller(va_list list)
{
    int nb = va_arg(list, int);

    return my_x(nb);
}

int my_x(int nb)
{
    char hexa[] = "0123456789abcdef";
    int nbcopy;
    int count = 0;

    if (nb >= 16)
        count += my_x(nb / 16);
    nbcopy = nb % 16;
    count += my_c(hexa[nbcopy]);
    return count;
}

char *my_x_char_caller(va_list list)
{
    int nb = va_arg(list, int);

    return my_x_char(nb);
}

char *my_x_char(int nb)
{
    char *result = malloc(100);
    char hexa[] = "0123456789abcdef";
    int i = 0;
    int nbcopy;

    do {
        nbcopy = nb % 16;
        result[i] = hexa[nbcopy];
        nb /= 16;
        i++;
    } while (nb != 0);
    result[i] = '\0';
    my_revstr(result);
    return result;
}
