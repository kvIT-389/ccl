/**
 * \file list.h
 * \brief Contains list data structure declaration.
 */

#ifndef LIST_H_INCLUDED_
#define LIST_H_INCLUDED_

#include <stdlib.h>

#include "list/listnode.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


/**
 * Linked list data structure.
 */
typedef struct list {
  /* The first node of the list. */
  list_node_t *head;

  /* List size i.e elements count. */
  size_t size;
} list_t;


/**
 * \brief Creates new linked list and returns pointer to it.
 */
list_t *createList(void);

/**
 * \brief Adds element to the end of the linked list.
 */
void addListElement(list_t *list, void *data);

/**
 * \brief Removes all elements of the linked list.
 */
void clearList(list_t *list);

/**
 * \brief Clears linked list and frees its.
 */
void freeList(list_t *list);


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* LIST_H_INCLUDED_ */
