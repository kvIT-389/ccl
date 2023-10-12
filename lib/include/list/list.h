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
 * \brief Linked list iterator.
 */
typedef struct list_iterator {
  list_node_t *current_node;
} list_iterator_t;


/**
 * \brief Creates new linked list.
 * 
 * \returns Pointer to created list.
 */
list_t *list__create(void);

/**
 * \brief Adds element to the end of the linked list.
 * 
 * \param list: list where to add element.
 * \param data: new element's data.
 */
void list__add(list_t *list, void *data);

/**
 * \brief Removes all elements of the linked list.
 * 
 * \param list: list to clear.
 */
void list__clear(list_t *list);

/**
 * \brief Clears linked list and frees its.
 * 
 * \param list: list to free.
 */
void list__free(list_t *list);

/**
 * \brief Gets list's nodes iterator.
 * 
 * \param list: list to get iterator from.
 * 
 * \returns Iterator for the given list.
 */
list_iterator_t list__get_iterator(list_t *list);

/**
 * \brief Gets current list iterator value as void pointer.
 * 
 * \param iterator: list iterator to get value from.
 * 
 * \returns Current list iterator value if `iterator` is not ended,
 *          `NULL` otherwise.
 */
void *list_iterator__current(list_iterator_t *iterator);

/**
 * \brief Changes list iterator value to the next.
 * 
 * \param iterator: iterator to change.
 * 
 * \returns Next list iterator value.
 */
void *list_iterator__next(list_iterator_t *iterator);

/**
 * \brief Checks if iterator is ended or not.
 * 
 * \param iterator: iterator to check.
 * 
 * \returns `1` if iterator is ended, `0` otherwise.
 */
int list_iterator__ended(list_iterator_t *iterator);


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* LIST_H_INCLUDED_ */
