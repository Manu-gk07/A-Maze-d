/*
** EPITECH PROJECT, 2026
** other_functions
** File description:
** print_only_alpha - prints only alphabetic characters from arguments
*/

#include "other_functions.h"

static void print_alpha_chars(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] >= 'a' && str[i] <= 'z') ||
            (str[i] >= 'A' && str[i] <= 'Z') ||
            str[i] == ' ')
            my_printf("%c", str[i]);
    }
}

int print_only_alpha(int argc, char **argv)
{
    if (argc < 1 || argv == NULL)
        return 84;
    for (int i = 1; i < argc; i++) {
        if (argv[i] == NULL)
            return 84;
        print_alpha_chars(argv[i]);
    }
    my_printf("\n");
    return 0;
}
