#include <stdlib.h>
#include <string.h>

#include <woodpile/queue.h>

#include "static/queue.h"

Queue *
CopyQueue
( const Queue *original )
{
  Queue *copy;

  if( !original )
    return NULL;

  copy = malloc( sizeof( Queue ) );
  if( !copy )
    return NULL;

  copy->elements = malloc( sizeof( void * ) * original->capacity );
  if( !copy->elements )
    return NULL;

  memcpy( copy->elements, original->elements, original->capacity );

  copy->back = original->back;
  copy->capacity = original->capacity;
  copy->front = original->front;

  return copy;
}

void
DestroyQueue
( const Queue *queue )
{
  if( !queue )
    return;

  free( ( void * ) queue->elements );
  free( ( void * ) queue );

  return;
}

Queue *
NewQueue
( void )
{
  Queue *queue = malloc( sizeof( Queue ) );
  if( !queue )
    return NULL;

  queue->front = queue->back = 0;
  queue->capacity = 100;

  queue->elements = malloc( sizeof( void * ) * queue->capacity );
  if( !queue->elements )
    return NULL;

  return queue;
}

Queue *
NewSizedQueue
( size_t capacity )
{
  return NULL;
}

void *
PeekAtQueue
( const Queue *queue )
{
  if( QueueIsEmpty( queue ) )
    return NULL;
  else
    return queue->elements[ queue->front ];
}

void *
PopFromQueue
( Queue *queue )
{
  void *value;

  if( !queue || !queue->elements || queue->front == queue->back )
    return NULL;

  value = queue->elements[ queue->front ];

  queue->front = (queue->front + 1) % queue->capacity;

  return value;
}

Queue *
PushToQueue
( Queue *queue, void *element )
{
  size_t new_back;

  if( !queue || !element )
    return NULL;

  new_back = (queue->back + 1) % queue->capacity;
  if( new_back == queue->front )
    return NULL;

  queue->elements[ queue->back ] = element;
  queue->back = new_back;

  return queue;
}

size_t
QueueCapacity
( const Queue *queue )
{
  return 0;
}

size_t
QueueContains
( const Queue *queue, const void *element )
{
  size_t count = 0, current;

  if( QueueIsEmpty( queue ) )
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
QueueIsEmpty
( const Queue *queue )
{
  return queue == NULL || queue->front == queue->back;
}

size_t
QueueSize
( const Queue *queue )
{
  if( !queue )
    return 0;
  if( queue->back >= queue->front )
    return queue->back - queue->front;
  else
    return queue->back + queue->capacity - queue->front;
}

char *
QueueToString
( const Queue *queue, char * ( *element_to_string )( const void * ) )
{
  return NULL;
}

void *
RemoveFromQueue
( Queue *queue, const void *value )
{
  size_t current;
  void *queue_value;

  if( QueueIsEmpty( queue ) )
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

Queue *
SetQueueCapacity
( Queue *queue, size_t capacity )
{
  return NULL;
}

size_t
TrimQueueToSize
( Queue *queue )
{
  return 0;
}
