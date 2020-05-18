/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** table
*/

#include "proto.h"

char **create_table(char *files)
{
    DIR *directory = open_files(files);
    struct dirent *RDIR;
    int nbr_col = nbr_files(files);
    int size = 0;
    int i = 0;
    char **table = malloc(sizeof(char *) * nbr_col);

    for (int pos = 0; (RDIR = readdir(directory)); pos++) {
            size = size_files(RDIR->d_name) + 1;
            table[pos] = malloc(sizeof(char) * size);
            for (i = 0; RDIR->d_name[i]; i++)
                table[pos][i] = RDIR->d_name[i];
            table[pos][i] = '\0';
    }
    closedir(directory);
    return table;
}

int size_files(char *files)
{
    int size = 0;

    while (files[size])
        size++;
    return size;
}

int nbr_files(char *files)
{
    int nbr = 0;
    DIR *directory = open_files(files);
    struct dirent *RDIR;

    while ((RDIR = readdir(directory)))
        nbr++;
    closedir(directory);
    return nbr;
}
