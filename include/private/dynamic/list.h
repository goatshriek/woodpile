#ifndef __WOODPILE_PRIVATE_DYNAMIC_LIST_H
#define __WOODPILE_PRIVATE_DYNAMIC_LIST_H

/**
 * @file
 * List definition
 */

#include <stdint.h>

struct node_t;
typedef struct node_t node_t;

/** a helper macro to XOR two node pointers together */
#define XORNODES( first, second )                                              \
( ( node_t * ) ( ( ( intptr_t ) ( first ) ) ^ ( ( intptr_t ) ( second ) ) ) )

/** the List container */
struct dlist_t {
  node_t *first; /**< the first Node in the list */
  node_t *last; /**< the last Node in the list */
};

/**
 * A node in the List, representing a single value.
 *
 * The List implementation uses an XOR approach to conserver memory, and thus
 * a node only has one node pointer, which holds the XOR of this node's
 * neighbors.
 */
struct node_t {
  node_t *neighbors; /**< the XOR of this Node's neighbors */
  void *element; /**< the element held by the Node */
};

#endif
