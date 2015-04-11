#ifndef __WOODPILE_STATIC_LIST_CONST_ITERATOR_H
#define __WOODPILE_STATIC_LIST_CONST_ITERATOR_H

/**
 * @file
 * ListConstIterator definition
 */

#include <woodpile/list.h>

#include "static/list.h"

/** the ListConstIterator structure */
struct ListConstIterator {
  const Node *current; /**< the current value of the iterator */
  const Node *previous; /**< the previous value of the iterator */
};

#endif
