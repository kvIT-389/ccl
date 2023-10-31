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

void call_from_list(list_t *list) {
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
}


int main(int argc, char const *argv[]) {
    list_t *list = list__create();

    printf("Initial size: %d\n", list->size);

    list__push_back(list, &f1);
    list__push_back(list, &f3);
    list__push_front(list, &f2);

    printf("Size after 3 pushes: %d\n", list->size);

    call_from_list(list);

    list__pop_back(list);
    list__pop_front(list);

    list__push_back(list, &f2);
    list__push_front(list, &f3);
    list__push_front(list, &f2);

    printf("Size after 2 pops and 3 pushes: %d\n", list->size);

    call_from_list(list);

    list__clear(list);

    printf("Size after clear(): %d\n", list->size);

    list__free(list);

    printf("Size after free(): %d\n (undefined)", list->size);

    return 0;
}
