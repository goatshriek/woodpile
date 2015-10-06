#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <woodpile/dynamic/tree/splay/iterator.h>

#include "test/function/dynamic/tree/splay/iterator_suite.h"
#include "test/helper.h"

int
main( void )
{
  unsigned failure_count = 0;
  const char *result;

  TEST( BeginWithEmptyDynamicSplay )
  TEST( BeginWithNullDynamicSplay )
  TEST( BeginWithPopulatedDynamicSplay )
  TEST( Copy )
  TEST( CopyContents )
  TEST( CopyDistinct )
  TEST( CopyNullIterator )
  TEST( CopyPosition )
  TEST( Destroy )
  TEST( DestroyNullIterator )
  TEST( EndWithEmptyDynamicSplay )
  TEST( EndWithNullDynamicSplay )
  TEST( EndWithPopulatedDynamicSplay )
  TEST( HasNextAtBeginning )
  TEST( HasNextAtEnd )
  TEST( HasNextAtMiddle )
  TEST( HasNextWithEmptyDynamicSplay )
  TEST( HasNextWithNullIterator )
  TEST( HasPreviousAtBeginning )
  TEST( HasPreviousAtEnd )
  TEST( HasPreviousAtMiddle )
  TEST( HasPreviousWithEmptyDynamicSplay )
  TEST( HasPreviousWithNullIterator )
  TEST( NextAtBeginning )
  TEST( NextAtEnd )
  TEST( NextAtMiddle )
  TEST( NextWithEmptyDynamicSplay )
  TEST( NextWithNullIterator )
  TEST( PreviousAtBeginning )
  TEST( PreviousAtEnd )
  TEST( PreviousAtMiddle )
  TEST( PreviousWithEmptyDynamicSplay )
  TEST( PreviousWithNullIterator )
  TEST( RemoveAfterNext )
  TEST( RemoveAfterPrevious )
  TEST( RemoveAfterRemove )
  TEST( RemoveBeforeNextOrPrevious )
  TEST( RemoveFromNullIterator )

  if( failure_count > 0 )
    return EXIT_FAILURE;
  else
    return EXIT_SUCCESS;
}

const char *
TestBeginWithEmptyDynamicSplay
( void )
{
  DSplay *splay;
  DSplayItr *iterator;

  splay = DSplayNew( NULL );
  if( !splay )
    return "could not build a splay";

  iterator = DSplayBegin( splay );
  if( !iterator )
    return "a NULL iterator was returned for an empty splay";

  if( DSplayItrPrevious( iterator ) != NULL )
    return "the previous element in the iterator was non-NULL";

  if( DSplayItrNext( iterator ) != NULL )
    return "the next element in the iterator was non-NULL";

  DSplayItrDestroy( iterator );
  DSplayDestroy( splay );

  return NULL;
}

const char *
TestBeginWithNullDynamicSplay
( void )
{
  if( DSplayBegin( NULL ) != NULL )
    return "a non-NULL iterator was returned for a NULL List";

  return NULL;
}

const char *
TestBeginWithPopulatedDynamicSplay
( void )
{
  DSplay *splay;
  DSplayItr *iterator;
  const void *element;

  splay = BuildDSplay();
  if( !splay )
    return "could not build a List";

  iterator = DSplayBegin( splay );
  if( !iterator )
    return "a NULL iterator was returned for a populated List";

  if( DSplayItrPrevious( iterator ) != NULL )
    return "the previous element of the iterator was non-NULL";

  element = DSplayItrNext( iterator );
  if( !element )
    return "the next element of the iterator was NULL";
  ASSERT_STRINGS_EQUAL( "Alpha", element, "the next element of the iterator was not the first element of the List" )

  DSplayDestroy( splay );
  DSplayItrDestroy( iterator );

  return NULL;
}

const char *
TestCopy
( void )
{
  DSplay *splay;
  DSplayItr *copy, *iterator;

  splay = BuildDSplay();
  if( !splay )
    return "could not build a List";

  iterator = DSplayBegin( splay );
  if( !iterator )
    return "could not build a iterator";

  copy = DSplayItrCopy( iterator );
  if( copy == NULL )
    return "NULL was returned for a non-NULL iterator";

  DSplayDestroy( splay );
  DSplayItrDestroy( copy );
  DSplayItrDestroy( iterator );

  return NULL;
}

