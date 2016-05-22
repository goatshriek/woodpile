#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <woodpile/config.h>
#include <woodpile/dynamic/list/const_iterator.h>

#include "test/function/dynamic/list/const_iterator_suite.h"
#include "test/helper.h"

static const dlist_t *common_list = NULL;

int
main( void )
{
  unsigned failure_count = 0;
  const char *result;

  common_list = BuildDList();
  if( !common_list ){
    puts( "could not build a List for testing" );
    return EXIT_FAILURE;
  }

#ifdef __WOODPILE_PARAMETER_VALIDATION
  TEST( CBeginWithNullList )
  TEST( CEndWithNullList )
  TEST( CopyNullIterator )
  TEST( NextWithNullIterator )
  TEST( PreviousWithNullIterator )
#endif

  TEST( CBeginWithEmptyList )
  TEST( CBeginWithPopulatedList )
  TEST( CEndWithEmptyList )
  TEST( CEndWithPopulatedList )
  TEST( Copy )
  TEST( CopyContents )
  TEST( CopyDistinct )
  TEST( CopyPosition )
  TEST( Destroy )
  TEST( DestroyNullIterator )
  TEST( HasNextAtBeginning )
  TEST( HasNextAtEnd )
  TEST( HasNextAtMiddle )
  TEST( HasNextWithEmptyList )
  TEST( HasNextWithNullIterator )
  TEST( HasPreviousAtBeginning )
  TEST( HasPreviousAtEnd )
  TEST( HasPreviousAtMiddle )
  TEST( HasPreviousWithEmptyList )
  TEST( HasPreviousWithNullIterator )
  TEST( NextAtBeginning )
  TEST( NextAtEnd )
  TEST( NextAtMiddle )
  TEST( NextWithEmptyList )
  TEST( PreviousAtBeginning )
  TEST( PreviousAtEnd )
  TEST( PreviousAtMiddle )
  TEST( PreviousWithEmptyList )

  DListDestroy( common_list );

  if( failure_count > 0 )
    return EXIT_FAILURE;
  else
    return EXIT_SUCCESS;
}

const char *
TestCBeginWithEmptyList
( void )
{
  const dlist_t *list;
  DListCItr *iterator;

  list = DListNew();
  if( !list )
    return "could not build a List";

  iterator = DListCBegin( list );
  if( !iterator )
    return "a NULL Itr was returned for an empty List";

  if( DListCItrPrevious( iterator ) != NULL )
    return "the previous element in the iterator was non-NULL";

  if( DListCItrNext( iterator ) != NULL )
    return "the next element in the iterator was non-NULL";

  DListCItrDestroy( iterator );
  DListDestroy( list );

  return NULL;
}

const char *
TestCBeginWithNullList
( void )
{
  if( DListCBegin( NULL ) != NULL )
    return "a non-NULL Itr was returned for a NULL List";

  return NULL;
}

const char *
TestCBeginWithPopulatedList
( void )
{
  DListCItr *iterator;
  const void *element;

  iterator = DListCBegin( common_list );
  if( !iterator )
    return "a NULL Itr was returned for a populated List";

  if( DListCItrPrevious( iterator ) != NULL )
    return "the previous element of the iterator was non-NULL";

  element = DListCItrNext( iterator );
  if( !element )
    return "the next element of the iterator was NULL";
  ASSERT_STRINGS_EQUAL( "This", element, "the next element of the iterator was not the first element of the List" )

  DListCItrDestroy( iterator );

  return NULL;
}

const char *
TestCEndWithEmptyList
( void )
{
  const dlist_t *list;
  DListCItr *iterator;

  list = DListNew();
  if( !list )
    return "could not build a List";

  iterator = DListCEnd( list );
  if( !iterator )
    return "a NULL Itr was returned for an empty List";

  if( DListCItrPrevious( iterator ) != NULL )
    return "the previous element in the iterator was non-NULL";

  if( DListCItrNext( iterator ) != NULL )
    return "the next element in the iterator was non-NULL";

  DListDestroy( list );
  DListCItrDestroy( iterator );

  return NULL;
}

const char *
TestCEndWithNullList
( void )
{
  if( DListCEnd( NULL ) != NULL )
    return "a non-NULL Itr was returned for a NULL List";

  return NULL;
}

