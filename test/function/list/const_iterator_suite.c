#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <woodpile/list/const_iterator.h>

#include "test/function/list/const_iterator_suite.h"
#include "test/helper.h"

int
main( void )
{
  unsigned failure_count = 0;
  const char *result;

  TEST( CBeginWithEmptyList )
  TEST( CBeginWithNullList )
  TEST( CBeginWithPopulatedList )
  TEST( CEndWithEmptyList )
  TEST( CEndWithNullList )
  TEST( CEndWithPopulatedList )
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
  TEST( NextWithNullIterator )
  TEST( PreviousAtBeginning )
  TEST( PreviousAtEnd )
  TEST( PreviousAtMiddle )
  TEST( PreviousWithEmptyList )
  TEST( PreviousWithNullIterator )

  if( failure_count > 0 )
    return EXIT_FAILURE;
  else
    return EXIT_SUCCESS;
}

const char *
TestCBeginWithEmptyList
( void )
{
  const List *list;
  ListConstIterator *iterator;
  const void *element;

  list = NewList();
  if( !list )
    return "could not build a List";

  iterator = CBeginList( list );
  if( !iterator )
    return "a NULL ListConstIterator was returned for an empty List";

  if( PreviousInListConstIterator( iterator ) != NULL )
    return "the previous element in the iterator was non-NULL";

  if( NextInListConstIterator( iterator ) != NULL )
    return "the next element in the iterator was non-NULL";

  DestroyListConstIterator( iterator );
  DestroyList( list );

  return NULL;
}

const char *
TestCBeginWithNullList
( void )
{
  if( CBeginList( NULL ) != NULL )
    return "a non-NULL ListConstIterator was returned for a NULL List";

  return NULL;
}

const char *
TestCBeginWithPopulatedList
( void )
{
  const List *list;
  ListConstIterator *iterator;
  const void *element;

  list = BuildList();
  if( !list )
    return "could not build a List";

  iterator = CBeginList( list );
  if( !iterator )
    return "a NULL ListConstIterator was returned for a populated List";

  if( PreviousInListConstIterator( iterator ) != NULL )
    return "the previous element of the iterator was non-NULL";

  element = NextInListConstIterator( iterator );
  if( !element )
    return "the next element of the iterator was NULL";
  ASSERT_STRINGS_EQUAL( "This", element, "the next element of the iterator was not the first element of the List" )

  DestroyList( list );
  DestroyListConstIterator( iterator );

  return NULL;
}

const char *
TestCEndWithEmptyList
( void )
{
  const List *list;
  ListConstIterator *iterator;
  const void *element;

  list = NewList();
  if( !list )
    return "could not build a List";

  iterator = CEndList( list );
  if( !iterator )
    return "a NULL ListConstIterator was returned for an empty List";

  if( PreviousInListConstIterator( iterator ) != NULL )
    return "the previous element in the iterator was non-NULL";

  if( NextInListConstIterator( iterator ) != NULL )
    return "the next element in the iterator was non-NULL";

  DestroyList( list );
  DestroyListConstIterator( iterator );

  return NULL;
}

const char *
TestCEndWithNullList
( void )
{
  if( CEndList( NULL ) != NULL )
    return "a non-NULL ListConstIterator was returned for a NULL List";

  return NULL;
}

const char *
TestCEndWithPopulatedList
( void )
{
  const List *list;
  ListConstIterator *iterator;
  const void *element;

  list = BuildList();
  if( !list )
    return "could not build a List";

  iterator = CEndList( list );
  if( !iterator )
    return "a NULL ListConstIterator was returned for a populated List";

  if( NextInListConstIterator( iterator ) != NULL )
    return "the next element of the iterator was non-NULL";

  element = PreviousInListConstIterator( iterator );
  if( !element )
    return "the previous element of the iterator was NULL";
  ASSERT_STRINGS_EQUAL( "strings!", element, "the previous element of the iterator was not the last element of the List" )

  DestroyList( list );
  DestroyListConstIterator( iterator );

  return NULL;
}

