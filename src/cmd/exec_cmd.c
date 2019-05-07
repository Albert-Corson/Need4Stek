/*
** EPITECH PROJECT, 2019
** AIA_n4s_2018_tmp
** File description:
** send_cmd
*/

#include "n4s.h"

api_response_t api_res_parse_res(char *str, int res_type);

api_response_t exec_cmd(int arg_tp, int res_type, char *cmd, ...)
{
    api_response_t ret;
    size_t n = 0;
    char *res = NULL;
    va_list ap;

    dprintf(1, "%s", cmd);
    va_start(ap, cmd);
    if (arg_tp == VA_FLOAT)
        dprintf(1, ":%f", va_arg(ap, double));
    else if (arg_tp == VA_INT)
        dprintf(1, ":%d", va_arg(ap, int));
    dprintf(1, "\n");
    va_end(ap);
    if (getline(&res, &n, stdin) < 0)
        res = NULL;
    ret = api_res_parse_res(res, res_type);
    free(res);
    return (ret);
}