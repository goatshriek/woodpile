#include <stdlib.h>

#include <woodpile/list/iterator.h>

#include "static/list.h"
#include "static/list/iterator.h"

ListIterator *
AddToListIterator
( ListIterator *iterator, void *element )
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

ListIterator *
BeginList
( List *list )
{
  ListIterator *iterator;

  if( !list )
    return NULL;

  iterator = malloc( sizeof( ListIterator ) );
  if( !iterator )
    return NULL;

  iterator->list = list;
  iterator->previous = NULL;
  iterator->current = list->first;

  return iterator;
}

ListIterator *
CopyListIterator
( const ListIterator *iterator )
{
  ListIterator *copy;

  if( !iterator )
    return NULL;

  copy = malloc( sizeof( ListIterator ) );
  if( !copy )
    return NULL;

  copy->current = iterator->current;
  copy->previous = iterator->previous;

  return copy;
}

void
DestroyListIterator
( ListIterator *iterator )
{
  free( ( void * ) iterator );
}

ListIterator *
EndList
( List *list )
{
  ListIterator *iterator;

  if( !list )
    return NULL;

  iterator = malloc( sizeof( ListIterator ) );
  if( !iterator )
    return NULL;

  iterator->list = list;
  iterator->previous = list->last;
  iterator->current = NULL;

  return iterator;
}

unsigned short
ListIteratorHasNext
( const ListIterator *iterator )
{
  return iterator != NULL && iterator->current != NULL;
}

unsigned short
ListIteratorHasPrevious
( const ListIterator *iterator )
{
  return iterator != NULL && iterator->previous != NULL;
}

void *
NextInListIterator
( ListIterator *iterator )
{
  Node *temp;
  void *element;

  if( !iterator || !iterator->current )
    return NULL;

  element = iterator->current->element;

  temp = iterator->current;
  iterator->current = XORNODES( iterator->previous, temp->neighbors );
  iterator->previous = temp;
  iterator->direction = 1;

  return element;
}

void *
PreviousInListIterator
( ListIterator *iterator )
{
  Node *temp;
  void *element;

  if( !iterator || !iterator->previous )
    return NULL;

  element = iterator->previous->element;

  temp = iterator->previous;
  iterator->previous = XORNODES( iterator->current, temp->neighbors );
  iterator->current = temp;
  iterator->direction = 2;

  return element;
}

void *
RemoveFromListIterator
( ListIterator *iterator )
{
  Node *left_neighbor, *removed, *right_neighbor;
  void *element;

  if( !iterator )
    return NULL;

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
