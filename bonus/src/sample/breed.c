/*
** EPITECH PROJECT, 2019
** AIA_n4s_2018
** File description:
** breed
*/

#include "train.h"

network_t *find_random_parent(network_t **sample, int size)
{
    int index = clang(0, size - 1);
    int loop = 0;

    while (index < size) {
        if (sample[index] && sample[index]->rank != -1) {
            ++index;
            return (sample[index - 1]);
        }
        ++index;
        if (index == size && !loop) {
            loop = 1;
            index = 0;
        }
    }
    return (NULL);
}

network_t **breed_sample(network_t **sample, int size)
{
    network_t *mother = find_random_parent(sample, size);
    network_t *father = find_random_parent(sample, size);
    int index = 0;

    while (index < size && mother && father) {
        if (sample[index] == NULL) {
            sample[index] = breed(mother, father);
            mother = find_random_parent(sample, size);
            father = find_random_parent(sample, size);
        }
        ++index;
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