/*
** EPITECH PROJECT, 2026
** my_printf
** File description:
** my_ee - print scientific notation (uppercase)
*/

#include "../include/my_printf.h"

static char *format_equal_zero_cap(int nb, char *dest)
{
    (void)nb;
    dest[0] = '0';
    dest[1] = '\0';
    return dest;
}

static void fill_decimal_cap_o(double decimal_part, char *dest, double nb)
{
    int new_uni = 0;

    dest[0] = (int)nb + '0';
    dest[1] = '.';
    for (int i = 2; i < 8; i++) {
        decimal_part *= 10;
        new_uni = (int)decimal_part;
        dest[i] = new_uni + '0';
        decimal_part -= new_uni;
    }
    dest[8] = 'E';
    dest[9] = '+';
    dest[10] = '0';
    dest[11] = '0';
}

static char *format_one_to_ten_cap(double nb, char *dest)
{
    double decimal_part = nb - (int)nb;

    if (decimal_part != 0)
        fill_decimal_cap_o(decimal_part, dest, nb);
    else {
        dest[0] = '0' + nb;
        dest[1] = '\0';
    }
    return dest;
}

static void fill_decimal_cap(char *dest, double decimal_part)
{
    for (int i = 2; i < 8; i++) {
        decimal_part *= 10;
        dest[i] = (int)(decimal_part + 1e-9) + '0';
        decimal_part -= (int)(decimal_part + 1e-9);
    }
}

static char *format_below_one_cap(double nb, char *dest, int *exponent)
{
    double nbcopy = nb;
    double decimal_part = 0;

    while (nbcopy < 1) {
        nbcopy *= 10;
        (*exponent)++;
    }
    decimal_part = nbcopy - (int)nbcopy;
    dest[0] = (int)nbcopy + '0';
    dest[1] = '.';
    fill_decimal_cap(dest, decimal_part);
    dest[8] = 'E';
    dest[9] = '-';
    dest[10] = '0';
    dest[11] = '0' + *exponent;
    dest[12] = '\0';
    return dest;
}

char *format_above_ten_cap(double nb, char *dest, int *exponent)
{
    double nbcopy = nb;
    double decimal_part = 0;

    while (nbcopy >= 10) {
        nbcopy /= 10;
        (*exponent)++;
    }
    decimal_part = nbcopy - (int)nbcopy;
    dest[0] = (int)nbcopy + '0';
    dest[1] = '.';
    fill_decimal_cap(dest, decimal_part);
    dest[8] = 'E';
    dest[9] = '+';
    dest[10] = '0';
    dest[11] = '0' + *exponent;
    dest[12] = '\0';
    return dest;
}

int my_ee_caller(va_list list)
{
    double nb = va_arg(list, double);

    return my_ee(nb);
}

char *select_format_cap(double nb, char *dest, int *exponent)
{
    if (nb == 0)
        return format_equal_zero_cap(nb, dest);
    if (nb >= 1 && nb < 10)
        return format_one_to_ten_cap(nb, dest);
    if (nb < 1 && nb > 0)
        return format_below_one_cap(nb, dest, exponent);
    if (nb >= 10)
        return format_above_ten_cap(nb, dest, exponent);
    return dest;
}

int my_ee(double nb)
{
    int exponent = 0;
    char *dest = malloc(100);
    int count = 0;

    if (nb < 0) {
        nb *= -1;
        count += my_c('-');
        count += my_ee(nb);
        return count;
    }
    dest = select_format_cap(nb, dest, &exponent);
    count += my_s(dest);
    return count;
}
