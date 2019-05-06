/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** list_met
*/

#include "n4s.h"

void *list_append(void **begin, void *node)
{
    node_t *st_begin = (node_t *)(*begin);
    node_t *st_node = (node_t *)node;
    node_t *tmp = st_begin;

    if (!st_node)
        return (NULL);
    if (*begin == NULL) {
        *begin = node;
        st_node->next = node;
    } else {
        while (tmp->next != st_begin)
            tmp = (node_t *)tmp->next;
        tmp->next = node;
        st_node->next = *begin;
    }
    return (node);
}

void list_destroy(void **begin)
{
    node_t *curr = (node_t *)begin;

    if (!curr)
        return;
    while (*begin)
        list_pop(begin, *begin);
    *begin = NULL;
}

int list_poll(void *begin, void **buffer)
{
    if (!begin)
        return (0);
    if (!*buffer)
        *buffer = begin;
    else if (((node_t *)*buffer)->next != begin)
        *buffer = ((node_t *)*buffer)->next;
    else
        return (0);
    return (1);
}

void *list_fetch(void *begin, char *label)
{
    node_t *curr = NULL;

    while (list_poll(begin, (void **)&curr)) {
        if (strcmp(curr->label, label) == 0)
            return (curr);
    }
    return (NULL);
}

void list_pop(void **begin, void *node)
{
    node_t *st_node = (node_t *)node;
    node_t *tmp = NULL;

    if (!*begin || !node)
        return;
    if (st_node == st_node->next) {
        *begin = NULL;
    } else {
        if (st_node == *begin)
            *begin = st_node->next;
        tmp = *begin;
        while (tmp->next != node && tmp->next != *begin)
            tmp = (node_t *)tmp->next;
        tmp->next = st_node->next;
    }
    st_node->destroy(node);
}