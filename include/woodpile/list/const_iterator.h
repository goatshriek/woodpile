#ifndef __WDOOPILE_LIST_CONST_ITERATOR_H
#define __WOODPILE_LIST_CONST_ITERATOR_H

/**
 * @file
 * Declaration and functions for the ListConstIterator iterator.
 */

#include <woodpile/list.h>

/**
 * The ListConstIterator provides a simple iterator for a List structure.
 *
 * Memory overhead can be calculated as follows:
 * 
 */
struct ListConstIterator;
typedef struct ListConstIterator ListConstIterator;

ListConstIterator *
CBeginList
( const List * );

ListConstIterator *
CEndList
( const List * );

ListConstIterator *
CopyListConstIterator
( const ListConstIterator * );

void
DestroyListConstIterator
( ListConstIterator * );

unsigned short
ListConstIteratorHasNext
( const ListConstIterator * );

ListConstIterator *
NewListConstIterator
( const List *, int );

const void *
NextInListConstIterator
( ListConstIterator * );

#endif
