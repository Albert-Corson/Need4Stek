/*
** EPITECH PROJECT, 2019
** AIA_n4s_2018_tmp
** File description:
** send_cmd
*/

#include "n4s.h"

api_response_t api_res_parse_res(char *str, int res_type);

api_response_t exec_cmd(int arg_type, int res_type, char *cmd, ...)
{
    api_response_t ret;
    size_t n = 0;
    char *res = NULL;
    va_list ap;

    dprintf(1, "%s", cmd);
    va_start(ap, cmd);
    if (arg_type == VA_FLOAT)
        dprintf(1, ":%f", va_arg(ap, double));
    else if (arg_type == VA_INT)
        dprintf(1, ":%d", va_arg(ap, int));
    dprintf(1, "\n");
    va_end(ap);
    if (getline(&res, &n, stdin) < 0)
        res = NULL;
    ret = api_res_parse_res(res, res_type);
    free(res);
    return (ret);
}

api_response_t auto_exec(char *str, ...)
{
    int i = 0;
    char *cmds[] = {"START_SIMULATION", "STOP_SIMULATION", "CAR_FORWARD", \
    "CAR_BACKWARDS", "WHEELS_DIR", "GET_INFO_LIDAR", "GET_CURRENT_SPEED", \
    "GET_CURRENT_WHEELS", "CYCLE_WAIT", "GET_CAR_SPEED_MAX", \
    "GET_CAR_SPEED_MIN", "GET_INFO_SIMTIME", NULL};
    int res_tp[] = {0, 0, 0, 0, 0, 1, 2, 2, 0, 2, 2, 4};
    int arg_tp[] = {0, 0, 1, 1, 1, 0, 0, 0, 2, 0, 0, 0};
    api_response_t ret;
    va_list ap;

    va_start(ap, str);
    while (i >= 0 && cmds[i]) {
        if (strcmp(cmds[i], str) == 0) {
            ret = exec_cmd(arg_tp[i], res_tp[i], cmds[i], va_arg(ap, void *));
            i = -1;
        }
        ++i;
    }
    va_end(ap);
    return (ret);
}