/*
** EPITECH PROJECT, 2026
** other_functions
** File description:
** other_functions header file
*/

#ifndef OTHER_FUNCTIONS_H_
    #define OTHER_FUNCTIONS_H_

    #include <stdarg.h>
    #include <stdbool.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <unistd.h>

// Include my_printf functions
int my_printf(const char *format, ...);
int my_c(char c);
int my_s(char *str);

// ============================================================================
// BASIC UTILITY FUNCTIONS
// ============================================================================

/*
** my_put_nbr - Displays an integer
** Example: my_put_nbr(42) -> prints "42"
**          my_put_nbr(-2147483648) -> prints "-2147483648"
*/
int my_put_nbr(int nb);

/*
** my_isneg - Displays 'N' if negative, 'P' if positive or null
** Example: my_isneg(-5) -> prints "N"
**          my_isneg(10) -> prints "P"
**          my_isneg(0) -> prints "P"
*/
int my_isneg(int n);

/*
** my_swap_int - Swaps the content of two integers
** Example: int a = 5, b = 10;
**          my_swap_int(&a, &b);
**          // Now a = 10, b = 5
*/
void my_swap_int(int *a, int *b);

// ============================================================================
// STRING MANIPULATION FUNCTIONS
// ============================================================================

/*
** my_evil_str - Reverses a string by swapping characters
** Example: char str[] = "hello";
**          my_evil_str(str); // str becomes "olleh"
*/
char *my_evil_str(char *str);

/*
** my_getnbr - Converts a string to an integer
** Example: my_getnbr("42") -> returns 42
**          my_getnbr("-123") -> returns -123
**          my_getnbr("+-+-42") -> returns -42
**          my_getnbr("99999999999999999") -> returns 0 (overflow)
*/
int my_getnbr(char const *str);

/*
** my_strcpy - Copies a string into another
** Example: char dest[10];
**          my_strcpy(dest, "hello"); // dest becomes "hello"
*/
char *my_strcpy(char *dest, char const *src);

/*
** my_strncpy - Copies n characters from a string into another
** Example: char dest[10];
**          my_strncpy(dest, "hello", 3); // dest becomes "hel"
*/
char *my_strncpy(char *dest, char const *src, int n);

/*
** my_strstr - Locates a substring in a string
** Example: my_strstr("hello world", "wor") -> returns pointer to "world"
**          my_strstr("test", "xyz") -> returns NULL
*/
char *my_strstr(char *str, char const *to_find);

/*
** my_strncmp - Compares n characters of two strings
** Example: my_strncmp("hello", "help", 3) -> returns negative value
**          my_strncmp("abc", "abc", 3) -> returns 0
*/
int my_strncmp(char const *s1, char const *s2, int n);

/*
** my_strupcase - Converts all letters to uppercase
** Example: char str[] = "Hello123";
**          my_strupcase(str); // str becomes "HELLO123"
*/
char *my_strupcase(char *str);

/*
** my_strlowcase - Converts all letters to lowercase
** Example: char str[] = "Hello123";
**          my_strlowcase(str); // str becomes "hello123"
*/
char *my_strlowcase(char *str);

/*
** my_strcapitalize - Capitalizes the first letter of each word
** Example: char str[] = "hello world 42abc";
**          my_strcapitalize(str); // str becomes "Hello World 42abc"
*/
char *my_strcapitalize(char *str);

/*
** my_strncat - Concatenates n characters to the end of dest
** Example: char dest[20] = "hello";
**          my_strncat(dest, " world!", 3); // dest becomes "hello wo"
*/
char *my_strncat(char *dest, char const *src, int nb);

// ============================================================================
// STRING CHECKING FUNCTIONS
// ============================================================================

/*
** my_isdigit - Checks if a character is a digit (0-9)
** Example: my_isdigit('5') -> returns 1
**          my_isdigit('a') -> returns 0
*/
int my_isdigit(char c);

/*
** my_str_isalpha - Checks if string contains only alphabetical characters
** Example: my_str_isalpha("Hello") -> returns 1
**          my_str_isalpha("Hello123") -> returns 0
**          my_str_isalpha("") -> returns 1
*/
int my_str_isalpha(char const *str);

/*
** my_str_isnum - Checks if string contains only digits
** Example: my_str_isnum("12345") -> returns 1
**          my_str_isnum("123a") -> returns 0
**          my_str_isnum("") -> returns 1
*/
int my_str_isnum(char const *str);

/*
** my_str_islower - Checks if string contains only lowercase letters
** Example: my_str_islower("hello") -> returns 1
**          my_str_islower("Hello") -> returns 0
**          my_str_islower("") -> returns 1
*/
int my_str_islower(char const *str);

/*
** my_str_isupper - Checks if string contains only uppercase letters
** Example: my_str_isupper("HELLO") -> returns 1
**          my_str_isupper("Hello") -> returns 0
**          my_str_isupper("") -> returns 1
*/
int my_str_isupper(char const *str);

// ============================================================================
// DISPLAY FUNCTIONS
// ============================================================================

/*
** my_showstr - Prints string with non-printable chars as \xx in hexadecimal
** Example: my_showstr("Hello\n") -> prints "Hello\0a"
**          my_showstr("Test\t") -> prints "Test\09"
*/
int my_showstr(char const *str);

