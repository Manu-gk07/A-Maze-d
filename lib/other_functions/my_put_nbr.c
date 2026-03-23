/*
** EPITECH PROJECT, 2026
** other_functions
** File description:
** my_put_nbr - display a number
*/

#include "other_functions.h"

int my_put_nbr(int nb)
{
    if (nb == -2147483648) {
        my_printf("-2147483648");
        return 11;
    }
    if (nb < 0) {
        my_printf("-");
        nb = -nb;
    }
    if (nb >= 10) {
        my_put_nbr(nb / 10);
    }
    my_printf("%c", (nb % 10) + '0');
    return 0;
}
