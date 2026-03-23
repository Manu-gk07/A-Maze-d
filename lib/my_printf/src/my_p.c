/*
** EPITECH PROJECT, 2026
** my_printf
** File description:
** my_p - print pointer address
*/

#include "../include/my_printf.h"

int my_x_p(unsigned long nb)
{
    char hexa[] = "0123456789abcdef";
    unsigned long nbcopy;
    int count = 0;

    if (nb >= 16)
        count += my_x_p(nb / 16);
    nbcopy = nb % 16;
    count += my_c(hexa[nbcopy]);
    return count;
}

int my_p_caller(va_list list)
{
    void *nb = va_arg(list, void *);

    return my_p(nb);
}

int my_p(void *pointeur)
{
    int count = 0;
    unsigned long number_pointer = (unsigned long)pointeur;

    count += my_s("0x");
    count += my_x_p(number_pointer);
    return count;
}
