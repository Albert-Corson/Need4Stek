/*
** EPITECH PROJECT, 2019
** AIA_n4s_2018
** File description:
** handle_outputs
*/

#include "n4s.h"

void handle_output_data(double *data)
{
    double car_speed = data[0];
    double wheels_dir = data[1] * 2 - 1;

    dprintf(2, "CAR_SPEED:\t%.2f\n", car_speed);
    dprintf(2, "WHEELS_DIR:\t%.2f\n\n", wheels_dir);
    auto_exec("CAR_FORWARD", car_speed);
    auto_exec("WHEELS_DIR", wheels_dir);
}