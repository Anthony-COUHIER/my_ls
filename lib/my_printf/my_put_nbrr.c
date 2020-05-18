/*
** EPITECH PROJECT, 2019
** PSU_printf_2019
** File description:
** my_put_long
*/

#include "my_printf.h"

void my_put_long(long nb)
{
    long res = 0;
    long long div = 1;
    long long trop = 0;

    nb = isneg(nb);
    if (nb == 0)
        my_putchar('0');
    while (nb % div != nb)
        div = div * 10;
    div = div / 10;
    while (div >= 1) {
        res = nb / div - trop * 10;
        trop = nb / div;
        div = div / 10;
        my_putchar(res + '0');
    }
}

void my_put_short(short nb)
{
    short res = 0;
    short div = 1;
    short trop = 0;

    nb = isneg(nb);
    if (nb == 0)
        my_putchar('0');
    while (nb % div != nb)
        div = div * 10;
    div = div / 10;
    while (div >= 1) {
        res = nb / div - trop * 10;
        trop = nb / div;
        div = div / 10;
        my_putchar(res + '0');
    }
}

int my_put_unint(unsigned int nb)
{
    int res = 0;
    int div = 1;
    int trop = 0;

    if (nb == 0)
        my_putchar('0');
    while (nb % div != nb)
        div = div * 10;
    div = div / 10;
    while (div >= 1) {
        res = nb / div - trop * 10;
        trop = nb / div;
        div = div / 10;
        my_putchar(res + '0');
    }
    return (res);
}
