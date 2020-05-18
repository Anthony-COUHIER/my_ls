/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** opt_upper_r
*/

#include "proto.h"

void opt_rec(char *files, opt_t *opt)
{
    struct stat sts;
    char *directory;
    mode_t mode;
    DIR *dir = open_files(files);
    struct dirent *RDIR;

    while ((RDIR = readdir(dir))) {
        if (visible(RDIR->d_name, opt) == -1 || check_rec(RDIR->d_name) == -1)
            continue;
        directory = my_strcat(my_strcat(files, "/"), RDIR->d_name);
        if (lstat(directory, &sts) == 0) {
            mode = sts.st_mode;
            if ((mode & __S_IFMT) == __S_IFDIR) {
                my_printf("\n");
                my_printf(BLUE"%s", directory);
                my_printf(NORMAL"%s", ":\n");
                my_ls(directory, opt);
            }
        }
    }
}

int check_rec(char *str)
{
    if (str[0] == '.' && str[1] == '\0')
        return -1;
    else if (str[0] == '.' && str[1] == '.' && str[2] == '\0')
        return -1;
    else
        return 1;
}
