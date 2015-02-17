#ifndef __WOODPILE_LIST_ITERATOR_H
#define __WOODPILE_LIST_ITERATOR_H

/**
 * @file
 * Declaration and functions for the ListIterator structure.
 */

#include <woodpile/list.h>

/**
 * The ListIterator provides a simple iterator for a List structure. The list
 * may also have elements added to and/or removed from it while being iterated
 * through.
 *
 * This iterator is bidirectional; that is, it can iterate through the list in
 * either a forward or backward direction but does not support random access.
 *
 * Memory overhead can be calculated as follows:
 * sizeof( void * ) * 3
 */
struct ListIterator;
typedef struct ListIteratore ListIterator;

/**
 * Inserts the specified element into the list. The element is inserted
 * immediately before the element that would be returned by a call to
 * NextInListIterator (if any), and after the element that would be returned by
 * a call to PreviousInListIterator (if any). A NULL element will be ignored.
 *
 * @param iterator the ListIterator to add to
 * @param element the element to insert into the List
 *
 * @return the ListIterator the element was added to
 */
ListIterator *
AddToListIterator
( ListIterator *iterator, void *element );

/**
 * Creates a new ListIterator for the List provided. The iterator will begin at
 * the beginning of the List.
 *
 * @param list the List to get an iterator for
 *
 * @return a ListIterator for the provided List. If list is NULL or invalid then
 * NULL is returned.
 */
ListIterator *
BeginList
( List *list );

/**
 * Creates a copy of a ListIterator. The position of the copy will be the same
 * as the original at the time of the copy.
 *
 * @param original the ListIterator to copy
 *
 * @return a copy of the original ListIterator
 */
ListIterator *
CopyListIterator
( const ListIterator *original );

/**
 * Destroys a ListIterator and releases its memory. This function does not
 * destroy the List associated with the iterator.
 *
 * @param iterator the ListIterator to destroy
 */
void
DestroyListIterator
( ListIterator *iterator );

/**
 * Creates a new ListIterator for the List provided. The iterator will begin at
 * the end of the List. This means that attempting to get the next element of
 * the iterator will return NULL, while previous will return the last element
 * of the List and advance the iterator pointer backwards one step.
 *
 * @param list the List to get an iterator for
 *
 * @return a ListIterator for the provided List. If list is NULL or invalid then
 * NULL is returned.
 */
ListIterator *
EndList
( List *list );

/**
 * Checks to see if a ListIterator has a next value.
 *
 * @param iterator the iterator to check for a next value
 *
 * @return a positive value if a next value exists, and a 0 if not.
 */
unsigned short
ListIteratorHasNext
( const ListIterator *iterator );

/**
 * Checks to see if a ListIterator has a previous value.
 *
 * @param iterator the iterator to check for a previous value
 *
 * @return a positive value if a previous value exists, and a 0 if not.
 */
unsigned short
ListIteratorHasPrevious
( const ListIterator *iterator );

/**
 * Gets the next value in the ListIterator. If the ListIterator does not have
 * any more values (it is at the end of the list) then NULL is returned. The
 * current index of the iterator is advanced forward by one as a result of this
 * function call.
 *
 * @param iterator the iterator to retrieve the next value of
 *
 * @return the next value of the iterator, or NULL if there is not one
 */
void *
NextInListIterator
( ListIterator *iterator );

/**
 * Gets the previous value in the ListIterator. If the ListIterator does not have
 * any previous values (it is at the beginning of the list) then NULL is
 * returned. The current index of the iterator is advanced backwards by one as a
 * result of this function call.
 *
 * @param iterator the iterator to retrieve the previous value of
 *
 * @return the previous value of the iterator, or NULL if there is not one
 */
void *
PreviousInListIterator
( ListIterator *iterator );

/**
 * Removes from the list the last element returned by either NextInListIterator
 * or PreviousInListIterator. This can only be done once per call to either
 * function, and only if a call to AddToListIterator has not been made since
 * then.
 *
 * @param iterator the ListIterator to remove the value from
 *
 * @return the element removed
 */
void *
ListIterator *
RemoveFromListIterator
( ListIterator *iterator );

#endif
