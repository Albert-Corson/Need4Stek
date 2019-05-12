/*
** EPITECH PROJECT, 2019
** AIA_n4s_2018
** File description:
** main
*/

#include "train.h"

void test(network_t **sample, int size);

int main(void)
{
    network_t **sample = restore_sample(20, "bonus/saves");

    evolve_sample(sample, 20, 500);
    destroy_sample(sample);
}