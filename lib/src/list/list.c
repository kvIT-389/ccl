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
        .head = list_node__create(),
        .tail = list_node__create(),
    };

    list->head->next = list->tail;
    list->tail->prev = list->head;

    return list;
}

void list__free(list_t *list) {
    list__clear(list);

    list_node__free(list__end(list).node);
    list_node__free(list__rend(list).node);

    free(list);
}


size_t list__size(const list_t *list) {
    return (list == NULL) ? (0) : (list->size);
}

uint8_t list__empty(const list_t *list) {
    return list__size(list) == 0;
}


void list__push_back(list_t *list, void *data) {
    list_node_t *node;

    if (list == NULL) {
        return;
    }

    node = list_node__create();
    node->prev = list->tail;

    list->tail->next = node;
    list->tail->data = data;

    list->tail = node;
    list->size++;
}

void list__push_front(list_t *list, void *data) {
    list_node_t *node;

    if (list == NULL) {
        return;
    }

    node = list_node__create();
    node->next = list->head;

    list->head->prev = node;
    list->head->data = data;

    list->head = node;
    list->size++;
}

void list__pop_back(list_t *list) {
    if (list__empty(list)) {
        return;
    }

    list->tail = list->tail->prev;
    list->size--;

    list_node__free(list->tail->next);

    list->tail->next = NULL;
    list->tail->data = NULL;
}

void list__pop_front(list_t *list) {
    if (list__empty(list)) {
        return;
    }

    list->head = list->head->next;
    list->size--;

    list_node__free(list->head->prev);

    list->head->prev = NULL;
    list->head->data = NULL;
}

void list__clear(list_t *list) {
    while (!list__empty(list)) {
        list__pop_back(list);
    }
}


list_iterator_t list__begin(list_t *list) {
    return (list_iterator_t){
        .list = list,
        .node = (list == NULL) ? (NULL) : (list->head->next)
    };
}

list_iterator_t list__end(list_t *list) {
    return (list_iterator_t){
        .list = list,
        .node = (list == NULL) ? (NULL) : (list->tail)
    };
}

list_iterator_t list__rbegin(list_t *list) {
    return (list_iterator_t){
        .list = list,
        .node = (list == NULL) ? (NULL) : (list->tail->prev)
    };
}

list_iterator_t list__rend(list_t *list) {
    return (list_iterator_t){
        .list = list,
        .node = (list == NULL) ? (NULL) : (list->head)
    };
}


uint8_t list_iterator__ended(const list_iterator_t *it) {
    return (it == NULL) ||
           (it->list == NULL) ||
           (it->node == list__end(it->list).node);
}

uint8_t list_iterator__rended(const list_iterator_t *it) {
    return (it == NULL) ||
           (it->list == NULL) ||
           (it->node == list__rend(it->list).node);
}


void *list_iterator__get(const list_iterator_t *it) {
    return (it == NULL) || (it->list == NULL) ?
                                       (NULL) :
                                       (it->node->data);
}

void *list_iterator__next(list_iterator_t *it) {
    if (!list_iterator__ended(it)) {
        it->node = it->node->next;
    }

    return list_iterator__get(it);
}

void *list_iterator__prev(list_iterator_t *it) {
    if (!list_iterator__rended(it)) {
        it->node = it->node->prev;
    }

    return list_iterator__get(it);
}
