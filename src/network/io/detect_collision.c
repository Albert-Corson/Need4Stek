/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** detect_collision
*/

#include "n4s.h"

bool detect_collision(void)
{
    api_response_t res;
    res = auto_exec("GET_INFO_LIDAR");
    int index = 0;

    while (index != 32) {
        if (((float *)res.data)[index] == 0)
            return (true);
        index++;
    }
    return (false);
}