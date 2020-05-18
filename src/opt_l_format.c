/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** opt_l_format
*/

#include "proto.h"

int size_max_str(char *str, int size)
{
    int i = 0;

    while (str[i])
        i++;
    if (i > size)
        return i;
    else
        return size;
}

int size_max_int(int octet, int size)
{
    int my_oct = 0;
    int i = 0;

    my_oct += octet;
    while ((my_oct /= 10) > 0)
        i++;
    if (i > size)
        return i;
    else
        return size;
}

void calc_format(opt_t *opt, int size, char **my_files, char *files)
{
    struct stat sts;
    struct group *grp;
    struct passwd *pw;

    for (int i = 0; i < size; i++) {
        if (stat(my_strcat(my_strcat(files, "/"), my_files[i]), &sts) == 0) {
            pw = getpwuid(sts.st_uid);
            grp = getgrgid(sts.st_gid);
            if (visible(my_files[i], opt) == 0) {
                opt->size_grp = size_max_str(grp->gr_name, opt->size_grp);
                opt->size_name = size_max_str(pw->pw_name, opt->size_name);
                opt->size_octet = size_max_int(sts.st_size, opt->size_octet);
                opt->size_link = size_max_int(sts.st_nlink, opt->size_link);
                opt->size_block = size_max_int(sts.st_blocks, opt->size_block);
            }
        }
    }
}
