/*
** EPITECH PROJECT, 2019
** AIA_n4s_2018
** File description:
** sigmoid
*/

#include <math.h>

double sigmoid(double x)
{
    return (1 / (1 + exp(-x)));
}

double sigmoid_deriv(double x)
{
    return (exp(-x) / pow(1 + exp(-x), 2));
}