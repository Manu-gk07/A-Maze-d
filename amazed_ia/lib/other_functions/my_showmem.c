/*
** EPITECH PROJECT, 2026
** other_functions
** File description:
** my_showmem - print memory dump
*/

#include "other_functions.h"

static void print_address(int addr)
{
    my_printf("%08x", addr);
}

static void print_hex_content(char const *str, int size, int offset)
{
    int i = 0;

    while (i < 16) {
        if (i + offset < size) {
            my_printf("%02x", (unsigned char)str[i + offset]);
        } else {
            my_printf("  ");
        }
        if (i % 2 == 1)
            my_printf(" ");
        i++;
    }
}

static void print_ascii_content(char const *str, int size, int offset)
{
    int i = 0;

    while (i < 16 && i + offset < size) {
        if (str[i + offset] >= 32 && str[i + offset] <= 126)
            my_printf("%c", str[i + offset]);
        else
            my_printf(".");
        i++;
    }
}

int my_showmem(char const *str, int size)
{
    int offset = 0;

    if (str == NULL || size < 0)
        return 84;
    while (offset < size) {
        print_address(offset);
        my_printf(": ");
        print_hex_content(str, size, offset);
        print_ascii_content(str, size, offset);
        my_printf("\n");
        offset += 16;
    }
    return 0;
}
