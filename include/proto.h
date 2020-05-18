/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** proto
*/

#ifndef PROTO_H_
#define PROTO_H_

#include "unistd.h"
#include "sys/stat.h"
#include "stdlib.h"
#include "stdio.h"
#include "fcntl.h"
#include "dirent.h"
#include "sys/types.h"
#include "sys/stat.h"
#include "pwd.h"
#include "grp.h"
#include "time.h"
#include "fcntl.h"

#define BLUE "\033[1;34m"
#define GREEN "\033[1;32m"
#define NORMAL "\033[0;39m"

typedef struct opt
{
    int size_octet;
    int size_block;
    int size_name;
    int size_grp;
    int size_link;
    int opt_l;
    int opt_R;
    int opt_d;
    int opt_r;
    int opt_t;
    int opt_a;
    int opt_o;
    int opt_p;
    int opt_s;
} opt_t;


void my_printf(char *format, ...);
int my_strlen(char *str);
char **my_swap(char **table, int pos1, int pos2);
char *my_strcat(char *str1, char *str2);
char **my_alpha_order(char **my_files, int size);
int my_strcmp(char *str1, char *str2);
char *my_strcpy(char *str);

int main(int argc, char *argv[]);
void zero_path(opt_t *opt);
void one_path(opt_t *opt, char **argv);
void many_path(opt_t *opt, int argc, char **argv);
int nbr_dir(int argc, char **argv, opt_t *opt);
void opt(char **argv, int pos, opt_t *opt);
int check_opt2(char c);
void print_d(char *files, opt_t *opt);
void calc_format_d(opt_t *opt, char *files);
int size_max_str(char *str, int size);
int size_max_int(int octet, int size);
void total(char *rep);
void calc_format(opt_t *opt, int size, char **my_files, char *files);
char *perm(struct stat sts);
char files_type(mode_t perm);
void info(struct stat sts, struct group *grp, struct passwd *pw, opt_t *opt);
void mark_info(char *files, opt_t *opt, struct stat *sts);
void aff_group(struct group *grp, opt_t *opt);
char *time_m(struct stat sts);
void check_opt(char *line, opt_t *opt);
DIR *open_files(char *my_dir);
char **create_table(char *files);
char **sort_by_time(char **my_files, int size, char *files);
char **my_reverse_order(char **my_files, int size);
int nbr_files(char *files);
int size_files(char *files);
void my_ls(char *files, opt_t *opt);
void print_l(char **my_files, char *files, int size, opt_t *opt);
void print_size(struct stat *sts, opt_t *opt);
void opt_rec(char *files, opt_t *opt);
int check_rec(char *str);
int visible(char *files, opt_t *opt);
#endif /* !PROTO_H_ */