const char *
TestCopyContents
( void )
{
  DSplay *splay;
  DSplayItr *copy, *iterator;
  const void *element;

  splay = BuildDSplay();
  if( !splay )
    return "could not build a List";

  iterator = DSplayBegin( splay );
  if( !iterator )
    return "could not build a iterator";

  copy = DSplayItrCopy( iterator );
  if( !copy )
    return "could not copy a iterator";

  element = DSplayItrNext( copy );
  if( !element )
    return "the copied iterator did not have a first element";

  if( element != DSplayFirst( splay ) )
    return "the first element in the iterator was not the first element in the List";

  if( element != DSplayItrNext( iterator ) )
    return "the first element in the original did not match the first element of the copy";

  DSplayDestroy( splay );
  DSplayItrDestroy( copy );
  DSplayItrDestroy( iterator );

  return NULL;
}

const char *
TestCopyDistinct
( void )
{
  DSplay *splay;
  DSplayItr *copy, *iterator;
  const void *element_1, *element_2, *element_3;

  splay = BuildDSplay();
  if( !splay )
    return "could not build a List";

  iterator = DSplayBegin( splay );
  if( !iterator )
    return "could not build a iterator";

  copy = DSplayItrCopy( iterator );
  if( !copy )
    return "could not copy a iterator";

  if( copy == iterator )
    return "the copy was the same structure as the original";

  element_1 = DSplayItrNext( copy );
  if( !element_1 )
    return "there was no first element";
  element_2 = DSplayItrNext( copy );
  if( !element_2 )
    return "there was no second element";
  element_3 = DSplayItrNext( copy );
  if( !element_3 )
    return "there was no third element";

  if( DSplayItrNext( iterator ) != element_1 )
    return "advancing the pointer of the copy changed the pointer of the original";

  DSplayItrPrevious( copy );
  DSplayItrPrevious( copy );

  if( DSplayItrPrevious( iterator ) != element_1 )
    return "backing up the pointer of the copy changed the pointer of the original";

  DSplayDestroy( splay );
  DSplayItrDestroy( copy );
  DSplayItrDestroy( iterator );

  return NULL;
}

const char *
TestCopyNullIterator
( void )
{
  if( DSplayItrCopy( NULL ) != NULL )
    return "a non-NULL value was returned when copying NULL";

  return NULL;
}

const char *
TestCopyPosition
( void )
{
  DSplay *splay;
  DSplayItr *copy, *iterator;

  splay = BuildDSplay();
  if( !splay )
    return "could not build a List";

  iterator = DSplayBegin( splay );
  if( !iterator )
    return "could not build a iterator";

  DSplayItrNext( iterator );
  DSplayItrNext( iterator );

  copy = DSplayItrCopy( iterator );
  if( !copy )
    return "could not copy a iterator";

  if( DSplayItrNext( iterator ) != DSplayItrNext( copy ) )
    return "the position of the iterator was not the same in the copy as the original";

  DSplayDestroy( splay );
  DSplayItrDestroy( copy );
  DSplayItrDestroy( iterator );

  return NULL;
}

const char *
TestDestroy
( void )
{
  DSplay *splay;
  DSplayItr *iterator;

  splay = BuildDSplay();
  if( !splay )
    return "could not build a List";

  iterator = DSplayBegin( splay );
  if( !iterator )
    return "could not build a iterator";

  DSplayItrDestroy( iterator );

  DSplayDestroy( splay );

  return NULL;
}

const char *
TestDestroyNullIterator
( void )
{
  DSplayItrDestroy( NULL );

  return NULL;
}

const char *
TestEndWithEmptyDynamicSplay
( void )
{
  DSplay *splay;
  DSplayItr *iterator;

  splay = DSplayNew( NULL );
  if( !splay )
    return "could not build a List";

  iterator = DSplayEnd( splay );
  if( !iterator )
    return "a NULL iterator was returned for an empty List";

  if( DSplayItrPrevious( iterator ) != NULL )
    return "the previous element in the iterator was non-NULL";

  if( DSplayItrNext( iterator ) != NULL )
    return "the next element in the iterator was non-NULL";

  DSplayDestroy( splay );
  DSplayItrDestroy( iterator );

  return NULL;
}

