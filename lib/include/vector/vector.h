/**
 * \file vector.h
 * \brief Contains vector data structure declaration.
 */

#ifndef VECTOR_H_INCLUDED_
#define VECTOR_H_INCLUDED_

#include <stdint.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


/**
 * \brief Vector data structure.
 */
typedef struct vector {
  /* Number of vector elements. */
  size_t size;

  /* Vector data (array of pointers to arbitrary type). */
  void **data;
} vector_t;


/**
 * \brief Vector iterator.
 */
typedef struct vector_iterator {
  /* Iterator's vector. */
  vector_t *vector;

  /* Index of current iterator value. */
  size_t index;
} vector_iterator_t;


/**
 * \brief Creates new vector.
 * 
 * \param size: initial size of the created vector.
 * 
 * \returns Pointer to created vector.
 */
vector_t *vector__create(size_t size);

/**
 * \brief Frees vector.
 * 
 * \param vector: vector to free.
 */
void vector__free(vector_t *vector);

/**
 * \brief Gets the number of vector elements.
 * 
 * \param vector: vector to get size.
 * 
 * \returns Number of vector elements.
 */
size_t vector__size(const vector_t *vector);

/**
 * \brief Checks if vector is empty or not.
 * 
 * \param vector: vector to check.
 * 
 * \returns `1` if vector is empty, `0` otherwise.
 */
uint8_t vector__empty(const vector_t *vector);

/**
 * \brief Gets vector element at certain index.
 * 
 * \param vector: vector where to get element.
 * \param n: index of the element.
 * 
 * \returns Vector element at index `n` if `vector` is not `NULL`
 *          and `n` is less than vector size, `NULL` otherwise.
 */
void *vector__at(const vector_t *vector, size_t n);

/**
 * \brief Sets vector value at certain index.
 * 
 * \param vector: vector where to get element.
 * \param n: index of the element.
 * \param value: new value to set.
 * 
 * \note If index `n` is greater than the maximum possible
 *       vector size will be automatically increased to `n + 1`.
 */
void vector__set(vector_t *vector, size_t n, void *value);

/**
 * \brief Adds element to the end of the vector.
 * 
 * \param vector: vector where to add element.
 * \param data: new element's data.
 */
void vector__push_back(vector_t *vector, void *data);

/**
 * \brief Removes the last element of the vector.
 * 
 * \param vector: vector where to remove element.
 */
void vector__pop_back(vector_t *vector);

/**
 * \brief Changes size of the vector.
 * 
 * \attention If new size is less then old all data
 *            at indexes started from `size` will be erased.
 * 
 * \param vector: vector to resize.
 * \param size: new vector size.
 */
void vector__resize(vector_t *vector, size_t size);

/**
 * \brief Gets iterator to the vector's first element.
 * 
 * \param vector: vector to get iterator from.
 * 
 * \returns Iterator to the given vector's first element.
 */
vector_iterator_t vector__begin(vector_t *vector);

/**
 * \brief Gets iterator to the vector end (past-the-last
 *        element).
 * 
 * \param vector: vector to get iterator from.
 * 
 * \returns Iterator to the given vector end.
 */
vector_iterator_t vector__end(vector_t *vector);

/**
 * \brief Gets iterator to the vector's last element.
 * 
 * \param vector: vector to get iterator from.
 * 
 * \returns Iterator to the given vector's last element.
 */
vector_iterator_t vector__rbegin(vector_t *vector);

/**
 * \brief Gets iterator to the vector beginning (past-the-last
 *        element in the reversed sequence).
 * 
 * \param vector: vector to get iterator from.
 * 
 * \returns Iterator to the given vector beginning.
 */
vector_iterator_t vector__rend(vector_t *vector);

/**
 * \brief Checks if vector iterator is equal to its end
 *        iterator (returned from `vector__end(...) call`).
 * 
 * \param iterator: vector iterator to check.
 * 
 * \returns `1` if iterator is ended, `0` otherwise.
 */
uint8_t vector_iterator__ended(const vector_iterator_t *it);

/**
 * \brief Checks if vector iterator is equal to its rend
 *        iterator (returned from `vector__rend(...) call`).
 * 
 * \param iterator: vector iterator to check.
 * 
 * \returns `1` if iterator is ended, `0` otherwise.
 */
uint8_t vector_iterator__rended(const vector_iterator_t *it);

/**
 * \brief Gets current vector iterator value as void pointer.
 * 
 * \param iterator: vector iterator to get value from.
 * 
 * \returns Current vector iterator value if `iterator` is not ended,
 *          `NULL` otherwise.
 */
void *vector_iterator__get(const vector_iterator_t *it);

/**
 * \brief Changes vector iterator value to the next.
 * 
 * \param iterator: vector iterator to change.
 * 
 * \returns Next vector iterator value.
 */
void *vector_iterator__next(vector_iterator_t *it);

/**
 * \brief Changes vector iterator value to the next.
 * 
 * \param iterator: vector iterator to change.
 * 
 * \returns Next vector iterator value.
 */
void *vector_iterator__prev(vector_iterator_t *it);


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* VECTOR_H_INCLUDED_ */
