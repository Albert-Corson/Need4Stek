/*
** EPITECH PROJECT, 2019
** AIA_n4s_2018
** File description:
** main
*/

#include "train.h"

int main(void)
{
    network_t **sample = restore_sample(40, "bonus/saves");

    evolve_sample(sample, 40, 50);
    destroy_sample(sample);
}