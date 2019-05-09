/*
** EPITECH PROJECT, 2019
** AIA_n4s_2018
** File description:
** str_parse
*/

#include "n4s.h"

int parse_str(char *str, char end, va_list ap)
{
    int ret = get_char_pos(str, end);
    char **ptr = va_arg(ap, char **);
    char *val = NULL;

    if (ret == -1)
        val = strdup(str);
    else
        val = strndup(str, ret);
    *ptr = val;
    return (ret);
}

int parse_long_int(char *str, char end, va_list ap)
{
    long *ptr = va_arg(ap, long *);
    long val = 0;

    str += str_skip_chars(str, "\t ");
    if (str_skip_chars(str, "-+0123456789") > 0 && *str != end && *str)
        val = atol(str);
    else
        return (-1);
    *ptr = val;
    return (get_char_pos(str, end));
}

int parse_float(char *str, char end, va_list ap)
{
    float *ptr = va_arg(ap, float *);
    float val = 0;

    str += str_skip_chars(str, "\t ");
    if (str_skip_chars(str, ".-+0123456789") > 0 && *str != end)
        val = atof(str);
    else
        return (-1);
    *ptr = val;
    return (get_char_pos(str, end));
}

int parse_double(char *str, char end, va_list ap)
{
    double *ptr = va_arg(ap, double *);
    double val = 0;

    str += str_skip_chars(str, "\t ");
    if (str_skip_chars(str, ".-+0123456789") > 0 && *str != end)
        val = strtod(str, NULL);
    else
        return (-1);
    *ptr = val;
    return (get_char_pos(str, end));
}

int str_parse(char *str, char end, data_type_t dt_type, ...)
{
    va_list ap;
    int (*parser[4])(char *, char, va_list) = {parse_float, parse_long_int, \
        parse_str, parse_double};
    int *tmp = NULL;
    int i = 0;

    if (!str || dt_type < 0)
        return (-1);
    va_start(ap, dt_type);
    if (dt_type == DT_NONE) {
        tmp = va_arg(ap, int *);
        i = get_char_pos(str, end);
        *tmp = i;
    } else
        i = parser[dt_type - 1](str, end, ap);
    va_end(ap);
    return (i == -1 ? -1 : i + 1);
}