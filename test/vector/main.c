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
    vector_t *vector = createVector(3);

    printf("Initial size: %d\n", vector->size);

    setVectorAt(vector, 0, &f1);
    setVectorAt(vector, 1, &f2);
    setVectorAt(vector, 2, &f3);

    ((void (*)())getVectorAt(vector, 2))();
    ((void (*)())getVectorAt(vector, 0))();

    printf("Size after 3 set()'s at maximum index 2: %d\n", vector->size);

    setVectorAt(vector, 4, &f2);

    ((void (*)())getVectorAt(vector, 4))();
    ((void (*)())getVectorAt(vector, 2))();

    printf("Size after extra set() at index 4, which was greater than vector's size: %d\n", vector->size);

    freeVector(vector);

    printf("Size after free(): %d\n", vector->size);

    return 0;
}
