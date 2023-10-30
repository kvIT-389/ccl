/**
 * \file listnode.h
 * \brief Contains declaration of linked list node structure.
 */

#ifndef LISTNODE_H_INCLUDED_
#define LISTNODE_H_INCLUDED_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


/**
 * \brief Doubly-linked list node.
 */
typedef struct list_node {
  /* List node data. */
  void *data;

  /* Pointer to the next list node. */
  struct list_node *next;

  /* Pointer to the next list node. */
  struct list_node *prev;
} list_node_t;


/**
 * \brief Create new list node.
 * 
 * \param data: data of the created node.
 * 
 * \returns Pointer to created node.
 */
list_node_t *list_node__create(void *data);

/**
 * \brief Frees list node.
 * 
 * \param node: node to free.
 */
void list_node__free(list_node_t *node);


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* LISTNODE_H_INCLUDED_ */
