#ifndef __WOODPILE_PRIVATE_DYNAMIC_LIST_CONST_ITERATOR_H
#define __WOODPILE_PRIVATE_DYNAMIC_LIST_CONST_ITERATOR_H

/**
 * @file
 * ListConstIterator definition
 */

#include "private/dynamic/list.h"

/** the ListConstIterator structure */
struct DynamicListConstIterator {
  const node_t *current; /**< the current value of the iterator */
  const node_t *previous; /**< the previous value of the iterator */
};

#endif
