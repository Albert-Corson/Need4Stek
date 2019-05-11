/*
** EPITECH PROJECT, 2019
** AIA_n4s_2018
** File description:
** train
*/

#ifndef TRAIN_H_
#define TRAIN_H_

#include "n4s.h"

void save_sample(network_t **sample, int size, char *dest_folder);
network_t **restore_sample(int size, char *src_folder);
void play_simulation(network_t *net);

#endif /* !TRAIN_H_ */