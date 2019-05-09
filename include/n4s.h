/*
** EPITECH PROJECT, 2019
** AIA_n4s_2018_tmp
** File description:
** n4s
*/

#ifndef N4S_H_
#define N4S_H_

/*
**  INCLUDES
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <stdarg.h>
#include <time.h>

/*
**  TYPES
*/

typedef enum opt_info_type_e opt_info_type_t;
typedef enum api_res_type_e api_res_type_t;
typedef enum data_type_e data_type_t;
typedef enum arg_type_e arg_type_t;
typedef struct vectorf_s vectorf_t;
typedef struct vectori_s vectori_t;
typedef struct network_s network_t;
typedef struct mx_s mx_t;
typedef struct api_response_s api_response_t;
typedef struct api_connector_s api_connector_t;

/*
**  ENUMS
*/

enum arg_type_e {
    VA_NO_ARG,
    VA_FLOAT,
    VA_INT
};

enum data_type_e {
    DT_NONE,
    DT_FLOAT,
    DT_LONG,
    DT_STR,
    DT_DOUBLE
};

enum api_res_type_e {
    RES_NONE,
    RES_FLOAT_32,
    RES_FLOAT_1,
    RES_LONG_2,
};

enum opt_info_type_e {
    OPT_NONE,
    OPT_FIRST_CP,
    OPT_CP,
    OPT_LAP,
    OPT_TRACK
};

/*
**  STRUCTS
*/

struct vectorf_s {
    double x;
    double y;
};

struct vectori_s {
    int x;
    int y;
};

struct api_response_s {
    int value_id;
    bool status;
    api_res_type_t data_type;
    void *data;
    opt_info_type_t opt_type;
    int cp_id;
    long timestamp[2];
};

struct api_connector_s {
    api_response_t response;
};

struct network_s {
    int inputs_size;
    int hidden_size;
    int hidden_count;
    int outputs_size;
    mx_t **layers;
    mx_t **weights;
    mx_t **biases;
};

struct mx_s {
    vectori_t size;
    double **arr;
};

/*
**  NEURAL NETWORK
*/

network_t *network_new(int inputs, int outputs, int hiddens, int hidden_count);
void *network_destroy(network_t *net);
void network_randomize(network_t *net);
void network_print(network_t *net);
void network_save(network_t *net, char *filename);
network_t *network_restore(char *savefile);

/*
**  MATRICES
*/

mx_t *mx_new(int width, int height);
void mx_print(mx_t *mx);
mx_t *mx_apply(mx_t *mx, double (*fn)(double));
mx_t *mx_fill_row(mx_t *mx, int row_id, double *data);
void *mx_destroy(mx_t *mx);

mx_t *mx_multiply_scalar(mx_t *a, double scalar, bool new);
mx_t *mx_add(mx_t *a, mx_t *b, bool new);
mx_t *mx_add_scalar(mx_t *a, double scalar, bool new);
mx_t *mx_subtract(mx_t *a, mx_t *b, bool new);
mx_t *mx_subtract_scalar(mx_t *a, double scalar, bool new);
mx_t *mx_multiply(mx_t *a, mx_t *b, bool new);
mx_t *mx_dot_product(mx_t *a, mx_t *b);
mx_t *mx_transpose(mx_t *a);

/*
**  TOOLS
*/

double randomize(double x);
mx_t *forward_propagation(network_t *net, double *inputs);
double sigmoid(double x);
double sigmoid_deriv(double x);
double *format_input_data(void);
void handle_output_data(double *data);

/*
**  COMMANDS
*/

char *exec_cmd(int arg_type, char *cmd, va_list ap);
bool auto_exec(api_response_t *res, char *str, ...);
api_response_t api_res_new(void);

/*
**  TOOLS
*/

int str_parse(char *str, char end, data_type_t dt_type, ...);
int str_skip_chars(char *str, char *to_skip);
int get_char_pos(char *str, char goal);

#endif /* !N4S_H_ */