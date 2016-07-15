#ifndef __WOODPILE_DYNAMIC_TREE_SPLAY_ITERATOR_H
#define __WOODPILE_DYNAMIC_TREE_SPLAY_ITERATOR_H

/**
 * @file
 * DynamicSplayIterator declaration and functions
 */

#include <woodpile/dynamic/tree/splay.h>

/**
 * @struct dsplay_itr_t
 * The DynamicSplayIterator provides a simple iterator for a DynamicSplay
 * structure. The splay may also have elements added to and/or removed from it
 * while being iterated through.
 *
 * This iterator is bidirectional; that is, it can iterate through the splay in
 * either a forward or backward direction but does not support random access.
 *
 * Unless addition or removal needs to be performed, it is recommended to use
 * a DynamicSplayConstIterator instead. This structure has several advantages
 * over it's non-const analog:
 *  + less memory overhead
 *  + enforces const-correctness
 *  + slightly faster
 *
 * Memory overhead can be calculated as follows:
 * ( sizeof( void * ) * 3 ) + sizeof( unsigned short )
 */
struct dsplay_itr_t;
typedef struct dsplay_itr_t dsplay_itr_t;

/**
 * Creates a new DynamicSplayIterator for the DynamicSplay provided. The
 * iterator will begin at the beginning of the DynamicSplay.
 *
 * @param splay the DynamicSplay to get an iterator for. Must not be NULL.
 *
 * @return a DynamicSplayIterator for the provided DynamicSplay. If splay is NULL
 * or invalid then NULL is returned.
 */
dsplay_itr_t *
DSplayBegin
( dsplay_t *splay );

/**
 * Creates a copy of a DynamicSplayIterator. The position of the copy will be
 * the same as the original at the time of the copy.
 *
 * @param iterator the DynamicSplayIterator to copy. Must not be NULL.
 *
 * @return a copy of the original DynamicSplayIterator
 */
dsplay_itr_t *
DSplayItrCopy
( const dsplay_itr_t *iterator );

/**
 * Destroys a DynamicSplayIterator and releases its memory. This function does
 * not destroy the DynamicSplay associated with the iterator.
 *
 * @param iterator the DynamicSplayIterator to destroy
 */
void
DSplayItrDestroy
( dsplay_itr_t *iterator );

/**
 * Creates a new DynamicSplayIterator for the DynamicSplay provided. The
 * iterator will begin at the end of splay. This means that attempting to get
 * the next element of the iterator will return NULL, while previous will return
 * the last element of the DynamicSplay and advance the iterator pointer
 * backwards one step.
 *
 * @param splay the DynamicSplay to get an iterator for. Must not be NULL.
 *
 * @return a DynamicSplayIterator for splay. If splay is NULL or invalid then
 * NULL is returned.
 */
dsplay_itr_t *
DSplayEnd
( dsplay_t *splay );

/**
 * Checks to see if a DSplayIterator has a next value.
 *
 * @param iterator the iterator to check for a next value
 *
 * @return a positive value if a next value exists, and a 0 if not.
 */
unsigned short
DSplayItrHasNext
( const dsplay_itr_t *iterator );

/**
 * Checks to see if a DynamicSplayIterator has a previous value.
 *
 * @param iterator the iterator to check for a previous value
 *
 * @return a positive value if a previous value exists, and a 0 if not.
 */
unsigned short
DSplayItrHasPrevious
( const dsplay_itr_t *iterator );

/**
 * Gets the next value in the DynamicSplayIterator. If the DynamicSplayIterator
 * does not have any more values (it is at the end of the splay) then NULL is
 * returned. The current index of the iterator is advanced forward by one as a
 * result of this function call.
 *
 * @param iterator the iterator to retrieve the next value of. Must not be NULL.
 *
 * @return the next value of the iterator, or NULL if there is not one
 */
void *
DSplayItrNext
( dsplay_itr_t *iterator );

/**
 * Gets the previous value in the DynamicSplayIterator. If iterator does not
 * have any previous values (it is at the beginning of the splay) then NULL is
 * returned. The current index of the iterator is advanced backwards by one as a
 * result of this function call.
 *
 * @param iterator the iterator to retrieve the previous value of. Must not be
 * NULL.
 *
 * @return the previous value of the iterator, or NULL if there is not one
 */
void *
DSplayItrPrevious
( dsplay_itr_t *iterator );

/**
 * Removes from the splay the last element returned by either
 * NextInDynamicSplayIterator or PreviousInDynamicSplayIterator. This can only
 * be done once per call to either function. An element close to the removed
 * element is splayed to the root of the tree after removal.
 *
 * @param iterator the DynamicSplayIterator to remove the value from. Must not
 * be NULL.
 *
 * @return the element removed
 */
void *
DSplayItrRemove
( dsplay_itr_t *iterator );

#endif