const char *
TestEndWithNullDynamicSplay
( void )
{
  if( DSplayEnd( NULL ) != NULL )
    return "a non-NULL iterator was returned for a NULL List";

  return NULL;
}

const char *
TestEndWithPopulatedDynamicSplay
( void )
{
  DSplay *splay;
  DSplayItr *iterator;
  const void *element;

  splay = BuildDSplay();
  if( !splay )
    return "could not build a List";

  iterator = DSplayEnd( splay );
  if( !iterator )
    return "a NULL iterator was returned for a populated List";

  if( DSplayItrNext( iterator ) != NULL )
    return "the next element of the iterator was non-NULL";

  element = DSplayItrPrevious( iterator );
  if( !element )
    return "the previous element of the iterator was NULL";
  ASSERT_STRINGS_EQUAL( "Zulu", element, "the previous element of the iterator was not the last element of the List" )

  DSplayDestroy( splay );
  DSplayItrDestroy( iterator );

  return NULL;
}

const char *
TestHasNextAtBeginning
( void )
{
  DSplay *splay;
  DSplayItr *iterator;

  splay = BuildDSplay();
  if( !splay )
    return "could not build a List";

  iterator = DSplayBegin( splay );
  if( !iterator )
    return "could not build a iterator";

  if( !DSplayItrHasNext( iterator ) )
    return "a iterator at the beginning of a List returned false";

  DSplayDestroy( splay );
  DSplayItrDestroy( iterator );

  return NULL;
}

const char *
TestHasNextAtEnd
( void )
{
  DSplay *splay;
  DSplayItr *iterator;

  splay = BuildDSplay();
  if( !splay )
    return "could not build a List";

  iterator = DSplayEnd( splay );
  if( !iterator )
    return "could not build a iterator";

  if( DSplayItrHasNext( iterator ) )
    return "a iterator at the end of a List returned true";

  DSplayDestroy( splay );
  DSplayItrDestroy( iterator );

  return NULL;
}

const char *
TestHasNextAtMiddle
( void )
{
  DSplay *splay;
  DSplayItr *iterator;

  splay = BuildDSplay();
  if( !splay )
    return "could not build a List";

  iterator = DSplayBegin( splay );
  if( !iterator )
    return "could not build a iterator";

  DSplayItrNext( iterator );
  DSplayItrNext( iterator );
  DSplayItrNext( iterator );

  if( !DSplayItrHasNext( iterator ) )
    return "a iterator in the middle of a List returned false";

  DSplayDestroy( splay );
  DSplayItrDestroy( iterator );

  return NULL;
}

const char *
TestHasNextWithEmptyDynamicSplay
( void )
{
  DSplay *splay;
  DSplayItr *iterator;

  splay = DSplayNew( NULL );
  if( !splay )
    return "could not build an empty splay";

  iterator = DSplayBegin( splay );
  if( !iterator )
    return "could not build a iterator";

  if( DSplayItrHasNext( iterator ) )
    return "an empty splay returned true";

  DSplayDestroy( splay );
  DSplayItrDestroy( iterator );

  return NULL;
}

const char *
TestHasNextWithNullIterator
( void )
{
  if( DSplayItrHasNext( NULL ) )
    return "a NULL iterator returned true";

  return NULL;
}

const char *
TestHasPreviousAtBeginning
( void )
{
  DSplay *splay;
  DSplayItr *iterator;

  splay = BuildDSplay();
  if( !splay )
    return "could not build a List";

  iterator = DSplayBegin( splay );
  if( !iterator )
    return "could not build a iterator";

  if( DSplayItrHasPrevious( iterator ) )
    return "a iterator at the beginning of a List returned true";

  DSplayDestroy( splay );
  DSplayItrDestroy( iterator );

  return NULL;
}

const char *
TestHasPreviousAtEnd
( void )
{
  DSplay *splay;
  DSplayItr *iterator;

  splay = BuildDSplay();
  if( !splay )
    return "could not build a List";

  iterator = DSplayEnd( splay );
  if( !iterator )
    return "could not build a iterator";

  if( !DSplayItrHasPrevious( iterator ) )
    return "a iterator at the end of a List returned false";

  DSplayDestroy( splay );
  DSplayItrDestroy( iterator );

  return NULL;
}

