/**
 * \file list.h
 * \brief Contains list data structure declaration.
 */

#ifndef LIST_H_INCLUDED_
#define LIST_H_INCLUDED_

#include <stdint.h>
#include <stdlib.h>

#include "list/listnode.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


/**
 * \brief Doubly-linked list data structure.
 */
typedef struct list {
  /* List size i.e elements count. */
  size_t size;

  /* The first node of the list. */
  list_node_t *head;

  /* The last node of the list. */
  list_node_t *tail;
} list_t;


/**
 * \brief List iterator.
 */
typedef struct list_iterator {
  /* List node with current iterator value. */
  list_node_t *current_node;
} list_iterator_t;


/**
 * \brief Creates new list.
 * 
 * \returns Pointer to created list.
 */
list_t *list__create(void);

/**
 * \brief Clears list and frees its.
 * 
 * \param list: list to free.
 */
void list__free(list_t *list);

/**
 * \brief Adds element to the end of the list.
 * 
 * \param list: list where to add element.
 * \param data: new element's data.
 */
void list__push_back(list_t *list, void *data);

/**
 * \brief Adds element to the beginning of the list.
 * 
 * \param list: list where to add element.
 * \param data: new element's data.
 */
void list__push_front(list_t *list, void *data);

/**
 * \brief Removes the last element of the list.
 * 
 * \param list: list where to remove element.
 */
void list__pop_back(list_t *list);

/**
 * \brief Removes the first element of the list.
 * 
 * \param list: list where to remove element.
 */
void list__pop_front(list_t *list);

/**
 * \brief Removes all elements of the list.
 * 
 * \param list: list to clear.
 */
void list__clear(list_t *list);

/**
 * \brief Checks if list is empty or not.
 * 
 * \param iterator: list to check.
 * 
 * \returns `1` if list is empty, `0` otherwise.
 */
uint8_t list__empty(list_t *list);

/**
 * \brief Gets list iterator.
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
 * \param iterator: list iterator to change.
 * 
 * \returns Next list iterator value.
 */
void *list_iterator__next(list_iterator_t *iterator);

/**
 * \brief Checks if list iterator is ended or not.
 * 
 * \param iterator: list iterator to check.
 * 
 * \returns `1` if iterator is ended, `0` otherwise.
 */
uint8_t list_iterator__ended(list_iterator_t *iterator);


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* LIST_H_INCLUDED_ */
