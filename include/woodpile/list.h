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
 * sequential walks via the iterators.
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

ListIterator *
BeginList
( List * );

ListConstIterator *
CBeginList
( const List * );

ListConstIterator *
CEndList
( const List * );

List *
CopyList
( const List * );

ListConstReverseIterator *
CRBeginList
( const List * );

ListConstReverseIterator *
CREndList
( const List * );

void
DestroyList
( List * );

ListIterator *
EndList
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

ListReverseIterator *
RBeginList
( List * );

ListReverseIterator *
REndList
( List * );

#endif
