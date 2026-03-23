/*
** EPITECH PROJECT, 2026
** other_functions
** File description:
** my_str_count_word - counts occurrences of a word in a string
*/

#include "other_functions.h"

int my_str_count_word(char const *str, char const *word)
{
    int count = 0;
    int word_len;
    int i = 0;

    if (str == NULL || word == NULL)
        return 0;
    word_len = my_strlen((char *)word);
    if (word_len == 0)
        return 0;
    while (str[i] != '\0') {
        if (my_strncmp(&str[i], word, word_len) == 0) {
            count++;
            i += word_len;
        } else {
            i++;
        }
    }
    return count;
}
