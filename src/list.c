#include <stdlib.h>

#include <woodpile/list.h>

#include "static/list.h"

List *
AddSeparatorToList
( List * list, void * value )
{
  if( !list || !value )
    return NULL;

  if( !list->first )
    return list;

  if( !SeparateNodes( NULL, list->first, value ) )
    return NULL;

  return list;
}

List *
AppendLists
( List * first, const List * second )
{
  Node *node, *previous = NULL, *temp;

  if( !first )
    return NULL;

  node = second->first;
  while( node ){
    AppendToList( first, node->value );

    temp = node;
    node = XORNODES( previous, node->neighbors );
    previous = temp;
  }

  return first;
}

// todo disallow NULL values
List *
AppendToList
( List * list, void * value )
{
  Node *node;

  if( !list )
    return NULL;

  node = malloc( sizeof( Node ) );
  if( !node )
    return NULL;

  node->neighbors = list->last;
  node->value = value;

  if( !list->last ){
    list->first = list->last = node;
  } else {
    list->last->neighbors = XORNODES( list->last->neighbors, node );
    list->last = node;
  }

  return list;
}

ListIterator *
BeginList
( List * list )
{
  return NewListIterator( list, 0 );
}

ListConstIterator *
CBeginList
( const List * list )
{
  return NewListConstIterator( list, 0 );
}

ListConstIterator *
CEndList
( const List * list )
{
  return NewListConstIterator( list, -1 );
}

List *
CopyList
( const List *list )
{
  List *copy;
  Node *node, *previous = NULL, *temp;

  if( !list )
    return NULL;

  copy = NewList();
  node = list->first;
  while( node ){
    AppendToList( copy, node->value );

    temp = node;
    node = XORNODES( previous, node->neighbors );
    previous = temp;
  }

  return copy;
}

ListConstReverseIterator *
CRBeginList
( const List * list )
{
  return NewListConstReverseIterator( list, 0 );
}

ListConstReverseIterator *
CREndList
( const List * list )
{
  return NewListConstReverseIterator( list, -1 );
}

void
DestroyList
( List * list )
{
  if( !list )
    return;

  DestroyNodes( NULL, list->first );

  free( list );

  return;
}

ListIterator *
EndList
( List * list )
{
  return NewListIterator( list, -1 );
}

void *
ListBack
( const List *list )
{
  if( !list || !list->last )
    return NULL;

  return list->last->value;
}

unsigned short
ListContains
( const List * list, const void * value )
{
  Node *node, *previous = NULL, *temp;

  if( !list )
    return 0;

  node = list->first;
  while( node ){
    if( node->value == value )
      return 1;

    temp = node;
    node = XORNODES( previous, node->neighbors );
    previous = temp;
  }

  return 0;
}

void *
ListFront
( const List *list )
{
  if( !list || !list->first )
    return NULL;

  return list->first->value;
}

unsigned short
ListIsEmpty
( const List * list )
{
  return !list || !list->first;
}

unsigned
ListSize
( const List * list )
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

List *
NewList
( void )
{
  List * list = malloc( sizeof( List ) );
  if( !list )
    return NULL;

  list->first = list->last = NULL;

  return list;
}

List *
PrependToList
( List * list, void * value )
{
  Node *node;

  if( !list )
    return NULL;

  node = malloc( sizeof( Node ) );
  if( !node )
    return NULL;

  node->neighbors = list->first;
  node->value = value;

  if( !list->first ){
    list->first = list->last = node;
  } else {
    list->first->neighbors = XORNODES( list->first->neighbors, node );
    list->first = node;
  }

  return list;
}

ListReverseIterator *
RBeginList
( List * list )
{
  return NewListReverseIterator( list, 0 );
}

ListReverseIterator *
REndList
( List * list )
{
  return NewListReverseIterator( list, -1 );
}

static
void
DestroyNodes
( Node *previous, Node *node )
{
  Node *next;

  if( !node )
    return;

  next = XORNODES( previous, node->neighbors );
  free( node );

  DestroyNodes( node, next );
}

static
void *
SeparateNodes
( Node * previous, Node *node, void *value )
{
  Node *next, *next_next, *separator;

  if( node->neighbors == previous )
    return value;

  separator = malloc( sizeof( Node ) );
  if( !separator )
    return NULL;

  next = XORNODES( previous, node->neighbors );

  separator->value = value;
  separator->neighbors = XORNODES( node, next );

  next_next = XORNODES( node, next->neighbors );
  node->neighbors = XORNODES( previous, separator );
  next->neighbors = XORNODES( separator, next_next );

  return SeparateNodes( separator, next, value );
}