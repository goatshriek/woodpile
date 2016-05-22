#ifndef __WOODPILE_DYNAMIC_LIST_CONST_ITERATOR_H
#define __WOODPILE_DYNAMIC_LIST_CONST_ITERATOR_H

/**
 * @file
 * DynamicListConstIterator declaration and functions
 */

#include <woodpile/dynamic/list.h>

/**
 * @struct DynamicListConstIterator
 * The DynamicListConstIterator provides a simple iterator for a DynamicList
 * structure that is guaranteed not to change the order or composition of the
 * DynamicList, or any of the elements the DynamicList contains.
 *
 * This iterator is bidirectional; that is, it can iterate through the list in
 * either a forward or backward direction but does not support random acccess.
 *
 * Memory overhead can be calculated as follows:
 * sizeof( void * ) * 2
 */
struct DynamicListConstIterator;
typedef struct DynamicListConstIterator DynamicListConstIterator;
typedef struct DynamicListConstIterator DListCItr;

/**
 * Creates a new DynamicListConstIterator for the DynamicList provided. The
 * iterator will begin at the beginning of the DynamicList.
 *
 * @param list the DynamicList to get an iterator for. Must not be NULL.
 *
 * @return a DynamicListConstIterator for the provided DynamicList. If list is
 * NULL or invalid then NULL is returned.
 */
DynamicListConstIterator *
CBeginDynamicList
( const dlist_t *list );
#define DListCBegin CBeginDynamicList

/**
 * Creates a new DynamicListConstIterator for the DynamicList provided. The
 * iterator will begin at the end of list. This means that attempting to get the
 * next element of the iterator will return NULL, while previous will return the
 * last element of the DynamicList and advance the iterator pointer backwards
 * one element.
 *
 * @param list the DynamicList to get an iterator for. Must not be NULL.
 *
 * @return a DynamicListConstIterator for the provided DynamicList. If list is
 * NULL or invalid then NULL is returned.
 */
DynamicListConstIterator *
CEndDynamicList
( const dlist_t *list );
#define DListCEnd CEndDynamicList

/**
 * Creates a copy of a DynamicListConstIterator. The position of the copy will
 * be the same as the original at the time of the copy.
 *
 * @param iterator the DynamicListConstIterator to copy. Must not be NULL.
 *
 * @return a copy of the original DynamicListConstIterator
 */
DynamicListConstIterator *
CopyDynamicListConstIterator
( const DynamicListConstIterator *iterator );
#define DListCItrCopy CopyDynamicListConstIterator

/**
 * Destroys a DynamicListConstIterator and releases its memory. This function
 * does not destroy the DynamicList associated with the iterator.
 *
 * @param iterator the DynamicListIterator to destroy
 */
void
DestroyDynamicListConstIterator
( const DynamicListConstIterator *iterator );
#define DListCItrDestroy DestroyDynamicListConstIterator

/**
 * Checks to see if a DynamicListConstIterator has a next value.
 *
 * @param iterator the iterator to check for a next value
 *
 * @return a positive value if a next value exists, and a 0 if not.
 */
unsigned short
DynamicListConstIteratorHasNext
( const DynamicListConstIterator *iterator );
#define DListCItrHasNext DynamicListConstIteratorHasNext

/**
 * Checks to see if a DynamicListConstIterator has a previous value.
 *
 * @param iterator the iterator to check for a previous value
 *
 * @return a positive value if a previous value exists, and a 0 if not.
 */
unsigned short
DynamicListConstIteratorHasPrevious
( const DynamicListConstIterator *iterator );
#define DListCItrHasPrevious DynamicListConstIteratorHasPrevious

/**
 * Gets the next value in the DynamicListConstIterator. If iterator does
 * not have any more values (it is at the end of the DynamicList) then NULL is
 * returned. The current index of the iterator is advanced forward by one as a
 * result of this function call.
 *
 * @param iterator the iterator to retrieve the next value of. Must not be NULL.
 *
 * @return the next value of the iterator, or NULL if there is not one
 */
const void *
NextInDynamicListConstIterator
( DynamicListConstIterator *iterator );
#define DListCItrNext NextInDynamicListConstIterator

/**
 * Gets the previous value in the DynamicListConstIterator. If iterator does
 * not have any previous values (it is at the beginning of the DynamicList) then
 * NULL is returned. The current index of the iterator is advanced backward by
 * one as a result of this function call.
 *
 * @param iterator the iterator to retrieve the previous value of. Must not be
 * NULL.
 *
 * @return the previous value of the iterator, or NULL if there is not one
 */
const void *
PreviousInDynamicListConstIterator
( DynamicListConstIterator *iterator );
#define DListCItrPrevious PreviousInDynamicListConstIterator

#endif