const char *
TestCEndWithPopulatedList
( void )
{
  DListCItr *iterator;
  const void *element;

  iterator = DListCEnd( common_list );
  if( !iterator )
    return "a NULL Itr was returned for a populated List";

  if( DListCItrNext( iterator ) != NULL )
    return "the next element of the iterator was non-NULL";

  element = DListCItrPrevious( iterator );
  if( !element )
    return "the previous element of the iterator was NULL";
  ASSERT_STRINGS_EQUAL( "strings!", element, "the previous element of the iterator was not the last element of the List" )

  DListCItrDestroy( iterator );

  return NULL;
}

const char *
TestCopy
( void )
{
  const DListCItr *copy, *iterator;

  iterator = DListCBegin( common_list );
  if( !iterator )
    return "could not build a Itr";

  copy = DListCItrCopy( iterator );
  if( copy == NULL )
    return "NULL was returned for a non-NULL Itr";

  DListCItrDestroy( copy );
  DListCItrDestroy( iterator );

  return NULL;
}

const char *
TestCopyContents
( void )
{
  DListCItr *copy, *iterator;
  const void *element;

  iterator = DListCBegin( common_list );
  if( !iterator )
    return "could not build a Itr";

  copy = DListCItrCopy( iterator );
  if( !copy )
    return "could not copy a Itr";

  element = DListCItrNext( copy );
  if( !element )
    return "the copied Itr did not have a first element";

  if( element != DListFront( common_list ) )
    return "the first element in the Itr was not the first element in the List";

  if( element != DListCItrNext( iterator ) )
    return "the first element in the original did not match the first element of the copy";

  DListCItrDestroy( copy );
  DListCItrDestroy( iterator );

  return NULL;
}

const char *
TestCopyDistinct
( void )
{
  DListCItr *copy, *iterator;
  const void *element_1, *element_2, *element_3;

  iterator = DListCBegin( common_list );
  if( !iterator )
    return "could not build a Itr";

  copy = DListCItrCopy( iterator );
  if( !copy )
    return "could not copy a Itr";

  if( copy == iterator )
    return "the copy was the same structure as the original";

  element_1 = DListCItrNext( copy );
  if( !element_1 )
    return "there was no first element";
  element_2 = DListCItrNext( copy );
  if( !element_2 )
    return "there was no second element";
  element_3 = DListCItrNext( copy );
  if( !element_3 )
    return "there was no third element";

  if( DListCItrNext( iterator ) != element_1 )
    return "advancing the pointer of the copy changed the pointer of the original";

  DListCItrPrevious( copy );
  DListCItrPrevious( copy );

  if( DListCItrPrevious( iterator ) != element_1 )
    return "backing up the pointer of the copy changed the pointer of the original";

  DListCItrDestroy( copy );
  DListCItrDestroy( iterator );

  return NULL;
}

const char *
TestCopyNullIterator
( void )
{
  if( DListCItrCopy( NULL ) != NULL )
    return "a non-NULL value was returned when copying NULL";

  return NULL;
}

const char *
TestCopyPosition
( void )
{
  DListCItr *copy, *iterator;

  iterator = DListCBegin( common_list );
  if( !iterator )
    return "could not build a Itr";

  DListCItrNext( iterator );
  DListCItrNext( iterator );

  copy = DListCItrCopy( iterator );
  if( !copy )
    return "could not copy a Itr";

  if( DListCItrNext( iterator ) != DListCItrNext( copy ) )
    return "the position of the iterator was not the same in the copy as the original";

  DListCItrDestroy( copy );
  DListCItrDestroy( iterator );

  return NULL;
}

const char *
TestDestroy
( void )
{
  const DListCItr *iterator;

  iterator = DListCBegin( common_list );
  if( !iterator )
    return "could not build a Itr";

  DListCItrDestroy( iterator );

  return NULL;
}

const char *
TestDestroyNullIterator
( void )
{
  DListCItrDestroy( NULL );

  return NULL;
}

const char *
TestHasNextAtBeginning
( void )
{
  DListCItr *iterator;

  iterator = DListCBegin( common_list );
  if( !iterator )
    return "could not build a Itr";

  if( !DListCItrHasNext( iterator ) )
    return "a Itr at the beginning of a List returned false";

  DListCItrDestroy( iterator );

  return NULL;
}

const char *
TestHasNextAtEnd
( void )
{
  DListCItr *iterator;

  iterator = DListCEnd( common_list );
  if( !iterator )
    return "could not build a Itr";

  if( DListCItrHasNext( iterator ) )
    return "a Itr at the end of a List returned true";

  DListCItrDestroy( iterator );

  return NULL;
}

