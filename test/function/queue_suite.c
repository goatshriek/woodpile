#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <woodpile/queue.h>

#include "test/function/queue_suite.h"
#include "test/helper.h"

int
main
( void )
{
  unsigned failure_count = 0;
  const char *result;

  TEST( ContainsDuplicateValues )
  TEST( ContainsNonExistentValue )
  TEST( ContainsNullValue )
  TEST( ContainsUniqueValue )
  TEST( ContainsWithNullQueue )
  TEST( Copy )
  TEST( CopyContents )
  TEST( CopyNotSame )
  TEST( CopyNullQueue )
  TEST( Destroy )
  TEST( DestroyNullQueue )
  TEST( IsEmptyWithEmptyQueue )
  TEST( IsEmptyWithPopulatedQueue )
  TEST( IsEmptyWithNullQueue )
  TEST( New )
  TEST( PeekAtEmptyQueue )
  TEST( PeekAtNullQueue )
  TEST( PeekAtPopulatedQueue )
  TEST( PopFromEmptyQueue )
  TEST( PopFromNullQueue )
  TEST( PopFromPopulatedQueue )
  TEST( PopRemovesValue )
  TEST( PushNullValue )
  TEST( PushToEmptyQueue )
  TEST( PushToNullQueue )
  TEST( PushToPopulatedQueue )
  TEST( RemoveDuplicateValues )
  TEST( RemoveFromNullQueue )
  TEST( RemoveLast )
  TEST( RemoveNonExistentValue )
  TEST( RemoveNullValue )
  TEST( RemoveUniqueValue )
  TEST( Size )
  TEST( SizeWithEmptyQueue )
  TEST( SizeWithNullQueue )

  if( failure_count > 0 )
    return EXIT_FAILURE;
  else
    return EXIT_SUCCESS;
}

const char *
TestContainsDuplicateValues
( void )
{
  Queue *queue;
  void *value;

  queue = BuildQueue();
  if( !queue )
    return "could not build Queue";
  
  value = PeekAtQueue( queue );
  if( !value )
    return "the Queue did not have any values";

  PushToQueue( queue, value );
  
  if( QueueContains( queue, value ) != 2 )
    return "2 was not returned with a value existing in the Queue twice";

  PushToQueue( queue, value );
  
  if( QueueContains( queue, value ) != 3 )
    return "3 was not returned with a value existing in the Queue three times";

  DestroyQueue( queue );

  return NULL;
}

const char *
TestContainsNonExistentValue
( void )
{
  const Queue *queue;
  const void *value = "this value does not exist in the Queue";
  
  queue = BuildQueue();
  if( !queue )
    return "could not build Queue";

  if( QueueContains( queue, value ) )
    return "a positive value was returned for a value not existing in the provided Queue";

  DestroyQueue( queue );

  return NULL;
}

const char *
TestContainsNullValue
( void )
{
  const Queue *queue;

  if( QueueContains( NULL, NULL ) )
    return "a NULL value and Queue did not return 0";

  queue = BuildQueue();
  if( !queue )
    return "could not build a Queue";

  if( QueueContains( queue, NULL ) )
    return "a NULL value and non-NULL Queue did not return 0";

  DestroyQueue( queue );

  return NULL;
}

const char *
TestContainsUniqueValue
( void )
{
  Queue *queue;
  void *value = "the Queue will contain this";

  queue = BuildQueue();
  if( !queue )
    return "could not build a Queue";
  
  PushToQueue( queue, value );

  if( QueueContains( queue, value ) != 1 )
    return "1 was returned for a value contained exactly once in the Queue";

  DestroyQueue( queue );

  return NULL;
}

const char *
TestContainsWithNullQueue
( void )
{
  const void *value = "test value";

  if( QueueContains( NULL, NULL ) )
    return "a NULL Queue and value did not return 0";

  if( QueueContains( NULL, value ) )
    return "a NULL Queue and non-NULL value did not return 0";

  return NULL;
}

