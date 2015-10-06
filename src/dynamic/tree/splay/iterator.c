#include <stdlib.h>
#include <woodpile/dynamic/tree/splay/iterator.h>
#include "private/dynamic/tree/splay.h"
#include "private/dynamic/tree/splay/iterator.h"

DSplayItr *
DSplayBegin
( DSplay *splay )
{
  DSplayItr *itr;
  Node *current;

  if( !splay )
    return NULL;

  itr = malloc( sizeof( DSplayItr ) );
  if( !itr )
    return NULL;

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

DSplayItr *
DSplayItrCopy
( const DSplayItr *iterator )
{
  DSplayItr *copy;

  if( !iterator )
    return NULL;

  copy = malloc( sizeof( DSplayItr ) );
  if( !copy )
    return NULL;

  copy->splay = iterator->splay;
  copy->previous = iterator->previous;
  copy->current = iterator->current;
  copy->direction = iterator->direction;

  return copy;
}

void
DSplayItrDestroy
( DSplayItr *iterator )
{
  free( ( void * ) iterator );

  return;
}

DSplayItr *
DSplayEnd
( DSplay *splay )
{
  DSplayItr *itr;
  Node *current;

  if( !splay )
    return NULL;

  itr = malloc( sizeof( DSplayItr ) );
  if( !itr )
    return NULL;

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
( const DSplayItr *iterator )
{
  return ( iterator != NULL ) && ( iterator->current != NULL );
}

unsigned short
DSplayItrHasPrevious
( const DSplayItr *iterator )
{
  return ( iterator != NULL ) && ( iterator->previous != NULL );
}

void *
DSplayItrNext
( DSplayItr *iterator )
{
  if( !iterator || !iterator->current )
    return NULL;

  iterator->previous = iterator->current;
  iterator->current = NextNode( iterator->previous );
  iterator->direction = 1;

  return iterator->previous->element;
}

void *
DSplayItrPrevious
( DSplayItr *iterator )
{
  if( !iterator || !iterator->previous )
    return NULL;

  iterator->current = iterator->previous;
  iterator->previous = PreviousNode( iterator->previous );
  iterator->direction = 2;

  return iterator->current->element;
}

void *
DSplayItrRemove
( DSplayItr *iterator )
{
  Node *removed, *root;
  void *element;

  if( !iterator )
    return NULL;

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
