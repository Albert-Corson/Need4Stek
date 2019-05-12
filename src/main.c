/*
** EPITECH PROJECT, 2019
** AIA_n4s_2018_tmp
** File description:
** main
*/

#include "n4s.h"
#include <unistd.h>

bool set_movement(api_response_t *res, double speed);

double get_forward_speed(api_response_t *res);

int main(void)
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