/*
** EPITECH PROJECT, 2026
** other_functions
** File description:
** my_strjoin - joins two strings with a separator
*/

#include "other_functions.h"

char *my_strjoin(char const *s1, char const *s2, char const *sep)
{
    int len1;
    int len2;
    int len_sep;
    char *result;
    int i = 0;

    if (s1 == NULL || s2 == NULL)
        return NULL;
    len1 = my_strlen((char *)s1);
    len2 = my_strlen((char *)s2);
    len_sep = (sep == NULL) ? 0 : my_strlen((char *)sep);
    result = malloc(sizeof(char) * (len1 + len2 + len_sep + 1));
    if (result == NULL)
        return NULL;
    my_strcpy(result, s1);
    if (sep != NULL)
        my_strcat(result, sep);
    my_strcat(result, s2);
    return result;
}
