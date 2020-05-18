/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** aff
*/

#include "proto.h"

void my_ls(char *files, opt_t *opt)
{
    struct stat sts;
    char **my_files = create_table(files);
    int size = nbr_files(files);

    my_files = my_alpha_order(my_files, size);
    (opt->opt_t == 1) ? sort_by_time(my_files, size, files) : 0;
    (opt->opt_r == 1) ? my_files = my_reverse_order(my_files, size) : 0;
    if (opt->opt_l == 1)
        print_l(my_files, files, size, opt);
    else {
        for (int i = 0; i < size; i++) {
        lstat(my_strcat(my_strcat(files, "/"), my_files[i]), &sts);
        print_size(&sts, opt);
            if (visible(my_files[i], opt) == 0)
                mark_info(my_files[i], opt, &sts);
        }
        (opt->opt_R == 1) ? opt_rec(files, opt) : 0;
    }
}

void print_l(char **my_files, char *files, int size, opt_t *opt)
{
    struct stat sts;
    struct group *grp;
    struct passwd *pw;

    calc_format(opt, size, my_files, files);
    total(files);
    for (int i = 0; i < size; i++) {
        if (lstat(my_strcat(my_strcat(files, "/"), my_files[i]), &sts) == 0) {
            pw = getpwuid(sts.st_uid);
            grp = getgrgid(sts.st_gid);
            if (visible(my_files[i], opt) == 0) {
                print_size(&sts, opt);
                my_printf(NORMAL"%s. ", perm(sts));
                info(sts, grp, pw, opt);
                mark_info(my_files[i], opt, &sts);
            }
        } else
            perror("stat");
    }
    (opt->opt_R == 1) ? opt_rec(files, opt) : 0;
}

void mark_info(char *files, opt_t *opt, struct stat *sts)
{
    mode_t m = sts->st_mode;

    if ((m & __S_IFMT) == __S_IFDIR) {
        my_printf(BLUE"%s", files);
        if (opt->opt_p == 1)
            my_printf("%s", NORMAL"/\n");
        else
            my_printf("\n");
        return;
    } else if ((m &S_IXOTH) || (m & S_IXUSR) || (m & S_IXGRP)) {
        my_printf(GREEN"%s", files);
        if (opt->opt_p == 1)
            my_printf("%s", NORMAL"*\n");
        else
            my_printf("\n");
        return;
    }
    my_printf(NORMAL"%s\n", files);
}

void print_size(struct stat *sts, opt_t *opt)
{
    int size_format_blk = sts->st_blocks / 2;
    int size_block = 0;

    if (opt->opt_s == 1) {
        for (; (size_format_blk /= 10) > 0; size_block++);
        for (; size_block < opt->size_block; size_block++, my_printf(" "));
        my_printf(NORMAL"%d ", sts->st_blocks / 2);
    }
}

void aff_group(struct group *grp, opt_t *opt)
{
    if (opt->opt_o == 0)
        my_printf(NORMAL"%s ", grp->gr_name);
}
