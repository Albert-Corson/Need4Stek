/*
** EPITECH PROJECT, 2019
** AIA_n4s_2018
** File description:
** mx_parse
*/

#include "n4s.h"

static int parse_mx_line(mx_t *mx, char *line, int y)
{
    int x = 0;
    int tmp = 0;

    if (!line || !mx)
        return (0);
    while (*line != '\n' && x < mx->size.x) {
        tmp = str_parse(line, '\t', DT_DOUBLE, &(mx->arr[y][x]));
        if (tmp == -1)
            return (0);
        line += tmp;
        ++x;
    }
    return (1);
}

static int parse_mx(mx_t *mx, FILE *file, char **save)
{
    int y = 0;
    size_t n = 0;

    while (!y || **save != '\n') {
        free(*save);
        *save = NULL;
        getline(save, &n, file);
        if (**save != 10 && (y >= mx->size.y || !parse_mx_line(mx, *save, y)))
            return (0);
        ++y;
    }
    return (1);
}

int parse_matrices(mx_t **matrices, FILE *file, char **save)
{
    int i = 0;

    while (matrices[i] && (!i || **save == '\n')) {
        if (!parse_mx(matrices[i], file, save))
            return (0);
        ++i;
    }
    return (1);
}