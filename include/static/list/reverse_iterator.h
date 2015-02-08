#ifndef __WOODPILE_STATIC_LIST_REVERSE_ITERATOR_H
#define __WOODPILE_STATIC_LIST_REVERSE_ITERATOR_H

/**
 * @file
 * The definition of the ListReverseIterator structure.
 */

#include <woodpile/list.h>

/** the ListReverseIterator structure */
struct ListReverseIterator {
  Node *current; /**< the current value of the iterator */
  List *list; /**< the List the iterator is for */
  Node *previous; /**< the previous value of the iterator */
};

#endif
