/*
** EPITECH PROJECT, 2019
** AIA_n4s_2018_tmp
** File description:
** send_cmd
*/

#include "n4s.h"

void api_res_parse_res(api_response_t *ret, char *str, int res_type);

char *exec_cmd(int arg_type, char *cmd, va_list ap)
{
    size_t n = 0;
    char *res = NULL;

    dprintf(1, "%s", cmd);
    if (arg_type == VA_FLOAT)
        dprintf(1, ":%f", va_arg(ap, double));
    else if (arg_type == VA_INT)
        dprintf(1, ":%d", va_arg(ap, int));
    dprintf(1, "\n");
    if (getline(&res, &n, stdin) < 0)
        res = NULL;
    return (res);
}

void auto_exec(api_response_t *res, char *cmd, ...)
{
    int i = 0;
    char *cmds[] = {"START_SIMULATION", "STOP_SIMULATION", "CAR_FORWARD", \
        "CAR_BACKWARDS", "WHEELS_DIR", "GET_INFO_LIDAR", "GET_CURRENT_SPEED", \
        "GET_CURRENT_WHEELS", "CYCLE_WAIT", "GET_CAR_SPEED_MAX", \
        "GET_CAR_SPEED_MIN", "GET_INFO_SIMTIME", NULL};
    int res_tp[] = {0, 0, 0, 0, 0, 1, 2, 2, 0, 2, 2, 4};
    int arg_tp[] = {0, 0, 1, 1, 1, 0, 0, 0, 2, 0, 0, 0};
    char *str = NULL;
    va_list ap;

    va_start(ap, cmd);
    while (i >= 0 && cmds[i]) {
        if (strcmp(cmds[i], cmd) == 0) {
            str = exec_cmd(arg_tp[i], cmds[i], ap);
            api_res_parse_res(res, str, res_tp[i]);
            i = -2;
        }
        ++i;
    }
    va_end(ap);
}