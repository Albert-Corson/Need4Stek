/*
** EPITECH PROJECT, 2019
** AIA_n4s_2018
** File description:
** mx_product
*/

#include "n4s.h"

static double dot_sum(mx_t *a, mx_t *b, int x, int y)
{
    int index = 0;
    double sum = 0;

    while (index < a->size.x) {
        sum += a->arr[y][index] * b->arr[index][x];
        ++index;
    }
    return (sum);
}

mx_t *mx_dot_product(mx_t *a, mx_t *b)
{
    vectori_t size = {b->size.x, a->size.y};
    mx_t *res = NULL;
    int x = 0;
    int y = 0;

    if (a->size.x != b->size.y)
        return (NULL);
    res = mx_new(size.x, size.y);
    while (y < size.y) {
        x = 0;
        while (x < size.x) {
            res->arr[y][x] = dot_sum(a, b, x, y);
            ++x;
        }
        ++y;
    }
    return (res);
}