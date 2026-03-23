/*
** EPITECH PROJECT, 2026
** other_functions
** File description:
** my_atoi - simple string to integer conversion
*/

#include "other_functions.h"

int my_atoi(char const *str)
{
    int result = 0;
    int sign = 1;
    int i = 0;

    if (str == NULL)
        return 0;
    while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
        i++;
    if (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return result * sign;
}

int my_atoi_quentin(char *str)
{
    int nb = 0;
    int i = 0;
    int sign = 1;

    if (str[0] == '-') {
        sign = -1;
        i = 1;
    } else if (str[0] == '+') {
        i = 1;
    }
    for (; i < my_strlen(str); i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            nb = (nb * 10) + (str[i] - '0');
        } else {
            break;
        }
    }
    return nb * sign;
}
