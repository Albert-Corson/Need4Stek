/*
** EPITECH PROJECT, 2019
** AIA_n4s_2018
** File description:
** format_inputs
*/

#include "n4s.h"

static void init_input_data(double *data, bool *initialized)
{
    api_response_t res;

    memset(data, 0, sizeof(double) * 32);
    res = auto_exec("GET_CAR_SPEED_MIN");
    data[0] = (*(float *)res.data) / 100;
    res = auto_exec("GET_CAR_SPEED_MAX");
    data[1] = (*(float *)res.data) / 100;
    *initialized = true;
}

double *format_input_data(void)
{
    static bool initialized = false;
    static double data[36];
    api_response_t res;
    int index = 4;

    if (!initialized)
        init_input_data((double *)data, &initialized);
    res = auto_exec("GET_CURRENT_SPEED");
    data[2] = *(float *)res.data;
    res = auto_exec("GET_CURRENT_WHEELS");
    data[3] = (*(float *)res.data + 1) / 2;
    res = auto_exec("GET_INFO_LIDAR");
    while (index < 36) {
        data[index] = (((float *)res.data)[index - 4]) / 3010;
        ++index;
    }
    return (data);
}