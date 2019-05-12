/*
** EPITECH PROJECT, 2019
** AIA_n4s_2018_tmp
** File description:
** main
*/

#include "n4s.h"

bool set_movement(api_response_t *res);

int bck_main(void)
{
    api_response_t res = api_res_new();
    bool running = true;

    if (!auto_exec(&res, START_SIMULATION))
        return (84);
    while (running && res.status && res.opt_type != OPT_TRACK)
        running = set_movement(&res);
    auto_exec(&res, STOP_SIMULATION);
    return (0);
}