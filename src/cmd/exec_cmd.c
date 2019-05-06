/*
** EPITECH PROJECT, 2019
** AIA_n4s_2018_tmp
** File description:
** send_cmd
*/

#include "n4s.h"

char *exec_cmd(int arg_type, char *cmd, ...)
{
    size_t n = 0;
    char *res = NULL;
    va_list ap;

    dprintf(1, "%s", cmd);
    va_start(ap, cmd);
    if (arg_type == va_float)
        dprintf(1, ":%f", va_arg(ap, double));
    else if (arg_type == va_int)
        dprintf(1, ":%d", va_arg(ap, int));
    dprintf(1, "\n");
    va_end(ap);
    if (getline(&res, &n, stdin) < 0)
        return (NULL);
    return (res);
}