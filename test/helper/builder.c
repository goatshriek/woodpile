#include <stdlib.h>
#include <string.h>
#include <woodpile/dynamic/list.h>
#include <woodpile/dynamic/tree/splay.h>
#include <woodpile/hasher.h>
#include <woodpile/static/queue.h>
#include "test/helper/builder.h"
#include "test/helper/fixture.h"

dlist_t *
BuildDList
( void )
{
  dlist_t *list = DListNew();

  DListAppend( list, "This" );
  DListAppend( list, "is" );
  DListAppend( list, "a" );
  DListAppend( list, "test" );
  DListAppend( list, "List" );
  DListAppend( list, "o'" );
  return DListAppend( list, "strings!" );
}

dsplay_t *
BuildDSplay
( void )
{
  dsplay_t *splay = DSplayNewWithComparator( CompareStrings );

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

shash_t *
BuildFullSHash
( void )
{
  shash_t *hash;

  hash = SHashNewDictionary();
  if( !hash )
    return NULL;

  SHashSetCapacity( hash, 7 );
  SHashSetHasher( hash, NullHash );
  SHashSetElementComparator( hash, CompareStrings );

  SHashPut( hash, "do", "c" );
  SHashPut( hash, "re", "d" );
  SHashPut( hash, "mi", "e" );
  SHashPut( hash, "fa", "f" );
  SHashPut( hash, "so", "g" );
  SHashPut( hash, "la", "a" );
  SHashPut( hash, "ti", "b" );

  return hash;
}

shash_t *
BuildSHash
( void )
{
  shash_t *hash;

  hash = SHashNewDictionary();
  if( !hash )
    return NULL;

  SHashSetHasher( hash, NullHash );
  SHashSetElementComparator( hash, CompareStrings );

  SHashPut( hash, "1st", "First" );
  SHashPut( hash, "2nd", "Second" );
  SHashPut( hash, "3rd", "Third" );
  SHashPut( hash, "4th", "Fourth" );
  SHashPut( hash, "5th", "Fifth" );
  SHashPut( hash, "6th", "Sixth" );
  SHashPut( hash, "7th", "Seventh" );
  SHashPut( hash, "8th", "Eighth" );
  SHashPut( hash, "9th", "Ninth" );
  SHashPut( hash, "10th", "Tenth" );

  return hash;
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
