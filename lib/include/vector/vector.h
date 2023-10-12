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
  /* Vector data (array of pointers to arbitrary type). */
  void **data;

  /* Vector size i.e. elements count. */
  size_t size;
} vector_t;


/**
 * \brief Vector iterator.
 */
typedef struct vector_iterator {
  /* Pointer to current iterator value. */
  void **current;

  /* Number of remaining iterator values including current. */
  size_t i;
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
 * \brief Changes size of the vector.
 * 
 * \attention If new size is less then old all data
 *            at indexes started from `size` will be erased.
 * 
 * \param vector: vector to resize.
 * \param size: new vector size.
 * 
 * \returns New size of the vector if `vector` is not `NULL`,
 *          `0` otherwise.
 */
size_t vector__resize(vector_t *vector, size_t size);

/**
 * \brief Gets vector element at certain index.
 * 
 * \param vector: vector where to get element.
 * \param n: index of the element.
 * 
 * \returns Vector element at index `n` if `vector` is not `NULL`
 *          and `n` is less than vector size, `NULL` otherwise.
 */
void *vector__at(vector_t *vector, size_t n);

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
 * \brief Frees vector.
 * 
 * \param vector: vector to free.
 */
void vector__free(vector_t *vector);

/**
 * \brief Gets vector values iterator.
 * 
 * \param vector: vector to get iterator from.
 * 
 * \returns Iterator of the given vector.
 */
vector_iterator_t vector__get_iterator(vector_t *vector);

/**
 * \brief Gets current vector iterator value as void pointer.
 * 
 * \param iterator: vector iterator to get value from.
 * 
 * \returns Current vector iterator value if `iterator` is not ended,
 *          `NULL` otherwise.
 */
void *vector_iterator__current(vector_iterator_t *iterator);

/**
 * \brief Changes vector iterator value to the next.
 * 
 * \param iterator: vector iterator to change.
 * 
 * \returns Next vector iterator value.
 */
void *vector_iterator__next(vector_iterator_t *iterator);

/**
 * \brief Checks if vector iterator is ended or not.
 * 
 * \param iterator: vector iterator to check.
 * 
 * \returns `1` if iterator is ended, `0` otherwise.
 */
uint8_t vector_iterator__ended(vector_iterator_t *iterator);


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* VECTOR_H_INCLUDED_ */
