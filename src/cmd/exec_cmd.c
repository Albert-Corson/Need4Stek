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

    printf("%s", cmd);
    va_start(ap, cmd);
    if (arg_type == va_float)
        printf(":%f", va_arg(ap, double));
    else if (arg_type == va_int)
        printf(":%d", va_arg(ap, int));
    printf("\n");
    va_end(ap);
    if (getline(&res, &n, stdin) < 0)
        return (NULL);
    return (res);
}