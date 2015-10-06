#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <woodpile/dynamic/tree/splay/const_iterator.h>

#include "test/function/dynamic/tree/splay/const_iterator_suite.h"
#include "test/helper.h"

static const DSplay *common_splay = NULL;

int
main( void )
{
  unsigned failure_count = 0;
  const char *result;

  common_splay = BuildDSplay();
  if( !common_splay ){
    puts( "could not build a splay for testing" );
    return EXIT_FAILURE;
  }

  TEST( CBeginWithEmptyDynamicSplay )
  TEST( CBeginWithNullDynamicSplay )
  TEST( CBeginWithPopulatedDynamicSplay )
  TEST( CEndWithEmptyDynamicSplay )
  TEST( CEndWithNullDynamicSplay )
  TEST( CEndWithPopulatedDynamicSplay )
  TEST( Copy )
  TEST( CopyContents )
  TEST( CopyDistinct )
  TEST( CopyNullIterator )
  TEST( CopyPosition )
  TEST( Destroy )
  TEST( DestroyNullIterator )
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

  DSplayDestroy( common_splay );

  if( failure_count > 0 )
    return EXIT_FAILURE;
  else
    return EXIT_SUCCESS;
}

const char *
TestCBeginWithEmptyDynamicSplay
( void )
{
  const DSplay *splay;
  DSplayCItr *iterator;

  splay = DSplayNew( NULL );
  if( !splay )
    return "could not build a Splay";

  iterator = DSplayCBegin( splay );
  if( !iterator )
    return "a NULL Itr was returned for an empty Splay";

  if( DSplayCItrPrevious( iterator ) != NULL )
    return "the previous element in the iterator was non-NULL";

  if( DSplayCItrNext( iterator ) != NULL )
    return "the next element in the iterator was non-NULL";

  DSplayCItrDestroy( iterator );
  DSplayDestroy( splay );

  return NULL;
}

const char *
TestCBeginWithNullDynamicSplay
( void )
{
  if( DSplayCBegin( NULL ) != NULL )
    return "a non-NULL Itr was returned for a NULL Splay";

  return NULL;
}

const char *
TestCBeginWithPopulatedDynamicSplay
( void )
{
  DSplayCItr *iterator;
  const void *element;

  iterator = DSplayCBegin( common_splay );
  if( !iterator )
    return "a NULL Itr was returned for a populated Splay";

  if( DSplayCItrPrevious( iterator ) != NULL )
    return "the previous element of the iterator was non-NULL";

  element = DSplayCItrNext( iterator );
  if( !element )
    return "the next element of the iterator was NULL";
  ASSERT_STRINGS_EQUAL( "Alpha", element, "the next element of the iterator was not the first element of the Splay" )

  DSplayCItrDestroy( iterator );

  return NULL;
}

const char *
TestCEndWithEmptyDynamicSplay
( void )
{
  const DSplay *splay;
  DSplayCItr *iterator;

  splay = DSplayNew( NULL );
  if( !splay )
    return "could not build a Splay";

  iterator = DSplayCEnd( splay );
  if( !iterator )
    return "a NULL Itr was returned for an empty Splay";

  if( DSplayCItrPrevious( iterator ) != NULL )
    return "the previous element in the iterator was non-NULL";

  if( DSplayCItrNext( iterator ) != NULL )
    return "the next element in the iterator was non-NULL";

  DSplayDestroy( splay );
  DSplayCItrDestroy( iterator );

  return NULL;
}

const char *
TestCEndWithNullDynamicSplay
( void )
{
  if( DSplayCEnd( NULL ) != NULL )
    return "a non-NULL Itr was returned for a NULL Splay";

  return NULL;
}

const char *
TestCEndWithPopulatedDynamicSplay
( void )
{
  DSplayCItr *iterator;
  const void *element;

  iterator = DSplayCEnd( common_splay );
  if( !iterator )
    return "a NULL Itr was returned for a populated Splay";

  if( DSplayCItrNext( iterator ) != NULL )
    return "the next element of the iterator was non-NULL";

  element = DSplayCItrPrevious( iterator );
  if( !element )
    return "the previous element of the iterator was NULL";
  ASSERT_STRINGS_EQUAL( "Zulu", element, "the previous element of the iterator was not the last element of the Splay" )

  DSplayCItrDestroy( iterator );

  return NULL;
}

const char *
TestCopy
( void )
{
  const DSplayCItr *copy, *iterator;

  iterator = DSplayCBegin( common_splay );
  if( !iterator )
    return "could not build a Itr";

  copy = DSplayCItrCopy( iterator );
  if( copy == NULL )
    return "NULL was returned for a non-NULL Itr";

  DSplayCItrDestroy( copy );
  DSplayCItrDestroy( iterator );

  return NULL;
}

