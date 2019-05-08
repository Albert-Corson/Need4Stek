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

/*
**  TYPES
*/

typedef enum opt_info_type_e opt_info_type_t;
typedef enum api_res_type_e api_res_type_t;
typedef enum data_type_e data_type_t;
typedef enum arg_type_e arg_type_t;
typedef struct node_s node_t;
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
    DT_STR
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

struct node_s {
    char *label;
    void *next;
    void *value;
    void (*destroy)(void *);
    void (*set)(void *, void *, size_t);
    void *(*get)(void *);
};

struct api_response_s {
    int value_id;
    bool status;
    api_res_type_t data_type;
    void *data;
    void (*destroy_data)(void *);
    opt_info_type_t opt_type;
    int cp_id;
    long timestamp[2];
};

struct api_connector_s {
    api_response_t response;
};

/*
**  LINKED LISTS
*/
void *node_new(char const *label);
void *list_append(void **begin, void *node);
void list_destroy(void **begin);
int list_poll(void *begin, void **buffer);
void *list_fetch(void *begin, char *label);
void list_pop(void **begin, void *node);

/*
**  COMMANDS
*/
api_response_t exec_cmd(int arg_tp, int res_type, char *cmd, ...);
api_response_t auto_exec(char *str, ...);

/*
**  TOOLS
*/
int str_parse(char *str, char end, data_type_t dt_type, ...);
int str_skip_chars(char *str, char *to_skip);
int get_char_pos(char *str, char goal);

#endif /* !N4S_H_ */