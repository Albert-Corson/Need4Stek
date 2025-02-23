/*
** EPITECH PROJECT, 2019
** AIA_n4s_2018
** File description:
** api_res_parse_data
*/

#include "n4s.h"

int api_res_data_get_float_32(api_response_t *res, char *str)
{
    int tmp = 0;
    int i = 0;
    int n = 0;

    while (n < 32) {
        tmp = str_parse(str, ':', DT_FLOAT, &(res->data[n]));
        if (i < 0)
            return (-1);
        i += tmp;
        str += tmp;
        ++n;
    }
    res->data_type = RES_FLOAT_32;
    return (i);
}

int api_res_data_get_float_1(api_response_t *res, char *str)
{
    int ret = 0;

    memset(res->data, 0, sizeof(double) * 32);
    ret = str_parse(str, ':', DT_FLOAT, &(res->data[0]));
    res->data_type = RES_FLOAT_1;
    return (ret);
}

int api_res_data_get_long_2(api_response_t *res, char *str)
{
    int ret = *str == '[';
    int tmp = 0;

    if (!ret)
        return (-1);
    memset(res->data, 0, sizeof(double) * 32);
    tmp = str_parse(str + ret, 's', DT_FLOAT, &(res->data[0]));
    if (tmp == -1 || str[ret + tmp] != ',')
        return (-1);
    ret += tmp + 1;
    tmp = str_parse(str + ret, 'n', DT_FLOAT, &(res->data[1]));
    if (tmp == -1 || strncmp(str + ret + tmp, "s]:", 3) != 0)
        return (-1);
    res->data_type = RES_LONG_2;
    return (ret + tmp + 3);
}

int api_res_parse_data(api_response_t *res, char *str, int res_type)
{
    int (*data_get[3])(api_response_t *, char *) = {api_res_data_get_float_32, \
        api_res_data_get_float_1, api_res_data_get_long_2};

    if (res_type < 0 || !res || !str || !*str)
        return (-1);
    else if (res_type == RES_NONE)
        return (0);
    return (data_get[res_type - 1](res, str));
}