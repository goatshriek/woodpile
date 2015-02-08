#ifndef __WOODPILE_STATIC_LIST_CONST_REVERSE_ITERATOR_H
#define __WOODPILE_STATIC_LIST_CONST_REVERSE_ITERATOR_H

/**
 * @file
 * The definition of the ListConstReverseIterator structure.
 */

#include <woodpile/list.h>

/** the ListConstReverseIterator structure */
struct ListConstReverseIterator {
  Node *current; /**< the current value of the iterator */
  const List *list; /**< the List the iterator is for */
  Node *previous; /**< the previous value of the iterator */
};

#endif