const char *
TestHasPreviousAtMiddle
( void )
{
  DSplay *splay;
  DSplayItr *iterator;

  splay = BuildDSplay();
  if( !splay )
    return "could not build a List";

  iterator = DSplayBegin( splay );
  if( !iterator )
    return "could not build a iterator";

  DSplayItrNext( iterator );
  DSplayItrNext( iterator );
  DSplayItrNext( iterator );

  if( !DSplayItrHasPrevious( iterator ) )
    return "a iterator in the middle of a List returned false";

  DSplayDestroy( splay );
  DSplayItrDestroy( iterator );

  return NULL;
}

const char *
TestHasPreviousWithEmptyDynamicSplay
( void )
{
  DSplay *splay;
  DSplayItr *iterator;

  splay = DSplayNew( NULL );
  if( !splay )
    return "could not build a List";

  iterator = DSplayBegin( splay );
  if( !iterator )
    return "could not build a iterator";

  if( DSplayItrHasPrevious( iterator ) )
    return "an empty List returned true";

  DSplayDestroy( splay );
  DSplayItrDestroy( iterator );

  return NULL;
}

const char *
TestHasPreviousWithNullIterator
( void )
{
  if( DSplayItrHasNext( NULL ) )
    return "a NULL iterator returned true";

  return NULL;
}

const char *
TestNextAtBeginning
( void )
{
  DSplay *splay;
  DSplayItr *iterator;

  splay = BuildDSplay();
  if( !splay )
    return "could not build a List";

  iterator = DSplayBegin( splay );
  if( !iterator )
    return "could not build a iterator";

  if( DSplayItrNext( iterator ) != DSplayFirst( splay ) )
    return "the first element in the List was not returned by the first call to DSplayItrNext";

  DSplayDestroy( splay );
  DSplayItrDestroy( iterator );

  return NULL;
}

const char *
TestNextAtEnd
( void )
{
  DSplay *splay;
  DSplayItr *iterator;

  splay = BuildDSplay();
  if( !splay )
    return "could not build a List";

  iterator = DSplayEnd( splay );
  if( !iterator )
    return "could not build a iterator";

  if( DSplayItrNext( iterator ) )
    return "a non-NULL value was returned by a iterator at the end of a List";

  DSplayDestroy( splay );
  DSplayItrDestroy( iterator );

  return NULL;
}

const char *
TestNextAtMiddle
( void )
{
  DSplay *splay;
  DSplayItr *iterator;
  const void *element;

  splay = BuildDSplay();
  if( !splay )
    return "could not build a List";

  iterator = DSplayBegin( splay );
  if( !iterator )
    return "could not build a iterator";

  element = DSplayItrNext( iterator );
  if( !element )
    return "the List did not have a first element";
  ASSERT_STRINGS_EQUAL( "Alpha", element, "the first element was not returned by the first call" )

  element = DSplayItrNext( iterator );
  if( !element )
    return "the List did not have a second element";
  ASSERT_STRINGS_EQUAL( "Beta", element, "the second element was not returned by the second call" )

  element = DSplayItrNext( iterator );
  if( !element )
    return "the List did not have a third element";
  ASSERT_STRINGS_EQUAL( "Charlie", element, "the third element was not returned by the third call" )

  element = DSplayItrNext( iterator );
  if( !element )
    return "the List did not have a fourth element";
  ASSERT_STRINGS_EQUAL( "Delta", element, "the fourth element was not returned by the fourth call" )

  element = DSplayItrNext( iterator );
  if( !element )
    return "the List did not have a fifth element";
  ASSERT_STRINGS_EQUAL( "Echo", element, "the fifth element was not returned by the fifth call" )

  element = DSplayItrNext( iterator );
  if( !element )
    return "the List did not have a sixth element";
  ASSERT_STRINGS_EQUAL( "Foxtrot", element, "the sixth element was not returned by the sixth call" )

  element = DSplayItrNext( iterator );
  if( !element )
    return "the List did not have a seventh element";
  ASSERT_STRINGS_EQUAL( "Gamma", element, "the seventh element was not returned by the seventh call" )

  DSplayDestroy( splay );
  DSplayItrDestroy( iterator );

  return NULL;
}