/*
** my_showmem - Displays a memory dump in hexadecimal format
** Example: my_showmem("Hello", 5) -> prints:
**          00000000: 4865 6c6c 6f00 0000 0000 0000 0000 0000 Hello...........
*/
int my_showmem(char const *str, int size);

/*
** print_only_alpha - Prints only alphabetic characters from arguments
** Example: print_only_alpha(3, {"prog", "Hello123", "World!"})
**          -> prints "Hello World\n"
**          print_only_alpha(2, {"prog", "42test"}) -> prints "test\n"
*/
int print_only_alpha(int argc, char **argv);

// ============================================================================
// ARRAY FUNCTIONS
// ============================================================================

/*
** my_sort_int_array - Sorts an integer array in ascending order
** Example: int arr[] = {5, 2, 8, 1, 9};
**          my_sort_int_array(arr, 5); // arr becomes {1, 2, 5, 8, 9}
*/
void my_sort_int_array(int *array, int size);

// ============================================================================
// STRING UTILITY FUNCTIONS (shared with my_printf)
// ============================================================================

/*
** my_revstr - Reverses a string
** Example: char str[] = "hello";
**          my_revstr(str); // str becomes "olleh"
*/
char *my_revstr(char *str);

/*
** my_strcat - Concatenates src to the end of dest
** Example: char dest[20] = "hello";
**          my_strcat(dest, " world"); // dest becomes "hello world"
*/
char *my_strcat(char *dest, char const *src);

/*
** my_strcmp - Compares two strings
** Example: my_strcmp("abc", "abc") -> returns 0
**          my_strcmp("abc", "abd") -> returns negative value
*/
int my_strcmp(char const *s1, char const *s2);

/*
** my_strdup - Duplicates a string (allocates memory)
** Example: char *dup = my_strdup("hello");
**          // dup is a new string containing "hello"
**          // Remember to free(dup) when done
*/
char *my_strdup(char const *src);

/*
** my_strlen - Returns the length of a string
** Example: my_strlen("hello") -> returns 5
**          my_strlen("") -> returns 0
*/
int my_strlen(char *str);

// ============================================================================
// ADDITIONAL STRING FUNCTIONS
// ============================================================================

/*
** my_strtrim - Removes whitespace from start and end of string
** Example: char str[] = "  hello  ";
**          my_strtrim(str); // str becomes "hello"
*/
char *my_strtrim(char *str);

/*
** my_str_replace - Replaces all occurrences of a character with another
** Example: char str[] = "hello";
**          my_str_replace(str, 'l', 'x'); // str becomes "hexxo"
*/
char *my_str_replace(char *str, char old_char, char new_char);

/*
** my_strjoin - Joins two strings with a separator (allocates memory)
** Example: char *result = my_strjoin("hello", "world", " ");
**          // result is "hello world"
**          // Remember to free(result) when done
*/
char *my_strjoin(char const *s1, char const *s2, char const *sep);

/*
** my_str_count_char - Counts occurrences of a character in a string
** Example: my_str_count_char("hello", 'l') -> returns 2
**          my_str_count_char("test", 'x') -> returns 0
*/
int my_str_count_char(char const *str, char c);

/*
** my_str_count_word - Counts occurrences of a word in a string
** Example: my_str_count_word("hello world hello", "hello") -> returns 2
**          my_str_count_word("testtest", "test") -> returns 2
**          my_str_count_word("hello", "world") -> returns 0
*/
int my_str_count_word(char const *str, char const *word);

/*
** my_print_word_count - Prints word count in format "Word": count
** Example: my_print_word_count("hello world hello", "hello")
**          -> prints "hello": 2
**          my_print_word_count("test", "test") -> prints "test": 1
*/
void my_print_word_count(char const *str, char const *word);

/*
** my_str_contains - Checks if a string contains a substring
** Example: my_str_contains("hello world", "wor") -> returns 1
**          my_str_contains("test", "xyz") -> returns 0
*/
int my_str_contains(char const *str, char const *to_find);

/*
** my_str_isalnum - Checks if string contains only alphanumeric characters
** Example: my_str_isalnum("Hello123") -> returns 1
**          my_str_isalnum("Hello 123") -> returns 0
**          my_str_isalnum("") -> returns 1
*/
int my_str_isalnum(char const *str);

/*
** my_strchr - Finds first occurrence of a character in a string
** Example: my_strchr("hello", 'e') -> returns pointer to "ello"
**          my_strchr("test", 'x') -> returns NULL
*/
char *my_strchr(char const *str, char c);

/*
** my_strrchr - Finds last occurrence of a character in a string
** Example: my_strrchr("hello", 'l') -> returns pointer to "lo"
**          my_strrchr("test", 'x') -> returns NULL
*/
char *my_strrchr(char const *str, char c);

// ============================================================================
// ADDITIONAL UTILITY FUNCTIONS
// ============================================================================

/*
** my_array_len - Calculates the length of a NULL-terminated string array
** Example: char *arr[] = {"hello", "world", NULL};
**          my_array_len(arr) -> returns 2
*/
int my_array_len(char **array);

/*
** my_atoi - Simple string to integer conversion
** Example: my_atoi("42") -> returns 42
**          my_atoi("-123") -> returns -123
**          my_atoi("  456") -> returns 456
*/
int my_atoi(char const *str);

#endif /* OTHER_FUNCTIONS_H_ */
