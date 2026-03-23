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
