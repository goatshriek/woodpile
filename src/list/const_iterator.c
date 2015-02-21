#include <stdlib.h>

#include <woodpile/list/const_iterator.h>

#include "static/list/const_iterator.h"

ListConstIterator *
CBeginList
( const List *list )
{
  return NULL;
}

ListConstIterator *
CEndList
( const List *list )
{
  return NULL;
}

ListConstIterator *
CopyListConstIterator
( const ListConstIterator *iterator )
{
  return NULL;
}

void
DestroyListConstIterator
( ListConstIterator *iterator )
{
  return;
}

unsigned short
ListConstIteratorHasNext
( const ListConstIterator *iterator )
{
  return 0;
}

unsigned short
ListConstIteratorHasPrevious
( const ListConstIterator *iterator )
{
  return NULL;
}

const void *
NextInListConstIterator
( ListConstIterator *iterator )
{
  return NULL;
}

const void *
PreviousInListConstIterator
( ListConstIterator *iterator )
{
  return NULL;
}

static
ListConstIterator *
NewListConstIterator
( const List *list, int index )
{
  return NULL;
}
