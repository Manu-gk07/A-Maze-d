/*
** EPITECH PROJECT, 2026
** my_printf
** File description:
** my_space - add space to positive numbers
*/

#include "../include/my_printf.h"

int my_space_caller(va_list list)
{
    int nb = va_arg(list, int);

    return my_space(nb);
}

int my_space(int nb)
{
    int count = 0;

    count += my_c(' ');
    if (nb > 9) {
        count += my_d(nb / 10);
    }
    count += my_c((nb % 10) + '0');
    return count;
}
