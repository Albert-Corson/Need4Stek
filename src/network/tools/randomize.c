/*
** EPITECH PROJECT, 2019
** AIA_n4s_2018
** File description:
** randomize
*/

#include "n4s.h"

void network_randomize(network_t *net)
{
    int layers_count = net->hidden_count + 2;
    int index = 0;

    while (index < layers_count) {
        mx_apply(net->layers[index], randomize);
        if (index < layers_count - 1) {
            mx_apply(net->weights[index], randomize);
            mx_apply(net->biases[index], randomize);
        }
        ++index;
    }
}

double randomize(double x)
{
    x = x;
    return ((double)(rand() % 10000) / (10000 + 0.1));
}