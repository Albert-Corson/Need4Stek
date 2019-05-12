/*
** EPITECH PROJECT, 2019
** AIA_n4s_2018_tmp
** File description:
** backdoor_ai
*/

#include "n4s.h"

bool avoid_collision(api_response_t *res, double turn, double speed);

double get_average_dist(double *signals);

vectorf_t get_average_side_dist(double *signals);

double get_longer_dist_index(double *signals);

double get_turn(api_response_t *res, double average, double turn)
{
    vectorf_t sides;
    double div_by = 8.0;
    int i = turn;

    turn /= 32.0;
    turn -= 0.50;
    turn *= -2;
    if (average < 650.0)
        div_by = 5.1;
    else if (res->data[i] >= 1500.0)
        div_by += 2.5;
    sides = get_average_side_dist(res->data);
    turn += ((sides.x + sides.y) * 2.0);
    turn /= div_by;
    if (turn <= -1.0)
        return (-1.0);
    else if (turn >= 1.0)
        return (1.0);
    return (turn);
}

bool set_movement(api_response_t *res, double speed)
{
    double wheels = 0;
    double average = 0;

    if (!auto_exec(res, GET_INFO_LIDAR))
        return (false);
    average = get_average_dist(res->data);
    if (average == 0.0)
        return (false);
    wheels = get_longer_dist_index(res->data);
    wheels = get_turn(res, average, wheels);
    if (avoid_collision(res, -wheels, speed))
        return (true);
    auto_exec(res, WHEELS_DIR, wheels);
    return (res->status);
}