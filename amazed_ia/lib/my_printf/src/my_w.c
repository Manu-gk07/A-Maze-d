/*
** EPITECH PROJECT, 2026
** my_printf
** File description:
** my_w - transform decimal to base 6
*/

#include "../include/my_printf.h"

int my_w_caller(va_list list)
{
    int nb = va_arg(list, int);

    return my_x(nb);
}

int my_w(int nb)
{
    char hexa[] = "012345";
    int nbcopy;
    int count = 0;

    if (nb >= 6)
        count += my_w(nb / 6);
    nbcopy = nb % 6;
    count += my_c(hexa[nbcopy]);
    return count;
}
