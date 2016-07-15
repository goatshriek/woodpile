#include <stdlib.h>
#include <woodpile/dynamic/tree/splay/iterator.h>
#include "lib/validate.h"
#include "private/dynamic/tree/splay.h"
#include "private/dynamic/tree/splay/iterator.h"

dsplay_itr_t *
DSplayBegin
( dsplay_t *splay )
{
  dsplay_itr_t *itr;
  node_t *current;

  VALIDATE_PARAMETERS( splay )

  itr = malloc( sizeof( dsplay_itr_t ) );
  VALIDATE_ALLOCATION( itr )

  itr->splay = splay;
  itr->current = NULL;
  itr->previous = NULL;
  itr->direction = 0;

  current = splay->root;
  while( current ){
    itr->current = current;
    current = current->left_child;
  }

  return itr;
}

dsplay_itr_t *
DSplayItrCopy
( const dsplay_itr_t *iterator )
{
  dsplay_itr_t *copy;

  VALIDATE_PARAMETERS( iterator )

  copy = malloc( sizeof( dsplay_itr_t ) );
  VALIDATE_ALLOCATION( copy )

  copy->splay = iterator->splay;
  copy->previous = iterator->previous;
  copy->current = iterator->current;
  copy->direction = iterator->direction;

  return copy;
}

void
DSplayItrDestroy
( dsplay_itr_t *iterator )
{
  free( ( void * ) iterator );

  return;
}

dsplay_itr_t *
DSplayEnd
( dsplay_t *splay )
{
  dsplay_itr_t *itr;
  node_t *current;

  VALIDATE_PARAMETERS( splay )

  itr = malloc( sizeof( dsplay_itr_t ) );
  VALIDATE_ALLOCATION( itr )

  itr->splay = splay;
  itr->current = NULL;
  itr->previous = NULL;
  itr->direction = 0;

  current = splay->root;
  while( current ){
    itr->previous = current;
    current = current->right_child;
  }

  return itr;
}

unsigned short
DSplayItrHasNext
( const dsplay_itr_t *iterator )
{
  return ( iterator != NULL ) && ( iterator->current != NULL );
}

unsigned short
DSplayItrHasPrevious
( const dsplay_itr_t *iterator )
{
  return ( iterator != NULL ) && ( iterator->previous != NULL );
}

void *
DSplayItrNext
( dsplay_itr_t *iterator )
{
  VALIDATE_PARAMETERS( iterator )

  if( !iterator->current )
    return NULL;

  iterator->previous = iterator->current;
  iterator->current = NextNode( iterator->previous );
  iterator->direction = 1;

  return iterator->previous->element;
}

void *
DSplayItrPrevious
( dsplay_itr_t *iterator )
{
  VALIDATE_PARAMETERS( iterator )

  if( !iterator->previous )
    return NULL;

  iterator->current = iterator->previous;
  iterator->previous = PreviousNode( iterator->previous );
  iterator->direction = 2;

  return iterator->current->element;
}

void *
DSplayItrRemove
( dsplay_itr_t *iterator )
{
  node_t *removed, *root;
  void *element;

  VALIDATE_PARAMETERS( iterator )

  switch( iterator->direction ){
    case 1:
      removed = iterator->previous;
      iterator->previous = PreviousNode( removed );
      break;
    case 2:
      removed = iterator->current;
      iterator->current = NextNode( removed );
      break;
    default:
      return NULL;
  }

  element = removed->element;
  iterator->direction = 0;

  if( removed->parent ){
    root = removed->parent;
  } else if( removed->left_child ){
    root = removed->left_child;
  } else if( removed->right_child ){
    root = removed->right_child;
  } else {
    DestroyNode( removed );
    iterator->splay->root = NULL;
    return element;
  }
  
  DestroyNode( removed );
  iterator->splay->root = root;
  Splay( root );

  return element;
}
