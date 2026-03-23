/*
** EPITECH PROJECT, 2026
** my_printf
** File description:
** my_plus - add plus sign to positive numbers
*/

#include "../include/my_printf.h"

int my_plus_caller(va_list list)
{
    int nb = va_arg(list, int);

    return my_plus(nb);
}

int my_plus(int nb)
{
    int count = 0;

    if (nb > 0)
        count += my_c('+');
    else {
        count += my_c('-');
        nb *= -1;
    }
    if (nb > 9) {
        count += my_d(nb / 10);
    }
    count += my_c((nb % 10) + '0');
    return count;
}
