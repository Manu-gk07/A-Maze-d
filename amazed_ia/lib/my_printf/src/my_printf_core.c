/*
** EPITECH PROJECT, 2026
** my_printf
** File description:
** my_printf core implementation
*/

#include "../include/my_printf.h"

const specifier_t specifiers[15] =
{
    {'c', &my_c_caller},
    {'i', &my_d_caller},
    {'d', &my_d_caller},
    {'s', &my_s_caller},
    {'f', &my_f_caller},
    {'l', &my_f_caller},
    {'u', &my_u_caller},
    {'o', &my_o_caller},
    {'e', &my_e_caller},
    {'E', &my_ee_caller},
    {'g', &my_g_caller},
    {'x', &my_x_caller},
    {'X', &my_xx_caller},
    {'w', &my_w_caller},
    {'p', &my_p_caller}
};

int flag_0(const char *s, int nb)
{
    if (s[0] == '0' && (s[2] == 'd' || s[2] == 'i'))
        return my_flag_0(s[1] - '0', nb, &my_decimal);
    if (s[0] == '0' && s[2] == 'x')
        return my_flag_0(s[1] - '0', nb, &my_x_char);
    if (s[0] == '0' && s[2] == 'X')
        return my_flag_0(s[1] - '0', nb, &my_xx_char);
    if (s[0] == '0' && s[2] == 'o')
        return my_flag_0(s[1] - '0', nb, &my_o_char);
    else
        return -1000;
}

int disp_stdarg(const char *s, va_list list)
{
    for (int i = 0; i < 15; i++) {
        if (specifiers[i].option == s[0])
            return specifiers[i].fonction_pointer(list);
    }
    if (s[0] == '%')
        return my_c('%');
    if (s[0] == '+') {
        my_plus(va_arg(list, int));
        return 1;
    }
    if (s[0] == ' ') {
        my_space(va_arg(list, int));
        return 1;
    }
    return flag_0(s, va_arg(list, int));
}

void handle_format_skip(const char *format, int *i)
{
    if (format[*i] == '0')
        *i += 2;
    if ((format[*i] == ' ') || (format[*i] == '+'))
        *i += 1;
}

int my_printf(const char *format, ...)
{
    va_list list;
    int count = 0;

    va_start(list, format);
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            count += disp_stdarg(format + i + 1, list);
            i++;
            handle_format_skip(format, &i);
        } else {
            my_c(format[i]);
            count++;
        }
    }
    va_end(list);
    return count;
}
