#ifndef __WOODPILE_LIST_ITERATOR_H
#define __WOODPILE_LIST_ITERATOR_H

/**
 * @file
 * Declaration and functions for the ListIterator structure.
 */

#include <woodpile/list.h>

/**
 * The ListIterator provides a simple iterator for a List structure.
 *
 * Memory overhead can be calculated as follows:
 * sizeof( void * ) * 3
 */
struct ListIterator;
typedef struct ListIteratore ListIterator;

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

ListIterator *
CopyListIterator
( const ListIterator * );

void
DestroyListIterator
( ListIterator * );

ListIterator *
EndList
( List * );

unsigned short
ListIteratorHasNext
( const ListIterator * );

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

void *
NextInListIterator
( ListIterator * );

void *
PreviousInListIterator
( ListIterator * );

#endif
