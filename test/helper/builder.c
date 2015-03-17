#include <stdlib.h>

#include <woodpile/list.h>

#include "test/helper/builder.h"

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
  AppendToList( list, "strings!" );

  return list;
}

ListConstIterator *
BuildListConstIterator
( void )
{
  ListConstIterator *iterator;

  iterator = CBeginList( BuildList() );
  NextInListConstIterator( iterator );
  NextInListConstIterator( iterator );
  NextInListConstIterator( iterator );

  return iterator;
}

ListIterator *
BuildListIterator
( void )
{
  ListIterator *iterator;

  iterator = BeginList( BuildList() );
  NextInListIterator( iterator );
  NextInListIterator( iterator );
  NextInListIterator( iterator );

  return iterator;
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
