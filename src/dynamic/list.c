#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <woodpile/dynamic/list.h>
#include "lib/str.h"
#include "lib/validate.h"
#include "private/dynamic/list.h"

DList *
DListAppendAll
( DList *first, const DList *second )
{
  Node *node, *previous=NULL, *temp;

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

DList *
DListAppend
( DList *list, void *element )
{
  Node *node;

  VALIDATE_PARAMETERS( list )

  if( !element )
    return list;

  node = malloc( sizeof( Node ) );
  if( !node )
    return NULL;

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

DList *
DListCopy
( const DList *list )
{
  DList *copy;
  Node *node, *previous=NULL, *temp;

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
( const DList *list )
{
  const Node *previous=NULL, *current, *next;

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
( const DList *list )
{
  VALIDATE_PARAMETERS( list )

  if( list->last )
    return list->last->element;
  else
    return NULL;
}

size_t
DListContains
( const DList *list, const void *element )
{
  Node *node, *previous = NULL, *temp;
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
( const DList *list )
{
  VALIDATE_PARAMETERS( list )

  if( list->first )
    return list->first->element;
  else
    return NULL;
}

void *
DListGet
( const DList *list, int index )
{
  Node *current, *next, *previous=NULL, *start;
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
( const DList *list )
{
  return !list || !list->first;
}

unsigned
DListSize
( const DList *list )
{
  Node *node, *previous = NULL, *temp;
  unsigned size = 0;

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
( const DList *list, char * ( *element_to_string )( const void * ) )
{
  char *str;
  const char *element;
  const Node *current, *next, *previous=NULL;
  size_t element_length, str_capacity=100, str_length=1;

  VALIDATE_PARAMETERS( list )

  if( !element_to_string )
    element_to_string = strpointer;

  str = malloc( sizeof( char ) * str_capacity );
  if( !str )
    return NULL;
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

DList *
DListNew
( void )
{
  DList *list = malloc( sizeof( DList ) );
  if( !list )
    return NULL;

  list->first = list->last = NULL;

  return list;
}

DList *
DListPrepend
( DList *list, void *element )
{
  Node *node;

  VALIDATE_PARAMETERS( list )

  node = malloc( sizeof( Node ) );
  if( !node )
    return NULL;

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