const char *
TestCopy
( void )
{
  const List *list;
  const ListConstIterator *copy, *iterator;

  list = BuildList();
  if( !list )
    return "could not build a List"; 

  iterator = CBeginList( list );
  if( !iterator )
    return "could not build a ListConstIterator";

  copy = CopyListConstIterator( iterator );
  if( copy == NULL )
    return "NULL was returned for a non-NULL ListConstIterator";

  DestroyList( list );
  DestroyListConstIterator( copy );
  DestroyListConstIterator( iterator );

  return NULL;
}

const char *
TestCopyContents
( void )
{
  const List *list;
  ListConstIterator *copy, *iterator;
  const void *element;

  list = BuildList();
  if( !list )
    return "could not build a List";

  iterator = CBeginList( list );
  if( !iterator )
    return "could not build a ListConstIterator";

  copy = CopyListConstIterator( iterator );
  if( !copy )
    return "could not copy a ListConstIterator";

  element = NextInListConstIterator( copy );
  if( !element )
    return "the copied ListConstIterator did not have a first element";

  if( element != ListFront( list ) )
    return "the first element in the ListConstIterator was not the first element in the List";

  if( element != NextInListConstIterator( iterator ) )
    return "the first element in the original did not match the first element of the copy";

  DestroyList( list );
  DestroyListConstIterator( copy );
  DestroyListConstIterator( iterator );

  return NULL;
}

const char *
TestCopyDistinct
( void )
{
  const List *list;
  ListConstIterator *copy, *iterator;
  const void *element_1, *element_2, *element_3;

  list = BuildList();
  if( !list )
    return "could not build a List";

  iterator = CBeginList( list );
  if( !iterator )
    return "could not build a ListConstIterator"; 

  copy = CopyListConstIterator( iterator );
  if( !copy )
    return "could not copy a ListConstIterator";

  if( copy == iterator )
    return "the copy was the same structure as the original";

  element_1 = NextInListConstIterator( copy );
  if( !element_1 )
    return "there was no first element";
  element_2 = NextInListConstIterator( copy );
  if( !element_2 )
    return "there was no second element";
  element_3 = NextInListConstIterator( copy );
  if( !element_3 )
    return "there was no third element";

  if( NextInListConstIterator( iterator ) != element_1 )
    return "advancing the pointer of the copy changed the pointer of the original";

  PreviousInListConstIterator( copy );
  PreviousInListConstIterator( copy );

  if( PreviousInListConstIterator( iterator ) != element_1 )
    return "backing up the pointer of the copy changed the pointer of the original";

  DestroyList( list );
  DestroyListConstIterator( copy );
  DestroyListConstIterator( iterator );
 
  return NULL;
}

const char *
TestCopyNullIterator
( void )
{
  if( CopyListConstIterator( NULL ) != NULL )
    return "a non-NULL value was returned when copying NULL";

  return NULL;
}

const char *
TestCopyPosition
( void )
{
  const List *list;
  ListConstIterator *copy, *iterator;

  list = BuildList();
  if( !list )
    return "could not build a List";

  iterator = CBeginList( list );
  if( !iterator )
    return "could not build a ListConstIterator";

  NextInListConstIterator( iterator );
  NextInListConstIterator( iterator );

  copy = CopyListConstIterator( iterator );
  if( !copy )
    return "could not copy a ListConstIterator";

  if( NextInListConstIterator( iterator ) != NextInListConstIterator( copy ) )
    return "the position of the iterator was not the same in the copy as the original";

  DestroyList( list );
  DestroyListConstIterator( copy );
  DestroyListConstIterator( iterator );

  return NULL;
}

const char *
TestDestroy
( void )
{
  const List *list;
  const ListConstIterator *iterator;

  list = BuildList();
  if( !list )
    return "could not build a List";

  iterator = CBeginList( list );
  if( !iterator )
    return "could not build a ListConstIterator";

  DestroyListConstIterator( iterator );

  DestroyList( list );

  return NULL;
}

