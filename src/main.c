/*
** EPITECH PROJECT, 2019
** AIA_n4s_2018_tmp
** File description:
** main
*/

#include "n4s.h"

int main(void)
{
    dprintf(2, "%s\n", exec_cmd(va_no_arg, "START_SIMULATION"));
    dprintf(2, "%s\n", exec_cmd(va_float, "CAR_FORWARD", 0.5));
    dprintf(2, "%s\n", exec_cmd(va_int, "CYCLE_WAIT", 100));
    dprintf(2, "%s\n", exec_cmd(va_no_arg, "STOP_SIMULATION"));
    return (0);
}