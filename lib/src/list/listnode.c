/**
 * \file listnode.c
 * \brief Contains linked list node functions implementation.
 */

#include <stdlib.h>

#include "list/listnode.h"


list_node_t *createNode(void *data) {
    list_node_t *new_node = (list_node_t *)malloc(
        sizeof(list_node_t)
    );

    new_node->data = data;
    new_node->next = NULL;

    return new_node;
}

list_node_t *freeNode(list_node_t *node) {
    list_node_t *next;

    if (node == NULL) {
        return NULL;
    }

    next = node->next;
    free(node);

    return next;
}
