/*
** EPITECH PROJECT, 2019
** AIA_n4s_2018_tmp
** File description:
** main
*/

#include "n4s.h"

int main(void)
{
    node_t *list = NULL;
    node_t *node = NULL;

    for (long x = 0; x < 10; x++) {
        node = node_new(NULL);
        node->set_long(node, x);
        list_append((void **)&list, node);
    }
    node = NULL;
    // while (list_poll(list, (void **)&node)) {
    //     printf("%ld\n", node->get_long(node));
    // }
    list_destroy((void **)&list);
    return (0);
}