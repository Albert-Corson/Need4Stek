/*
** EPITECH PROJECT, 2019
** AIA_n4s_2018
** File description:
** evolve
*/

#include "n4s.h"

network_t **evolve_sample(network_t **sample, int size, int generations)
{
    int generation = 0;
    api_response_t res = api_res_new();

    while (generation < generations) {
        dprintf(2, "\e[31m\e[1mGENERATION %d\e[0m\e[39m\n\n", generation);
        sample = evaluate_sample(&res, sample);
        sample = keep_elite(sample, size);
        sample = breed_sample(sample, size);
        ++generation;
    }
    return (sample);
}