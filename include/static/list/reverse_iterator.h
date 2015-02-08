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

/**
 * Creates a new ListReverseIterator for the List provided.
 *
 * The iterator is set to start at the element specified by index. Since this 
 * iterator traverses from back to front, 0 refers to the last element in the
 * List, 1 to the second to last element in the List, and so on. Negative
 * indices are interpreted as counting forward direction; -1 is the first
 * element in the list, -2 is the second element, and so on.
 *
 * The function truncates index to be less than the size of the list before
 * beginning the traversal, thus there is no need to do so before calling the
 * function.
 *
 * @param list the List the iterator is for
 * @param index the index the iterator will start at
 *
 * @return the new ListReverseIterator
 */
static
ListReverseIterator *
NewListReverseIterator
( List *list, int index );

#endif
