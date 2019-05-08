/*
** EPITECH PROJECT, 2019
** AIA_n4s_2018
** File description:
** mx
*/

#include "n4s.h"

mx_t *mx_new(int width, int height)
{
    mx_t *mx = malloc(sizeof(mx_t));

    if (!mx || width == 0 || height == 0)
        return (NULL);
    mx->size = (vectori_t){width, 0};
    mx->arr = calloc(height, sizeof(double *));
    if (!mx->arr)
        return (mx_destroy(mx));
    while (mx->size.y < height) {
        mx->arr[mx->size.y] = calloc(width, sizeof(double));
        if (!mx->arr[mx->size.y])
            return (mx_destroy(mx));
        ++mx->size.y;
    }
    return (mx);
}

mx_t *mx_apply(mx_t *mx, double (*fn)(double))
{
    vectori_t size = mx->size;
    int x = 0;
    int y = 0;

    while (y < size.y) {
        x = 0;
        while (x < size.x) {
            mx->arr[y][x] = fn(mx->arr[y][x]);
            ++x;
        }
        ++y;
    }
    return (mx);
}

void mx_print(mx_t *mx)
{
    vectori_t size = mx->size;
    int x = 0;
    int y = 0;

    while (y < size.y) {
        x = 0;
        while (x < size.x) {
            printf("%.2f\t", mx->arr[y][x]);
            ++x;
        }
        printf("\n");
        ++y;
    }
}

mx_t *mx_fill_row(mx_t *mx, int row_id, double *data)
{
    int index = 0;

    while (index < mx->size.x) {
        mx->arr[row_id][index] = data[index];
        ++index;
    }
    return (mx);
}

void *mx_destroy(mx_t *mx)
{
    while (mx && mx->arr && mx->size.y > 0) {
        free(mx->arr[(int)mx->size.y - 1]);
        --mx->size.y;
    }
    if (mx && mx->arr)
        free(mx->arr);
    if (mx)
        free(mx);
    return (NULL);
}