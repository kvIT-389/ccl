/**
 * \file vector.c
 * \brief Contains vector functions implementation.
 */

#include "vector/vector.h"

#include <stdlib.h>


vector_t *vector__create(size_t size) {
    vector_t *vector = malloc(sizeof(vector_t));

    *vector = (vector_t){
        .data = malloc(size * sizeof(void *)),
        .size = size
    };

    return vector;
}

void vector__free(vector_t *vector) {
    if (vector == NULL) {
        return;
    }

    free(vector->data);
    free(vector);
}


size_t vector__size(const vector_t *vector) {
    return (vector == NULL) ? (0) : (vector->size);
}

uint8_t vector__empty(const vector_t *vector) {
    return vector__size(vector) == 0;
}

void *vector__at(const vector_t *vector, size_t n) {
    return (vector == NULL) || (n >= vector->size) ?
                                            (NULL) :
                                            (vector->data[n]);
}


void vector__set(vector_t *vector, size_t n, void *value) {
    if (vector == NULL) {
        return;
    }

    if (n >= vector->size) {
        vector__resize(vector, n + 1);
    }

    vector->data[n] = value;
}

void vector__push_back(vector_t *vector, void *value) {
    vector__set(vector, vector__size(vector), value);
}

void vector__pop_back(vector_t *vector) {
    if (!vector__empty(vector)) {
        vector__resize(vector, vector__size(vector) - 1);
    }
}

void vector__resize(vector_t *vector, size_t size) {
    if (vector == NULL) {
        return;
    }

    vector->data = realloc(
        vector->data,
        size * sizeof(void *)
    );

    vector->size = size;
}


vector_iterator_t vector__begin(vector_t *vector) {
    return (vector_iterator_t){
        .vector = vector,
        .index = 0
    };
}

vector_iterator_t vector__end(vector_t *vector) {
    return (vector_iterator_t){
        .vector = vector,
        .index = vector__size(vector)
    };
}

vector_iterator_t vector__rbegin(vector_t *vector) {
    return (vector_iterator_t){
        .vector = vector,
        .index = vector__size(vector) - 1
    };
}

vector_iterator_t vector__rend(vector_t *vector) {
    return (vector_iterator_t){
        .vector = vector,
        .index = -1
    };
}


uint8_t vector_iterator__ended(const vector_iterator_t *it) {
    return (it == NULL) ||
           (it->vector == NULL) ||
           (it->index == vector__end(it->vector).index);
}

uint8_t vector_iterator__rended(const vector_iterator_t *it) {
    return (it == NULL) ||
           (it->vector == NULL) ||
           (it->index == vector__rend(it->vector).index);
}


void *vector_iterator__get(const vector_iterator_t *it) {
    return (it == NULL) ?
                 (NULL) :
                 (vector__at(it->vector, it->index));
}

void *vector_iterator__next(vector_iterator_t *it) {
    if (!vector_iterator__ended(it)) {
        ++it->index;
    }

    return vector_iterator__get(it);
}

void *vector_iterator__prev(vector_iterator_t *it) {
    if (!vector_iterator__rended(it)) {
        --it->index;
    }

    return vector_iterator__get(it);
}