const char *
TestCopyContents
( void )
{
  DSplayCItr *copy, *iterator;
  const void *element;

  iterator = DSplayCBegin( common_splay );
  if( !iterator )
    return "could not build a Itr";

  copy = DSplayCItrCopy( iterator );
  if( !copy )
    return "could not copy a Itr";

  element = DSplayCItrNext( copy );
  if( !element )
    return "the copied Itr did not have a first element";

  if( element != DSplayFirst( common_splay ) )
    return "the first element in the Itr was not the first element in the Splay";

  if( element != DSplayCItrNext( iterator ) )
    return "the first element in the original did not match the first element of the copy";

  DSplayCItrDestroy( copy );
  DSplayCItrDestroy( iterator );

  return NULL;
}

const char *
TestCopyDistinct
( void )
{
  DSplayCItr *copy, *iterator;
  const void *element_1, *element_2, *element_3;

  iterator = DSplayCBegin( common_splay );
  if( !iterator )
    return "could not build a Itr";

  copy = DSplayCItrCopy( iterator );
  if( !copy )
    return "could not copy a Itr";

  if( copy == iterator )
    return "the copy was the same structure as the original";

  element_1 = DSplayCItrNext( copy );
  if( !element_1 )
    return "there was no first element";
  element_2 = DSplayCItrNext( copy );
  if( !element_2 )
    return "there was no second element";
  element_3 = DSplayCItrNext( copy );
  if( !element_3 )
    return "there was no third element";

  if( DSplayCItrNext( iterator ) != element_1 )
    return "advancing the pointer of the copy changed the pointer of the original";

  DSplayCItrPrevious( copy );
  DSplayCItrPrevious( copy );

  if( DSplayCItrPrevious( iterator ) != element_1 )
    return "backing up the pointer of the copy changed the pointer of the original";

  DSplayCItrDestroy( copy );
  DSplayCItrDestroy( iterator );

  return NULL;
}

const char *
TestCopyNullIterator
( void )
{
  if( DSplayCItrCopy( NULL ) != NULL )
    return "a non-NULL value was returned when copying NULL";

  return NULL;
}

const char *
TestCopyPosition
( void )
{
  DSplayCItr *copy, *iterator;

  iterator = DSplayCBegin( common_splay );
  if( !iterator )
    return "could not build a Itr";

  DSplayCItrNext( iterator );
  DSplayCItrNext( iterator );

  copy = DSplayCItrCopy( iterator );
  if( !copy )
    return "could not copy a Itr";

  if( DSplayCItrNext( iterator ) != DSplayCItrNext( copy ) )
    return "the position of the iterator was not the same in the copy as the original";

  DSplayCItrDestroy( copy );
  DSplayCItrDestroy( iterator );

  return NULL;
}

const char *
TestDestroy
( void )
{
  const DSplayCItr *iterator;

  iterator = DSplayCBegin( common_splay );
  if( !iterator )
    return "could not build a Itr";

  DSplayCItrDestroy( iterator );

  return NULL;
}

const char *
TestDestroyNullIterator
( void )
{
  DSplayCItrDestroy( NULL );

  return NULL;
}

const char *
TestHasNextAtBeginning
( void )
{
  DSplayCItr *iterator;

  iterator = DSplayCBegin( common_splay );
  if( !iterator )
    return "could not build a Itr";

  if( !DSplayCItrHasNext( iterator ) )
    return "a Itr at the beginning of a Splay returned false";

  DSplayCItrDestroy( iterator );

  return NULL;
}

const char *
TestHasNextAtEnd
( void )
{
  DSplayCItr *iterator;

  iterator = DSplayCEnd( common_splay );
  if( !iterator )
    return "could not build a Itr";

  if( DSplayCItrHasNext( iterator ) )
    return "a Itr at the end of a Splay returned true";

  DSplayCItrDestroy( iterator );

  return NULL;
}

const char *
TestHasNextAtMiddle
( void )
{
  DSplayCItr *iterator;

  iterator = DSplayCBegin( common_splay );
  if( !iterator )
    return "could not build a Itr";

  DSplayCItrNext( iterator );
  DSplayCItrNext( iterator );
  DSplayCItrNext( iterator );

  if( !DSplayCItrHasNext( iterator ) )
    return "a Itr in the middle of a Splay returned false";

  DSplayCItrDestroy( iterator );

  return NULL;
}

