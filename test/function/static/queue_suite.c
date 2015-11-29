#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <woodpile/config.h>
#include <woodpile/static/queue.h>

#include "test/function/static/queue_suite.h"
#include "test/helper.h"

int
main
( void )
{
  unsigned failure_count = 0;
  const char *result;

#ifdef __WOODPILE_PARAMETER_VALIDATION
  TEST( CopyNullQueue )
  TEST( PopFromNullQueue )
  TEST( PushNullValue )
  TEST( PushToNullQueue )
#endif

  TEST( ContainsDuplicateValues )
  TEST( ContainsNonExistentValue )
  TEST( ContainsNullValue )
  TEST( ContainsUniqueValue )
  TEST( ContainsWithNullQueue )
  TEST( Copy )
  TEST( CopyContents )
  TEST( CopyDistinct )
  TEST( CopySize )
  TEST( DestroyNullQueue )
  TEST( DestroyPopulatedQueue )
  TEST( IsEmptyWithEmptyQueue )
  TEST( IsEmptyWithPopulatedQueue )
  TEST( IsEmptyWithNullQueue )
  TEST( New )
  TEST( PeekAtEmptyQueue )
  TEST( PeekAtNullQueue )
  TEST( PeekAtPopulatedQueue )
  TEST( PopFromEmptyQueue )
  TEST( PopFromPopulatedQueue )
  TEST( PopRemovesValue )
  TEST( PushToEmptyQueue )
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
  SQueue *queue;
  void *value;

  queue = BuildSQueue();
  if( !queue )
    return "could not build Queue";
  
  value = SQueuePeek( queue );
  if( !value )
    return "the Queue did not have any values";

  SQueuePush( queue, value );
  
  if( SQueueContains( queue, value ) != 2 )
    return "2 was not returned with a value existing in the Queue twice";

  SQueuePush( queue, value );
  
  if( SQueueContains( queue, value ) != 3 )
    return "3 was not returned with a value existing in the Queue three times";

  SQueueDestroy( queue );

  return NULL;
}

const char *
TestContainsNonExistentValue
( void )
{
  const SQueue *queue;
  const void *value = "this value does not exist in the Queue";
  
  queue = BuildSQueue();
  if( !queue )
    return "could not build Queue";

  if( SQueueContains( queue, value ) )
    return "a positive value was returned for a value not existing in the provided Queue";

  SQueueDestroy( queue );

  return NULL;
}

const char *
TestContainsNullValue
( void )
{
  const SQueue *queue;

  if( SQueueContains( NULL, NULL ) )
    return "a NULL value and Queue did not return 0";

  queue = BuildSQueue();
  if( !queue )
    return "could not build a Queue";

  if( SQueueContains( queue, NULL ) )
    return "a NULL value and non-NULL Queue did not return 0";

  SQueueDestroy( queue );

  return NULL;
}

const char *
TestContainsUniqueValue
( void )
{
  SQueue *queue;
  void *value = "the Queue will contain this";

  queue = BuildSQueue();
  if( !queue )
    return "could not build a Queue";
  
  SQueuePush( queue, value );

  if( SQueueContains( queue, value ) != 1 )
    return "1 was not returned for a value contained exactly once in the Queue";

  SQueueDestroy( queue );

  return NULL;
}

const char *
TestContainsWithNullQueue
( void )
{
  const void *value = "test value";

  if( SQueueContains( NULL, NULL ) )
    return "a NULL Queue and value did not return 0";

  if( SQueueContains( NULL, value ) )
    return "a NULL Queue and non-NULL value did not return 0";

  return NULL;
}

const char *
TestCopy
( void )
{
  SQueue *copy, *queue;

  queue = BuildSQueue();
  if( !queue )
    return "could not build a Queue";

  copy = SQueueCopy( queue );

  if( !copy )
    return "NULL was returned for a non-NULL Queue";

  SQueueDestroy( copy );
  SQueueDestroy( queue );

  return NULL;
}

