#include <stdlib.h>

#include <woodpile/list/iterator.h>

#include "static/list/iterator.h"

ListIterator *
AddToListIterator
( ListIterator *iterator, void *element )
{
  return NULL;
}

ListIterator *
BeginList
( List *list )
{
  return NULL;
}

ListIterator *
CopyListIterator
( const ListIterator *original )
{
  return NULL;
}

void
DestroyListIterator
( ListIterator *iterator )
{
  return;
}

ListIterator *
EndList
( List *list )
{
  return NULL;
}

unsigned short
ListIteratorHasNext
( const ListIterator *iterator )
{
  return 0;
}

unsigned short
ListIteratorHasPrevious
( const ListIterator *iterator )
{
  return 0;
}

void *
NextInListIterator
( ListIterator *iterator )
{
  return NULL;
}

void *
PreviousInListIterator
( ListIterator *iterator )
{
  return NULL;
}

void *
RemoveFromListIterator
( ListIterator *iterator )
{
  return NULL;
}

static
ListIterator *
NewListIterator
( List *list, int index )
{
  return NULL;
}
