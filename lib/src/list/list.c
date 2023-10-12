/**
 * \file list.c
 * \brief Contains linked list functions implementation.
 */

#include <stdlib.h>

#include "list/list.h"
#include "list/listnode.h"


list_t *list__create(void) {
    list_t *new_list = (list_t *)malloc(sizeof(list_t));

    new_list->head = NULL;
    new_list->size = 0;

    return new_list;
}

void list__add(list_t *list, void *data) {
    list_node_t *new_node, *node;

    if (list == NULL) {
        return;
    }

    new_node = list_node__create(data);
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

void list__clear(list_t *list) {
    list_node_t *node;

    if (list == NULL) {
        return;
    }

    node = list->head;
    while (node != NULL) {
        node = list_node__free(node);
    }

    list->head = NULL;
    list->size = 0;
}

void list__free(list_t *list) {
    list__clear(list);
    free(list);
}


list_iterator_t list__get_iterator(list_t *list) {
    if (list == NULL) {
        return (list_iterator_t){};
    }

    return (list_iterator_t){
        .current_node = list->head
    };
}

void *list_iterator__current(list_iterator_t *iterator) {
    if (iterator == NULL || list_iterator__ended(iterator)) {
        return NULL;
    }

    return iterator->current_node->data;
}

void *list_iterator__next(list_iterator_t *iterator) {
    if (iterator == NULL || list_iterator__ended(iterator)) {
        return NULL;
    }

    iterator->current_node = iterator->current_node->next;

    return list_iterator__current(iterator);
}

uint8_t list_iterator__ended(list_iterator_t *iterator) {
    return iterator == NULL || iterator->current_node == NULL;
}