const char *
TestNextWithEmptyDynamicSplay
( void )
{
  DSplay *splay;
  DSplayItr *iterator;

  splay = DSplayNew( NULL );
  if( !splay )
    return "could not build a List";

  iterator = DSplayBegin( splay );
  if( !iterator )
    return "could not build a iterator";

  if( DSplayItrNext( iterator ) )
    return "an empty List returned a non-NULL value";

  DSplayDestroy( splay );
  DSplayItrDestroy( iterator );

  return NULL;
}

const char *
TestNextWithNullIterator
( void )
{
  if( DSplayItrNext( NULL ) != NULL )
    return "calling the function with a NULL iterator returned a non-NULL value";

  return NULL;
}

const char *
TestPreviousAtBeginning
( void )
{
  DSplay *splay;
  DSplayItr *iterator;

  splay = BuildDSplay();
  if( !splay )
    return "could not build a List";

  iterator = DSplayBegin( splay );
  if( !iterator )
    return "could not build a iterator";

  if( DSplayItrPrevious( iterator ) != NULL )
    return "a non-NULL value was returned by the first call to DSplayItrPrevious";

  DSplayDestroy( splay );
  DSplayItrDestroy( iterator );

  return NULL;
}

const char *
TestPreviousAtEnd
( void )
{
  DSplay *splay;
  DSplayItr *iterator;

  splay = BuildDSplay();
  if( !splay )
    return "could not build a List";

  iterator = DSplayEnd( splay );
  if( !iterator )
    return "could not build a iterator";

  if( DSplayItrPrevious( iterator ) != DSplayLast( splay ) )
    return "the last element was not returned by a iterator at the end of a List";

  DSplayDestroy( splay );
  DSplayItrDestroy( iterator );

  return NULL;
}

const char *
TestPreviousAtMiddle
( void )
{
  DSplay *splay;
  DSplayItr *iterator;
  const void *element;

  splay = BuildDSplay();
  if( !splay )
    return "could not build a List";

  iterator = DSplayEnd( splay );
  if( !iterator )
    return "could not build a iterator";

  element = DSplayItrPrevious( iterator );
  if( !element )
    return "the List did not have a last element";
  ASSERT_STRINGS_EQUAL( "Zulu", element, "the last element was not returned by the first call" )

  element = DSplayItrPrevious( iterator );
  if( !element )
    return "the List did not have a second to last element";
  ASSERT_STRINGS_EQUAL( "Yankee", element, "the second to last element was not returned by the second call" )

  element = DSplayItrPrevious( iterator );
  if( !element )
    return "the List did not have a third to last element";
  ASSERT_STRINGS_EQUAL( "X-Ray", element, "the third to last element was not returned by the third call" )

  element = DSplayItrPrevious( iterator );
  if( !element )
    return "the List did not have a fourth to last element";
  ASSERT_STRINGS_EQUAL( "Whiskey", element, "the fourth to last element was not returned by the fourth call" )

  element = DSplayItrPrevious( iterator );
  if( !element )
    return "the List did not have a fifth to last element";
  ASSERT_STRINGS_EQUAL( "Victor", element, "the fifth to last element was not returned by the fifth call" )

  element = DSplayItrPrevious( iterator );
  if( !element )
    return "the List did not have a sixth to last element";
  ASSERT_STRINGS_EQUAL( "Uniform", element, "the sixth to last element was not returned by the sixth call" )

  element = DSplayItrPrevious( iterator );
  if( !element )
    return "the List did not have a seventh to last element";
  ASSERT_STRINGS_EQUAL( "Tango", element, "the seventh to last element was not returned by the seventh call" )

  DSplayDestroy( splay );
  DSplayItrDestroy( iterator );

  return NULL;
}

const char *
TestPreviousWithEmptyDynamicSplay
( void )
{
  DSplay *splay;
  DSplayItr *iterator;

  splay = DSplayNew( NULL );
  if( !splay )
    return "could not build a List";

  iterator = DSplayBegin( splay );
  if( !iterator )
    return "could not build a iterator";

  if( DSplayItrPrevious( iterator ) )
    return "an empty List returned a non-NULL value";

  DSplayDestroy( splay );
  DSplayItrDestroy( iterator );

  return NULL;
}

const char *
TestPreviousWithNullIterator
( void )
{
  if( DSplayItrPrevious( NULL ) != NULL )
    return "calling the function with a NULL iterator returned a non-NULL value";

  return NULL;
}

