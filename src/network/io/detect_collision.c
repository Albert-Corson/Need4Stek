/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** detect_collision
*/

#include "n4s.h"

bool detect_collision(api_response_t *res)
{
    int index = 0;

    auto_exec(res, "GET_INFO_LIDAR");
    while (index != 32) {
        if (res->data[index] == 0)
            return (true);
        index++;
    }
    return (false);
}