#ifndef __WOODPILE_LIST_H
#define __WOODPILE_LIST_H

/**
 * @file
 * Declaration and functions for the List container.
 */

/**
 * The List data structure is a simple doubly linked list implementation.
 *
 * The List is optimized for insertions and deletions at either end, and
 * sequential walks via the iterators. If random access is needed then the
 * ArrayList structure is more suitable.
 *
 * Memory for this structure is allocated dynamically, allowing it to grow and
 * shrink along with the number of elements it holds. This makes it suitable for
 * use when the size is constantly changing; if a more static list size is
 * needed then the ArrayList structure would be more efficient as its memory
 * overhead is lower.
 *
 * Memory overhead can be calculated as follows:
 * 2 * sizeof( void * ) * ( number_of_elements + 1 )
 */
struct List;
typedef struct List List;

List *
AddSeparatorToList
( List *, void * );

List *
AppendLists
( List *, const List * );

List *
AppendToList
( List *, void * );

List *
CopyList
( const List * );

void
DestroyList
( List * );

void *
ListBack
( const List * );

unsigned short
ListContains
( const List *, const void * );

void *
ListFront
( const List * );

unsigned short
ListIsEmpty
( const List * );

unsigned
ListSize
( const List * );

List *
NewList
( void );

List *
PrependToList
( List *, void * );

#endif
