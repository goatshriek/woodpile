#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <woodpile/list.h>

#include "static/list.h"

List *
AppendAllToList
( List *first, const List *second )
{
  Node *node, *previous=NULL, *temp;

  if( !first )
    return NULL;

  if( !second )
    return first;

  node = second->first;
  while( node ){
    AppendToList( first, node->element );

    temp = node;
    node = XORNODES( previous, node->neighbors );
    previous = temp;
  }

  return first;
}

List *
AppendToList
( List *list, void *element )
{
  Node *node;

  if( !list )
    return NULL;

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

List *
CopyList
( const List *list )
{
  List *copy;
  Node *node, *previous=NULL, *temp;

  if( !list )
    return NULL;
  
  copy = NewList();
  node = list->first;
  while( node ){
    AppendToList( copy, node->element );

    temp = node;
    node = XORNODES( previous, node->neighbors );
    previous = temp;
  }

  return copy;
}

void
DestroyList
( const List *list )
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
ListBack
( const List *list )
{
  if( !list || !list->last )
    return NULL;

  return list->last->element;
}

size_t
ListContains
( const List *list, const void *element )
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
ListFront
( const List *list )
{
  if( !list || !list->first )
    return NULL;

  return list->first->element;
}

void *
ListGet
( const List *list, int index )
{
  Node *current, *next, *previous=NULL, *start;
  size_t i, steps;
  void *element;

  if( ListIsEmpty( list ) )
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
ListIsEmpty
( const List *list )
{
  return !list || !list->first;
}

unsigned
ListSize
( const List *list )
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
ListToString
( const List *list, char * ( *element_to_string )( const void * ) )
{
  char *str;
  const char *element;
  const Node *current, *next, *previous=NULL;
  size_t element_length, str_capacity=100, str_length=1;

  if( !list )
    return NULL;

  if( !element_to_string )
    element_to_string = PointerToString;

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

    strncpy( str + str_length, element, element_length );
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

List *
NewList
( void )
{
  List *list = malloc( sizeof( List ) );
  if( !list )
    return NULL;

  list->first = list->last = NULL;

  return list;
}

List *
PrependToList
( List *list, void *element )
{
  Node *node;

  if( !list )
    return NULL;

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

static
char *
PointerToString
( const void *pointer )
{
  char *str;
  size_t size;

  str = malloc( sizeof( char ) * 100 );
  if( !str )
    return NULL;
  
  sprintf( str, "%p", pointer );

  return str;
}
