/*
** EPITECH PROJECT, 2019
** AIA_n4s_2018
** File description:
** str_skip_chars
*/

#include "n4s.h"

int str_skip_chars(char *str, char *to_skip)
{
    int i = 0;

    if (!str)
        return (-1);
    while (str[i] && strchr(to_skip, str[i]))
        ++i;
    return (i);
}