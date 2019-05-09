/*
** EPITECH PROJECT, 2019
** AIA_n4s_2018
** File description:
** handle_outputs
*/

#include "n4s.h"

void handle_output_data(double *data, api_response_t *res)
{
    double car_speed = data[0];
    double wheels_dir = data[1] * 2 - 1;

    auto_exec(res, "CAR_FORWARD", car_speed);
    auto_exec(res, "WHEELS_DIR", wheels_dir);
}