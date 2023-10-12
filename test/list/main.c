#include <stdio.h>

#include "list/list.h"


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
    list_t *list = list__create();

    printf("Initial size: %d\n", list->size);

    list__add(list, &f1);
    list__add(list, &f2);

    printf("Size after 2 add()'s: %d\n", list->size);

    ((void (*)())list->head->data)();
    ((void (*)())list->head->next->data)();

    list__add(list, &f3);

    printf("Size after 1 more add(): %d\n", list->size);

    list__add(list, &f1);
    list__add(list, &f1);

    printf("Size after 2 extra add()'s: %d\n", list->size);

    list_iterator_t list_iter = list__get_iterator(list);

    printf("Start iterating through list...\n");

    void (*fn)() = list_iterator__current(&list_iter);
    while (!list_iterator__ended(&list_iter)) {
        /* Using value */
        if (fn != NULL) {
            fn();
        } else {
            printf("Vector value is NULL.\n");
        }

        /* Updating value */
        fn = list_iterator__next(&list_iter);
    }

    printf("Iteration ended.\n");

    list__clear(list);

    printf("Size after clear(): %d\n", list->size);

    list__free(list);

    printf("Size after free(): %d\n", list->size);

    return 0;
}