const char *
TestCopyContents
( void )
{
  SQueue *copy, *queue;
  const void *copy_value, *queue_value;

  queue = BuildSQueue();
  if( !queue )
    return "could not build a Queue";

  copy = SQueueCopy( queue );
  if( !copy )
    return "the copy of the Queue was NULL";

  while( SQueuePeek( queue ) ){
    queue_value = SQueuePop( queue );
    copy_value = SQueuePop( copy );

    if( queue_value != copy_value )
      return "the copy did not have the same contents as the original";
  }

  SQueueDestroy( copy );
  SQueueDestroy( queue );

  return NULL;
}

const char *
TestCopyDistinct
( void )
{
  const SQueue *copy, *queue;

  queue = BuildSQueue();
  if( !queue )
    return "could not build a Queue";

  copy = SQueueCopy( queue );

  if( copy == queue )
    return "the copy Queue was the same structure as the original Queue";

  SQueueDestroy( copy );
  SQueueDestroy( queue );

  return NULL;
}

const char *
TestCopyNullQueue
( void )
{
  if( SQueueCopy( NULL ) != NULL )
    return "NULL was not returned when copying a NULL Queue";

  return NULL;
}

const char *
TestCopySize
( void )
{
  const SQueue *copy, *queue;

  queue = BuildSQueue();
  if( !queue )
    return "could not build a Queue";

  copy = SQueueCopy( queue );

  if( SQueueSize( queue ) != SQueueSize( copy ) )
    return "the copy was not the same size as the original";

  SQueueDestroy( copy );
  SQueueDestroy( queue );

  return NULL;
}

const char *
TestDestroyNullQueue
( void )
{
  SQueueDestroy( NULL );
  
  return NULL;
}

const char *
TestDestroyPopulatedQueue
( void )
{
  const SQueue *queue;
  
  queue = BuildSQueue();
  if( !queue )
    return "could not build a Queue";

  SQueueDestroy( queue );

  return NULL;
}

const char *
TestIsEmptyWithEmptyQueue
( void )
{
  SQueue *queue;

  queue = SQueueNew();
  if( !queue )
    return "could not build a Queue";

  if( SQueueIsEmpty( queue ) <= 0 )
    return "a non-positive value was returned for an empty Queue";

  SQueueDestroy( queue );

  return NULL;
}

const char *
TestIsEmptyWithPopulatedQueue
( void )
{
  SQueue *queue;
  
  queue = BuildSQueue();
  if( !queue )
    return "could not build a Queue";

  if( SQueueIsEmpty( queue ) > 0 )
    return "a positive value was returned for a populated Queue";

  SQueueDestroy( queue );

  return NULL;
}

const char *
TestIsEmptyWithNullQueue
( void )
{
  if( SQueueIsEmpty( NULL ) <= 0 )
    return "a non-positive value was returned for a NULL Queue";

  return NULL;
}

const char *
TestNew
( void )
{
  const SQueue *queue;

  queue = SQueueNew();
  if( !queue )
    return "a new Queue could not be constructed";

  SQueueDestroy( queue );

  return NULL;
}

const char *
TestPeekAtEmptyQueue
( void )
{
  const SQueue *queue;
  
  queue = SQueueNew();
  if( !queue )
    return "could not build a Queue";

  if( SQueuePeek( queue ) )
    return "an empty Queue returned a value";

  SQueueDestroy( queue );

  return NULL;
}

const char *
TestPeekAtNullQueue
( void )
{
  if( SQueuePeek( NULL ) )
    return "a NULL Queue returned a value";

  return NULL;
}

const char *
TestPeekAtPopulatedQueue
( void )
{
  char *str;
  const SQueue *queue;

  queue = BuildSQueue();
  if( !queue )
    return "could not build a Queue";

  str = SQueuePeek( queue );
  if( !str )
    return "NULL was returned for a populated Queue";

  ASSERT_STRINGS_EQUAL( "front of Queue", str, "the first value in the Queue was not returned" )

  SQueueDestroy( queue );

  return NULL;
}

