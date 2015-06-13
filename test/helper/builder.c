#include <stdlib.h>

#include <woodpile/dynamic/list.h>
#include <woodpile/static/queue.h>

#include "test/helper/builder.h"

DList *
BuildDList
( void )
{
  DList *list = DListNew();

  DListAppend( list, "This" );
  DListAppend( list, "is" );
  DListAppend( list, "a" );
  DListAppend( list, "test" );
  DListAppend( list, "List" );
  DListAppend( list, "o'" );
  return DListAppend( list, "strings!" );
}

SQueue *
BuildSQueue
( void )
{
  SQueue *queue = SQueueNew();

  SQueuePush( queue, "front of Queue" );
  SQueuePush( queue, "test string" );
  SQueuePush( queue, "middle string" );
  SQueuePush( queue, "second test string" );
  return SQueuePush( queue, "end of Queue" );
}

SStack *
BuildSStack
( void )
{
  return NULL;
}