const char *
TestCopy
( void )
{
  Queue *copy, *queue;

  queue = BuildQueue();
  if( !queue )
    return "could not build a Queue";

  copy = CopyQueue( queue );

  if( !copy )
    return "NULL was returned for a non-NULL Queue";

  DestroyQueue( copy );
  DestroyQueue( queue );

  return NULL;
}

const char *
TestCopyContents
( void )
{
  Queue *copy, *queue;
  const void *copy_value, *queue_value;

  queue = BuildQueue();
  if( !queue )
    return "could not build a Queue";

  copy = CopyQueue( queue );
  if( !copy )
    return "the copy of the Queue was NULL";

  while( PeekAtQueue( queue ) ){
    queue_value = PopFromQueue( queue );
    copy_value = PopFromQueue( copy );

    if( queue_value != copy_value )
      return "the copy did not have the same contents as the original";
  }

  DestroyQueue( copy );
  DestroyQueue( queue );

  return NULL;
}

const char *
TestCopyNotSame
( void )
{
  const Queue *copy, *queue;

  queue = BuildQueue();
  if( !queue )
    return "could not build a Queue";

  copy = CopyQueue( queue );

  if( copy == queue )
    return "the copy Queue was the same structure as the original Queue";

  DestroyQueue( copy );
  DestroyQueue( queue );

  return NULL;
}

const char *
TestCopyNullQueue
( void )
{
  if( CopyQueue( NULL ) != NULL )
    return "NULL was not returned for a NULL Queue";

  return NULL;
}

const char *
TestDestroy
( void )
{
  Queue *queue;
  
  queue = BuildQueue();
  if( !queue )
    return "could not build a Queue";

  DestroyQueue( queue );

  return NULL;
}

const char *
TestDestroyNullQueue
( void )
{
  DestroyQueue( NULL );
  
  return NULL;
}

const char *
TestIsEmptyWithEmptyQueue
( void )
{
  Queue *queue;

  queue = NewQueue();
  if( !queue )
    return "could not build a Queue";

  if( QueueIsEmpty( queue ) <= 0 )
    return "a non-positive value was returned for an empty Queue";

  DestroyQueue( queue );

  return NULL;
}

const char *
TestIsEmptyWithPopulatedQueue
( void )
{
  Queue *queue;
  
  queue = BuildQueue();
  if( !queue )
    return "could not build a Queue";

  if( QueueIsEmpty( queue ) > 0 )
    return "a positive value was returned for a populated Queue";

  DestroyQueue( queue );

  return NULL;
}

const char *
TestIsEmptyWithNullQueue
( void )
{
  if( QueueIsEmpty( NULL ) <= 0 )
    return "a non-positive value was returned for a NULL Queue";

  return NULL;
}

const char *
TestNew
( void )
{
  Queue *queue;

  queue = NewQueue();
  if( !queue )
    return "a new Queue could not be constructed";

  DestroyQueue( queue );

  return NULL;
}

const char *
TestPeekAtEmptyQueue
( void )
{
  const Queue *queue;
  
  queue = NewQueue();
  if( !queue )
    return "could not build a Queue";

  if( PeekAtQueue( queue ) )
    return "an empty Queue returned a value";

  DestroyQueue( queue );

  return NULL;
}

const char *
TestPeekAtNullQueue
( void )
{
  if( PeekAtQueue( NULL ) )
    return "a NULL Queue returned a value";

  return NULL;
}

const char *
TestPeekAtPopulatedQueue
( void )
{
  char *str;
  const Queue *queue;

  queue = BuildQueue();
  if( !queue )
    return "could not build a Queue";

  str = PeekAtQueue( queue );
  if( !str )
    return "NULL was returned for a populated Queue";

  ASSERT_STRINGS_EQUAL( "front of Queue", str, "the first value in the Queue was not returned" )

  DestroyQueue( queue );

  return NULL;
}

