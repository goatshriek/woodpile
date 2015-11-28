#include <stdlib.h>
#include <woodpile/dynamic/list/const_iterator.h>
#include "lib/validate.h"
#include "private/dynamic/list.h"
#include "private/dynamic/list/const_iterator.h"


DListCItr *
DListCBegin
( const DList *list )
{
  DListCItr *iterator;

  VALIDATE_PARAMETER( list )

  iterator = malloc( sizeof( DListCItr ) );
  if( !iterator )
    return NULL;

  iterator->previous = NULL;
  iterator->current = list->first;

  return iterator;
}

DListCItr *
DListCEnd
( const DList *list )
{
  DListCItr *iterator;

  VALIDATE_PARAMETER( list )

  iterator = malloc( sizeof( DListCItr ) );
  if( !iterator )
    return NULL;

  iterator->previous = list->last;
  iterator->current = NULL;

  return iterator;
}

DListCItr *
DListCItrCopy
( const DListCItr *iterator )
{
  DListCItr *copy;

  VALIDATE_PARAMETER( iterator )

  copy = malloc( sizeof( DListCItr ) );
  if( !copy )
    return NULL;

  copy->current = iterator->current;
  copy->previous = iterator->previous;

  return copy;
}

void
DListCItrDestroy
( const DListCItr *iterator )
{
  free( ( void * ) iterator );
}

unsigned short
DListCItrHasNext
( const DListCItr *iterator )
{
  return iterator != NULL && iterator->current != NULL;
}

unsigned short
DListCItrHasPrevious
( const DListCItr *iterator )
{
  return iterator != NULL && iterator->previous != NULL;
}

const void *
DListCItrNext
( DListCItr *iterator )
{
  const Node *temp;
  const void *element;

  VALIDATE_PARAMETER( iterator )

  if( !iterator->current )
    return NULL;

  element = iterator->current->element;

  temp = iterator->current;
  iterator->current = XORNODES( iterator->previous, temp->neighbors );
  iterator->previous = temp;

  return element;
}

const void *
DListCItrPrevious
( DListCItr *iterator )
{
  const Node *temp;
  const void *element;

  VALIDATE_PARAMETER( iterator )

  if( !iterator->previous )
    return NULL;

  element = iterator->previous->element;

  temp = iterator->previous;
  iterator->previous = XORNODES( iterator->current, temp->neighbors );
  iterator->current = temp;

  return element;
}
