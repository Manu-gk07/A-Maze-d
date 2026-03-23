/*
** EPITECH PROJECT, 2026
** other_functions
** File description:
** print_only_alpha - prints only alphabetic characters from arguments
*/

#include "other_functions.h"

int print_only_alpha(int argc, char **argv)
{
    if (argc < 1 || argv == NULL)
        return 84;
    for (int i = 1; i < argc; i++) {
        if (argv[i] == NULL)
            return 84;
        for (int j = 0; argv[i][j] != '\0'; j++) {
            if ((argv[i][j] >= 'a' && argv[i][j] <= 'z') ||
                (argv[i][j] >= 'A' && argv[i][j] <= 'Z') ||
                argv[i][j] == ' ')
                my_printf("%c", argv[i][j]);
        }
    }
    my_printf("\n");
    return 0;
}
