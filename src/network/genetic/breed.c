/*
** EPITECH PROJECT, 2019
** AIA_n4s_2018
** File description:
** breed
*/

#include "n4s.h"

network_t *find_next_parent(network_t **sample, int *index)
{
    while (sample[*index]) {
        if (sample[*index] && sample[*index]->rank != -1) {
            ++*index;
            return (sample[*index]);
        }
        ++*index;
    }
    return (NULL);
}

network_t **breed_sample(network_t **sample, int size)
{
    int x = 0;
    int y = 0;
    int desired_children = ((1 - 0.25) * size) / ((0.25) * size);
    int children_count = 0;
    network_t *mother = find_next_parent(sample, &y);
    network_t *father = find_next_parent(sample, &y);
    network_t *first = mother;

    while (y < size && mother && father) {
        children_count = 0;
        for (x = 0; x < size && children_count < desired_children; ++x) {
            children_count += (sample[x] == NULL);
            sample[x] = (!sample[x] ? breed(mother, father) : sample[x]);
        }
        mother = father;
        if (!(father = find_next_parent(sample, &y)) && first) {
            father = first;
            first = NULL;
        }
    }
    return (sample);
}

double inherit(double x, double y)
{
    double mutation = clang(0, 1);
    double output = 0;

    if (round(clang(0, 1)) == 1)
        output = x;
    else
        output = y;
    if (mutation < 0.05)
        output *= clang(0, 1);
    return (output);
}

mx_t *breed_mx(mx_t *mx, mx_t *mother, mx_t *father)
{
    int x = 0;
    int y = 0;

    while (y < mx->size.y) {
        x = 0;
        while (x < mx->size.x) {
            mx->arr[y][x] = inherit(mother->arr[y][x], father->arr[y][x]);
            ++x;
        }
        ++y;
    }
    return (mx);
}

network_t *breed(network_t *mother, network_t *father)
{
    int inputs = mother->inputs_size;
    int outputs = mother->outputs_size;
    int hiddens = mother->hidden_size;
    int hidden_count = mother->hidden_count;
    network_t *child = network_new(inputs, outputs, hiddens, hidden_count);
    int layers_count = child->hidden_count + 2;
    int x = 0;

    while (x < layers_count) {
        breed_mx(child->layers[x], mother->layers[x], father->layers[x]);
        if (x < layers_count - 1) {
            breed_mx(child->biases[x], mother->biases[x], father->biases[x]);
            breed_mx(child->weights[x], mother->weights[x], father->weights[x]);
        }
        ++x;
    }
    return (child);
}