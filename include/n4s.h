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

/*
**  TYPES
*/

typedef enum node_type_e node_type_t;
typedef struct node_s node_t;
typedef struct api_response_s api_response_t;
typedef struct api_connector_s api_connector_t;

/*
**  ENUMS
*/



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
    char *code_str;
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

#endif /* !N4S_H_ */