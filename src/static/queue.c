#include <stdlib.h>
#include <string.h>
#include <woodpile/static/queue.h>
#include "lib/validate.h"
#include "private/static/queue.h"

SQueue *
SQueueCopy
( const SQueue *original )
{
  SQueue *copy;

  VALIDATE_PARAMETERS( original )

  copy = malloc( sizeof( SQueue ) );
  VALIDATE_ALLOCATION( copy )

  copy->elements = malloc( sizeof( void * ) * original->capacity );
  VALIDATE_ALLOCATION( copy )

  memcpy( copy->elements, original->elements, original->capacity );

  copy->back = original->back;
  copy->capacity = original->capacity;
  copy->front = original->front;

  return copy;
}

void
SQueueDestroy
( const SQueue *queue )
{
  if( !queue )
    return;

  free( ( void * ) queue->elements );
  free( ( void * ) queue );

  return;
}

SQueue *
SQueueNew
( void )
{
  SQueue *queue = malloc( sizeof( SQueue ) );
  VALIDATE_ALLOCATION( queue )

  queue->front = queue->back = 0;
  queue->capacity = 100;

  queue->elements = malloc( sizeof( void * ) * queue->capacity );
  VALIDATE_ALLOCATION( queue->elements )

  return queue;
}

SQueue *
SQueueNewSized
( size_t capacity )
{
  return NULL;
}

void *
SQueuePeek
( const SQueue *queue )
{
  if( SQueueIsEmpty( queue ) )
    return NULL;
  else
    return queue->elements[ queue->front ];
}

void *
SQueuePop
( SQueue *queue )
{
  void *value;

  VALIDATE_PARAMETERS( queue && queue->elements )

  if( queue->front == queue->back )
    return NULL;

  value = queue->elements[ queue->front ];

  queue->front = (queue->front + 1) % queue->capacity;

  return value;
}

SQueue *
SQueuePush
( SQueue *queue, void *element )
{
  size_t new_back;

  VALIDATE_PARAMETERS( queue && element )

  new_back = (queue->back + 1) % queue->capacity;
  if( new_back == queue->front )
    return NULL;

  queue->elements[ queue->back ] = element;
  queue->back = new_back;

  return queue;
}

size_t
SQueueCapacity
( const SQueue *queue )
{
  return 0;
}

size_t
SQueueContains
( const SQueue *queue, const void *element )
{
  size_t count = 0, current;

  if( SQueueIsEmpty( queue ) )
    return 0;

  current = queue->front;
  while( current != queue->back ){
    if( queue->elements[current] == element )
      count++;

    current = ( current + 1 ) % queue->capacity;
  }

  return count;
}

unsigned short
SQueueIsEmpty
( const SQueue *queue )
{
  return queue == NULL || queue->front == queue->back;
}

size_t
SQueueSize
( const SQueue *queue )
{
  if( !queue )
    return 0;
  if( queue->back >= queue->front )
    return queue->back - queue->front;
  else
    return queue->back + queue->capacity - queue->front;
}

char *
SQueueToString
( const SQueue *queue, char * ( *element_to_string )( const void * ) )
{
  return NULL;
}

void *
SQueueRemove
( SQueue *queue, const void *value )
{
  size_t current;
  void *queue_value;

  if( SQueueIsEmpty( queue ) )
    return NULL;

  current = queue->front;
  while( current != queue->back ){
    queue_value = queue->elements[current];

    if( queue_value == value ){
      queue->back = queue->back == 0 ? queue->capacity - 1 : queue->back - 1;

      while( current != queue->back ){
        queue->elements[current] = queue->elements[( current + 1 ) % queue->capacity];
        current = (current + 1 ) % queue->capacity;
      }

      return queue_value;
    }

    current = ( current + 1 ) % queue->capacity;
  }

  return NULL;
}

SQueue *
SQueueSetCapacity
( SQueue *queue, size_t capacity )
{
  return NULL;
}

size_t
SQueueTrimToSize
( SQueue *queue )
{
  return 0;
}
