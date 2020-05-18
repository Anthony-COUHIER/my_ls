/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** my_strcmp
*/

#include "proto.h"

int my_strcmp(char *str1, char *str2)
{
    char *s1 = my_strcpy(str1);
    char *s2 = my_strcpy(str2);
    int i = 0;

    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] >= 97 && s1[i] <= 122)
            s1[i] -= 32;
        if (s2[i] >= 97 && s2[i] <= 122)
            s2[i] -= 32;
        if (s1[i] == s2[i])
            i++;
        else
            break;
    }
    if (s1[i] > s2[i])
        return 2;
    else if (s1[i] < s2[i])
        return 1;
    else
        return 0;
}
