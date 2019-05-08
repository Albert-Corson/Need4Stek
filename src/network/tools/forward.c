/*
** EPITECH PROJECT, 2019
** AIA_n4s_2018
** File description:
** forward
*/

#include "n4s.h"

mx_t *forward_propagation(network_t *net, double *inputs)
{
    mx_t *tmp = mx_new(net->inputs_size, 1);
    mx_t *res = NULL;
    int index = 0;

    mx_fill_row(net->layers[0], 0, inputs);
    for (index = 0; index < net->inputs_size; index++)
        tmp->arr[0][index] = net->layers[0]->arr[0][index];
    index = 0;
    while (index < net->hidden_count + 1) {
        res = mx_dot_product(tmp, net->weights[index]);
        mx_destroy(tmp);
        res = mx_add(res, net->biases[index], false);
        res = mx_apply(res, sigmoid);
        tmp = res;
        ++index;
    }
    mx_fill_row(net->layers[net->hidden_count + 1], 0, res->arr[0]);
    mx_destroy(res);
    return (net->layers[net->hidden_count + 1]);
}