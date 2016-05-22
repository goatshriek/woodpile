#ifndef __WOODPILE_PRIVATE_DYNAMIC_TREE_SPLAY_CONST_ITERATOR_H
#define __WOODPILE_PRIVATE_DYNAMIC_TREE_SPLAY_CONST_ITERATOR_H

/**
 * @file
 * DynamicSplayConstIterator definition
 */

#include "private/dynamic/tree/splay.h"

/** the DynamicSplayConstIterator structure */
struct DynamicSplayConstIterator {
  const node_t *current; /**< the current node of the iterator */
  const node_t *previous; /**< the previous node of the iterator */
};

#endif
