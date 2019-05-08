/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** node_tor
*/

#include "n4s.h"

void *node_get_value(node_t *node)
{
    return (node->value);
}

void node_set_value(node_t *node, void *value, size_t n)
{
    if (node->value)
        free(node->value);
    if (!value || !(node->value = malloc(n)))
        return;
    memcpy(node->value, value, n);
}

static void *node_destroy(node_t *node)
{
    if (node->value)
        free(node->value);
    free(node);
    return (NULL);
}

static void node_ctor(node_t *node)
{
    node->next = node;
    node->destroy = node_destroy;
}

node_t *node_new(void)
{
    node_t *node = malloc(sizeof(node_t));

    if (!node)
        return (NULL);
    node_ctor(node);
    return ((void *)node);
}