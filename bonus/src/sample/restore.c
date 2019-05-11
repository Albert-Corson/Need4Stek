/*
** EPITECH PROJECT, 2019
** AIA_n4s_2018
** File description:
** restore
*/

#include "train.h"

network_t **restore_sample(int size, char *src_folder)
{
    int index = 0;
    char src_file[128];
    network_t **sample = NULL;

    if (size <= 0)
        return (NULL);
    if (src_folder[strlen(src_folder) - 1] == '/')
        src_folder[strlen(src_folder) - 1] = 0;
    sample = calloc(size + 1, sizeof(network_t *));
    while (index < size) {
        sprintf(src_file, "%s/.%d", src_folder, index);
        sample[index] = network_restore(src_file);
        ++index;
    }
    return (sample);
}