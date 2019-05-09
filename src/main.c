/*
** EPITECH PROJECT, 2019
** AIA_n4s_2018_tmp
** File description:
** main
*/

#include "n4s.h"
#include <unistd.h>

int main(void)
{
    network_t *net = network_new(36, 2, 72, 1);
    double *inputs = NULL;
    double *outputs = NULL;
    api_response_t res;

    srand(0);
    res = auto_exec("START_SIMULATION");
    if (!res.status) {
        dprintf(2, "V-REP software not running.");
        return (84);
    }
    network_randomize(net);
    for (int index = 0; index < 10; index++) {
        inputs = format_input_data();
        mx_t *out = forward_propagation(net, inputs);
        outputs = out->arr[0];
        handle_output_data(outputs);
        // network_print(net);
        auto_exec("CYCLE_WAIT", 5);
    }
    auto_exec("STOP_SIMULATION");
    network_print(net);
    network_destroy(net);
    return (0);
}