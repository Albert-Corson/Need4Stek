/*
** EPITECH PROJECT, 2019
** AIA_n4s_2018
** File description:
** parse_res
*/

#include "n4s.h"

void api_res_parse_opt(api_response_t *res, char *str);

int api_res_parse_data(api_response_t *res, char *str, int res_type);

static void api_res_init(api_response_t *res)
{
    res->value_id = -1;
    res->status = false;
    res->data_type = DT_NONE;
    res->data = NULL;
    res->opt_type = OPT_NONE;
    res->cp_id = -1;
    res->timestamp[0] = 0;
    res->timestamp[1] = 0;
}

static int api_res_get_status(api_response_t *res, char *str)
{
    if (!res || !str || !*str)
        return (-1);
    if (strncmp(str, "KO:", 3) == 0) {
        res->status = false;
        return (3);
    } else if (strncmp(str, "OK:", 3) == 0) {
        res->status = true;
        return (3);
    } else {
        res->status = false;
        return (-1);
    }
}

int api_res_get_value_id(api_response_t *res, char *str)
{
    res->value_id = atoi(str);
    return (str_skip_chars(str, "0123456789:"));
}

api_response_t api_res_parse_res(char *str, int res_type)
{
    api_response_t ret;
    int tmp = 0;

    api_res_init(&ret);
    if (res_type < 0 || !str)
        return (ret);
    str += api_res_get_value_id(&ret, str);
    if (api_res_get_status(&ret, str) == -1)
        return (ret);
    str += 3;
    for (; *str && *str != ':'; ++str);
    if (ret.status) {
        tmp = api_res_parse_data(&ret, str + 1, res_type);
        if (tmp == -1)
            return (ret);
        str += tmp;
    }
    api_res_parse_opt(&ret, str + 1);
    return (ret);
}