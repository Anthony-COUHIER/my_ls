/*
** EPITECH PROJECT, 2019
** PSU_printf_2019
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_

#include "stdarg.h"
#include "unistd.h"

void my_printf(char *format, ...);
void my_flags(char *format, int i, va_list ap);
void cond_1(char *format, int i, va_list ap);
void cond_2(char *format, int i, va_list ap);
void cond_3(char *format, int i, va_list ap);
void my_put_short(short nb);
void my_put_long(long nb);
void my_put_nbr_hex(long nb, char format, int hex);
void my_put_nbr_oct(int nb);
void my_put_nbr_bin(int nb);
void my_put_nbr_dec(int nb);
int my_put_unint(unsigned int nb);
int isneg(int nb);
void my_putstr(char *str);
void my_putchar(char c);
void my_carac_no_print(char *str);
void my_ascii(char carac);

#endif /* !MY_H_ */
