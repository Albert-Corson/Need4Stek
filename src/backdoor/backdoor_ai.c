/*
** EPITECH PROJECT, 2019
** AIA_n4s_2018_tmp
** File description:
** main
*/

#include "n4s.h"

double get_average_dist(double *signals)
{
    int i = 0;
    double average = 0;

    while (i < 32) {
        average += signals[i];
        ++i;
    }
    average /= i;
    return (average);
}

bool is_colliding(double *signals)
{
    bool colliding = false;
    int i = 0;

    while (i < 32 && !colliding) {
        if (signals[i] <= 10.0)
            colliding = true;
        ++i;
    }
    if (signals[0] <= 18.0 || signals[31] <= 18.0)
        colliding = true;
    return (colliding);
}

double avoid_walls(double *signals)
{
    int i = 0;
    double coef = 1;
    double left = 0;
    double right = 0;
    double total = 0;

    while (i < 16) {
        coef = exp((double)(16 - i));
        signals[i] *= coef;
        signals[31 - i] *= coef;
        total += (signals[i] + signals[31 - i]);
        left += signals[i];
        right += signals[31 - i];
        ++i;
    }
    total = (left - right) / total;
    total = total > (double)1.0 ? (double)1.0 : total; 
    total = total < (double)-1.0 ? (double)-1.0 : total; 
    if (total == NAN)
        total = 0.0;
    return (total);
}

bool avoid_collision(api_response_t *res)
{
    bool avoid = is_colliding(res->data);
    double dir_check = 0;

    if (avoid) {
        dir_check = avoid_walls(res->data);
        auto_exec(res, "WHEELS_DIR", 0.0);
        auto_exec(res, "CAR_FORWARD", 0.0);
        auto_exec(res, "CYCLE_WAIT", 5);
        auto_exec(res, "CAR_BACKWARDS", 0.7);
        auto_exec(res, "CYCLE_WAIT", 8);
        auto_exec(res, "CAR_FORWARD", 0.25);
        if (dir_check >= -0.05 && dir_check <= 0.05)
            auto_exec(res, "WHEELS_DIR", 0.6 * (dir_check < 0.0 ? -1.0 : 1.0));
    }
    return (avoid);
}

void set_movement(api_response_t *res)
{
    double wheels = 0;

    if (!auto_exec(res, "GET_INFO_LIDAR"))
        return;
    if (avoid_collision(res))
        return;
    wheels = avoid_walls(res->data);
    auto_exec(res, "WHEELS_DIR", wheels);
}