const char *
TestHasNextWithEmptyDynamicSplay
( void )
{
  const DSplay *splay;
  DSplayCItr *iterator;

  splay = DSplayNew( NULL );
  if( !splay )
    return "could not build a Splay";

  iterator = DSplayCBegin( splay );
  if( !iterator )
    return "could not build a Itr";

  if( DSplayCItrHasNext( iterator ) )
    return "an empty Splay returned true";

  DSplayDestroy( splay );
  DSplayCItrDestroy( iterator );

  return NULL;
}

const char *
TestHasNextWithNullIterator
( void )
{
  if( DSplayCItrHasNext( NULL ) )
    return "a NULL iterator returned true";

  return NULL;
}

const char *
TestHasPreviousAtBeginning
( void )
{
  DSplayCItr *iterator;

  iterator = DSplayCBegin( common_splay );
  if( !iterator )
    return "could not build a Itr";

  if( DSplayCItrHasPrevious( iterator ) )
    return "a Itr at the beginning of a Splay returned true";

  DSplayCItrDestroy( iterator );

  return NULL;
}

const char *
TestHasPreviousAtEnd
( void )
{
  DSplayCItr *iterator;

  iterator = DSplayCEnd( common_splay );
  if( !iterator )
    return "could not build a Itr";

  if( !DSplayCItrHasPrevious( iterator ) )
    return "a Itr at the end of a Splay returned false";

  DSplayCItrDestroy( iterator );

  return NULL;
}

const char *
TestHasPreviousAtMiddle
( void )
{
  DSplayCItr *iterator;

  iterator = DSplayCBegin( common_splay );
  if( !iterator )
    return "could not build a Itr";

  DSplayCItrNext( iterator );
  DSplayCItrNext( iterator );
  DSplayCItrNext( iterator );

  if( !DSplayCItrHasPrevious( iterator ) )
    return "a Itr in the middle of a Splay returned false";

  DSplayCItrDestroy( iterator );

  return NULL;
}

const char *
TestHasPreviousWithEmptyDynamicSplay
( void )
{
  const DSplay *splay;
  DSplayCItr *iterator;

  splay = DSplayNew( NULL );
  if( !splay )
    return "could not build a Splay";

  iterator = DSplayCBegin( splay );
  if( !iterator )
    return "could not build a Itr";

  if( DSplayCItrHasPrevious( iterator ) )
    return "an empty Splay returned true";

  DSplayDestroy( splay );
  DSplayCItrDestroy( iterator );

  return NULL;
}

const char *
TestHasPreviousWithNullIterator
( void )
{
  if( DSplayCItrHasNext( NULL ) )
    return "a NULL iterator returned true";

  return NULL;
}

const char *
TestNextAtBeginning
( void )
{
  DSplayCItr *iterator;

  iterator = DSplayCBegin( common_splay );
  if( !iterator )
    return "could not build a Itr";

  if( DSplayCItrNext( iterator ) != DSplayFirst( common_splay ) )
    return "the first element in the Splay was not returned by the first call to DSplayCItrNext";

  DSplayCItrDestroy( iterator );

  return NULL;
}

const char *
TestNextAtEnd
( void )
{
  DSplayCItr *iterator;

  iterator = DSplayCEnd( common_splay );
  if( !iterator )
    return "could not build a Itr";

  if( DSplayCItrNext( iterator ) )
    return "a non-NULL value was returned by a Itr at the end of a Splay";

  DSplayCItrDestroy( iterator );

  return NULL;
}

const char *
TestNextAtMiddle
( void )
{
  DSplayCItr *iterator;
  const void *element;

  iterator = DSplayCBegin( common_splay );
  if( !iterator )
    return "could not build a Itr";

  element = DSplayCItrNext( iterator );
  if( !element )
    return "the Splay did not have a first element";
  ASSERT_STRINGS_EQUAL( "Alpha", element, "the first element was not returned by the first call" )

  element = DSplayCItrNext( iterator );
  if( !element )
    return "the Splay did not have a second element";
  ASSERT_STRINGS_EQUAL( "Beta", element, "the second element was not returned by the second call" )

  element = DSplayCItrNext( iterator );
  if( !element )
    return "the Splay did not have a third element";
  ASSERT_STRINGS_EQUAL( "Charlie", element, "the third element was not returned by the third call" )

  element = DSplayCItrNext( iterator );
  if( !element )
    return "the Splay did not have a fourth element";
  ASSERT_STRINGS_EQUAL( "Delta", element, "the fourth element was not returned by the fourth call" )

  element = DSplayCItrNext( iterator );
  if( !element )
    return "the Splay did not have a fifth element";
  ASSERT_STRINGS_EQUAL( "Echo", element, "the fifth element was not returned by the fifth call" )

  element = DSplayCItrNext( iterator );
  if( !element )
    return "the Splay did not have a sixth element";
  ASSERT_STRINGS_EQUAL( "Foxtrot", element, "the sixth element was not returned by the sixth call" )

  element = DSplayCItrNext( iterator );
  if( !element )
    return "the Splay did not have a seventh element";
  ASSERT_STRINGS_EQUAL( "Gamma", element, "the seventh element was not returned by the seventh call" )

  DSplayCItrDestroy( iterator );

  return NULL;
}

