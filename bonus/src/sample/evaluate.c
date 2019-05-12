/*
** EPITECH PROJECT, 2019
** AIA_n4s_2018
** File description:
** evaluate
*/

#include "train.h"

double get_sample_average(network_t **sample)
{
    int index = 0;
    double average = 0;

    while (sample[index]) {
        average += sample[index]->rank;
        ++index;
    }
    average /= (index - 1);
    return (average);
}

void show_scoreboard(network_t **sample)
{
    int index = 0;
    double average = get_sample_average(sample);

    dprintf(2, "## SCORES ##\n");
    while (sample[index]) {
        dprintf(2, "%d. %.3f\n", index, sample[index]->rank);
        ++index;
    }
    dprintf(2, "# average score [%.3f] #\n\n", average);
}

void evaluate_network(network_t *net)
{
    api_response_t res = api_res_new();
    double lidar_average = 0;
    double *inputs = NULL;
    mx_t *out = NULL;
    time_t start = time(NULL);
    bool timeout = false;

    auto_exec(&res, START_SIMULATION);
    while (!detect_collision(&res) && !timeout) {
        inputs = format_input_data(&res);
        lidar_average = get_average_dist(res.data);
        out = forward_propagation(net, inputs);
        handle_output_data(out->arr[0], &res);
        auto_exec(&res, GET_INFO_SIMTIME);
        if (time(NULL) - start > 60)
            timeout = true;
    }
    net->rank = res.cp_id + 1 / (double)(1 + res.timestamp[0]);
    net->rank += lidar_average / 3010;
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