/*
** EPITECH PROJECT, 2019
** AIA_n4s_2018_tmp
** File description:
** main
*/

#include "n4s.h"
#include <unistd.h>

int main(void)
{
    network_t **sample = create_sample(0, 20, 36, 2);

    evolve_sample(sample, 20, 1);
    destroy_sample(sample);
    return (0);
}