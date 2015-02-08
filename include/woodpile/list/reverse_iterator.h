#ifndef __WOODPILE_LIST_REVERSE_ITERATOR_H
#define __WOODPILE_LIST_REVERSE_ITERATOR_H

/**
 * @file
 * Declaration and functions for the ListReverseIterator structure.
 */

#include <woodpile/list.h>

/**
 * The ListReverseIterator provides an iterator for the List structure that
 * traverses the List from back to front.
 *
 * Memory overhead can be calculated as follows:
 * sizeof( void * ) * 3
 */
struct ListReverseIterator;
typedef struct ListReverseIterator ListReverseIterator;

ListReverseIterator *
CopyListReverseIterator
( const ListReverseIterator * );

void
DestroyListReverseIterator
( ListReverseIterator * );

unsigned short
ListReverseIteratorHasNext
( const ListReverseIterator * );

/**
 * Checks to see if a ListReverseIterator has a previous value.
 *
 * @param iterator the iterator to check for a previous value
 *
 * @return a positive value if a previous value exists, and a 0 if not
 */
unsigned short
ListReverseIteratorHasPrevious
( const ListReverseIterator *iterator );

void *
NextInListReverseIterator
( ListReverseIterator * );

void *
PreviousInListReverseIterator
( ListReverseIterator *);

ListReverseIterator *
RBeginList
( List * );

ListReverseIterator *
REndList
( List * );

#endif
