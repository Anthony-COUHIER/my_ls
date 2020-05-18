/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** my_strlen
*/

#include "proto.h"

int my_strlen(char *str)
{
    int size = 0;

    while (str[size])
        size++;
    return size;
}
