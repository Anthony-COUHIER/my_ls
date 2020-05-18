/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** my_strcpy
*/

#include "proto.h"

char *my_strcpy(char *str)
{
    char *tmp;
    int size = 0;

    while (str[size] != '\0')
        size++;
    tmp = malloc(sizeof(char) * size + 1);
    for (int i = 0; str[i]; i++)
        tmp[i] = str[i];
    tmp[size] = '\0';
    return tmp;
}