const char *
TestPopFromEmptyQueue
( void )
{
  Queue *queue;

  queue = NewQueue();
  if( !queue )
    return "could not build a Queue";

  if( PopFromQueue( queue ) )
    return "a value was popped from an empty Queue";
 
  DestroyQueue( queue );
 
  return NULL;
}

const char *
TestPopFromNullQueue
( void )
{
  if( PopFromQueue( NULL ) )
    return "a value was popped from a NULL Queue";

  return NULL;
}

const char *
TestPopFromPopulatedQueue
( void )
{
  const char *str;
  Queue *queue;

  queue = BuildQueue();
  if( !queue )
    return "could not build a Queue";

  str = PopFromQueue( queue );
  if( !str )
    return "NULL was returned for a populated Queue";

  ASSERT_STRINGS_EQUAL( "front of Queue", str, "the first value in the Queue was not returned" )

  DestroyQueue( queue );

  return NULL;
}

const char *
TestPopRemovesValue
( void )
{
  const char *str;
  Queue *queue;

  queue = BuildQueue();
  if( !queue )
    return "could not build a Queue";
  
  str = PopFromQueue( queue );
  if( !str )
    return "the first pop did not return a value";
  ASSERT_STRINGS_EQUAL( "front of Queue", str, "the first value popped was not the value at the front of the Queue" )
  
  str = PopFromQueue( queue );
  if( !str )
    return "the second pop did not return a value";
  ASSERT_STRINGS_EQUAL( "test string", str, "the second value popped was not the second value in the Queue" )
  
  str = PopFromQueue( queue );
  if( !str )
    return "the third pop did not return a value";
  ASSERT_STRINGS_EQUAL( "middle string", str, "the third value popped was not the third value in the Queue" )
  
  str = PopFromQueue( queue );
  if( !str )
    return "the fourth pop did not return a value";
  ASSERT_STRINGS_EQUAL( "second test string", str, "the fourth value popped was not the fourth value in the Queue" )
  
  str = PopFromQueue( queue );
  if( !str )
    return "the fifth pop did not return a value";
  ASSERT_STRINGS_EQUAL( "end of Queue", str, "the fifth value popped was not the fifth value in the Queue" )

  DestroyQueue( queue );

  return NULL;
}

const char *
TestPushNullValue
( void )
{
  Queue *queue;

  if( PushToQueue( NULL, NULL ) )
    return "a non-NULL value was returned for a NULL value and Queue";

  queue = BuildQueue();
  if( !queue )
    return "could not build a Queue";

  if( PushToQueue( queue, NULL ) )
    return "a non-NULL value was returned for a NULL value";

  DestroyQueue( queue );

  return NULL;
}

const char *
TestPushToEmptyQueue
( void )
{
  Queue *queue;
  void *value = "test value";

  queue = NewQueue();
  if( !queue )
    return "could not build a Queue";

  if( PushToQueue( queue, value ) != queue )
    return "pushing a value resulted in a failure";

  if( PeekAtQueue( queue ) != value )
    return "the value was not the first in the Queue after a push";

  if( QueueSize( queue ) != 1 )
    return "pushing to an empty Queue did not result in a size of 1";

  DestroyQueue( queue );

  return NULL;
}

const char *
TestPushToNullQueue
( void )
{
  void *value = "test value";

  if( PushToQueue( NULL, NULL ) )
    return "a non-NULL value was returned for a NULL Queue and value";

  if( PushToQueue( NULL, value ) )
    return "a non-NULL value was returned for a NULL Queue";

  return NULL;
}

const char *
TestPushToPopulatedQueue
( void )
{
  Queue *queue;
  unsigned i, size;
  void *front_value, *value = "test push string";

  queue = BuildQueue();
  if( !queue )
    return "could not build a Queue";

  size = QueueSize( queue );
  front_value = PeekAtQueue( queue );
  if( !front_value )
    return "the test Queue did not have a first value";

  if( PushToQueue( queue, value ) != queue )
    return "pushing a value resulted in a failure";

  if( PeekAtQueue( queue ) != front_value )
    return "pushing a value changed the front element of the Queue";

  for( i = 0; i < size; i++ )
    PopFromQueue( queue );

  if( PeekAtQueue( queue ) != value )
    return "the pushed value was not added to the back of the Queue";

  DestroyQueue( queue );

  return NULL;
}

