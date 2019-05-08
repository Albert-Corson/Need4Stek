/*
** EPITECH PROJECT, 2019
** AIA_n4s_2018_tmp
** File description:
** main
*/

#include "n4s.h"

void show(api_response_t res)
{
    float *db = res.data;
    long *tm = res.data;
    int i = 0;

    dprintf(2, "%d:%d\n", res.value_id, res.status);
    if (res.data_type == RES_NONE)
        dprintf(2, "NO DATA\n");
    if (res.data_type == RES_FLOAT_1)
        dprintf(2, "%.5f\n", *db);
    if (res.data_type == RES_LONG_2)
        dprintf(2, "%lds %ldns\n", tm[0], tm[1]);
    if (res.data_type == RES_FLOAT_32) {
        while (i < 32) {
            dprintf(2, "%.5f: ", db[i]);
            ++i;
        }
        dprintf(2, "\n");
    }
    dprintf(2, "CP: %d", res.cp_id);
    dprintf(2, "[%lds,%ldns]\n", res.timestamp[0], res.timestamp[1]);
    dprintf(2, "\n");
}


int main(void)
{
    show(auto_exec("START_SIMULATION"));
    show(auto_exec("CAR_FORWARD", 0.5));
    show(auto_exec("GET_INFO_LIDAR"));
    show(auto_exec("CYCLE_WAIT", 50));
    show(auto_exec("GET_INFO_SIMTIME"));
    show(auto_exec("CYCLE_WAIT", 50));
    show(auto_exec("STOP_SIMULATION"));
    return (0);
}

/*
**  TEST INPUTS
*/

// GET_INFO_LIDAR
// 1:OK:No errors so far:575.0:625.0:675.0:700.0:750.0:800.0:900.0:975.0:1050.0:1125.0:1375.0:1500.0:2500.0:2750.0:3000.0:3000.0:3000.0:3000.0:2750.0:1500.0:1375.0:1125.0:975.0:900.0:800.0:700.0:625.0:600.0:550.0:500.0:487.5:450.0:No further info

// CYCLE_WAIT
// 20:OK:CYCLE DONE:First CP Cleared: [0][3s 152764356ns]

// GET_INFO_SIMTIME
// 1:OK:No errors so far:[5s,568380618ns]:No further info