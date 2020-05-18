/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** my_strcat
*/

#include "proto.h"

char *my_strcat(char *str1, char *str2)
{
    int pos = 0;
    int size1 = my_strlen(str1);
    int size2 = my_strlen(str2);
    char *tmp = malloc(sizeof(char) * (size1 + 1 + size2));

    if (tmp == NULL)
        return NULL;
    for (int i = 0; i < size1; i++, pos++)
        tmp[pos] = str1[i];
    for (int i = 0; i < size2; i++, pos++)
        tmp[pos] = str2[i];
    tmp[pos] = '\0';
    return tmp;
}
