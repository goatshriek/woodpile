#include <stdlib.h>

#include <woodpile/list.h>

#include "static/list.h"

List *
AppendAllToList
( List *first, const List *second )
{
  return NULL;
}

List *
AppendToList
( List *list, void *element )
{
  return NULL;
}

List *
CopyList
( const List *list )
{
  return NULL;
}

void
DestroyList
( List *list )
{
  return;
}

void *
GetListBack
( const List *list )
{
  return NULL;
}

void *
GetListFront
( const List *list );

unsigned
GetListSize
( const List *list )
{
  return 0;
}

unsigned short
ListContains
( const List *list, const void *element )
{
  return 0;
}

unsigned short
ListIsEmpty
( const List *list )
{
  return 0;
}

char *
ListToString
( const List *list, char * ( *element_to_string )( const void * ) )
{
  return NULL;
}

List *
NewList
( void )
{
  return NULL;
}

List *
PrependToList
( List *list, void *element )
{
  return NULL;
}