const char *
TestNextWithEmptyDynamicSplay
( void )
{
  const DSplay *splay;
  DSplayCItr *iterator;

  splay = DSplayNew( NULL );
  if( !splay )
    return "could not build a Splay";

  iterator = DSplayCBegin( splay );
  if( !iterator )
    return "could not build a Itr";

  if( DSplayCItrNext( iterator ) )
    return "an empty Splay returned a non-NULL value";

  DSplayDestroy( splay );
  DSplayCItrDestroy( iterator );

  return NULL;
}

const char *
TestNextWithNullIterator
( void )
{
  if( DSplayCItrNext( NULL ) != NULL )
    return "calling the function with a NULL Itr returned a non-NULL value";

  return NULL;
}

const char *
TestPreviousAtBeginning
( void )
{
  DSplayCItr *iterator;

  iterator = DSplayCBegin( common_splay );
  if( !iterator )
    return "could not build a Itr";

  if( DSplayCItrPrevious( iterator ) != NULL )
    return "a non-NULL value was returned by the first call to DSplayCItrPrevious";

  DSplayCItrDestroy( iterator );

  return NULL;
}

const char *
TestPreviousAtEnd
( void )
{
  DSplayCItr *iterator;

  iterator = DSplayCEnd( common_splay );
  if( !iterator )
    return "could not build a Itr";

  if( DSplayCItrPrevious( iterator ) != DSplayLast( common_splay ) )
    return "the last element was not returned by a Itr at the end of a Splay";

  DSplayCItrDestroy( iterator );

  return NULL;
}

const char *
TestPreviousAtMiddle
( void )
{
  DSplayCItr *iterator;
  const void *element;

  iterator = DSplayCEnd( common_splay );
  if( !iterator )
    return "could not build a Itr";

  element = DSplayCItrPrevious( iterator );
  if( !element )
    return "the Splay did not have a last element";
  ASSERT_STRINGS_EQUAL( "Zulu", element, "the last element was not returned by the first call" )

  element = DSplayCItrPrevious( iterator );
  if( !element )
    return "the Splay did not have a second to last element";
  ASSERT_STRINGS_EQUAL( "Yankee", element, "the second to last element was not returned by the second call" )

  element = DSplayCItrPrevious( iterator );
  if( !element )
    return "the Splay did not have a third to last element";
  ASSERT_STRINGS_EQUAL( "X-Ray", element, "the third to last element was not returned by the third call" )

  element = DSplayCItrPrevious( iterator );
  if( !element )
    return "the Splay did not have a fourth to last element";
  ASSERT_STRINGS_EQUAL( "Whiskey", element, "the fourth to last element was not returned by the fourth call" )

  element = DSplayCItrPrevious( iterator );
  if( !element )
    return "the Splay did not have a fifth to last element";
  ASSERT_STRINGS_EQUAL( "Victor", element, "the fifth to last element was not returned by the fifth call" )

  element = DSplayCItrPrevious( iterator );
  if( !element )
    return "the Splay did not have a sixth to last element";
  ASSERT_STRINGS_EQUAL( "Uniform", element, "the sixth to last element was not returned by the sixth call" )

  element = DSplayCItrPrevious( iterator );
  if( !element )
    return "the Splay did not have a seventh to last element";
  ASSERT_STRINGS_EQUAL( "Tango", element, "the seventh to last element was not returned by the seventh call" )

  DSplayCItrDestroy( iterator );

  return NULL;
}

const char *
TestPreviousWithEmptyDynamicSplay
( void )
{
  const DSplay *splay;
  DSplayCItr *iterator;

  splay = DSplayNew( NULL );
  if( !splay )
    return "could not build a Splay";

  iterator = DSplayCBegin( splay );
  if( !iterator )
    return "could not build a Itr";

  if( DSplayCItrPrevious( iterator ) )
    return "an empty Splay returned a non-NULL value";

  DSplayDestroy( splay );
  DSplayCItrDestroy( iterator );

  return NULL;
}

const char *
TestPreviousWithNullIterator
( void )
{
  if( DSplayCItrPrevious( NULL ) != NULL )
    return "calling the function with a NULL Itr returned a non-NULL value";

  return NULL;
}
