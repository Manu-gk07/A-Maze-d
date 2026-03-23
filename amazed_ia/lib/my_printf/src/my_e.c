/*
** EPITECH PROJECT, 2026
** my_printf
** File description:
** my_e - print scientific notation (lowercase)
*/

#include "../include/my_printf.h"

static char *equal_zero(int nb, char *dest)
{
    (void)nb;
    dest[0] = '0';
    dest[1] = '\0';
    return dest;
}

static void fill_decimal(double decimal_part, char *dest, double nb)
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
    dest[8] = 'e';
    dest[9] = '+';
    dest[10] = '0';
    dest[11] = '0';
}

static char *one_to_10(double nb, char *dest)
{
    double decimal_part = nb - (int)nb;

    if (decimal_part != 0)
        fill_decimal(decimal_part, dest, nb);
    else {
        dest[0] = '0' + nb;
        dest[1] = '\0';
    }
    return dest;
}

static void fill_decimal_part(char *dest, double decimal_part)
{
    for (int i = 2; i < 8; i++) {
        decimal_part *= 10;
        dest[i] = (int)(decimal_part + 1e-9) + '0';
        decimal_part -= (int)(decimal_part + 1e-9);
    }
}

static char *format_zero_to_one(double nb, char *dest, int *exponent)
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
    fill_decimal_part(dest, decimal_part);
    dest[8] = 'e';
    dest[9] = '-';
    dest[10] = '0';
    dest[11] = '0' + *exponent;
    dest[12] = '\0';
    return dest;
}

char *format_sup_10(double nb, char *dest, int *exponent)
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
    fill_decimal_part(dest, decimal_part);
    dest[8] = 'e';
    dest[9] = '+';
    dest[10] = '0';
    dest[11] = '0' + *exponent;
    dest[12] = '\0';
    return dest;
}

int is_nan(double nb)
{
    if (nb == 0.000000)
        return 1;
    else
        return 0;
}

int my_e_caller(va_list list)
{
    double nb = va_arg(list, double);

    if (is_nan(nb) == 1)
        nb = va_arg(list, int);
    return my_e(nb);
}

char *select_format(double nb, char *dest, int *exponent)
{
    if (nb == 0)
        return equal_zero(nb, dest);
    if (nb >= 1 && nb < 10)
        return one_to_10(nb, dest);
    if (nb < 1 && nb > 0)
        return format_zero_to_one(nb, dest, exponent);
    if (nb >= 10)
        return format_sup_10(nb, dest, exponent);
    return dest;
}

int my_e(double nb)
{
    int exponent = 0;
    char *dest = malloc(13);
    int count = 0;

    if (nb < 0) {
        nb *= -1;
        count += my_c('-');
        count += my_e(nb);
        return count;
    }
    dest = select_format(nb, dest, &exponent);
    count += my_s(dest);
    return count;
}
