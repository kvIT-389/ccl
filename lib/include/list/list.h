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
 * \brief Linked list data structure.
 */
typedef struct list {
  /* The first node of the list. */
  list_node_t *head;

  /* List size i.e elements count. */
  size_t size;
} list_t;


/**
 * \brief Creates new linked list.
 * 
 * \returns Pointer to created list.
 */
list_t *createList(void);

/**
 * \brief Adds element to the end of the linked list.
 * 
 * \param list: list instance where to add element.
 * \param data: new element's data.
 */
void addListElement(list_t *list, void *data);

/**
 * \brief Removes all elements of the linked list.
 * 
 * \param list: list instance to clear.
 */
void clearList(list_t *list);

/**
 * \brief Clears linked list and frees its.
 * 
 * \param list: list instance to free.
 */
void freeList(list_t *list);


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* LIST_H_INCLUDED_ */
