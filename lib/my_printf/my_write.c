/*
** EPITECH PROJECT, 2019
** my_putchar.c
** File description:
** putchar
*/

#include "my_printf.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char *str)
{
    int i = 0;
    for (; str[i]; i++);
    write(1, str, i);
}

void my_ascii(char carac)
{
    my_putchar('\\');
    if (carac <= 7) {
        my_putstr("00");
        my_put_nbr_oct(carac);
    }
    if (carac < 32 && carac > 7) {
        my_putstr("0");
        my_put_nbr_oct(carac);
    }
    if (carac > 126 ) {
        my_put_nbr_oct(carac);
    }
}

void my_carac_no_print(char *str)
{
    int i = 0;

    for (; str[i]; i++) {
        if (str[i] < 32 || str[i] >= 127)
            my_ascii(str[i]);
        else
            my_putchar(str[i]);
    }
}
