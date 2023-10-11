/**
 * \file vector.c
 * \brief Contains vector functions implementation.
 */

#include <stdlib.h>

#include "vector/vector.h"


vector_t *vector__create(size_t size) {
    vector_t *vector = (vector_t *)malloc(sizeof(vector_t));

    vector->data = (void **)malloc(size * sizeof(void *));
    vector->size = size;

    return vector;
}

size_t vector__resize(vector_t *vector, size_t size) {
    if (vector == NULL) {
        return 0;
    }

    vector->data = (void **)realloc(
        vector->data,
        size * sizeof(void *)
    );
    vector->size = size;

    return size;
}

void *vector__at(vector_t *vector, size_t n) {
    if (vector == NULL || n >= vector->size) {
        return NULL;
    }

    return vector->data[n];
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

void vector__free(vector_t *vector) {
    if (vector == NULL) {
        return;
    }

    free(vector->data);
    free(vector);
}
