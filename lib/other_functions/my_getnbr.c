/*
** EPITECH PROJECT, 2026
** other_functions
** File description:
** my_getnbr - convert string to number
*/

#include "other_functions.h"

static int count_signs(char const *str, int *i)
{
    int sign = 1;

    while (str[*i] == '+' || str[*i] == '-' || str[*i] == ' ') {
        if (str[*i] == '-')
            sign *= -1;
        (*i)++;
    }
    return sign;
}

static int check_overflow(long long nb, int digit, int sign)
{
    if (sign == 1 && (nb > (2147483647 - digit) / 10))
        return 1;
    if (sign == -1 && (-nb < (-2147483648 + digit) / 10))
        return 1;
    return 0;
}

int my_getnbr(char const *str)
{
    int i = 0;
    int sign;
    long long nb = 0;

    if (str == NULL)
        return 0;
    sign = count_signs(str, &i);
    while (str[i] >= '0' && str[i] <= '9') {
        if (check_overflow(nb, str[i] - '0', sign))
            return 0;
        nb = nb * 10 + (str[i] - '0');
        i++;
    }
    return (int)(nb * sign);
}
