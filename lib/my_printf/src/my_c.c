/*
** EPITECH PROJECT, 2026
** my_printf
** File description:
** my_c - print a character
*/

#include "../include/my_printf.h"

int my_c_caller(va_list list)
{
    char c = (char)va_arg(list, int);

    return my_c(c);
}

int my_c(char c)
{
    return write(1, &c, 1);
}
