/*
** EPITECH PROJECT, 2019
** AIA_n4s_2018_tmp
** File description:
** backdoor_ai
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
    average /= (double)i;
    return (average);
}

bool is_colliding(double *signals)
{
    bool colliding = false;
    int i = 0;

    while (i < 32 && !colliding) {
        if (signals[i] <= 15.0)
            colliding = true;
        ++i;
    }
    if (signals[0] <= 27.5 || signals[31] <= 27.5)
        colliding = true;
    return (colliding);
}

bool avoid_collision(api_response_t *res, double turn, double speed)
{
    bool avoid = is_colliding(res->data);

    if (avoid) {
        auto_exec(res, CAR_FORWARD, 0.0);
        auto_exec(res, CYCLE_WAIT, 6);
        auto_exec(res, WHEELS_DIR, turn / 1.1);
        auto_exec(res, CAR_BACKWARDS, 0.85);
        auto_exec(res, CYCLE_WAIT, 15);
        auto_exec(res, WHEELS_DIR, -turn / 3.0);
        auto_exec(res, CAR_FORWARD, speed);
    }
    return (avoid);
}

double get_longer_dist_index(double *signals)
{
    double ret = 0;
    int i = 0;

    while (i < 32) {
        if (signals[i] > signals[(int)ret])
            ret = i;
        ++i;
    }
    return (ret);
}

vectorf_t get_average_side_dist(double *signals)
{
    int i = 0;
    double total = 0;
    vectorf_t sides = {0.0, 0.0};

    while (i < 16) {
        sides.x += signals[i];
        sides.y += signals[31 - i];
        ++i;
    }
    total = sides.x + sides.y;
    sides.x /= total;
    sides.y /= total;
    sides.y *= -1;
    return (sides);
}