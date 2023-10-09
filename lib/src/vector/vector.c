/**
 * \file vector.c
 * \brief Contains vector functions implementation.
 */

#include <stdlib.h>

#include "vector/vector.h"


vector_t *createVector(size_t size) {
    vector_t *vector = (vector_t *)malloc(sizeof(vector_t));

    vector->data = (void **)malloc(size * sizeof(void *));
    vector->size = size;

    return vector;
}

size_t resizeVector(vector_t *vector, size_t size) {
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

void *getVectorAt(vector_t *vector, size_t n) {
    if (vector == NULL || n >= vector->size) {
        return NULL;
    }

    return vector->data[n];
}

void setVectorAt(vector_t *vector, size_t n, void *value) {
    if (vector == NULL) {
        return;
    }

    if (n >= vector->size) {
        resizeVector(vector, n + 1);
    }

    vector->data[n] = value;
}

void freeVector(vector_t *vector) {
    if (vector == NULL) {
        return;
    }

    free(vector->data);
    free(vector);
}
