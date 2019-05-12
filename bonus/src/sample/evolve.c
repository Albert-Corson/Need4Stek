/*
** EPITECH PROJECT, 2019
** AIA_n4s_2018
** File description:
** evolve
*/

#include "train.h"
#include <sys/stat.h>

network_t **evolve_sample(network_t **sample, int size, int generations)
{
    int generation = 0;
    char dest_dir[128] = {0};

    while (generation < generations) {
        dprintf(2, "\e[31m\e[1mGENERATION %d\e[0m\e[39m\n\n", generation);
        sample = evaluate_sample(sample);
        show_scoreboard(sample);
        sample = keep_elite(sample, size);
        sample = breed_sample(sample, size);
        sprintf(dest_dir, "bonus/saves/%d", generation);
        mkdir(dest_dir, 0777);
        save_sample(sample, size, dest_dir);
        ++generation;
    }
    return (sample);
}