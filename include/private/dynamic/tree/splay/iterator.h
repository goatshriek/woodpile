#ifndef __WOODPILE_PRIVATE_DYNAMIC_TREE_SPLAY_ITERATOR_H
#define __WOODPILE_PRIVATE_DYNAMIC_TREE_SPLAY_ITERATOR_H

/**
 * @file
 * DynamicSplayIterator definition
 */

#include "private/dynamic/tree/splay.h"

/** the DynamicSplayIterator structure */
struct DynamicSplayIterator {
  DSplay *splay; /**< the splay this iterator is for */
  Node *current; /**< the iterator's current position */
  Node *previous; /**< the iterator's previous position */
  /**
   * direction the iterator last went in
   *  0 - no calls to DSPlayItrNext or DSplayItrPrevious since the last call to
   *      AddToListIterator or RemoveFromListIterator
   *  1 - last call was to DSplayItrNext
   *  2 - last call was to DSPlayItrPrevious
   */
  unsigned short direction;
};

#endif
