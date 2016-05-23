#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <woodpile/dynamic/list.h>
#include "lib/str.h"
#include "lib/validate.h"
#include "private/dynamic/list.h"

dlist_t *
DListAppendAll
( dlist_t *first, const dlist_t *second )
{
  node_t *node, *previous=NULL, *temp;

  VALIDATE_PARAMETERS( first )

  if( !second )
    return first;

  node = second->first;
  while( node ){
    DListAppend( first, node->element );

    temp = node;
    node = XORNODES( previous, node->neighbors );
    previous = temp;
  }

  return first;
}

dlist_t *
DListAppend
( dlist_t *list, void *element )
{
  node_t *node;

  VALIDATE_PARAMETERS( list )

  if( !element )
    return list;

  node = malloc( sizeof( node_t ) );
  VALIDATE_ALLOCATION( node )

  node->neighbors = list->last;
  node->element = element;

  if( !list->last ){
    list->first = list->last = node;
  } else {
    list->last->neighbors = XORNODES( list->last->neighbors, node );
    list->last = node;
  }

  return list;
}

dlist_t *
DListCopy
( const dlist_t *list )
{
  dlist_t *copy;
  node_t *node, *previous=NULL, *temp;

  VALIDATE_PARAMETERS( list )

  copy = DListNew();
  node = list->first;
  while( node ){
    DListAppend( copy, node->element );

    temp = node;
    node = XORNODES( previous, node->neighbors );
    previous = temp;
  }

  return copy;
}

void
DListDestroy
( const dlist_t *list )
{
  const node_t *previous=NULL, *current, *next;

  if( !list )
    return;

  current = list->first;
  while( current ){
    free( ( void * ) previous );

    next = XORNODES( previous, current->neighbors );
    previous = current;
    current = next;
  }

  free( ( void * ) list );

  return;
}

void *
DListBack
( const dlist_t *list )
{
  VALIDATE_PARAMETERS( list )

  if( list->last )
    return list->last->element;
  else
    return NULL;
}

size_t
DListContains
( const dlist_t *list, const void *element )
{
  node_t *node, *previous = NULL, *temp;
  size_t count=0;

  if( !list )
    return 0;

  node = list->first;
  while( node ){
    if( node->element == element )
      count++;

    temp = node;
    node = XORNODES( previous, node->neighbors );
    previous = temp;
  }

  return count;
}

void *
DListFront
( const dlist_t *list )
{
  VALIDATE_PARAMETERS( list )

  if( list->first )
    return list->first->element;
  else
    return NULL;
}

void *
DListGet
( const dlist_t *list, int index )
{
  node_t *current, *next, *previous=NULL, *start;
  size_t i, steps;

  if( DListIsEmpty( list ) )
    return NULL;

  if( index < 0 ){
    start = list->last;
    steps = -( index + 1 );
  } else {
    start = list->first;
    steps = index;
  }

  current = start;
  for( i = 0; i < steps; i++ ){
    next = XORNODES( previous, current->neighbors );
    if( !next ){
      previous = NULL;
      current = start;
    } else {
      previous = current;
      current = next;
    }
  }

  return current->element;
}

unsigned short
DListIsEmpty
( const dlist_t *list )
{
  return !list || !list->first;
}

size_t
DListSize
( const dlist_t *list )
{
  node_t *node, *previous = NULL, *temp;
  size_t size = 0;

  if( !list )
    return 0;

  node = list->first;
  while( node ){
    size++;

    temp = node;
    node = XORNODES( previous, node->neighbors );
    previous = temp;
  }

  return size;
}

char *
DListToString
( const dlist_t *list, char * ( *element_to_string )( const void * ) )
{
  char *str;
  const char *element;
  const node_t *current, *next, *previous=NULL;
  size_t element_length, str_capacity=100, str_length=1;

  VALIDATE_PARAMETERS( list )

  if( !element_to_string )
    element_to_string = strpointer;

  str = malloc( sizeof( char ) * str_capacity );
  VALIDATE_ALLOCATION( str )
  str[0] = '[';

  current = list->first;
  while( current ){
    element = element_to_string( current->element );
    element_length = strlen( element );

    while( str_capacity < str_length + element_length + 2 ){
      str_capacity *= 2;
      str = realloc( str, str_capacity );
    }

    memcpy( str + str_length, element, element_length * sizeof( char ) );
    str_length += element_length;
    free( ( void * ) element );

    next = XORNODES( previous, current->neighbors );
    previous = current;
    current = next;

    if( current ){
      str[str_length++] = ',';
      str[str_length++] = ' ';
    }
  }

  if( str_capacity != str_length + 2 ){
    str = realloc( str, str_length + 2 );
  }

  str[str_length++] = ']';
  str[str_length] = '\0';

  return str;
}

dlist_t *
DListNew
( void )
{
  dlist_t *list = malloc( sizeof( dlist_t ) );
  VALIDATE_ALLOCATION( list )

  list->first = list->last = NULL;

  return list;
}

dlist_t *
DListPrepend
( dlist_t *list, void *element )
{
  node_t *node;

  VALIDATE_PARAMETERS( list )

  node = malloc( sizeof( node_t ) );
  VALIDATE_ALLOCATION( node )

  node->neighbors = list->first;
  node->element = element;

  if( !list->first ){
    list->first = list->last = node;
  } else {
    list->first->neighbors = XORNODES( list->first->neighbors, node );
    list->first = node;
  }

  return list;
}
