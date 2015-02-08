#ifndef __WOODPILE_STATIC_LIST_H
#define __WOODPILE_STATIC_LIST_H

#include <stdint.h>
#include <woodpile/list.h>


/** a helper macro to XOR two Node pointers together */
#define XORNODES( first, second )                                              \
( ( Node * ) ( ( ( intptr_t ) ( first ) ) ^ ( ( intptr_t ) ( second ) ) ) )

/** the List container */
struct List {
  Node * first; /**< the first Node in the list */
  Node * last; /**< the last Node in the list */
};

/**
 * A node in the List, representing a single value.
 *
 * The List implementation uses an XOR approach to conserver memory, and thus
 * a Node only has one Node pointer, which holds the XOR of this Node's
 * neighbors.
 */
struct Node {
  Node *neighbors; /**< the XOR of this Node's neighbors */
  void *value; /**< the value held by the Node */
};
typedef struct Node Node;

static
void
DestroyNodes
( Node *, Node * );

static
void *
SeparateNodes
( Node *, Node *, void * );

#endif