const char *
TestHasNextAtMiddle
( void )
{
  DListCItr *iterator;

  iterator = DListCBegin( common_list );
  if( !iterator )
    return "could not build a Itr";

  DListCItrNext( iterator );
  DListCItrNext( iterator );
  DListCItrNext( iterator );

  if( !DListCItrHasNext( iterator ) )
    return "a Itr in the middle of a List returned false";

  DListCItrDestroy( iterator );

  return NULL;
}

const char *
TestHasNextWithEmptyList
( void )
{
  const dlist_t *list;
  DListCItr *iterator;

  list = DListNew();
  if( !list )
    return "could not build a List";

  iterator = DListCBegin( list );
  if( !iterator )
    return "could not build a Itr";

  if( DListCItrHasNext( iterator ) )
    return "an empty List returned true";

  DListDestroy( list );
  DListCItrDestroy( iterator );

  return NULL;
}

const char *
TestHasNextWithNullIterator
( void )
{
  if( DListCItrHasNext( NULL ) )
    return "a NULL iterator returned true";

  return NULL;
}

const char *
TestHasPreviousAtBeginning
( void )
{
  DListCItr *iterator;

  iterator = DListCBegin( common_list );
  if( !iterator )
    return "could not build a Itr";

  if( DListCItrHasPrevious( iterator ) )
    return "a Itr at the beginning of a List returned true";

  DListCItrDestroy( iterator );

  return NULL;
}

const char *
TestHasPreviousAtEnd
( void )
{
  DListCItr *iterator;

  iterator = DListCEnd( common_list );
  if( !iterator )
    return "could not build a Itr";

  if( !DListCItrHasPrevious( iterator ) )
    return "a Itr at the end of a List returned false";

  DListCItrDestroy( iterator );

  return NULL;
}

const char *
TestHasPreviousAtMiddle
( void )
{
  DListCItr *iterator;

  iterator = DListCBegin( common_list );
  if( !iterator )
    return "could not build a Itr";

  DListCItrNext( iterator );
  DListCItrNext( iterator );
  DListCItrNext( iterator );

  if( !DListCItrHasPrevious( iterator ) )
    return "a Itr in the middle of a List returned false";

  DListCItrDestroy( iterator );

  return NULL;
}

const char *
TestHasPreviousWithEmptyList
( void )
{
  const dlist_t *list;
  DListCItr *iterator;

  list = DListNew();
  if( !list )
    return "could not build a List";

  iterator = DListCBegin( list );
  if( !iterator )
    return "could not build a Itr";

  if( DListCItrHasPrevious( iterator ) )
    return "an empty List returned true";

  DListDestroy( list );
  DListCItrDestroy( iterator );

  return NULL;
}

const char *
TestHasPreviousWithNullIterator
( void )
{
  if( DListCItrHasNext( NULL ) )
    return "a NULL iterator returned true";

  return NULL;
}

const char *
TestNextAtBeginning
( void )
{
  DListCItr *iterator;

  iterator = DListCBegin( common_list );
  if( !iterator )
    return "could not build a Itr";

  if( DListCItrNext( iterator ) != DListFront( common_list ) )
    return "the first element in the List was not returned by the first call to DListCItrNext";

  DListCItrDestroy( iterator );

  return NULL;
}

const char *
TestNextAtEnd
( void )
{
  DListCItr *iterator;

  iterator = DListCEnd( common_list );
  if( !iterator )
    return "could not build a Itr";

  if( DListCItrNext( iterator ) )
    return "a non-NULL value was returned by a Itr at the end of a List";

  DListCItrDestroy( iterator );

  return NULL;
}

const char *
TestNextAtMiddle
( void )
{
  DListCItr *iterator;
  const void *element;

  iterator = DListCBegin( common_list );
  if( !iterator )
    return "could not build a Itr";

  element = DListCItrNext( iterator );
  if( !element )
    return "the List did not have a first element";
  ASSERT_STRINGS_EQUAL( "This", element, "the first element was not returned by the first call" )

  element = DListCItrNext( iterator );
  if( !element )
    return "the List did not have a second element";
  ASSERT_STRINGS_EQUAL( "is", element, "the second element was not returned by the second call" )

  element = DListCItrNext( iterator );
  if( !element )
    return "the List did not have a third element";
  ASSERT_STRINGS_EQUAL( "a", element, "the third element was not returned by the third call" )

  element = DListCItrNext( iterator );
  if( !element )
    return "the List did not have a fourth element";
  ASSERT_STRINGS_EQUAL( "test", element, "the fourth element was not returned by the fourth call" )

  element = DListCItrNext( iterator );
  if( !element )
    return "the List did not have a fifth element";
  ASSERT_STRINGS_EQUAL( "List", element, "the fifth element was not returned by the fifth call" )

  element = DListCItrNext( iterator );
  if( !element )
    return "the List did not have a sixth element";
  ASSERT_STRINGS_EQUAL( "o'", element, "the sixth element was not returned by the sixth call" )

  element = DListCItrNext( iterator );
  if( !element )
    return "the List did not have a seventh element";
  ASSERT_STRINGS_EQUAL( "strings!", element, "the seventh element was not returned by the seventh call" )

  DListCItrDestroy( iterator );

  return NULL;
}

