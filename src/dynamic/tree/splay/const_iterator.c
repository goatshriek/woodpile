#include <stdlib.h>
#include <woodpile/dynamic/tree/splay/const_iterator.h>
#include "lib/validate.h"
#include "private/dynamic/tree/splay.h"
#include "private/dynamic/tree/splay/const_iterator.h"

DSplayCItr *
DSplayCBegin
( const dsplay_t *splay )
{
  DSplayCItr *itr;
  const node_t *current;

  VALIDATE_PARAMETERS( splay )

  itr = malloc( sizeof( DSplayCItr ) );
  VALIDATE_ALLOCATION( itr )

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
( const dsplay_t *splay )
{
  DSplayCItr *itr;
  const node_t *current;

  VALIDATE_PARAMETERS( splay )

  itr = malloc( sizeof( DSplayCItr ) );
  VALIDATE_ALLOCATION( itr )

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

  VALIDATE_PARAMETERS( iterator )

  copy = malloc( sizeof( DSplayCItr ) );
  VALIDATE_ALLOCATION( copy )

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
  VALIDATE_PARAMETERS( iterator )

  if( !iterator->current )
    return NULL;

  iterator->previous = iterator->current;
  iterator->current = ConstNextNode( iterator->previous );

  return iterator->previous->element;
}

const void *
DSplayCItrPrevious
( DSplayCItr *iterator )
{
  VALIDATE_PARAMETERS( iterator )

  if( !iterator->previous )
    return NULL;

  iterator->current = iterator->previous;
  iterator->previous = ConstPreviousNode( iterator->previous );

  return iterator->current->element;
}
