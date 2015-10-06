#ifndef __WOODPILE_PRIVATE_DYNAMIC_TREE_SPLAY_CONST_ITERATOR_H
#define __WOODPILE_PRIVATE_DYNAMIC_TREE_SPLAY_CONST_ITERATOR_H

/**
 * @file
 * DynamicSplayConstIterator definition
 */

#include "private/dynamic/tree/splay.h"

/** the DynamicSplayConstIterator structure */
struct DynamicSplayConstIterator {
  const Node *current; /**< the current node of the iterator */
  const Node *previous; /**< the previous node of the iterator */
};

#endif
