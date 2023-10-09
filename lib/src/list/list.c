/**
 * \file list.c
 * \brief Contains linked list functions implementation.
 */

#include <stdlib.h>

#include "list/list.h"
#include "list/listnode.h"


list_t *createList(void) {
    list_t *new_list = (list_t *)malloc(sizeof(list_t));

    new_list->head = NULL;
    new_list->size = 0;

    return new_list;
}

void addListElement(list_t *list, void *data) {
    list_node_t *new_node, *node;

    if (list == NULL) {
        return;
    }

    new_node = createNode(data);
    node = list->head;

    list->size++;

    if (node == NULL) {
        list->head = new_node;
        return;
    }

    while (node->next != NULL) {
        node = node->next;
    }

    node->next = new_node;
}

void clearList(list_t *list) {
    list_node_t *node;

    if (list == NULL) {
        return;
    }

    node = list->head;
    while (node != NULL) {
        node = freeNode(node);
    }

    list->head = NULL;
    list->size = 0;
}

void freeList(list_t *list) {
    clearList(list);
    free(list);
}
