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
 * Linked list node.
 */
typedef struct list_node {
  /* Pointer to node data. */
  void *data;

  /* Pointer to the next list node. */
  struct list_node *next;
} list_node_t;


/**
 * Create new linked list node and return pointer to it.
 */
list_node_t *createNode(void *data);

/**
 * Frees linked list node and returns its next node.
 */
list_node_t *freeNode(list_node_t *node);


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* LISTNODE_H_INCLUDED_ */
