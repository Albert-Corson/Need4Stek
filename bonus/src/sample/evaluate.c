/*
** EPITECH PROJECT, 2019
** AIA_n4s_2018
** File description:
** evaluate
*/

#include "train.h"

void evaluate_network(network_t *net)
{
    api_response_t res = api_res_new();
    double *inputs = NULL;
    mx_t *out = NULL;

    auto_exec(&res, START_SIMULATION);
    while (!detect_collision(&res)) {
        inputs = format_input_data(&res);
        out = forward_propagation(net, inputs);
        handle_output_data(out->arr[0], &res);
        auto_exec(&res, CYCLE_WAIT, 5);
    }
    if (res.timestamp[0] == 0)
        net->rank = res.cp_id;
    else
        net->rank = (double)res.cp_id / (double)res.timestamp[0];
    dprintf(2, "cpc: %d\n", res.cp_id);
    dprintf(2, "tim: %ld\n", res.timestamp[0]);
    dprintf(2, "eff: %.5f\n", net->rank);
    auto_exec(&res, STOP_SIMULATION);
}

network_t **evaluate_sample(network_t **sample)
{
    int index = 0;

    while (sample[index]) {
        if (sample[index]->rank == -1) {
            dprintf(2, "\e[94mgenome %d\e[39m\n", index);
            sample[index]->rank = clang(0, 1);
            play_simulation(sample[index]);
        }
        ++index;
    }
    return (sample);
}