const char *
TestRemoveDuplicateValues
( void )
{
  Queue *queue;
  void *value;
  
  queue = BuildQueue();
  if( !queue )
    return "could not build a Queue";

  value = PeekAtQueue( queue );
  if( !value )
    return "the test Queue did not contain any elements";

  if( PushToQueue( queue, value ) != queue )
    return "could not push the value to the Queue";

  if( RemoveFromQueue( queue, value ) != value )
    return "the value could not be removed from the Queue";

  if( PeekAtQueue( queue ) == value )
    return "the first occurence of the value was not removed from the Queue";

  if( !QueueContains( queue, value ) )
    return "all occurrences of the value were removed from the Queue";

  DestroyQueue( queue );

  return NULL;
}

const char *
TestRemoveFromNullQueue
( void )
{
  const char *value = "test value";

  if( RemoveFromQueue( NULL, NULL ) )
    return "a non-NULL value was returned for a NULL Queue and value";

  if( RemoveFromQueue( NULL, value ) )
    return "a non-NULL value was returned for a NULL Queue";

  return NULL;
}

const char *
TestRemoveLast
( void )
{
  Queue *queue;
  void *value = "test value";

  queue = NewQueue();
  if( !queue )
    return "could not build a Queue";

  if( PushToQueue( queue, value ) != queue )
    return "could not push a value to the Queue";

  if( RemoveFromQueue( queue, value ) != value )
    return "the value could not be removed from the Queue";

  if( !QueueIsEmpty( queue ) )
    return "the Queue was not empty after the only value was removed from it";

  DestroyQueue( queue );

  return NULL;
}

const char *
TestRemoveNonExistentValue
( void )
{
  const char *value = "this doesn't exist in the Queue";
  Queue *queue;

  queue = BuildQueue();
  if( !queue )
    return "could not build a Queue";

  if( RemoveFromQueue( queue, value ) != NULL )
    return "a non-NULL value was returned when removing a non-existent value from the Queue";

  DestroyQueue( queue );

  return NULL;
}

const char *
TestRemoveNullValue
( void )
{
  Queue *queue;

  if( RemoveFromQueue( NULL, NULL ) )
    return "a non-NULL value was returned for a NULL value and Queue";

  queue = BuildQueue();
  if( !queue )
    return "could not build a Queue";

  if( RemoveFromQueue( queue, NULL ) )
    return "a non-NULL value was returned for a NULL value";

  DestroyQueue( queue );

  return NULL;
}

const char *
TestRemoveUniqueValue
( void )
{
  Queue *queue;
  void *value;

  queue = BuildQueue();
  if( !queue )
    return "could not build a Queue";

  value = PeekAtQueue( queue );
  if( !value )
    return "the test Queue did not have any elements";

  if( RemoveFromQueue( queue, value ) != value )
    return "the value was not returned when removed from a Queue";

  if( QueueContains( queue, value ) )
    return "the value was not removed from the Queue";

  DestroyQueue( queue );

  return NULL;
}

const char *
TestSize
( void )
{
  const Queue *queue;

  queue = BuildQueue();
  if( !queue )
    return "could not build a Queue";

  if( QueueSize( queue ) != 5 )
    return "a populated Queue did not return the correct size";

  DestroyQueue( queue );

  return NULL;
}

const char *
TestSizeWithEmptyQueue
( void )
{
  const Queue *queue;

  queue = NewQueue(); 
  if( !queue )
    return "could not build a Queue";

  if( QueueSize( queue ) != 0 )
    return "an empty Queue did not return 0";

  DestroyQueue( queue );

  return NULL;
}

const char *
TestSizeWithNullQueue
( void )
{
  if( QueueSize( NULL ) != 0 )
    return "a NULL Queue did not return 0";

  return NULL;
}