const char *
TestPopFromEmptyQueue
( void )
{
  SQueue *queue;

  queue = SQueueNew();
  if( !queue )
    return "could not build a Queue";

  if( SQueuePop( queue ) )
    return "a value was popped from an empty Queue";
 
  SQueueDestroy( queue );
 
  return NULL;
}

const char *
TestPopFromNullQueue
( void )
{
  if( SQueuePop( NULL ) )
    return "a value was popped from a NULL Queue";

  return NULL;
}

const char *
TestPopFromPopulatedQueue
( void )
{
  const char *str;
  SQueue *queue;

  queue = BuildSQueue();
  if( !queue )
    return "could not build a Queue";

  str = SQueuePop( queue );
  if( !str )
    return "NULL was returned for a populated Queue";

  ASSERT_STRINGS_EQUAL( "front of Queue", str, "the first value in the Queue was not returned" )

  SQueueDestroy( queue );

  return NULL;
}

const char *
TestPopRemovesValue
( void )
{
  const char *str;
  SQueue *queue;

  queue = BuildSQueue();
  if( !queue )
    return "could not build a Queue";
  
  str = SQueuePop( queue );
  if( !str )
    return "the first pop did not return a value";
  ASSERT_STRINGS_EQUAL( "front of Queue", str, "the first value popped was not the value at the front of the Queue" )
  
  str = SQueuePop( queue );
  if( !str )
    return "the second pop did not return a value";
  ASSERT_STRINGS_EQUAL( "test string", str, "the second value popped was not the second value in the Queue" )
  
  str = SQueuePop( queue );
  if( !str )
    return "the third pop did not return a value";
  ASSERT_STRINGS_EQUAL( "middle string", str, "the third value popped was not the third value in the Queue" )
  
  str = SQueuePop( queue );
  if( !str )
    return "the fourth pop did not return a value";
  ASSERT_STRINGS_EQUAL( "second test string", str, "the fourth value popped was not the fourth value in the Queue" )
  
  str = SQueuePop( queue );
  if( !str )
    return "the fifth pop did not return a value";
  ASSERT_STRINGS_EQUAL( "end of Queue", str, "the fifth value popped was not the fifth value in the Queue" )

  SQueueDestroy( queue );

  return NULL;
}

const char *
TestPushNullValue
( void )
{
  SQueue *queue;

  if( SQueuePush( NULL, NULL ) )
    return "a non-NULL value was returned for a NULL value and Queue";

  queue = BuildSQueue();
  if( !queue )
    return "could not build a Queue";

  if( SQueuePush( queue, NULL ) )
    return "a non-NULL value was returned for a NULL value";

  SQueueDestroy( queue );

  return NULL;
}

const char *
TestPushToEmptyQueue
( void )
{
  SQueue *queue;
  void *value = "test value";

  queue = SQueueNew();
  if( !queue )
    return "could not build a Queue";

  if( SQueuePush( queue, value ) != queue )
    return "pushing a value resulted in a failure";

  if( SQueuePeek( queue ) != value )
    return "the value was not the first in the Queue after a push";

  if( SQueueSize( queue ) != 1 )
    return "pushing to an empty Queue did not result in a size of 1";

  SQueueDestroy( queue );

  return NULL;
}

const char *
TestPushToNullQueue
( void )
{
  void *value = "test value";

  if( SQueuePush( NULL, NULL ) )
    return "a non-NULL value was returned for a NULL Queue and value";

  if( SQueuePush( NULL, value ) )
    return "a non-NULL value was returned for a NULL Queue";

  return NULL;
}

const char *
TestPushToPopulatedQueue
( void )
{
  SQueue *queue;
  size_t i, size;
  void *front_value, *value = "test push string";

  queue = BuildSQueue();
  if( !queue )
    return "could not build a Queue";

  size = SQueueSize( queue );
  front_value = SQueuePeek( queue );
  if( !front_value )
    return "the test Queue did not have a first value";

  if( SQueuePush( queue, value ) != queue )
    return "pushing a value resulted in a failure";

  if( SQueuePeek( queue ) != front_value )
    return "pushing a value changed the front element of the Queue";

  for( i = 0; i < size; i++ )
    SQueuePop( queue );

  if( SQueuePeek( queue ) != value )
    return "the pushed value was not added to the back of the Queue";

  SQueueDestroy( queue );

  return NULL;
}

