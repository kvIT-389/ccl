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
    list_t *list = createList();

    printf("Initial size: %d\n", list->size);

    addListElement(list, &f1);
    addListElement(list, &f2);

    printf("Size after 2 add()'s: %d\n", list->size);

    ((void (*)())list->head->data)();
    ((void (*)())list->head->next->data)();

    addListElement(list, &f3);

    printf("Size after 1 extra add(): %d\n", list->size);

    ((void (*)())list->head->next->next->data)();
    ((void (*)())list->head->data)();
    ((void (*)())list->head->next->data)();

    clearList(list);

    printf("Size after clear(): %d\n", list->size);

    freeList(list);

    printf("Size after free(): %d\n", list->size);

    return 0;
}
