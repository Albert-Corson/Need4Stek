/*
** EPITECH PROJECT, 2019
** AIA_n4s_2018
** File description:
** parse_res
*/

#include "n4s.h"

int api_res_parse_data(api_response_t *res, char *str, int res_type);

static void api_res_init(api_response_t *res)
{
    res->data_type = DT_NONE;
    res->data = NULL;
    res->destroy_data = NULL;
    res->status = false;
    res->value_id = -1;
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

api_response_t api_res_parse_res(char *str, int res_type)
{
    api_response_t ret;
    int tmp = 0;
    int i = 0;

    api_res_init(&ret);
    if (res_type < 0 || !str)
        return (ret);
    ret.value_id = atoi(str);
    for (; (str[i] >= '0' && str[i] <= '9') || str[i] == ':'; ++i);
    tmp = api_res_get_status(&(ret), str + i);
    if (tmp == -1 || ret.status == false)
        return (ret);
    i += tmp;
    for (; str[i] && str[i] != ':'; ++i);
    tmp = api_res_parse_data(&ret, str + i, res_type);
    if (tmp == -1 || ret.status == false)
    i += tmp;
    for (; str[i] && str[i] != ':'; ++i);
    // api_res_parse_opt_info();
    return (ret);
}