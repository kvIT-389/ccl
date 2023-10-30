/**
 * \file list.c
 * \brief Contains list functions implementation.
 */

#include "list/list.h"

#include <stdlib.h>

#include "list/listnode.h"


list_t *list__create(void) {
    list_t *list;

    list = malloc(sizeof(list_t));

    *list = (list_t){
        .size = 0,
        .head = NULL,
        .tail = NULL,
    };

    return list;
}

void list__free(list_t *list) {
    list__clear(list);
    free(list);
}

void list__push_back(list_t *list, void *data) {
    list_node_t *node;

    if (list == NULL) {
        return;
    }

    node = list_node__create(data);

    if (list__empty(list)) {
        list->head = node;
    } else {
        node->prev = list->tail;
        list->tail->next = node;
    }

    list->tail = node;
    list->size++;
}

void list__push_front(list_t *list, void *data) {
    list_node_t *node;

    if (list == NULL) {
        return;
    }

    node = list_node__create(data);

    if (list__empty(list)) {
        list->tail = node;
    } else {
        node->next = list->head;
        list->head->prev = node;
    }

    list->head = node;
    list->size++;
}

void list__pop_back(list_t *list) {
    if (list == NULL || list__empty(list)) {
        return;
    }

    list->tail = list->tail->prev;
    list->size--;

    if (list__empty(list)) {
        list_node__free(list->head);
        list->head = NULL;
    } else {
        list_node__free(list->tail->next);
        list->tail->next = NULL;
    }
}

void list__pop_front(list_t *list) {
    if (list == NULL || list__empty(list)) {
        return;
    }

    list->head = list->head->next;
    list->size--;

    if (list__empty(list)) {
        list_node__free(list->tail);
        list->tail = NULL;
    } else {
        list_node__free(list->head->prev);
        list->head->prev = NULL;
    }
}

void list__clear(list_t *list) {
    while (!list__empty(list)) {
        list__pop_back(list);
    }
}

uint8_t list__empty(list_t *list) {
    return list == NULL || list->size == 0;
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