const char *
TestRemoveDuplicateValues
( void )
{
  SQueue *queue;
  void *value;
  
  queue = BuildSQueue();
  if( !queue )
    return "could not build a Queue";

  value = SQueuePeek( queue );
  if( !value )
    return "the test Queue did not contain any elements";

  if( SQueuePush( queue, value ) != queue )
    return "could not push the value to the Queue";

  if( SQueueRemove( queue, value ) != value )
    return "the value could not be removed from the Queue";

  if( SQueuePeek( queue ) == value )
    return "the first occurence of the value was not removed from the Queue";

  if( !SQueueContains( queue, value ) )
    return "all occurrences of the value were removed from the Queue";

  SQueueDestroy( queue );

  return NULL;
}

const char *
TestRemoveFromNullQueue
( void )
{
  const char *value = "test value";

  if( SQueueRemove( NULL, NULL ) )
    return "a non-NULL value was returned for a NULL Queue and value";

  if( SQueueRemove( NULL, value ) )
    return "a non-NULL value was returned for a NULL Queue";

  return NULL;
}

const char *
TestRemoveLast
( void )
{
  SQueue *queue;
  void *value = "test value";

  queue = SQueueNew();
  if( !queue )
    return "could not build a Queue";

  if( SQueuePush( queue, value ) != queue )
    return "could not push a value to the Queue";

  if( SQueueRemove( queue, value ) != value )
    return "the value could not be removed from the Queue";

  if( !SQueueIsEmpty( queue ) )
    return "the Queue was not empty after the only value was removed from it";

  SQueueDestroy( queue );

  return NULL;
}

const char *
TestRemoveNonExistentValue
( void )
{
  const char *value = "this doesn't exist in the Queue";
  SQueue *queue;

  queue = BuildSQueue();
  if( !queue )
    return "could not build a Queue";

  if( SQueueRemove( queue, value ) != NULL )
    return "a non-NULL value was returned when removing a non-existent value from the Queue";

  SQueueDestroy( queue );

  return NULL;
}

const char *
TestRemoveNullValue
( void )
{
  SQueue *queue;

  if( SQueueRemove( NULL, NULL ) )
    return "a non-NULL value was returned for a NULL value and Queue";

  queue = BuildSQueue();
  if( !queue )
    return "could not build a Queue";

  if( SQueueRemove( queue, NULL ) )
    return "a non-NULL value was returned for a NULL value";

  SQueueDestroy( queue );

  return NULL;
}

const char *
TestRemoveUniqueValue
( void )
{
  SQueue *queue;
  void *value;

  queue = BuildSQueue();
  if( !queue )
    return "could not build a Queue";

  value = SQueuePeek( queue );
  if( !value )
    return "the test Queue did not have any elements";

  if( SQueueRemove( queue, value ) != value )
    return "the value was not returned when removed from a Queue";

  if( SQueueContains( queue, value ) )
    return "the value was not removed from the Queue";

  SQueueDestroy( queue );

  return NULL;
}

const char *
TestSize
( void )
{
  const SQueue *queue;

  queue = BuildSQueue();
  if( !queue )
    return "could not build a Queue";

  if( SQueueSize( queue ) != 5 )
    return "a populated Queue did not return the correct size";

  SQueueDestroy( queue );

  return NULL;
}

const char *
TestSizeWithEmptyQueue
( void )
{
  const SQueue *queue;

  queue = SQueueNew(); 
  if( !queue )
    return "could not build a Queue";

  if( SQueueSize( queue ) != 0 )
    return "an empty Queue did not return 0";

  SQueueDestroy( queue );

  return NULL;
}

const char *
TestSizeWithNullQueue
( void )
{
  if( SQueueSize( NULL ) != 0 )
    return "a NULL Queue did not return 0";

  return NULL;
}
