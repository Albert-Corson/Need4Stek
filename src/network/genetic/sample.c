/*
** EPITECH PROJECT, 2019
** AIA_n4s_2018
** File description:
** sample
*/

#include "n4s.h"

network_t **create_sample(long seed, int size, int inputs, int outputs)
{
    network_t **sample = calloc(size + 1, sizeof(network_t *));
    int index = 0;
    int hid_size = 0;
    int hid_count = 0;

    srand(seed);
    while (index < size) {
        hid_size = 20;
        hid_count = 2;
        sample[index] = network_new(inputs, outputs, hid_size, hid_count);
        network_randomize(sample[index]);
        ++index;
    }
    return (sample);
}

void *destroy_sample(network_t **sample)
{
    int index = 0;

    if (!sample)
        return (NULL);
    while (sample[index]) {
        network_destroy(sample[index]);
        ++index;
    }
    free(sample);
    return (NULL);
}