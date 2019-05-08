/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** list_met
*/

#include "n4s.h"

node_t *list_append(node_t **begin, node_t *node)
{
    node_t *tmp = *begin;

    if (!begin || !node)
        return (NULL);
    if (*begin == NULL) {
        *begin = node;
        node->next = node;
    } else {
        while (tmp->next != *begin)
            tmp = (node_t *)tmp->next;
        tmp->next = node;
        node->next = *begin;
    }
    return (node);
}

void *list_destroy(node_t **begin)
{
    if (!begin || !*begin)
        return (NULL);
    while (*begin)
        list_pop(begin, *begin);
    *begin = NULL;
    return (NULL);
}

int list_poll(node_t *begin, node_t **buffer)
{
    if (!begin || !buffer)
        return (0);
    if (!*buffer)
        *buffer = begin;
    else if ((*buffer)->next != begin)
        *buffer = (*buffer)->next;
    else
        return (0);
    return (1);
}

void list_pop(node_t **begin, node_t *node)
{
    node_t *tmp = NULL;

    if (!*begin || !node)
        return;
    if (node == node->next) {
        *begin = NULL;
    } else {
        if (node == *begin)
            *begin = node->next;
        tmp = *begin;
        while (tmp->next != node && tmp->next != *begin)
            tmp = (node_t *)tmp->next;
        tmp->next = node->next;
    }
    node->destroy(node);
}