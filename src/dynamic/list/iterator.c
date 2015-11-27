#include <stdlib.h>
#include <woodpile/dynamic/list/iterator.h>
#include "lib/validate.h"
#include "private/dynamic/list.h"
#include "private/dynamic/list/iterator.h"

DListItr *
DListItrAdd
( DListItr *iterator, void *element )
{
  Node *addition;

  if( !iterator || !element )
    return iterator;

  addition = malloc( sizeof( Node ) );
  if( !addition )
    return NULL;

  addition->neighbors = XORNODES( iterator->previous, iterator->current );
  addition->element = element;

  if( !iterator->previous ){
    iterator->list->first = addition;
  } else {
    iterator->previous->neighbors = XORNODES( addition,
                                    XORNODES( iterator->previous->neighbors,
                                              iterator->current ) );
  }

  if( !iterator->current ){
    iterator->list->last = addition;
  } else {
    iterator->current->neighbors = XORNODES( addition,
                                   XORNODES( iterator->current->neighbors,
                                             iterator->previous ) );
  }

  iterator->previous = addition;
  iterator->direction = 0;

  return iterator;
}

DListItr *
DListBegin
( DList *list )
{
  DListItr *iterator;

  VALIDATE( list )

  iterator = malloc( sizeof( DListItr ) );
  if( !iterator )
    return NULL;

  iterator->list = list;
  iterator->previous = NULL;
  iterator->current = list->first;

  return iterator;
}

DListItr *
DListItrCopy
( const DListItr *iterator )
{
  DListItr *copy;

  VALIDATE( iterator )

  copy = malloc( sizeof( DListItr ) );
  if( !copy )
    return NULL;

  copy->current = iterator->current;
  copy->previous = iterator->previous;

  return copy;
}

void
DListItrDestroy
( DListItr *iterator )
{
  free( ( void * ) iterator );
}

DListItr *
DListEnd
( DList *list )
{
  DListItr *iterator;

  VALIDATE( list )

  iterator = malloc( sizeof( DListItr ) );
  if( !iterator )
    return NULL;

  iterator->list = list;
  iterator->previous = list->last;
  iterator->current = NULL;

  return iterator;
}

unsigned short
DListItrHasNext
( const DListItr *iterator )
{
  return iterator != NULL && iterator->current != NULL;
}

unsigned short
DListItrHasPrevious
( const DListItr *iterator )
{
  return iterator != NULL && iterator->previous != NULL;
}

void *
DListItrNext
( DListItr *iterator )
{
  Node *temp;
  void *element;

  VALIDATE( iterator )

  if( !iterator->current )
    return NULL;

  element = iterator->current->element;

  temp = iterator->current;
  iterator->current = XORNODES( iterator->previous, temp->neighbors );
  iterator->previous = temp;
  iterator->direction = 1;

  return element;
}

void *
DListItrPrevious
( DListItr *iterator )
{
  Node *temp;
  void *element;

  VALIDATE( iterator )

  if( !iterator->previous )
    return NULL;

  element = iterator->previous->element;

  temp = iterator->previous;
  iterator->previous = XORNODES( iterator->current, temp->neighbors );
  iterator->current = temp;
  iterator->direction = 2;

  return element;
}

void *
DListItrRemove
( DListItr *iterator )
{
  Node *left_neighbor, *removed, *right_neighbor;
  void *element;

  VALIDATE( iterator )

  switch( iterator->direction ){
    case 1:
      removed = iterator->previous;
      if( !removed )
        return NULL;

      right_neighbor = iterator->current;
      left_neighbor = XORNODES( removed->neighbors, right_neighbor);
      break;
    case 2:
      removed = iterator->current;
      if( !removed )
        return NULL;
      
      left_neighbor = iterator->previous;
      right_neighbor = XORNODES( removed->neighbors, left_neighbor );
      break;
    default:
      return NULL;
  }

  iterator->direction = 0;
  element = removed->element;

  if( left_neighbor ){
    left_neighbor->neighbors = XORNODES( right_neighbor,
                               XORNODES( left_neighbor->neighbors, removed ) );
  } else {
    iterator->list->first = right_neighbor;
  }
    
  if( right_neighbor ){
    right_neighbor->neighbors = XORNODES( left_neighbor,
                                XORNODES( right_neighbor->neighbors,
                                          removed ) );
  } else {
    iterator->list->last = left_neighbor;
  }

  free( removed );

  return element;
}
