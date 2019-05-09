/*
** EPITECH PROJECT, 2019
** AIA_n4s_2018
** File description:
** network_restore
*/

#include "n4s.h"

int parse_matrices(mx_t **matrices, FILE *file, char **save);

int network_restore_matrice(network_t *net, FILE *file, char **str)
{
    int i = 0;
    char *data_type[3] = {"## LAYERS:\n", "## WEIGHTS:\n", "## BIASES:\n"};
    mx_t **to_fill[3] = {net->layers, net->weights, net->biases};

    while (i < 3) {
        if (strcmp(data_type[i], *str) == 0)
            return (parse_matrices(to_fill[i], file, str));
        ++i;
    }
    return (0);
}

int network_restore_data(network_t *net, FILE *file)
{
    char *str = NULL;
    size_t n = 0;
    int check = 1;

    if (getline(&str, &n, file) < 0)
        check = -1;
    while (check > 0 && str) {
        if (!network_restore_matrice(net, file, &str))
            check = getline(&str, &n, file);
    }
    free(str);
    return (1);
}

network_t *network_new_from_savefile(FILE *file)
{
    char *str = NULL;
    size_t n = 0;
    long nsize[4] = {-1, -1, -1, -1};
    int tmp = 0;
    int i = 0;

    getline(&str, &n, file);
    tmp = str_parse(str, ':', DT_LONG, &nsize[0]);
    i += tmp == -1 ? 0 : tmp;
    tmp = str_parse(str + i, ':', DT_LONG, &nsize[1]);
    i += tmp == -1 ? 0 : tmp;
    tmp = str_parse(str + i, ':', DT_LONG, &nsize[2]);
    i += tmp == -1 ? 0 : tmp;
    tmp = str_parse(str + i, '\n', DT_LONG, &nsize[3]);
    free(str);
    if (nsize[0] < 1 || nsize[1] < 1 || nsize[2] < 1 || nsize[3] < 0 || tmp < 0)
        return (NULL);
    return (network_new(nsize[0], nsize[1], nsize[2], nsize[3]));
}

network_t *network_restore(char *savefile)
{
    network_t *ret = NULL;
    FILE *file = savefile ? fopen(savefile, "r") : NULL;

    if (!file) {
        ret = network_new(36, 2, 72, 1);
        network_randomize(ret);
        return (ret);
    }
    ret = network_new_from_savefile(file);
    if (ret && !network_restore_data(ret, file)) {
        network_destroy(ret);
        ret = NULL;
    }
    fclose(file);
    return (ret);
}