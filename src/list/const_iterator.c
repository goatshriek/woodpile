#include <stdlib.h>

#include <woodpile/list/const_iterator.h>

#include "static/list.h"
#include "static/list/const_iterator.h"

ListConstIterator *
CBeginList
( const List *list )
{
  ListConstIterator *iterator;

  if( !list )
    return NULL;

  iterator = malloc( sizeof( ListConstIterator ) );
  if( !iterator )
    return NULL;

  iterator->previous = NULL;
  iterator->current = list->first;

  return iterator;
}

ListConstIterator *
CEndList
( const List *list )
{
  ListConstIterator *iterator;

  if( !list )
    return NULL;

  iterator = malloc( sizeof( ListConstIterator ) );
  if( !iterator )
    return NULL;

  iterator->previous = list->last;
  iterator->current = NULL;

  return iterator;
}

ListConstIterator *
CopyListConstIterator
( const ListConstIterator *iterator )
{
  ListConstIterator *copy;

  if( !iterator )
    return NULL;

  copy = malloc( sizeof( ListConstIterator ) );
  if( !copy )
    return NULL;

  copy->current = iterator->current;
  copy->previous = iterator->previous;

  return copy;
}

void
DestroyListConstIterator
( const ListConstIterator *iterator )
{
  free( ( void * ) iterator );
}

unsigned short
ListConstIteratorHasNext
( const ListConstIterator *iterator )
{
  return iterator != NULL && iterator->current != NULL;
}

unsigned short
ListConstIteratorHasPrevious
( const ListConstIterator *iterator )
{
  return iterator != NULL && iterator->previous != NULL;
}

const void *
NextInListConstIterator
( ListConstIterator *iterator )
{
  const Node *temp;
  const void *element;

  if( !iterator || !iterator->current )
    return NULL;

  element = iterator->current->element;

  temp = iterator->current;
  iterator->current = XORNODES( iterator->previous, temp->neighbors );
  iterator->previous = temp;

  return element;
}

const void *
PreviousInListConstIterator
( ListConstIterator *iterator )
{
  const Node *temp;
  const void *element;

  if( !iterator || !iterator->previous )
    return NULL;

  element = iterator->previous->element;

  temp = iterator->previous;
  iterator->previous = XORNODES( iterator->current, temp->neighbors );
  iterator->current = temp;

  return element;
}
