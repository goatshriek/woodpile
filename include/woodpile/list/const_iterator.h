#ifndef __WOODPILE_LIST_CONST_ITERATOR_H
#define __WOODPILE_LIST_CONST_ITERATOR_H

/**
 * @file
 * Declaration and functions for the ListConstIterator structure.
 */

#include <woodpile/list.h>

/**
 * The ListConstIterator provides a simple iterator for a List structure that
 * is guaranteed not to change the order or composition of the List, or any of
 * the elements the List contains.
 *
 * This iterator is bidirectional; that is, it can iterate through the list in
 * either a forward or backward direction but does not support random acccess.
 *
 * Memory overhead can be calculated as follows:
 * sizeof( void * ) * 3
 */
struct ListConstIterator;
typedef struct ListConstIterator ListConstIterator;

/**
 * Creates a new ListConstIterator for the List provided. The iterator will
 * begin at the beginning of the List.
 *
 * @param list the List to get an iterator for
 *
 * @return a ListConstIterator for the provided List. If list is NULL or invalid
 * then NULL is returned.
 */
ListConstIterator *
CBeginList
( const List *list );

/**
 * Creates a new ListConstIterator for the List provided. The iterator will
 * begin at the end of the List. This means that attempting to get the next
 * element of the iterator will return NULL, while previous will return the
 * last element of the List and advance the iterator pointer backwards one step.
 *
 * @param list the List to get an iterator for
 *
 * @return a ListConstIterator for the provided List. If list is NULL or invalid
 * then NULL is returned.
 */
ListConstIterator *
CEndList
( const List *list );

/**
 * Creates a copy of a ListConstIterator. The position of the copy will be the
 * same as the original at the time of the copy.
 *
 * @param original the ListConstIterator to copy
 *
 * @return a copy of the original ListConstIterator
 */
ListConstIterator *
CopyListConstIterator
( const ListConstIterator *iterator );

/**
 * Destroys a ListConstIterator and releases its memory. This function does not
 * destroy the List associated with the iterator.
 *
 * @param iterator the ListIterator to destroy
 */
void
DestroyListConstIterator
( ListConstIterator *iterator );

/**
 * Checks to see if a ListConstIterator has a next value.
 *
 * @param iterator the iterator to check for a next value
 *
 * @return a positive value if a next value exists, and a 0 if not.
 */
unsigned short
ListConstIteratorHasNext
( const ListConstIterator *iterator );

/**
 * Gets the next value in the ListConstIterator. If the ListConstIterator does
 * not have any more values (it is at the end of the list) then NULL is
 * returned. The current index of the iterator is advanced forward by one as a
 * result of this function call.
 *
 * @param iterator the iterator to retrieve the next value of
 *
 * @return the next value of the iterator, or NULL if there is not one
 */
const void *
NextInListConstIterator
( ListConstIterator *iterator );

#endif
