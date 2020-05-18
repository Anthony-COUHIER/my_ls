/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** display number given as params
*/

#include "my_printf.h"

int isneg(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    return (nb);
}

void my_put_nbr_dec(int nb)
{
    long long res = 0;
    long long div = 1;

    if (nb == -2147483648) {
        my_putstr("-2147483648");
        return;
    }
    nb = isneg(nb);
    if (nb == 0)
        my_putchar('0');
    for (; nb % div != nb; div = div * 10);
    div = div / 10;
    for (long long trop = 0; div >= 1; ) {
        res = nb / div - trop * 10;
        trop = nb / div;
        div = div / 10;
        my_putchar(res + '0');
    }
}

void my_put_nbr_bin(int nb)
{
    long power = 1;
    int res;
    int i = 0;
    int bin = 2;
    char *base_bin = "01234567";

    if (nb == 0)
        my_putchar('0');
    for (; nb > power; i++)
        power = bin * power;
    for (power = 1, i--; i != -1; i--) {
        for (int j = 0; j != i; j++)
            power = bin * power;
        res = nb / power;
        my_putchar(base_bin[res]);
        nb = nb % power;
        power = 1;
    }
}

void my_put_nbr_hex(long nb, char format, int hex)
{
    long power = 1;
    long res;
    int i = 0;
    char *base_hex = "0123456789ABCDEF0123456789abcdef";

    if (nb == 0)
        my_putchar('0');
    for (; nb > power; i++)
        power = hex * power;
    for (power = 1, i--; i != -1; i--) {
        for (int j = 0; j != i; j++)
            power = hex * power;
        res = nb / power;
        format == 'X' ? my_putchar(base_hex[res]) :
        my_putchar(base_hex[16 + res]);
        nb = nb % power;
        power = 1;
    }
}

void my_put_nbr_oct(int nb)
{
    long power = 1;
    int res;
    int i = 0;
    int oct = 8;
    char *base_oct = "01234567";

    if (nb == 0)
        my_putchar('0');
    for (; nb > power; i++)
        power = oct * power;
    for (power = 1, i--; i != -1; i--) {
        for (int j = 0; j != i; j++)
            power = oct * power;
        res = nb / power;
        my_putchar(base_oct[res]);
        nb = nb % power;
        power = 1;
    }
}
