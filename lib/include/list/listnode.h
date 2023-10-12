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
 * \brief Linked list node.
 */
typedef struct list_node {
  /* Pointer to node data. */
  void *data;

  /* Pointer to the next list node. */
  struct list_node *next;
} list_node_t;


/**
 * \brief Create new linked list node.
 * 
 * \param data: data of the created node.
 * 
 * \returns Pointer to created node.
 */
list_node_t *list_node__create(void *data);

/**
 * \brief Frees linked list node.
 * 
 * \param node: node to free.
 * 
 * \returns Pointer to node next to the freed.
 */
list_node_t *list_node__free(list_node_t *node);


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* LISTNODE_H_INCLUDED_ */
