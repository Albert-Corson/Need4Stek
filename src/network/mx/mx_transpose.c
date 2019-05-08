/*
** EPITECH PROJECT, 2019
** AIA_n4s_2018
** File description:
** mx_transpose
*/

#include "n4s.h"

mx_t *mx_transpose(mx_t *a)
{
    vectori_t size = a->size;
    mx_t *res = mx_new(size.y, size.x);
    int x = 0;
    int y = 0;

    while (y < size.x) {
        x = 0;
        while (x < size.y) {
            res->arr[y][x] = a->arr[x][y];
            ++x;
        }
        ++y;
    }
    return (res);
}