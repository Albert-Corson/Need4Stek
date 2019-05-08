/*
** EPITECH PROJECT, 2019
** AIA_n4s_2018
** File description:
** mx_add
*/

#include "n4s.h"

mx_t *mx_add_scalar(mx_t *a, double scalar, bool new)
{
    vectori_t size = a->size;
    mx_t *res = NULL;
    int x = 0;
    int y = 0;

    res = (new ? mx_new(size.x, size.y) : a);
    while (y < size.y) {
        x = 0;
        while (x < size.x) {
            res->arr[y][x] = a->arr[y][x] + scalar;
            ++x;
        }
        ++y;
    }
    return (res);
}

mx_t *mx_subtract_scalar(mx_t *a, double scalar, bool new)
{
    vectori_t size = a->size;
    mx_t *res = NULL;
    int x = 0;
    int y = 0;

    res = (new ? mx_new(size.x, size.y) : a);
    while (y < size.y) {
        x = 0;
        while (x < size.x) {
            res->arr[y][x] = a->arr[y][x] - scalar;
            ++x;
        }
        ++y;
    }
    return (res);
}

mx_t *mx_add(mx_t *a, mx_t *b, bool new)
{
    vectori_t size = a->size;
    mx_t *res = NULL;
    int x = 0;
    int y = 0;

    if (a->size.x != b->size.x || a->size.y != b->size.y)
        return (NULL);
    res = (new ? mx_new(size.x, size.y) : a);
    while (y < size.y) {
        x = 0;
        while (x < size.x) {
            res->arr[y][x] = a->arr[y][x] + b->arr[y][x];
            ++x;
        }
        ++y;
    }
    return (res);
}

mx_t *mx_subtract(mx_t *a, mx_t *b, bool new)
{
    vectori_t size = a->size;
    mx_t *res = NULL;
    int x = 0;
    int y = 0;

    if (a->size.x != b->size.x || a->size.y != b->size.y)
        return (NULL);
    res = (new ? mx_new(size.x, size.y) : a);
    while (y < size.y) {
        x = 0;
        while (x < size.x) {
            res->arr[y][x] = a->arr[y][x] - b->arr[y][x];
            ++x;
        }
        ++y;
    }
    return (res);
}