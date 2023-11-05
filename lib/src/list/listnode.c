/**
 * \file listnode.c
 * \brief Contains list node functions implementation.
 */

#include "list/listnode.h"

#include <stdlib.h>


list_node_t *list_node__create(void) {
    list_node_t *node;

    node = malloc(sizeof(list_node_t));

    *node = (list_node_t){
        .data = NULL,
        .next = NULL,
        .prev = NULL
    };

    return node;
}

void list_node__free(list_node_t *node) {
    free(node);
}