const char *
TestRemoveAfterNext
( void )
{
  DSplay *splay;
  DSplayItr *iterator;
  const void *element;

  splay = BuildDSplay();
  if( !splay )
    return "could not build a populated splay";

  iterator = DSplayBegin( splay );
  if( !iterator )
    return "could not build an iterator";

  DSplayItrNext( iterator );
  element = DSplayItrNext( iterator );

  if( DSplayItrRemove( iterator ) != element )
    return "the last element returned by DSplayItrNext was not returned";

  if( DSplayContains( splay, element ) )
    return "the element was not removed from the splay";

  element = DSplayFirst( splay );
  if( !element )
    return "after removal the List did not have a front element";
  ASSERT_STRINGS_EQUAL( "Alpha", element, "the first element of the List changed" )

  element = DSplayItrNext( iterator );
  if( !element )
    return "after removal the splay did not have a second element";
  ASSERT_STRINGS_EQUAL( "Charlie", element, "the second element of the List was not the previous third" )

  DSplayDestroy( splay );
  DSplayItrDestroy( iterator );

  return NULL;
}

const char *
TestRemoveAfterPrevious
( void )
{
  DSplay *splay;
  DSplayItr *iterator;
  const void *element;

  splay = BuildDSplay();
  if( !splay )
    return "could not build a populated splay";

  iterator = DSplayEnd( splay );
  if( !iterator )
    return "could not build an iterator";

  DSplayItrPrevious( iterator );
  element = DSplayItrPrevious( iterator );

  if( DSplayItrRemove( iterator ) != element )
    return "the last element returned by DSplayItrPrevious was not returned";

  if( DSplayContains( splay, element ) )
    return "the element was not removed after the call";

  element = DSplayLast( splay );
  if( !element )
    return "after removal the splay did not have a back element";
  ASSERT_STRINGS_EQUAL( "Zulu", element, "the last element of the List changed" )

  element = DSplayItrPrevious( iterator );
  if( !element )
    return "after removal the splay did not have a second to last element";
  ASSERT_STRINGS_EQUAL( "X-Ray", element, "the position of the iterator changed after a call to DSplayItrRemove" )

  DSplayDestroy( splay );
  DSplayItrDestroy( iterator );

  return NULL;
}

const char *
TestRemoveAfterRemove
( void )
{
  DSplay *splay;
  DSplayItr *iterator;
  const void *element, *removed;

  splay = BuildDSplay();
  if( !splay )
    return "could not build a List";

  iterator = DSplayBegin( splay );
  if( !iterator )
    return "could not build a iterator";

  element = DSplayItrNext( iterator );
  DSplayItrNext( iterator );

  removed = DSplayItrRemove( iterator );

  if( DSplayItrRemove( iterator ) != NULL )
    return "a second successive call to DSplayItrRemove returned a non-NULL value";

  if( DSplayContains( splay, removed ) )
    return "the removed element was no longer removed from the List";

  if( DSplayFirst( splay ) != element )
    return "the front element changed after the second call to DSplayItrRemove";

  element = DSplayItrNext( iterator );
  if( !element )
    return "the iterator did not have a next element";
  ASSERT_STRINGS_EQUAL( "Charlie", element, "the position of the iterator was changed after the second call to DSplayItrRemove" )

  DSplayDestroy( splay );
  DSplayItrDestroy( iterator );

  return NULL;
}

const char *
TestRemoveBeforeNextOrPrevious
( void )
{
  DSplay *splay;
  DSplayItr *iterator;

  splay = BuildDSplay();
  if( !splay )
    return "could not build a List";

  iterator = DSplayBegin( splay );
  if( !iterator )
    return "could not build a iterator";

  if( DSplayItrRemove( iterator ) != NULL )
    return "a non-NULL value was returned from a premature call to DSplayItrRemove";

  if( DSplayItrNext( iterator ) != DSplayFirst( splay ) )
    return "the position of the iterator was changed after a premature call to DSplayItrRemove";

  DSplayDestroy( splay );
  DSplayItrDestroy( iterator );

  return NULL;
}

const char *
TestRemoveFromNullIterator
( void )
{
  if( DSplayItrRemove( NULL ) != NULL )
    return "a non-NULL value was returned for a NULL iterator";

  return NULL;
}
