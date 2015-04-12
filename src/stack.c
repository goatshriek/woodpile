#include <stdlib.h>

#include <woodpile/stack.h>

#include "static/stack.h"

Stack *
CopyStack
( const Stack *stack )
{
  Stack *copy;
  unsigned i;

  if( !stack )
    return NULL;

  copy = malloc( sizeof( Stack ) );
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
DestroyStack
( Stack *stack )
{
  if( !stack )
    return;

  free( stack->values );
  free( stack );
}

Stack *
NewSizedStack
( size_t size )
{
  return NULL;
}

Stack *
NewStack
( void )
{
  Stack *stack;

  stack = malloc( sizeof( Stack ) );
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
PeekAtStack
( const Stack *stack )
{
  if( !stack || stack->top == 0 )
    return NULL;

  return stack->values[stack->top - 1];
}

void *
PopFromStack
( Stack *stack )
{
  if( !stack || stack->top == 0 )
    return NULL;

  return stack->values[--stack->top];
}

Stack *
PushToStack
( Stack *stack, void *value )
{
  if( !stack )
    return NULL;

  if( stack->top == stack->capacity )
    if( !Resize( stack ) )
      return NULL;

  stack->values[stack->top++] = value;

  return stack;
}

Stack *
SetStackCapacity
( Stack *stack, size_t capacity )
{
  return NULL;
}

size_t
StackCapacity
( const Stack *stack )
{
  if( !stack )
    return 0;

  return stack->capacity;
}

size_t
StackContains
( const Stack *stack, const void *element )
{
  return 0;
}

unsigned short
StackIsEmpty
( const Stack *stack )
{
  return stack == NULL || stack->top == 0;
}

size_t
StackSize
( const Stack *stack )
{
  if( !stack )
    return 0;

  return stack->top;
}

char *
StackToString
( const Stack *stack, char * ( *element_to_string )( const void * ) )
{
  return NULL;
}

static
Stack *
Resize
( Stack *stack )
{
  unsigned i;
  void **new_array;

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
