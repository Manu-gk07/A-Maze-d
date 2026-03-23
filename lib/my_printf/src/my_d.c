/*
** EPITECH PROJECT, 2026
** my_printf
** File description:
** my_d - print a decimal number
*/

#include "../include/my_printf.h"

int my_d_caller(va_list list)
{
    int nb = va_arg(list, int);

    return my_d(nb);
}

int my_d(int nb)
{
    int count = 0;

    if (nb < 0) {
        my_c('-');
        nb *= -1;
    }
    if (nb > 9) {
        count += my_d(nb / 10);
    }
    count += my_c((nb % 10) + '0');
    return count;
}
