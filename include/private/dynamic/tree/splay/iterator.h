#ifndef __WOODPILE_PRIVATE_DYNAMIC_TREE_SPLAY_ITERATOR_H
#define __WOODPILE_PRIVATE_DYNAMIC_TREE_SPLAY_ITERATOR_H

/**
 * @file
 * DynamicSplayIterator definition
 */

#include "private/dynamic/tree/splay.h"

/** the dsplay_itr_t structure */
struct dsplay_itr_t {
  dsplay_t *splay; /**< the splay this iterator is for */
  node_t *current; /**< the iterator's current position */
  node_t *previous; /**< the iterator's previous position */
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
