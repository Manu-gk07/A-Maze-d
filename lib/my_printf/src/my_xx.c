/*
** EPITECH PROJECT, 2026
** my_printf
** File description:
** my_xx - transform decimal to hexadecimal (uppercase)
*/

#include "../include/my_printf.h"

int my_xx_caller(va_list list)
{
    int nb = va_arg(list, int);

    return my_xx(nb);
}

int my_xx(int nb)
{
    char hexa[] = "0123456789ABCDEF";
    int nbcopy;
    int count = 0;

    if (nb >= 16)
        count += my_xx(nb / 16);
    nbcopy = nb % 16;
    count += my_c(hexa[nbcopy]);
    return count;
}

char *my_xx_char_caller(va_list list)
{
    int nb = va_arg(list, int);

    return my_xx_char(nb);
}

char *my_xx_char(int nb)
{
    char *result = malloc(100);
    char hexa[] = "0123456789ABCDEF";
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
