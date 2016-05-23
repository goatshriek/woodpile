#ifndef __WOODPILE_DYNAMIC_LIST_ITERATOR_H
#define __WOODPILE_DYNAMIC_LIST_ITERATOR_H

/**
 * @file
 * DynamicListIterator declaration and functions
 */

#include <woodpile/dynamic/list.h>

/**
 * @struct DynamicListIterator
 * The DynamicListIterator provides a simple iterator for a DynamicList
 * structure. The list may also have elements added to and/or removed from it
 * while being iterated through.
 *
 * This iterator is bidirectional; that is, it can iterate through the list in
 * either a forward or backward direction but does not support random access.
 *
 * Unless addition or removal needs to be performed, it is recommended to use
 * a DynamicListConstIterator instead. This structure has several advantages
 * over it's non-const analog:
 *  + less memory overhead
 *  + enforces const-correctness
 *  + slightly faster
 *
 * Memory overhead can be calculated as follows:
 * ( sizeof( void * ) * 3 ) + sizeof( unsigned short )
 */
struct dlist_itr_t;
typedef struct dlist_itr_t dlist_itr_t;

/**
 * Inserts the specified element into the list. The element is inserted
 * immediately before the element that would be returned by a call to
 * NextInDynamicListIterator (if any), and after the element that would be
 * returned by a call to PreviousInDynamicListIterator (if any). A NULL element
 * is ignored.
 *
 * After a call to this function, the position of iterator will be directly
 * after the added element. That is, a call to PreviousInDynamicListIterator
 * would return element, and a call to NextInDynamicListIterator would return
 * the same element as it would have before a call to this function.
 *
 * @param iterator the DynamicListIterator to add to
 * @param element the element to insert into the DynamicList
 *
 * @return the DynamicListIterator the element was added to
 */
dlist_itr_t *
DListItrAdd
( dlist_itr_t *iterator, void *element );

/**
 * Creates a new DynamicListIterator for the DynamicList provided. The iterator
 * will begin at the beginning of the DynamicList.
 *
 * @param list the DynamicList to get an iterator for. Must not be NULL.
 *
 * @return a DynamicListIterator for the provided DynamicList. If list is NULL
 * or invalid then NULL is returned.
 */
dlist_itr_t *
DListBegin
( dlist_t *list );

/**
 * Creates a copy of a DynamicListIterator. The position of the copy will be the
 * same as the original at the time of the copy.
 *
 * @param iterator the DynamicListIterator to copy. Must not be NULL.
 *
 * @return a copy of the original DynamicListIterator
 */
dlist_itr_t *
DListItrCopy
( const dlist_itr_t *iterator );

/**
 * Destroys a DynamicListIterator and releases its memory. This function does
 * not destroy the DynamicList associated with the iterator.
 *
 * @param iterator the DynamicListIterator to destroy
 */
void
DListItrDestroy
( dlist_itr_t *iterator );

/**
 * Creates a new DynamicListIterator for the DynamicList provided. The iterator
 * will begin at the end of list. This means that attempting to get the next
 * element of the iterator will return NULL, while previous will return the last
 * element of the DynamicList and advance the iterator pointer backwards one step.
 *
 * @param list the DynamicList to get an iterator for. Must not be NULL.
 *
 * @return a DynamicListIterator for list. If list is NULL or invalid then NULL
 * is returned.
 */
dlist_itr_t *
DListEnd
( dlist_t *list );

/**
 * Checks to see if a DynamicListIterator has a next value.
 *
 * @param iterator the iterator to check for a next value
 *
 * @return a positive value if a next value exists, and a 0 if not.
 */
unsigned short
DListItrHasNext
( const dlist_itr_t *iterator );

/**
 * Checks to see if a DynamicListIterator has a previous value.
 *
 * @param iterator the iterator to check for a previous value
 *
 * @return a positive value if a previous value exists, and a 0 if not.
 */
unsigned short
DListItrHasPrevious
( const dlist_itr_t *iterator );

/**
 * Gets the next value in the DynamicListIterator. If the DynamicListIterator
 * does not have any more values (it is at the end of the list) then NULL is
 * returned. The current index of the iterator is advanced forward by one as a
 * result of this function call.
 *
 * @param iterator the iterator to retrieve the next value of. Must not be NULL.
 *
 * @return the next value of the iterator, or NULL if there is not one
 */
void *
DListItrNext
( dlist_itr_t *iterator );

/**
 * Gets the previous value in the DynamicListIterator. If iterator does not have
 * any previous values (it is at the beginning of the list) then NULL is
 * returned. The current index of the iterator is advanced backwards by one as a
 * result of this function call.
 *
 * @param iterator the iterator to retrieve the previous value of. Must not be
 * NULL.
 *
 * @return the previous value of the iterator, or NULL if there is not one
 */
void *
DListItrPrevious
( dlist_itr_t *iterator );

/**
 * Removes from the list the last element returned by either
 * NextInDynamicListIterator or PreviousInDynamicListIterator. This can only be
 * done once per call to either function, and only if a call to
 * AddToDynamicListIterator has not been made since then.
 *
 * @param iterator the DynamicListIterator to remove the value from. Must not be
 * NULL.
 *
 * @return the element removed
 */
void *
DListItrRemove
( dlist_itr_t *iterator );

#endif
