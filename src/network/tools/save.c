/*
** EPITECH PROJECT, 2019
** AIA_n4s_2018
** File description:
** network_save
*/

#include "n4s.h"

void mx_fprint(FILE *output, mx_t *mx)
{
    vectori_t size = mx->size;
    int x = 0;
    int y = 0;

    while (y < size.y) {
        x = 0;
        while (x < size.x) {
            fprintf(output, "%f\t", mx->arr[y][x]);
            ++x;
        }
        fprintf(output, "\n");
        ++y;
    }
}

void network_fprint_matirces(FILE *output, mx_t **matrices, char *comment)
{
    int i = 0;

    if (!matrices)
        return;
    fprintf(output, "%s\n", comment);
    while (matrices[i]) {
        mx_fprint(output, matrices[i]);
        fprintf(output, "\n");
        ++i;
    }
}

void network_save(network_t *net, char *filename)
{
    FILE *file = filename ? fopen(filename, "w") : stderr;

    if (!file || !net) {
        dprintf(2, "Error while saving Neural Network's datas\n");
        return;
    }
    fprintf(file, "%d:%d", net->inputs_size, net->outputs_size);
    fprintf(file, ":%d:%d\n\n", net->hidden_size, net->hidden_count);
    network_fprint_matirces(file, net->layers, "## LAYERS:");
    network_fprint_matirces(file, net->weights, "## WEIGHTS:");
    network_fprint_matirces(file, net->biases, "## BIASES:");
    if (file != stderr)
        fclose(file);
}