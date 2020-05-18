/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** manage_dir
*/

#include "proto.h"

DIR *open_files(char *my_dir)
{
    DIR *directory = opendir(my_dir);

    if (directory == NULL) {
        my_printf("my_ls: cannot access '%s' : ", my_dir);
        perror("");
        exit(84);
    }
    return directory;
}

int nbr_dir(int argc, char **argv, opt_t *op)
{
    int j = 1;
    int count = 0;
    op->opt_d = 0;
    op->opt_l = 0;
    op->opt_R = 0;
    op->opt_t = 0;
    op->opt_r = 0;
    op->opt_a = 0;
    op->opt_o = 0;
    op->opt_s = 0;
    op->opt_p = 0;

    while (argv[j]) {
        if (argv[j][0] == '-') {
            opt(argv, j, op);
            count++;
        }
        j++;
    }
    return count;
}

void opt(char **av, int pos, opt_t *opt)
{
    opt->size_grp = 0;
    opt->size_name = 0;
    opt->size_octet = 0;
    opt->size_link = 0;
    opt->size_block = 0;
    int i = 1;

    if (av[pos][i])
        check_opt(av[pos], opt);
    else {
        my_printf("%s: cannot access '-': No such file or directory\n", av[0]);
        exit(84);
    }
}

void check_opt(char *line, opt_t *opt)
{
    for (int i = 1; line[i]; i++) {
        (line[i] == 'l') ? opt->opt_l = 1 : 0;
        (line[i] == 'R') ? opt->opt_R = 1 : 0;
        (line[i] == 'd') ? opt->opt_d = 1 : 0;
        (line[i] == 'r') ? opt->opt_r = 1 : 0;
        (line[i] == 't') ? opt->opt_t = 1 : 0;
        (line[i] == 'a') ? opt->opt_a = 1 : 0;
        (line[i] == 'o') ? opt->opt_o = 1 : 0;
        (line[i] == 'p') ? opt->opt_p = 0 : 1;
        (line[i] == 's') ? opt->opt_s = 1 : 0;
        if (check_opt2(line[i]) != 0) {
            my_printf("my_ls: invalid option -- '%c'\n", line[i]);
            exit(84);
        }
    }
}

int check_opt2(char c)
{
    int count = 0;

    (c == 'l') ? count = 1 : 0;
    (c == 'R') ? count = 1 : 0;
    (c == 'd') ? count = 1 : 0;
    (c == 'r') ? count = 1 : 0;
    (c == 't') ? count = 1 : 0;
    (c == 'a') ? count = 1 : 0;
    (c == 'o') ? count = 1 : 0;
    (c == 'p') ? count = 1 : 0;
    (c == 's') ? count = 1 : 0;
    if (count == 1)
        return 0;
    else
        return -1;
}
