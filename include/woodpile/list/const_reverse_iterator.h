#ifndef __WOODPILE_LIST_CONST_REVERSE_ITERATOR_H
#define __WOODPILE_LIST_CONST_REVERSE_ITERATOR_H

#include <woodpile/list.h>

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

ListConstReverseIterator *
NewListConstReverseIterator
( const List *, int );

const void *
NextInListConstReverseIterator
( ListConstReverseIterator * );

#endif
