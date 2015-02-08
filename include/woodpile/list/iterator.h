#ifndef __WOODPILE_LIST_ITERATOR_H
#define __WOODPILE_LIST_ITERATOR_H

#include <woodpile/list.h>

ListIterator *
BeginList
( List * );

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

ListIterator *
NewListIterator
( List *, int );

void *
NextInListIterator
( ListIterator * );

void *
PreviousInListIterator
( ListIterator * );

#endif