const char *
TestDestroyNullIterator
( void )
{
  DestroyListConstIterator( NULL );

  return NULL;
}

const char *
TestHasNextAtBeginning
( void )
{
  const List *list;
  ListConstIterator *iterator;

  list = BuildList();
  if( !list )
    return "could not build a List";

  iterator = CBeginList( list );
  if( !iterator )
    return "could not build a ListConstIterator";

  if( !ListConstIteratorHasNext( iterator ) )
    return "a ListConstIterator at the beginning of a List returned false";

  DestroyList( list );
  DestroyListConstIterator( iterator );

  return NULL;
}

const char *
TestHasNextAtEnd
( void )
{
  const List *list;
  ListConstIterator *iterator;

  list = BuildList();
  if( !list )
    return "could not build a List";

  iterator = CEndList( list );
  if( !iterator )
    return "could not build a ListConstIterator";

  if( ListConstIteratorHasNext( iterator ) )
    return "a ListConstIterator at the end of a List returned true";

  DestroyList( list );
  DestroyListConstIterator( iterator );

  return NULL;
}

const char *
TestHasNextAtMiddle
( void )
{
  const List *list;
  ListConstIterator *iterator;

  list = BuildList();
  if( !list )
    return "could not build a List";

  iterator = CBeginList( list );
  if( !iterator )
    return "could not build a ListConstIterator";

  NextInListConstIterator( iterator );
  NextInListConstIterator( iterator );
  NextInListConstIterator( iterator );

  if( !ListConstIteratorHasNext( iterator ) )
    return "a ListConstIterator in the middle of a List returned false";

  DestroyList( list );
  DestroyListConstIterator( iterator );

  return NULL;
}

const char *
TestHasNextWithEmptyList
( void )
{
  const List *list;
  ListConstIterator *iterator;

  list = NewList();
  if( !list )
    return "could not build a List";

  iterator = CBeginList( list );
  if( !iterator )
    return "could not build a ListConstIterator";

  if( ListConstIteratorHasNext( iterator ) )
    return "an empty List returned true";

  DestroyList( list );
  DestroyListConstIterator( iterator );

  return NULL;
}

const char *
TestHasNextWithNullIterator
( void )
{
  if( ListConstIteratorHasNext( NULL ) )
    return "a NULL iterator returned true";

  return NULL;
}

const char *
TestHasPreviousAtBeginning
( void )
{
  const List *list;
  ListConstIterator *iterator;

  list = BuildList();
  if( !list )
    return "could not build a List";

  iterator = CBeginList( list );
  if( !iterator )
    return "could not build a ListConstIterator";

  if( ListConstIteratorHasPrevious( iterator ) )
    return "a ListConstIterator at the beginning of a List returned true";

  DestroyList( list );
  DestroyListConstIterator( iterator );

  return NULL;
}

const char *
TestHasPreviousAtEnd
( void )
{
  const List *list;
  ListConstIterator *iterator;

  list = BuildList();
  if( !list )
    return "could not build a List";

  iterator = CEndList( list );
  if( !iterator )
    return "could not build a ListConstIterator";

  if( !ListConstIteratorHasPrevious( iterator ) )
    return "a ListConstIterator at the end of a List returned false";

  DestroyList( list );
  DestroyListConstIterator( iterator );

  return NULL;
}

const char *
TestHasPreviousAtMiddle
( void )
{
  const List *list;
  ListConstIterator *iterator;

  list = BuildList();
  if( !list )
    return "could not build a List";

  iterator = CBeginList( list );
  if( !iterator )
    return "could not build a ListConstIterator";

  NextInListConstIterator( iterator );
  NextInListConstIterator( iterator );
  NextInListConstIterator( iterator );

  if( !ListConstIteratorHasPrevious( iterator ) )
    return "a ListConstIterator in the middle of a List returned false";

  DestroyList( list );
  DestroyListConstIterator( iterator );

  return NULL;
}

