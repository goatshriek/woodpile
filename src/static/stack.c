#include <stdlib.h>
#include <woodpile/static/stack.h>
#include "lib/validate.h"
#include "private/static/stack.h"

SStack *
SStackCopy
( const SStack *stack )
{
  SStack *copy;
  unsigned i;

  VALIDATE_PARAMETERS( stack )

  copy = malloc( sizeof( SStack ) );
  if( !copy )
    return NULL;

  copy->capacity = stack->capacity;
  copy->values = malloc( sizeof( void * ) * copy->capacity );
  if( !copy->values )
    return NULL;

  for( i = 0; i < stack->top; i++ )
    copy->values[i] = stack->values[i];

  copy->top = stack->top;

  return copy;
}

void
SStackDestroy
( SStack *stack )
{
  if( !stack )
    return;

  free( stack->values );
  free( stack );
}

SStack *
SStackNewSized
( size_t size )
{
  return NULL;
}

SStack *
SStackNew
( void )
{
  SStack *stack;

  stack = malloc( sizeof( SStack ) );
  if( !stack )
    return NULL;

  stack->capacity = 10;
  stack->values = malloc( sizeof( void * ) * stack->capacity );
  if( !stack->values )
    return NULL;
  stack->top = 0;

  return stack;
}

void *
SStackPeek
( const SStack *stack )
{
  VALIDATE_PARAMETERS( stack )

  if( stack->top == 0 )
    return NULL;
  else
    return stack->values[stack->top - 1];
}

void *
SStackPop
( SStack *stack )
{
  VALIDATE_PARAMETERS( stack )

  if( stack->top == 0 )
    return NULL;
  else
    return stack->values[--stack->top];
}

SStack *
SStackPush
( SStack *stack, void *value )
{
  VALIDATE_PARAMETERS( stack )

  if( stack->top == stack->capacity )
    if( !Resize( stack ) )
      return NULL;

  stack->values[stack->top++] = value;

  return stack;
}

SStack *
SStackSetCapacity
( SStack *stack, size_t capacity )
{
  return NULL;
}

size_t
SStackCapacity
( const SStack *stack )
{
  if( !stack )
    return 0;

  return stack->capacity;
}

size_t
SStackContains
( const SStack *stack, const void *element )
{
  return 0;
}

unsigned short
SStackIsEmpty
( const SStack *stack )
{
  return stack == NULL || stack->top == 0;
}

size_t
SStackSize
( const SStack *stack )
{
  if( !stack )
    return 0;

  return stack->top;
}

char *
SStackToString
( const SStack *stack, char * ( *element_to_string )( const void * ) )
{
  return NULL;
}

static
SStack *
Resize
( SStack *stack )
{
  unsigned i;
  void **new_array;

  VALIDATE_PARAMETERS( stack )

  stack->capacity *= 2;

  new_array = malloc( sizeof( void * ) * stack->capacity );
  if( !new_array )
    return NULL;

  for( i = 0; i < stack->top; i++ )
    new_array[i] = stack->values[i];

  free( stack->values );
  stack->values = new_array;

  return stack;
}
