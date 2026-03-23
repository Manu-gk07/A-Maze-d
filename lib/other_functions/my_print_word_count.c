/*
** EPITECH PROJECT, 2026
** other_functions
** File description:
** my_print_word_count - prints word count in format "Word": count
*/

#include "other_functions.h"

void my_print_word_count(char const *str, char const *word)
{
    int count;

    if (str == NULL || word == NULL)
        return;
    count = my_str_count_word(str, word);
    my_printf("\"%s\": %d\n", word, count);
}