const char *
TestHasPreviousWithEmptyList
( void )
{
  const List *list;
  ListConstIterator *iterator;

  list = NewList();
  if( !list )
    return "could not build a List";

  iterator = CBeginList( list );
  if( !iterator )
    return "could not build a ListConstIterator";

  if( ListConstIteratorHasPrevious( iterator ) )
    return "an empty List returned true";

  DestroyList( list );
  DestroyListConstIterator( iterator );

  return NULL;
}

const char *
TestHasPreviousWithNullIterator
( void )
{
  if( ListConstIteratorHasNext( NULL ) )
    return "a NULL iterator returned true";

  return NULL;
}

const char *
TestNextAtBeginning
( void )
{
  const List *list;
  ListConstIterator *iterator;

  list = BuildList();
  if( !list )
    return "could not build a List";

  iterator = CBeginList( list );
  if( !iterator )
    return "could not build a ListConstIterator";

  if( NextInListConstIterator( iterator ) != ListFront( list ) )
    return "the first element in the List was not returned by the first call to NextInListConstIterator";

  DestroyList( list );
  DestroyListConstIterator( iterator );

  return NULL;
}

const char *
TestNextAtEnd
( void )
{
  const List *list;
  ListConstIterator *iterator;

  list = BuildList();
  if( !list )
    return "could not build a List";

  iterator = CEndList( list );
  if( !iterator )
    return "could not build a ListConstIterator";

  if( NextInListConstIterator( iterator ) )
    return "a non-NULL value was returned by a ListConstIterator at the end of a List";

  DestroyList( list );
  DestroyListConstIterator( iterator );

  return NULL;
}

const char *
TestNextAtMiddle
( void )
{
  const List *list;
  ListConstIterator *iterator;
  const void *element;

  list = BuildList();
  if( !list )
    return "could not build a List";

  iterator = CBeginList( list );
  if( !iterator )
    return "could not build a ListConstIterator";

  element = NextInListConstIterator( iterator );
  if( !element )
    return "the List did not have a first element";
  ASSERT_STRINGS_EQUAL( "This", element, "the first element was not returned by the first call" )

  element = NextInListConstIterator( iterator );
  if( !element )
    return "the List did not have a second element";
  ASSERT_STRINGS_EQUAL( "is", element, "the second element was not returned by the second call" )

  element = NextInListConstIterator( iterator );
  if( !element )
    return "the List did not have a third element";
  ASSERT_STRINGS_EQUAL( "a", element, "the third element was not returned by the third call" )

  element = NextInListConstIterator( iterator );
  if( !element )
    return "the List did not have a fourth element";
  ASSERT_STRINGS_EQUAL( "test", element, "the fourth element was not returned by the fourth call" )

  element = NextInListConstIterator( iterator );
  if( !element )
    return "the List did not have a fifth element";
  ASSERT_STRINGS_EQUAL( "List", element, "the fifth element was not returned by the fifth call" )

  element = NextInListConstIterator( iterator );
  if( !element )
    return "the List did not have a sixth element";
  ASSERT_STRINGS_EQUAL( "o'", element, "the sixth element was not returned by the sixth call" )

  element = NextInListConstIterator( iterator );
  if( !element )
    return "the List did not have a seventh element";
  ASSERT_STRINGS_EQUAL( "strings!", element, "the seventh element was not returned by the seventh call" )

  DestroyList( list );
  DestroyListConstIterator( iterator );

  return NULL;
}

const char *
TestNextWithEmptyList
( void )
{
  const List *list;
  ListConstIterator *iterator;

  list = NewList();
  if( !list )
    return "could not build a List";

  iterator = CBeginList( list );
  if( !iterator )
    return "could not build a ListConstIterator";

  if( NextInListConstIterator( iterator ) )
    return "an empty List returned a non-NULL value";

  DestroyList( list );
  DestroyListConstIterator( iterator );

  return NULL;
}

