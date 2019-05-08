/*
** EPITECH PROJECT, 2019
** AIA_n4s_2018_tmp
** File description:
** main
*/

#include "n4s.h"

int main(int ac, char *av[])
{
    double in[3] = {0, 0, 0};
    network_t *net = network_new(3, 3, 4, 1);
    int index = 1;

    while (index < ac && index < 4) {
        in[index - 1] = atof(av[index]);
        ++index;
    }
    network_randomize(net);
    forward_propagation(net, in);
    network_print(net);
    network_destroy(net);
    // auto_exec("START_SIMULATION");
    // auto_exec("CAR_FORWARD", 0.5);
    // auto_exec("GET_INFO_LIDAR");
    // auto_exec("CYCLE_WAIT", 50);
    // auto_exec("GET_INFO_SIMTIME");
    // auto_exec("CYCLE_WAIT", 50);
    // auto_exec("STOP_SIMULATION");
    return (0);
}