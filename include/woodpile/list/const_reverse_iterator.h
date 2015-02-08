#ifndef __WOODPILE_LIST_CONST_REVERSE_ITERATOR_H
#define __WOODPILE_LIST_CONST_REVERSE_ITERATOR_H

/**
 * @file
 * Declaration and functions for the ListConstReverseIterator structure.
 */

#include <woodpile/list.h>

/**
 * The ListConstReverseIterator provides an iterator for the List structure that
 * traverses the list from the back to front. The iterator is guaranteed not to
 * change the order or composition of the List, or any of the elements the List
 * contains.
 *
 * Memory overhead can be calculated as follows:
 * sizeof( void * ) * 3
 */
struct ListConstReverseIterator;
typedef struct ListConstReverseIterator ListConstReverseIterator;

ListConstReverseIterator *
CopyListConstReverseIterator
( const ListConstReverseIterator * );

ListConstReverseIterator *
CRBeginList
( const List * );

ListConstReverseIterator *
CREndList
( const List * );

void
DestroyListConstReverseIterator
( ListConstReverseIterator * );

unsigned short
ListConstReverseIteratorHasNext
( const ListConstReverseIterator * );

const void *
NextInListConstReverseIterator
( ListConstReverseIterator * );

#endif
