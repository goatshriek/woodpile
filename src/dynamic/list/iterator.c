#include <stdlib.h>
#include <woodpile/dynamic/list/iterator.h>
#include "lib/validate.h"
#include "private/dynamic/list.h"
#include "private/dynamic/list/iterator.h"

dlist_itr_t *
DListItrAdd
( dlist_itr_t *iterator, void *element )
{
  node_t *addition;

  if( !iterator || !element )
    return iterator;

  addition = malloc( sizeof( node_t ) );
  VALIDATE_ALLOCATION( addition )

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

dlist_itr_t *
DListBegin
( dlist_t *list )
{
  dlist_itr_t *iterator;

  VALIDATE_PARAMETERS( list )

  iterator = malloc( sizeof( dlist_itr_t ) );
  VALIDATE_ALLOCATION( iterator )

  iterator->list = list;
  iterator->previous = NULL;
  iterator->current = list->first;

  return iterator;
}

dlist_itr_t *
DListItrCopy
( const dlist_itr_t *iterator )
{
  dlist_itr_t *copy;

  VALIDATE_PARAMETERS( iterator )

  copy = malloc( sizeof( dlist_itr_t ) );
  VALIDATE_ALLOCATION( copy )

  copy->current = iterator->current;
  copy->previous = iterator->previous;

  return copy;
}

void
DListItrDestroy
( dlist_itr_t *iterator )
{
  free( ( void * ) iterator );
}

dlist_itr_t *
DListEnd
( dlist_t *list )
{
  dlist_itr_t *iterator;

  VALIDATE_PARAMETERS( list )

  iterator = malloc( sizeof( dlist_itr_t ) );
  VALIDATE_ALLOCATION( iterator )

  iterator->list = list;
  iterator->previous = list->last;
  iterator->current = NULL;

  return iterator;
}

unsigned short
DListItrHasNext
( const dlist_itr_t *iterator )
{
  return iterator != NULL && iterator->current != NULL;
}

unsigned short
DListItrHasPrevious
( const dlist_itr_t *iterator )
{
  return iterator != NULL && iterator->previous != NULL;
}

void *
DListItrNext
( dlist_itr_t *iterator )
{
  node_t *temp;
  void *element;

  VALIDATE_PARAMETERS( iterator )

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
( dlist_itr_t *iterator )
{
  node_t *temp;
  void *element;

  VALIDATE_PARAMETERS( iterator )

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
( dlist_itr_t *iterator )
{
  node_t *left_neighbor, *removed, *right_neighbor;
  void *element;

  VALIDATE_PARAMETERS( iterator )

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
