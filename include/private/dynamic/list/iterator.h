#ifndef __WOODPILE_PRIVATE_DYNAMIC_LIST_ITERATOR_H
#define __WOODPILE_PRIVATE_DYNAMIC_LIST_ITERATOR_H

/**
 * @file
 * ListIterator definition
 */

#include "private/dynamic/list.h"

/** the dlist_itr_t structure */
struct dlist_itr_t {
  dlist_t *list; /**< the List this iterator is for */
  node_t *current; /**< the current value of the iterator */
  node_t *previous; /**< the previous value of the iterator */
  /**
   * direction the iterator last went in
   *  0 - no calls to NextInListIterator or PreviousInListIterator since the
   *      last call to AddToListIterator or RemoveFromListIterator
   *  1 - last call was to NextInListIterator
   *  2 - last call was to PreviousInListIterator
   */
  unsigned short direction;
};

#endif
