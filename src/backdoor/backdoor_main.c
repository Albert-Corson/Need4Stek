/*
** EPITECH PROJECT, 2019
** AIA_n4s_2018_tmp
** File description:
** main
*/

#include "n4s.h"

void set_movement(api_response_t *res);

int bckdoor_main(void)
{
    api_response_t res = api_res_new();

    if (!auto_exec(&res, "START_SIMULATION"))
        return (84);
    auto_exec(&res, "CAR_FORWARD", 0.25);
    while (res.status && res.opt_type != OPT_TRACK)
        set_movement(&res);
    auto_exec(&res, "STOP_SIMULATION");
    return (0);
}