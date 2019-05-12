/*
** EPITECH PROJECT, 2019
** AIA_n4s_2018
** File description:
** selection
*/

#include "train.h"

void sortswap(network_t **base, int index, __compar_fn_t compar)
{
    void *tmp = NULL;

    if (compar(base[index], base[index + 1])) {
        tmp = base[index];
        base[index] = base[index + 1];
        base[index + 1] = tmp;
    }
}

void sort(network_t **base, size_t size, __compar_fn_t compar)
{
    size_t x = 0;
    size_t y = 0;

    for (x = 0; x < size - 1; x++) {
        for (y = 0; y < size - 1 - x; y++) {
            sortswap(base, y, compar);
        }
    }
}

int compar(const void *n1, const void *n2)
{
    return (((network_t *)n2)->rank > ((network_t *)n1)->rank);
}

network_t **keep_elite(network_t **sample, int size)
{
    double threshold = fmax(1.2, get_sample_average(sample) * 0.9);
    bool lucky = false;
    int max = fmax(2, floor(0.25 * size));
    int index = 0;

    sort(sample, size, compar);
    while (index < size) {
        lucky = (clang(0, 1) < 0.1);
        if ((sample[index]->rank < threshold || index > max) && !lucky) {
            network_destroy(sample[index]);
            sample[index] = NULL;
        }
        ++index;
    }
    return (sample);
}