const char *
TestNextWithNullIterator
( void )
{
  if( NextInListConstIterator( NULL ) != NULL )
    return "calling the function with a NULL ListConstIterator returned a non-NULL value";

  return NULL;
}

const char *
TestPreviousAtBeginning
( void )
{
  const List *list;
  ListConstIterator *iterator;

  list = BuildList();
  if( !list )
    return "could not build a List";

  iterator = CBeginList( list );
  if( !iterator )
    return "could not build a ListConstIterator";

  if( PreviousInListConstIterator( iterator ) != NULL )
    return "a non-NULL value was returned by the first call to PreviousInListConstIterator";

  DestroyList( list );
  DestroyListConstIterator( iterator );

  return NULL;
}

const char *
TestPreviousAtEnd
( void )
{
  const List *list;
  ListConstIterator *iterator;

  list = BuildList();
  if( !list )
    return "could not build a List";

  iterator = CEndList( list );
  if( !iterator )
    return "could not build a ListConstIterator";

  if( PreviousInListConstIterator( iterator ) != ListBack( list ) )
    return "the last element was not returned by a ListConstIterator at the end of a List";

  DestroyList( list );
  DestroyListConstIterator( iterator );

  return NULL;
}

const char *
TestPreviousAtMiddle
( void )
{
  const List *list;
  ListConstIterator *iterator;
  const void *element;

  list = BuildList();
  if( !list )
    return "could not build a List";

  iterator = CEndList( list );
  if( !iterator )
    return "could not build a ListConstIterator";

  element = PreviousInListConstIterator( iterator );
  if( !element )
    return "the List did not have a last element";
  ASSERT_STRINGS_EQUAL( "strings!", element, "the last element was not returned by the first call" )

  element = PreviousInListConstIterator( iterator );
  if( !element )
    return "the List did not have a second to last element";
  ASSERT_STRINGS_EQUAL( "o'", element, "the second to last element was not returned by the second call" )

  element = PreviousInListConstIterator( iterator );
  if( !element )
    return "the List did not have a third to last element";
  ASSERT_STRINGS_EQUAL( "List", element, "the third to last element was not returned by the third call" )

  element = PreviousInListConstIterator( iterator );
  if( !element )
    return "the List did not have a fourth to last element";
  ASSERT_STRINGS_EQUAL( "test", element, "the fourth to last element was not returned by the fourth call" )

  element = PreviousInListConstIterator( iterator );
  if( !element )
    return "the List did not have a fifth to last element";
  ASSERT_STRINGS_EQUAL( "a", element, "the fifth to last element was not returned by the fifth call" )

  element = PreviousInListConstIterator( iterator );
  if( !element )
    return "the List did not have a sixth to last element";
  ASSERT_STRINGS_EQUAL( "is", element, "the sixth to last element was not returned by the sixth call" )

  element = PreviousInListConstIterator( iterator );
  if( !element )
    return "the List did not have a seventh to last element";
  ASSERT_STRINGS_EQUAL( "This", element, "the seventh to last element was not returned by the seventh call" )

  DestroyList( list );
  DestroyListConstIterator( iterator );

  return NULL;
}

const char *
TestPreviousWithEmptyList
( void )
{
  const List *list;
  ListConstIterator *iterator;

  list = NewList();
  if( !list )
    return "could not build a List";

  iterator = CBeginList( list );
  if( !iterator )
    return "could not build a ListConstIterator";

  if( PreviousInListConstIterator( iterator ) )
    return "an empty List returned a non-NULL value";

  DestroyList( list );
  DestroyListConstIterator( iterator );

  return NULL;
}

const char *
TestPreviousWithNullIterator
( void )
{
  if( PreviousInListConstIterator( NULL ) != NULL )
    return "calling the function with a NULL ListConstIterator returned a non-NULL value";

  return NULL;
}
