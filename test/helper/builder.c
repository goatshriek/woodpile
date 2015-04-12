#include <stdlib.h>

#include <woodpile/list.h>

#include "test/helper/builder.h"

Dictionary *
BuildDictionary
( void )
{
  return NULL;
}

DictionaryConstIterator *
BuildDictionaryConstIterator
( void )
{
  return NULL;
}

List *
BuildList
( void )
{
  List *list;

  list = NewList();

  AppendToList( list, "This" );
  AppendToList( list, "is" );
  AppendToList( list, "a" );
  AppendToList( list, "test" );
  AppendToList( list, "List" );
  AppendToList( list, "o'" );
  return AppendToList( list, "strings!" );
}

Queue *
BuildQueue
( void )
{
  Queue *queue;

  queue = NewQueue();

  PushToQueue( queue, "front of Queue" );
  PushToQueue( queue, "test string" );
  PushToQueue( queue, "middle string" );
  PushToQueue( queue, "second test string" );
  PushToQueue( queue, "end of Queue" );

  return queue;
}

Stack *
BuildStack
( void )
{
  return NULL;
}

Tree *
BuildTree
( void )
{
  return NULL;
}
