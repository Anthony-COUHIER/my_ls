/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** opt
*/

#include "proto.h"

void total(char *files)
{
    struct stat sts;
    struct dirent *drt;
    int tot = 0;
    char *cat;
    DIR *directory = opendir(files);

    while ((drt = readdir(directory))) {
        cat = my_strcat(my_strcat(files, "/"), drt->d_name);
        if ((lstat(cat, &sts)) == 0)
            (drt->d_name[0] != '.') ? tot += sts.st_blocks : 0;
    }
    closedir(directory);
    my_printf(NORMAL"total %d\n", tot / 2);
}

char *perm(struct stat sts)
{
    char *mode = malloc(sizeof(char) * 10 + 1);

    mode[0] = files_type(sts.st_mode);
    mode[1] = (sts.st_mode & S_IRUSR) ? 'r' : '-';
    mode[2] = (sts.st_mode & S_IWUSR) ? 'w' : '-';
    mode[3] = (sts.st_mode & S_IXUSR) ? 'x' : '-';
    mode[4] = (sts.st_mode & S_IRGRP) ? 'r' : '-';
    mode[5] = (sts.st_mode & S_IWGRP) ? 'w' : '-';
    mode[6] = ((sts.st_mode & S_IXGRP) && !(sts.st_mode & S_ISGID)) ? 'x' : '-';
    ((sts.st_mode & S_ISGID) && !(sts.st_mode & S_IXGRP)) ? mode[6] = 'S' : 0;
    ((sts.st_mode & S_ISGID) && (sts.st_mode & S_IXGRP)) ? mode[6] = 's': 0;
    mode[7] = (sts.st_mode & S_IROTH) ? 'r' : '-';
    mode[8] = (sts.st_mode & S_IWOTH) ? 'w' : '-';
    mode[9] = (sts.st_mode & S_IXOTH && !(sts.st_mode & __S_ISVTX)) ? 'x' : '-';
    ((sts.st_mode & __S_ISVTX) && !(sts.st_mode & S_IXOTH)) ? mode[9] = 'T' : 0;
    ((sts.st_mode & __S_ISVTX) && (sts.st_mode & S_IXOTH)) ? mode[9] = 't' : 0;
    mode[10] = '\0';
    return mode;
}

char files_type(mode_t perm)
{
    switch (perm & __S_IFMT) {
    case __S_IFDIR:
        return 'd';
    case __S_IFIFO:
        return 'p';
    case __S_IFLNK:
        return 'l';
    case __S_IFSOCK:
        return 's';
    case __S_IFCHR:
        return 'c';
    case __S_IFBLK:
        return 'b';
    default:
        return '-';
    }
}

void info(struct stat sts, struct group *grp, struct passwd *pw, opt_t *opt)
{
    int size_oct = sts.st_size;
    int size_nlink = sts.st_nlink;
    char *time = time_m(sts);
    int size_name = 0;
    int size_grp = 0;
    int size_octet = 0;
    int size_link = 0;

    for (; pw->pw_name[size_name]; size_name++);
    for (; grp->gr_name[size_grp]; size_grp++);
    for (; (size_oct /= 10) > 0; size_octet++);
    for (; (size_nlink /= 10) > 0; size_link++);
    for (; size_link < opt->size_link; size_link++, my_printf(" "));
    my_printf(NORMAL"%d ", sts.st_nlink);
    my_printf(NORMAL"%s ", pw->pw_name);
    for (; size_name < opt->size_name; size_name++, my_printf(" "));
    aff_group(grp, opt);
    for (; size_grp < opt->size_grp; size_grp++, my_printf(" "));
    for (; size_octet < opt->size_octet; size_octet++, my_printf(" "));
    my_printf(NORMAL"%d%s ", sts.st_size, time);
}

char *time_m(struct stat sts)
{
    char *time = ctime(&sts.st_mtime);
    int i = 0;

    time[16] = '\0';
    for (; time[i]; i++)
        time[i] = time[i + 3];
    time[i] = '\0';
    return time;
}
