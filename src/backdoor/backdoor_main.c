/*
** EPITECH PROJECT, 2019
** AIA_n4s_2018_tmp
** File description:
** main
*/

#include "n4s.h"

bool set_movement(api_response_t *res, double speed);

double get_forward_speed(api_response_t *res)
{
    double max = 0.0;
    double speed = 0.0;
    double wished = 35.0;

    auto_exec(res, GET_CAR_SPEED_MAX);
    max = *res->data;
    speed = wished / max;
    if (speed >= 1.00)
        return (0.95);
    return (speed);
}

int bck_main(void)
{
    api_response_t res = api_res_new();
    bool running = true;
    double speed = 0.0;

    if (!auto_exec(&res, START_SIMULATION))
        return (84);
    speed = get_forward_speed(&res);
    auto_exec(&res, CAR_FORWARD, speed);
    while (running && res.status && res.opt_type != OPT_TRACK)
        running = set_movement(&res, speed);
    auto_exec(&res, STOP_SIMULATION);
    return (0);
}