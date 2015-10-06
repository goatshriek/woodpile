#include <stdlib.h>
#include <string.h>

#include <woodpile/dynamic/list.h>
#include <woodpile/dynamic/tree/splay.h>
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

DSplay *
BuildDSplay
( void )
{
  DSplay *splay = DSplayNew( ( comparator_t ) strcmp );

  DSplayAdd( splay, "Alpha" );
  DSplayAdd( splay, "Zulu" );
  DSplayAdd( splay, "Beta" );
  DSplayAdd( splay, "Yankee" );
  DSplayAdd( splay, "Charlie" );
  DSplayAdd( splay, "X-Ray" );
  DSplayAdd( splay, "Delta" );
  DSplayAdd( splay, "Whiskey" );
  DSplayAdd( splay, "Echo" );
  DSplayAdd( splay, "Victor" );
  DSplayAdd( splay, "Foxtrot" );
  DSplayAdd( splay, "Uniform" );
  DSplayAdd( splay, "Gamma" );
  DSplayAdd( splay, "Tango" );
  DSplayAdd( splay, "Hotel" );
  DSplayAdd( splay, "Sierra" );
  DSplayAdd( splay, "India" );
  DSplayAdd( splay, "Romeo" );
  DSplayAdd( splay, "Juliet" );
  DSplayAdd( splay, "Quebec" );
  DSplayAdd( splay, "Kilo" );
  DSplayAdd( splay, "Papa" );
  DSplayAdd( splay, "Oscar");
  DSplayAdd( splay, "Lima" );
  DSplayAdd( splay, "November" );
  return DSplayAdd( splay, "Mike" );
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
