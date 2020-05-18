/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** opt_d
*/

#include "proto.h"

void print_d(char *files, opt_t *opt)
{
    struct stat sts;
    struct group *grp;
    struct passwd *pw;

    if (opt->opt_l == 1) {
        calc_format_d(opt, files);
        if (stat(files, &sts) == 0) {
            pw = getpwuid(sts.st_uid);
            grp = getgrgid(sts.st_gid);
                my_printf("%s. ", perm(sts));
                info(sts, grp, pw, opt);
                my_printf("%s/\n", files, sts);
        } else
            perror("stat");
    } else
        my_printf("%s/\n", files, sts);

}

void calc_format_d(opt_t *opt, char *files)
{
    struct stat sts;
    struct group *grp;
    struct passwd *pw;
    opt->size_grp = 0;
    opt->size_name = 0;
    opt->size_octet = 0;
    opt->size_link = 0;

    if (stat(files, &sts) == 0) {
        pw = getpwuid(sts.st_uid);
        grp = getgrgid(sts.st_gid);
        opt->size_grp = size_max_str(pw->pw_name, opt->size_grp);
        opt->size_name = size_max_str(grp->gr_name, opt->size_name);
        opt->size_octet = size_max_int(sts.st_size, opt->size_octet);
        opt->size_link = size_max_int(sts.st_nlink, opt->size_link);
    }
}
