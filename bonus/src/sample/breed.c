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
    double average = get_sample_average(sample);
    double mutation = 0;
    int index = 0;

    while (index < size) {
        if (!mother && !father && !sample[index]) {
            sample[index] = network_new(36, 2, 20, 2);
            network_randomize(sample[index]);
        } else if (sample[index] == NULL) {
            mutation = (mother && father ? 0.25 : 0.50);
            mutation /= average;
            sample[index] = breed(mother, father, mutation);
            mother = find_random_parent(sample, size);
            father = find_random_parent(sample, size);
        }
        ++index;
    }
    return (sample);
}

double inherit(double x, double y, double threshold)
{
    double mutation = clang(0, 1);
    double output = 0;

    if (round(clang(0, 1)) == 1)
        output = x;
    else
        output = y;
    if (mutation < threshold)
        output = randomize(0);
    return (output);
}

mx_t *breed_mx(mx_t *mx, mx_t *m, mx_t *f, double mutation)
{
    int x = 0;
    int y = 0;

    while (y < mx->size.y) {
        x = 0;
        while (x < mx->size.x) {
            mx->arr[y][x] = inherit(m->arr[y][x], f->arr[y][x], mutation);
            ++x;
        }
        ++y;
    }
    return (mx);
}

network_t *breed(network_t *m, network_t *f, double mutation)
{
    int inputs = m->inputs_size;
    int outputs = m->outputs_size;
    int hiddens = m->hidden_size;
    int hidden_count = m->hidden_count;
    network_t *c = network_new(inputs, outputs, hiddens, hidden_count);
    int layers_count = c->hidden_count + 2;
    int x = 0;

    while (x < layers_count) {
        breed_mx(c->layers[x], m->layers[x], f->layers[x], mutation);
        if (x < layers_count - 1) {
            breed_mx(c->biases[x], m->biases[x], f->biases[x], mutation);
            breed_mx(c->weights[x], m->weights[x], f->weights[x], mutation);
        }
        ++x;
    }
    return (c);
}