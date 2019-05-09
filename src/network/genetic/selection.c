/*
** EPITECH PROJECT, 2019
** AIA_n4s_2018
** File description:
** selection
*/

#include "n4s.h"

int find_replacement_id(network_t **sample, int max, int curr, int *ids)
{
    int index = 0;

    while (index < max) {
        if (ids[index] == -1 || sample[ids[index]]->rank < sample[curr]->rank)
            return (index);
        ++index;
    }
    return (-1);
}

void get_elite_ids(network_t **sample, int max, int *ids)
{
    int x = 0;
    int y = 0;

    memset(ids, -1, sizeof(int) * max);
    while (sample[x]) {
        y = find_replacement_id(sample, max, x, ids);
        if (y != -1)
            ids[y] = x;
        ++x;
    }
}

bool in_array(int *arr, int size, int value)
{
    int index = 0;

    while (index < size) {
        if (arr[index] == value)
            return (true);
        ++index;
    }
    return (false);
}

network_t **keep_elite(network_t **sample, int size)
{
    int max = 0.25 * size;
    int bests[max];
    int index = 0;

    get_elite_ids(sample, max, bests);
    while (index < size) {
        if (!in_array(bests, max, index)) {
            network_destroy(sample[index]);
            sample[index] = NULL;
        }
        ++index;
    }
    return (sample);
}
