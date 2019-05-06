/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** node_tor
*/

#include "n4s.h"

void *node_get_value(void *node)
{
    node_t *st_node = node;

    return (st_node->value);
}

void node_set_value(void *node, void *value, size_t n)
{
    node_t *st_node = node;

    if (st_node->value)
        free(st_node->value);
    if (!value || !(st_node->value = malloc(n)))
        return;
    memcpy(st_node->value, value, n);
}

void node_destroy(void *node)
{
    node_t *st_node = node;

    if (st_node->label) {
        free(st_node->label);
        st_node->label = NULL;
    }
    if (st_node->value)
        free(st_node->value);
    free(node);
}

void node_ctor(void *node, char const *label)
{
    node_t *st_node = (node_t *)node;

    if (!st_node)
        return;
    st_node->label = (label ? strdup(label) : NULL);
    st_node->next = st_node;
    st_node->destroy = node_destroy;
    st_node->set = node_set_value;
    st_node->get = node_get_value;
}

void *node_new(char const *label)
{
    node_t *st_node = malloc(sizeof(node_t));

    if (!st_node)
        return (NULL);
    node_ctor(st_node, label);
    return ((void *)st_node);
}