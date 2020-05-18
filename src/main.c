/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** main
*/

#include "proto.h"

int main(int argc, char **argv)
{
    opt_t *opt = malloc(sizeof(opt_t));
    int nbr_opt = nbr_dir(argc, argv, opt);

    if (argc == (nbr_opt + 1)) {
        zero_path(opt);
    } else if (argc == (nbr_opt + 2)) {
        one_path(opt, argv);
    } else
        many_path(opt, argc, argv);
    return 0;
}

void zero_path(opt_t *opt)
{
    if (opt->opt_d == 0) {
        if (opt->opt_R == 1) {
            my_printf(BLUE".");
            my_printf(NORMAL"%s", ":\n");
        }
        my_ls(".", opt);
    } else
        print_d(".", opt);
}

void one_path(opt_t *opt, char **argv)
{
    int pos = 1;

    for (; argv[pos][0] == '-'; pos++);
    if (opt->opt_d == 0) {
        if (opt->opt_R == 1) {
            my_printf(BLUE"%s", argv[pos]);
            my_printf(NORMAL"%s", ":\n");
        }
        my_ls(argv[pos], opt);
    } else
        print_d(argv[pos], opt);
}

void many_path(opt_t *opt, int argc, char **argv)
{
    int pos = 1;

    while (pos != argc) {
        for (; argv[pos][0] == '-'; pos++);
        if (opt->opt_d == 0) {
            my_printf("%s:\n", argv[pos]);
            my_ls(argv[pos], opt);
            if (pos + 1 != argc)
                my_printf("\n");
        } else
            print_d(argv[pos], opt);
        pos++;
    }
}
