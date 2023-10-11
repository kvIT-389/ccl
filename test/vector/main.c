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


int main(int argc, char const *argv[]) {
    vector_t *vector = vector__create(3);

    printf("Initial size: %d\n", vector->size);

    vector__set(vector, 0, &f1);
    vector__set(vector, 1, &f2);
    vector__set(vector, 2, &f3);

    ((void (*)())vector__at(vector, 2))();
    ((void (*)())vector__at(vector, 0))();

    printf("Size after 3 set()'s at maximum index 2: %d\n", vector->size);

    vector__set(vector, 4, &f2);

    ((void (*)())vector__at(vector, 4))();
    ((void (*)())vector__at(vector, 2))();

    printf("Size after extra set() at index 4, which was greater than vector's size: %d\n", vector->size);

    vector__free(vector);

    printf("Size after free(): %d\n", vector->size);

    return 0;
}