const char *
TestNextWithEmptyList
( void )
{
  const dlist_t *list;
  DListCItr *iterator;

  list = DListNew();
  if( !list )
    return "could not build a List";

  iterator = DListCBegin( list );
  if( !iterator )
    return "could not build a Itr";

  if( DListCItrNext( iterator ) )
    return "an empty List returned a non-NULL value";

  DListDestroy( list );
  DListCItrDestroy( iterator );

  return NULL;
}

const char *
TestNextWithNullIterator
( void )
{
  if( DListCItrNext( NULL ) != NULL )
    return "calling the function with a NULL Itr returned a non-NULL value";

  return NULL;
}

const char *
TestPreviousAtBeginning
( void )
{
  DListCItr *iterator;

  iterator = DListCBegin( common_list );
  if( !iterator )
    return "could not build a Itr";

  if( DListCItrPrevious( iterator ) != NULL )
    return "a non-NULL value was returned by the first call to DListCItrPrevious";

  DListCItrDestroy( iterator );

  return NULL;
}

const char *
TestPreviousAtEnd
( void )
{
  DListCItr *iterator;

  iterator = DListCEnd( common_list );
  if( !iterator )
    return "could not build a Itr";

  if( DListCItrPrevious( iterator ) != DListBack( common_list ) )
    return "the last element was not returned by a Itr at the end of a List";

  DListCItrDestroy( iterator );

  return NULL;
}

const char *
TestPreviousAtMiddle
( void )
{
  DListCItr *iterator;
  const void *element;

  iterator = DListCEnd( common_list );
  if( !iterator )
    return "could not build a Itr";

  element = DListCItrPrevious( iterator );
  if( !element )
    return "the List did not have a last element";
  ASSERT_STRINGS_EQUAL( "strings!", element, "the last element was not returned by the first call" )

  element = DListCItrPrevious( iterator );
  if( !element )
    return "the List did not have a second to last element";
  ASSERT_STRINGS_EQUAL( "o'", element, "the second to last element was not returned by the second call" )

  element = DListCItrPrevious( iterator );
  if( !element )
    return "the List did not have a third to last element";
  ASSERT_STRINGS_EQUAL( "List", element, "the third to last element was not returned by the third call" )

  element = DListCItrPrevious( iterator );
  if( !element )
    return "the List did not have a fourth to last element";
  ASSERT_STRINGS_EQUAL( "test", element, "the fourth to last element was not returned by the fourth call" )

  element = DListCItrPrevious( iterator );
  if( !element )
    return "the List did not have a fifth to last element";
  ASSERT_STRINGS_EQUAL( "a", element, "the fifth to last element was not returned by the fifth call" )

  element = DListCItrPrevious( iterator );
  if( !element )
    return "the List did not have a sixth to last element";
  ASSERT_STRINGS_EQUAL( "is", element, "the sixth to last element was not returned by the sixth call" )

  element = DListCItrPrevious( iterator );
  if( !element )
    return "the List did not have a seventh to last element";
  ASSERT_STRINGS_EQUAL( "This", element, "the seventh to last element was not returned by the seventh call" )

  DListCItrDestroy( iterator );

  return NULL;
}

const char *
TestPreviousWithEmptyList
( void )
{
  const dlist_t *list;
  DListCItr *iterator;

  list = DListNew();
  if( !list )
    return "could not build a List";

  iterator = DListCBegin( list );
  if( !iterator )
    return "could not build a Itr";

  if( DListCItrPrevious( iterator ) )
    return "an empty List returned a non-NULL value";

  DListDestroy( list );
  DListCItrDestroy( iterator );

  return NULL;
}

const char *
TestPreviousWithNullIterator
( void )
{
  if( DListCItrPrevious( NULL ) != NULL )
    return "calling the function with a NULL Itr returned a non-NULL value";

  return NULL;
}
