#include <stdio.h>

#include "vector/vector.h"


void f1() {
    printf("f1() call\n");
}

void f2() {
    printf("f2() call\n");
}

void f3() {
    printf("f3() call\n");
}


void iterate_forward(vector_t *vector) {
    vector_iterator_t it = vector__begin(vector);

    printf("Start iterating forward through vector...\n");

    void (*fn)() = vector_iterator__get(&it);
    while (!vector_iterator__ended(&it)) {
        printf("[%d] ", it.index);

        /* Using value */
        if (fn != NULL) {
            fn();
        } else {
            printf("NULL.\n");
        }

        /* Updating value */
        fn = vector_iterator__next(&it);
    }

    printf("Iteration ended.\n");
}

void iterate_backward(vector_t *vector) {
    vector_iterator_t it = vector__rbegin(vector);

    printf("Start iterating backward through vector...\n");

    void (*fn)() = vector_iterator__get(&it);
    while (!vector_iterator__rended(&it)) {
        printf("[%d] ", it.index);

        /* Using value */
        if (fn != NULL) {
            fn();
        } else {
            printf("NULL.\n");
        }

        /* Updating value */
        fn = vector_iterator__prev(&it);
    }

    printf("Iteration ended.\n");
}


int main(int argc, char const *argv[]) {
    vector_t *vector = vector__create(3);

    printf("Initial size: %d\n", vector__size(vector));

    vector__set(vector, 0, &f3);
    vector__set(vector, 1, &f1);
    vector__set(vector, 2, &f2);

    iterate_forward(vector);

    printf("Size after 3 set()'s at maximum index 2: %d\n", vector__size(vector));

    vector__set(vector, 4, &f3);

    ((void (*)())vector__at(vector, 4))();
    ((void (*)())vector__at(vector, 2))();

    printf("Size after extra set() at index 4, which was greater than vector size: %d\n", vector__size(vector));

    iterate_backward(vector);

    vector__free(vector);

    printf("Size after free(): %d\n", vector__size(vector));

    return 0;
}
