/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** opt_a
*/

#include "proto.h"

int visible(char *files, opt_t *opt)
{
    int test = 0;

    if (opt->opt_a == 1)
        return 0;
    (files[0] == '.') ? test = 1 : 0;
    (files[0] == '~' && files[1] == '.') ? test = 1 : 0;
    if (test == 1)
        return -1;
    else
        return 0;
}
