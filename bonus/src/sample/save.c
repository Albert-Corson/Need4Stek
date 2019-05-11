/*
** EPITECH PROJECT, 2019
** AIA_n4s_2018
** File description:
** save
*/

#include "train.h"

void save_sample(network_t **sample, int size, char *dest_folder)
{
    int index = 0;
    char dest_file[128];

    if (dest_folder[strlen(dest_folder) - 1] == '/')
        dest_folder[strlen(dest_folder) - 1] = 0;
    while (index < size) {
        sprintf(dest_file, "%s/.%d", dest_folder, index);
        network_save(sample[index], dest_file);
        ++index;
    }
}