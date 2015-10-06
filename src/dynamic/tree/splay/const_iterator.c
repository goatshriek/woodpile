#include <stdlib.h>
#include <woodpile/dynamic/tree/splay/const_iterator.h>
#include "private/dynamic/tree/splay.h"
#include "private/dynamic/tree/splay/const_iterator.h"

DSplayCItr *
DSplayCBegin
( const DSplay *splay )
{
  DSplayCItr *itr;
  const Node *current;

  if( !splay )
    return NULL;

  itr = malloc( sizeof( DSplayCItr ) );
  if( !itr )
    return NULL;

  itr->current = NULL;
  itr->previous = NULL;

  current = splay->root;
  while( current ){
    itr->current = current;
    current = current->left_child;
  }

  return itr;
}

DSplayCItr *
DSplayCEnd
( const DSplay *splay )
{
  DSplayCItr *itr;
  const Node *current;

  if( !splay )
    return NULL;

  itr = malloc( sizeof( DSplayCItr ) );
  if( !itr )
    return NULL;

  itr->current = NULL;
  itr->previous = NULL;

  current = splay->root;
  while( current ){
    itr->previous = current;
    current = current->right_child;
  }

  return itr;
}

DSplayCItr *
DSplayCItrCopy
( const DSplayCItr *iterator )
{
  DSplayCItr *copy;

  if( !iterator )
    return NULL;

  copy = malloc( sizeof( DSplayCItr ) );
  if( !copy )
    return NULL;

  copy->previous = iterator->previous;
  copy->current = iterator->current;

  return copy;
}

void
DSplayCItrDestroy
( const DSplayCItr *iterator )
{
  free( ( void * ) iterator );

  return;
}

unsigned short
DSplayCItrHasNext
( const DSplayCItr *iterator )
{
  return ( iterator != NULL ) && ( iterator->current != NULL );
}

unsigned short
DSplayCItrHasPrevious
( const DSplayCItr *iterator )
{
  return ( iterator != NULL ) && ( iterator->previous != NULL );
}

const void *
DSplayCItrNext
( DSplayCItr *iterator )
{
  if( !iterator || !iterator->current )
    return NULL;

  iterator->previous = iterator->current;
  iterator->current = ConstNextNode( iterator->previous );

  return iterator->previous->element;
}

const void *
DSplayCItrPrevious
( DSplayCItr *iterator )
{
  if( !iterator || !iterator->previous )
    return NULL;

  iterator->current = iterator->previous;
  iterator->previous = ConstPreviousNode( iterator->previous );

  return iterator->current->element;
}
