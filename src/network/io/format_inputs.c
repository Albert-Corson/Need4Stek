/*
** EPITECH PROJECT, 2019
** AIA_n4s_2018
** File description:
** format_inputs
*/

#include "n4s.h"

static void init_input_data(double *data, bool *initialized)
{
    api_response_t res = api_res_new();

    memset(data, 0, sizeof(double) * 32);
    auto_exec(&res, "GET_CAR_SPEED_MIN");
    data[0] = (*res.data) / 100;
    auto_exec(&res, "GET_CAR_SPEED_MAX");
    data[1] = (*res.data) / 100;
    *initialized = true;
}

double *format_input_data(api_response_t *res)
{
    static bool initialized = false;
    static double data[36];
    int index = 4;

    if (!initialized)
        init_input_data((double *)data, &initialized);
    auto_exec(res, "GET_CURRENT_SPEED");
    data[2] = (*res->data);
    auto_exec(res, "GET_CURRENT_WHEELS");
    data[3] = (*res->data) + 1 / 2;
    auto_exec(res, "GET_INFO_LIDAR");
    while (index < 36) {
        data[index] = res->data[index - 4] / 3010;
        ++index;
    }
    return (data);
}