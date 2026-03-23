/*
** EPITECH PROJECT, 2026
** my_printf
** File description:
** my_f - print floating point number
*/

#include "../include/my_printf.h"

int my_f_caller(va_list list)
{
    double nb = va_arg(list, double);

    return my_f(nb);
}

int my_f(double nb)
{
    int ncopy = (int)nb;
    double decimal = nb - (double)ncopy;
    int count = 0;
    int decimal_part;

    count += my_d(ncopy);
    count += my_c('.');
    decimal_part = (int)(decimal * 1000000.0 + 0.5);
    if (decimal_part < 100000)
        count += my_c('0');
    if (decimal_part < 10000)
        count += my_c('0');
    if (decimal_part < 1000)
        count += my_c('0');
    if (decimal_part < 100)
        count += my_c('0');
    if (decimal_part < 10)
        count += my_c('0');
    count += my_d(decimal_part);
    return count;
}
