#ifndef __WOODPILE_DYNAMIC_TREE_SPLAY_CONST_ITERATOR_H
#define __WOODPILE_DYNAMIC_TREE_SPLAY_CONST_ITERATOR_H

/**
 * @file
 * DynamicSplayConstIterator declaration and functions
 */

#include <woodpile/dynamic/tree/splay.h>

/**
 * @struct DynamicSplayConstIterator
 * The DynamicSplayConstIterator provides a simple iterator for a DynamicSplay
 * structure that is guaranteed not to change the order or composition of the
 * DynamicSplay, or any of the elements the DynamicSplay contains.
 *
 * This iterator is bidirectional; that is, it can iterate through the splay in
 * either a forward or backward direction but does not support random acccess.
 *
 * Memory overhead can be calculated as follows:
 * sizeof( void * ) * 2
 */
struct DynamicSplayConstIterator;
typedef struct DynamicSplayConstIterator DSplayCItr;

/**
 * Creates a new DynamicSplayConstIterator for the DynamicSplay provided. The
 * iterator will begin at the beginning of the DynamicSplay.
 *
 * @param splay the DynamicSplay to get an iterator for
 *
 * @return a DynamicSplayConstIterator for the provided DynamicSplay. If splay
 * is NULL or invalid then NULL is returned.
 */
DSplayCItr *
CBeginDynamicSplay
( const DSplay *splay );
#define DSplayCBegin CBeginDynamicSplay

/**
 * Creates a new DynamicSplayConstIterator for the DynamicSplay provided. The
 * iterator will begin at the end of splay. This means that attempting to get the
 * next element of the iterator will return NULL, while previous will return the
 * last element of the DynamicSplay and advance the iterator pointer backwards
 * one element.
 *
 * @param splay the DynamicSplay to get an iterator for
 *
 * @return a DynamicSplayConstIterator for the provided DynamicSplay. If splay
 * is NULL or invalid then NULL is returned.
 */
DSplayCItr *
CEndDynamicSplay
( const DSplay *splay );
#define DSplayCEnd CEndDynamicSplay

/**
 * Creates a copy of a DynamicSplayConstIterator. The position of the copy will
 * be the same as the original at the time of the copy.
 *
 * @param iterator the DynamicSplayConstIterator to copy
 *
 * @return a copy of the original DynamicSplayConstIterator
 */
DSplayCItr *
CopyDynamicSplayConstIterator
( const DSplayCItr *iterator );
#define DSplayCItrCopy CopyDynamicSplayConstIterator

/**
 * Destroys a DynamicSplayConstIterator and releases its memory. This function
 * does not destroy the DynamicSplay associated with the iterator.
 *
 * @param iterator the DynamicSplayIterator to destroy
 */
void
DestroyDynamicSplayConstIterator
( const DSplayCItr *iterator );
#define DSplayCItrDestroy DestroyDynamicSplayConstIterator

/**
 * Checks to see if a DynamicSplayConstIterator has a next value.
 *
 * @param iterator the iterator to check for a next value
 *
 * @return a positive value if a next value exists, and a 0 if not.
 */
unsigned short
DynamicSplayConstIteratorHasNext
( const DSplayCItr *iterator );
#define DSplayCItrHasNext DynamicSplayConstIteratorHasNext

/**
 * Checks to see if a DynamicSplayConstIterator has a previous value.
 *
 * @param iterator the iterator to check for a previous value
 *
 * @return a positive value if a previous value exists, and a 0 if not.
 */
unsigned short
DynamicSplayConstIteratorHasPrevious
( const DSplayCItr *iterator );
#define DSplayCItrHasPrevious DynamicSplayConstIteratorHasPrevious

/**
 * Gets the next value in the DynamicSplayConstIterator. If iterator does
 * not have any more values (it is at the end of the DynamicSplay) then NULL is
 * returned. The current index of the iterator is advanced forward by one as a
 * result of this function call.
 *
 * @param iterator the iterator to retrieve the next value of
 *
 * @return the next value of the iterator, or NULL if there is not one
 */
const void *
NextInDynamicSplayConstIterator
( DSplayCItr *iterator );
#define DSplayCItrNext NextInDynamicSplayConstIterator

/**
 * Gets the previous value in the DynamicSplayConstIterator. If iterator does
 * not have any previous values (it is at the beginning of the DynamicSplay) then
 * NULL is returned. The current index of the iterator is advanced backward by
 * one as a result of this function call.
 *
 * @param iterator the iterator to retrieve the previous value of
 *
 * @return the previous value of the iterator, or NULL if there is not one
 */
const void *
PreviousInDynamicSplayConstIterator
( DSplayCItr *iterator );
#define DSplayCItrPrevious PreviousInDynamicSplayConstIterator

#endif
