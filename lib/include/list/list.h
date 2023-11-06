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
  /* Number of list elements. */
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
  /* Iterator's list. */
  list_t *list;

  /* List node with current iterator value. */
  list_node_t *node;
} list_iterator_t;


/**
 * \brief Creates new list.
 * 
 * \returns Pointer to created list.
 */
list_t *list__create(void);

/**
 * \brief Clears list and frees it.
 * 
 * \param list: list to free.
 */
void list__free(list_t *list);

/**
 * \brief Gets the number of list elements.
 * 
 * \param list: list to get size.
 * 
 * \returns Number of list elements.
 */
size_t list__size(const list_t *list);

/**
 * \brief Checks if list is empty or not.
 * 
 * \param iterator: list to check.
 * 
 * \returns `1` if list is empty, `0` otherwise.
 */
uint8_t list__empty(const list_t *list);

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
 * \brief Gets iterator to the list's first element.
 * 
 * \param list: list to get iterator from.
 * 
 * \returns Iterator to the given list's first element.
 */
list_iterator_t list__begin(list_t *list);

/**
 * \brief Gets iterator to the list end (past-the-last element).
 * 
 * \param list: list to get iterator from.
 * 
 * \returns Iterator to the given list end.
 */
list_iterator_t list__end(list_t *list);

/**
 * \brief Gets iterator to the list's last element.
 * 
 * \param list: list to get iterator from.
 * 
 * \returns Iterator to the given list's last element.
 */
list_iterator_t list__rbegin(list_t *list);

/**
 * \brief Gets iterator to the list beginning (past-the-last
 *        element in the reversed sequence).
 * 
 * \param list: list to get iterator from.
 * 
 * \returns Iterator to the given list beginning.
 */
list_iterator_t list__rend(list_t *list);

/**
 * \brief Checks if list forward iterator is ended or not.
 * 
 * \param it: list iterator to check.
 * 
 * \returns `1` if iterator is ended, `0` otherwise.
 */
uint8_t list_iterator__ended(const list_iterator_t *it);

/**
 * \brief Checks if list reverse iterator is ended or not.
 * 
 * \param it: list iterator to check.
 * 
 * \returns `1` if iterator is ended, `0` otherwise.
 */
uint8_t list_iterator__rended(const list_iterator_t *it);

/**
 * \brief Gets current list iterator value as void pointer.
 * 
 * \param it: list iterator to get value from.
 * 
 * \returns Current list iterator value if `iterator` is not ended,
 *          `NULL` otherwise.
 */
void *list_iterator__get(const list_iterator_t *it);

/**
 * \brief Changes list iterator value to the next.
 * 
 * \param it: list iterator to change.
 * 
 * \returns Next list iterator value.
 */
void *list_iterator__next(list_iterator_t *it);

/**
 * \brief Changes list iterator value to the previous.
 * 
 * \param it: list iterator to change.
 * 
 * \returns Previous list iterator value.
 */
void *list_iterator__prev(list_iterator_t *it);


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* LIST_H_INCLUDED_ */
