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


void iterate_forward(list_t *list) {
    list_iterator_t it = list__begin(list);

    printf("Start iterating forward through list...\n");

    void (*fn)() = list_iterator__current(&it);
    while (!list_iterator__ended(&it)) {
        /* Using value */
        if (fn != NULL) {
            fn();
        } else {
            printf("List value is NULL.\n");
        }

        /* Updating value */
        fn = list_iterator__next(&it);
    }

    printf("Iteration ended.\n");
}

void iterate_backward(list_t *list) {
    list_iterator_t it = list__rbegin(list);

    printf("Start iterating backward through list...\n");

    void (*fn)() = list_iterator__current(&it);
    while (!list_iterator__rended(&it)) {
        /* Using value */
        if (fn != NULL) {
            fn();
        } else {
            printf("List value is NULL.\n");
        }

        /* Updating value */
        fn = list_iterator__prev(&it);
    }

    printf("Iteration ended.\n");
}


int main(int argc, char const *argv[]) {
    list_t *list = list__create();

    printf("Initial size: %d\n", list__size(list));

    list__push_back(list, &f1);
    list__push_back(list, &f3);
    list__push_front(list, &f2);

    printf("Size after 3 pushes: %d\n", list__size(list));

    iterate_forward(list);

    list__pop_back(list);
    list__pop_front(list);

    list__push_back(list, &f2);
    list__push_front(list, &f3);
    list__push_front(list, &f2);

    printf("Size after 2 pops and 3 pushes: %d\n", list__size(list));

    iterate_backward(list);

    list__clear(list);

    printf("Size after clear(): %d\n", list__size(list));

    list__free(list);

    printf("Size after free(): %d [undefined]\n", list__size(list));

    return 0;
}
