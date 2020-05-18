/*
** EPITECH PROJECT, 2019
** PSU_printf_2019
** File description:
** my_printf
*/

#include "my_printf.h"

void my_printf(char *format, ...)
{
    va_list ap;
    int j = 0;
    int i = 0;

    for (; format[j]; j++);
    va_start(ap, format);
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            i++;
            my_flags(format, i, ap);
            if (format[i] == 'h' || format[i] == 'l')
                i++;
        } else
            my_putchar(format[i]);
    }
    va_end(ap);
}

void my_flags(char *format, int i, va_list ap)
{
    while ((format[i] == '#' || format[i] == '+' || format[i] == '-'
    || format[i] == ' ' || (format[i] <= '9' && format[i] >= '0')))
        i++;
    cond_1(format, i, ap);
}

void cond_1(char *format, int i, va_list ap)
{
    (format[i] == '%') ? my_putchar('%') : 0;
    (format[i] == 'c') ? my_putchar(va_arg(ap, int)) : 0;
    (format[i] == 's') ? my_putstr(va_arg(ap, char *)) : 0;
    (format[i] == 'S') ? my_carac_no_print(va_arg(ap, char *)) : 0;
    (format[i] == 'd') ? my_put_nbr_dec(va_arg(ap, int)) : 0;
    (format[i] == 'i') ? my_put_nbr_dec(va_arg(ap, int)) : 0;
    (format[i] == 'x') ? my_put_nbr_hex(va_arg(ap, int), format[i], 16) : 0;
    (format[i] == 'X') ? my_put_nbr_hex(va_arg(ap, int), format[i], 16) : 0;
    (format[i] == 'o') ? my_put_nbr_oct(va_arg(ap, int)) : 0;
    (format[i] == 'b') ? my_put_nbr_bin(va_arg(ap, int)) : 0;
    (format[i] == 'u') ? my_put_unint(va_arg(ap, unsigned int)) : 0;
    if (format[i] == 'p') {
        my_putstr("0x");
        my_put_nbr_hex((long) va_arg(ap, void *), format[i], 16);
    }
    cond_2(format, i, ap);
}

void cond_2(char *format, int i, va_list ap)
{
    if (format[i] == 'l' && format[i + 1] == 'd')
        my_put_long(va_arg(ap, long));
    if (format[i] == 'h' && format[i + 1] == 'd')
        my_put_short(va_arg(ap, int));
    if (format[i] != '%' && format[i] != 'c' && format[i] != 's' &&
    format[i] != 'S' && format[i] != 'd' && format[i] != 'i' && format[i] != 'x'
    && format[i] != 'X' && format[i] != 'o' && format[i] != 'b' &&
    format[i] != 'u' && format[i] != 'p' && format[i] != 'l' &&
    format[i] != 'h') {
        my_putchar('%');
        my_putchar(format[i]);
    }
    if ((format[i] == 'l' || format[i] == 'h') && format[i + 1] != 'd') {
        my_putchar('%');
        my_putchar(format[i]);
        my_putchar(format[i] + 1);
    }
}
