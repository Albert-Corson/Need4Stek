/*
** EPITECH PROJECT, 2019
** AIA_n4s_2018
** File description:
** api_res_parse_opt
*/

#include "n4s.h"

void api_res_parse_opt_data(api_response_t *res, char *str)
{
    int tmp = 0;

    str += str_skip_chars(str, "\t [");
    tmp = str_parse(str, ']', DT_LONG, &(res->cp_id));
    if (tmp < 0 || str[tmp] != '[')
        return;
    str += tmp + 1;
    tmp = str_parse(str, 's', DT_LONG, &(res->timestamp[0]));
    if (tmp < 0 || str[tmp] != ' ')
        return;
    str += tmp;
    tmp = str_parse(str, 'n', DT_LONG, &(res->timestamp[1]));
}

void api_res_parse_opt(api_response_t *res, char *str)
{
    char *opts[5] = {"No further info\n", "First CP Cleared:", "CP Cleared:", \
        "Lap Cleared:", "Track Cleared:"};
    int len = 0;
    int i = 0;
    int check = 1;

    if (!str || !res)
        return;
    while (i < 5 && check) {
        len = strlen(opts[i]);
        if (strncmp(str, opts[i], len) == 0)
            check = 0;
        else
            ++i;
    }
    res->opt_type = i;
    if (i != 0)
        api_res_parse_opt_data(res, str + len);
}