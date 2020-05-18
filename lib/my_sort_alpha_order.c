/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** my_sort_alpha_order
*/

#include "proto.h"

char **my_alpha_order(char **my_files, int size)
{
    int pos = 0;
    int res = 0;

    for (; pos + 1 != size;) {
        res = my_strcmp(my_files[pos], my_files[pos + 1]);
        if (res == 1) {
            pos++;
        } else if (res == 0) {
            pos++;
        } else {
            my_files = my_swap(my_files, pos, pos + 1);
            pos = 0;
        }
    }
    return my_files;
}

char **my_swap(char **table, int pos1, int pos2)
{
    char *tmp = table[pos1];

    table[pos1] = table[pos2];
    table[pos2] = tmp;
    return table;
}

char **my_reverse_order(char **my_files, int size)
{
    char **tmp = malloc(sizeof(char *) * size);
    int max = size;
    int i = 0;

    while (i != max) {
        tmp[size - 1] = my_files[i];
        i++;
        size--;
    }
    return tmp;
}

char **sort_by_time(char **my_files, int size, char *files)
{
    struct stat sts;
    int i = 0;
    int time1;
    int time2;

    while (i + 1 != size) {
        lstat(my_strcat(my_strcat(files, "/"), my_files[i]), &sts);
        time1 = sts.st_mtime;
        lstat(my_strcat(my_strcat(files, "/"), my_files[i + 1]), &sts);
        time2 = sts.st_mtime;
        if (time1 > time2)
            i++;
        else if (time1 == time2) {
            my_swap(my_files, i, i + 1);
            i++;
        } else {
            my_swap(my_files, i, i + 1);
            i = 0;
        }
    }
    return my_files;
}
