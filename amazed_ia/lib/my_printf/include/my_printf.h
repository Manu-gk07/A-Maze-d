/*
** EPITECH PROJECT, 2026
** my_printf
** File description:
** my_printf header file
*/

#ifndef _MY_PRINTF_H_
    #define _MY_PRINTF_H_
    #define SIZEBUFFER 16000
    #include <unistd.h>
    #include <stdarg.h>
    #include <stdarg.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdio.h>

typedef struct specifier_s {
    char option;
    int (*fonction_pointer)(va_list list);
} specifier_t;

int my_u_caller(va_list list);
int my_g_caller(va_list list);
int my_s_caller(va_list list);
int my_c_caller(va_list list);
int my_c(char c);
int my_d(int nb);
int my_d_caller(va_list list);
void my_swap(char *a, char *b);
int my_s(char *str);
int my_f(double nb);
int my_f_caller(va_list list);
int my_strlen(char *str);
char *my_strcat(char *dest, char const *src);
int my_e(double nb);
int my_e_caller(va_list list);
int my_ee(double nb);
int my_ee_caller(va_list list);
char *my_revstr(char *str);
int my_xx(int nb);
int my_xx_caller(va_list list);
char *my_xx_char_caller(va_list list);
char *my_xx_char(int nb);
int my_x(int nb);
int my_x_caller(va_list list);
char *my_x_char_caller(va_list list);
char *my_x_char(int nb);
int my_o(int nb);
int my_o_caller(va_list list);
char *my_o_char(int nb);
char *my_o_char_caller(va_list list);
int my_u(unsigned int n);
int my_g(double nb);
int my_w(int nb);
int my_w_caller(va_list list);
int my_plus(int nb);
int my_plus_caller(va_list list);
int my_space(int nb);
int my_space_caller(va_list list);
int my_flag_0(int min, int nb, char *(*fnt_ptr)(int nb));
char *my_decimal(int nb);
int my_p(void *pointeur);
int my_p_caller(va_list list);
int my_printf(const char *format, ...);
char *my_strdup(char const *src);
int my_strcmp(char const *s1, char const *s2);

#endif /* _MY_PRINTF_H_ */
