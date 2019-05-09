/*
** EPITECH PROJECT, 2019
** AIA_n4s_2018
** File description:
** network
*/

#include "n4s.h"

void *network_destroy(network_t *net)
{
    int index = 0;
    int layers_count = net->hidden_count + 2;

    while (index < layers_count) {
        mx_destroy(net->layers[index]);
        if (index < layers_count - 1) {
            mx_destroy(net->weights[index]);
            mx_destroy(net->biases[index]);
        }
        ++index;
    }
    free(net->layers);
    free(net->weights);
    free(net->biases);
    free(net);
    return (NULL);
}

void network_init(network_t *net)
{
    int index = 0;
    vectori_t sizes = {0, net->inputs_size};
    int layers_count = net->hidden_count + 2;

    net->layers = calloc(layers_count + 1, sizeof(mx_t *));
    net->weights = calloc(layers_count, sizeof(mx_t *));
    net->biases = calloc(layers_count, sizeof(mx_t *));
    while (index < layers_count) {
        sizes.x = sizes.y;
        sizes.y = net->hidden_size;
        sizes.y = (index == layers_count - 1 ? 0 : sizes.y);
        sizes.y = (index == layers_count - 2 ? net->outputs_size : sizes.y);
        net->layers[index] = mx_new(sizes.x, 1);
        if (index < layers_count - 1) {
            net->weights[index] = mx_new(sizes.y, sizes.x);
            net->biases[index] = mx_new(sizes.y, 1);
        }
        ++index;
    }
}

void network_print(network_t *net)
{
    int layers_count = net->hidden_count + 2;
    int index = 0;

    while (index < layers_count) {
        if (index >= 1)
            mx_print(net->biases[index - 1]);
        mx_print(net->layers[index]);
        dprintf(2, "\n");
        if (index < layers_count - 1) {
            mx_print(net->weights[index]);
            dprintf(2, "\n");
        }
        ++index;
    }
}

network_t *network_new(int inputs, int outputs, int hiddens, int hidden_count)
{
    network_t *net = malloc(sizeof(network_t));

    if (!net)
        return (NULL);
    net->rank = -1;
    net->inputs_size = inputs;
    net->hidden_count = hidden_count;
    net->hidden_size = hiddens;
    net->outputs_size = outputs;
    net->layers = NULL;
    net->weights = NULL;
    net->biases = NULL;
    network_init(net);
    return (net);
}