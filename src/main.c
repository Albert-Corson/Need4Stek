/*
** EPITECH PROJECT, 2019
** AIA_n4s_2018_tmp
** File description:
** main
*/

#include "n4s.h"

int main(void)
{
    exec_cmd(VA_NO_ARG, RES_NONE, "START_SIMULATION");
    exec_cmd(VA_FLOAT, RES_NONE, "CAR_FORWARD", 0.5);
    exec_cmd(VA_NO_ARG, RES_FLOAT_32, "GET_INFO_LIDAR");
    exec_cmd(VA_INT, RES_FLOAT_1, "CYCLE_WAIT", 100);
    exec_cmd(VA_NO_ARG, RES_NONE, "STOP_SIMULATION");
    return (0);
}