#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <woodpile/dynamic/list/iterator.h>

#include "test/function/dynamic/list/iterator_suite.h"
#include "test/helper.h"

int
main( void )
{
  unsigned failure_count = 0;
  const char *result;

  TEST( AddNullElement )
  TEST( AddToBeginning )
  TEST( AddToEmptyList )
  TEST( AddToEnd )
  TEST( AddToMiddle )
  TEST( AddWithNullIterator )
  TEST( BeginWithEmptyList )
  TEST( BeginWithNullList )
  TEST( BeginWithPopulatedList )
  TEST( Copy )
  TEST( CopyContents )
  TEST( CopyDistinct )
  TEST( CopyNullIterator )
  TEST( CopyPosition )
  TEST( Destroy )
  TEST( DestroyNullIterator )
  TEST( EndWithEmptyList )
  TEST( EndWithNullList )
  TEST( EndWithPopulatedList )
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
  TEST( RemoveAfterNext )
  TEST( RemoveAfterNextAndAdd )
  TEST( RemoveAfterPrevious )
  TEST( RemoveAfterPreviousAndAdd )
  TEST( RemoveAfterRemove )
  TEST( RemoveBeforeNextOrPrevious )
  TEST( RemoveFromNullIterator )

  if( failure_count > 0 )
    return EXIT_FAILURE;
  else
    return EXIT_SUCCESS;
}

const char *
TestAddNullElement
( void )
{
  DList *list;
  DListItr *iterator;

  if( DListItrAdd( NULL, NULL ) != NULL )
    return "a non-NULL value was returned when adding a NULL element to a NULL ListIterator";

  list = BuildDList();
  if( !list )
    return "could not build a List";

  iterator = DListBegin( list );
  if( !iterator )
    return "could not build a ListIterator";

  if( DListItrAdd( iterator, NULL ) != iterator )
    return "a NULL element could not be added to a non-NULL ListIterator";

  DListDestroy( list );
  DListItrDestroy( iterator );

  return NULL;
}

const char *
TestAddToBeginning
( void )
{
  DList *list;
  DListItr *iterator;
  void *element = "new element";

  list = BuildDList();
  if( !list )
    return "could not build a List";

  iterator = DListBegin( list );
  if( !iterator )
    return "could not build a ListIterator";

  if( DListItrAdd( iterator, element ) != iterator )
    return "could not add an element to the ListIterator";

  if( DListFront( list ) != element )
    return "the element was not added to the beginning of the List";

  if( !DListItrHasNext( iterator ) )
    return "the ListIterator did not have a next element after insertion";

  if( !DListItrHasPrevious( iterator ) )
    return "the ListIterator did not have a previous element after insertion";

  if( DListItrPrevious( iterator ) != element )
    return "the previous element in the ListIterator was not the inserted element";

  DListDestroy( list );
  DListItrDestroy( iterator );

  return NULL;
}

const char *
TestAddToEmptyList
( void )
{
  DList *list;
  DListItr *iterator;
  void *element = "new element";

  list = DListNew();
  if( !list )
    return "could not build a List";

  iterator = DListBegin( list );
  if( !iterator )
    return "could not build a ListIterator";

  if( DListItrAdd( iterator, element ) != iterator )
    return "could not add an element to the ListIterator";

  if( DListItrHasNext( iterator ) )
    return "a ListIterator had a next element after insertion";

  if( !DListItrHasPrevious( iterator ) )
    return "a ListIterator did not have a previous element after insertion";

  if( DListItrPrevious( iterator ) != element )
    return "the previous element in a ListIterator was not the inserted element";

  DListDestroy( list );
  DListItrDestroy( iterator );

  return NULL;
}

const char *
TestAddToEnd
( void )
{
  DList *list;
  DListItr *iterator;
  void *element = "new element";

  list = BuildDList();
  if( !list )
    return "could not build a List";

  iterator = DListEnd( list );
  if( !iterator )
    return "could not build a ListIterator";

  if( DListItrAdd( iterator, element ) != iterator )
    return "could not add an element to the ListIterator";

  if( DListBack( list ) != element )
    return "the element was not added to the end of the List";

  if( DListItrHasNext( iterator ) )
    return "the ListIterator had a next element after insertion";

  if( !DListItrHasPrevious( iterator ) )
    return "the ListIterator did not have a previous element after insertion";

  if( DListItrPrevious( iterator ) != element )
    return "the previous element in the ListIterator was not the inserted element";

  DListDestroy( list );
  DListItrDestroy( iterator );

  return NULL;
}

const char *
TestAddToMiddle
( void )
{
  DList *list;
  DListItr *iterator;
  void *element = "new element";

  list = BuildDList();
  if( !list )
    return "could not build a List";

  iterator = DListBegin( list );
  if( !iterator )
    return "could not build a ListIterator";

  DListItrNext( iterator );
  DListItrNext( iterator );

  if( DListItrAdd( iterator, element ) != iterator )
    return "could not add an element to the ListIterator";

  if( !DListItrHasNext( iterator ) )
    return "the ListIterator did not have a next element after insertion";

  if( !DListItrHasPrevious( iterator ) )
    return "the ListIterator did not have a previous element after insertion";

  if( DListItrPrevious( iterator ) != element )
    return "the previous element in the ListIterator was not the inserted element";

  if( DListGet( list, 2 ) != element )
    return "the element was not inserted into the proper location";

  DListDestroy( list );
  DListItrDestroy( iterator );

  return NULL;
}

const char *
TestAddWithNullIterator
( void )
{
  void *element = "new element";

  if( DListItrAdd( NULL, NULL ) != NULL )
    return "a non-NULL value was returned when adding a NULL element to a NULL ListIterator";

  if( DListItrAdd( NULL, element ) != NULL )
    return "a non-NULL value was returned when adding a non-NULL element to a NULL ListIterator";

  return NULL;
}

const char *
TestBeginWithEmptyList
( void )
{
  DList *list;
  DListItr *iterator;

  list = DListNew();
  if( !list )
    return "could not build a List";

  iterator = DListBegin( list );
  if( !iterator )
    return "a NULL ListIterator was returned for an empty List";

  if( DListItrPrevious( iterator ) != NULL )
    return "the previous element in the iterator was non-NULL";

  if( DListItrNext( iterator ) != NULL )
    return "the next element in the iterator was non-NULL";

  DListItrDestroy( iterator );
  DListDestroy( list );

  return NULL;
}

const char *
TestBeginWithNullList
( void )
{
  if( DListBegin( NULL ) != NULL )
    return "a non-NULL ListIterator was returned for a NULL List";

  return NULL;
}

const char *
TestBeginWithPopulatedList
( void )
{
  DList *list;
  DListItr *iterator;
  const void *element;

  list = BuildDList();
  if( !list )
    return "could not build a List";

  iterator = DListBegin( list );
  if( !iterator )
    return "a NULL ListIterator was returned for a populated List";

  if( DListItrPrevious( iterator ) != NULL )
    return "the previous element of the iterator was non-NULL";

  element = DListItrNext( iterator );
  if( !element )
    return "the next element of the iterator was NULL";
  ASSERT_STRINGS_EQUAL( "This", element, "the next element of the iterator was not the first element of the List" )

  DListDestroy( list );
  DListItrDestroy( iterator );

  return NULL;
}

const char *
TestCopy
( void )
{
  DList *list;
  DListItr *copy, *iterator;

  list = BuildDList();
  if( !list )
    return "could not build a List";

  iterator = DListBegin( list );
  if( !iterator )
    return "could not build a ListIterator";

  copy = DListItrCopy( iterator );
  if( copy == NULL )
    return "NULL was returned for a non-NULL ListIterator";

  DListDestroy( list );
  DListItrDestroy( copy );
  DListItrDestroy( iterator );

  return NULL;
}

const char *
TestCopyContents
( void )
{
  DList *list;
  DListItr *copy, *iterator;
  const void *element;

  list = BuildDList();
  if( !list )
    return "could not build a List";

  iterator = DListBegin( list );
  if( !iterator )
    return "could not build a ListIterator";

  copy = DListItrCopy( iterator );
  if( !copy )
    return "could not copy a ListIterator";

  element = DListItrNext( copy );
  if( !element )
    return "the copied ListIterator did not have a first element";

  if( element != DListFront( list ) )
    return "the first element in the ListIterator was not the first element in the List";

  if( element != DListItrNext( iterator ) )
    return "the first element in the original did not match the first element of the copy";

  DListDestroy( list );
  DListItrDestroy( copy );
  DListItrDestroy( iterator );

  return NULL;
}

const char *
TestCopyDistinct
( void )
{
  DList *list;
  DListItr *copy, *iterator;
  const void *element_1, *element_2, *element_3;

  list = BuildDList();
  if( !list )
    return "could not build a List";

  iterator = DListBegin( list );
  if( !iterator )
    return "could not build a ListIterator";

  copy = DListItrCopy( iterator );
  if( !copy )
    return "could not copy a ListIterator";

  if( copy == iterator )
    return "the copy was the same structure as the original";

  element_1 = DListItrNext( copy );
  if( !element_1 )
    return "there was no first element";
  element_2 = DListItrNext( copy );
  if( !element_2 )
    return "there was no second element";
  element_3 = DListItrNext( copy );
  if( !element_3 )
    return "there was no third element";

  if( DListItrNext( iterator ) != element_1 )
    return "advancing the pointer of the copy changed the pointer of the original";

  DListItrPrevious( copy );
  DListItrPrevious( copy );

  if( DListItrPrevious( iterator ) != element_1 )
    return "backing up the pointer of the copy changed the pointer of the original";

  DListDestroy( list );
  DListItrDestroy( copy );
  DListItrDestroy( iterator );

  return NULL;
}

const char *
TestCopyNullIterator
( void )
{
  if( DListItrCopy( NULL ) != NULL )
    return "a non-NULL value was returned when copying NULL";

  return NULL;
}

const char *
TestCopyPosition
( void )
{
  DList *list;
  DListItr *copy, *iterator;

  list = BuildDList();
  if( !list )
    return "could not build a List";

  iterator = DListBegin( list );
  if( !iterator )
    return "could not build a ListIterator";

  DListItrNext( iterator );
  DListItrNext( iterator );

  copy = DListItrCopy( iterator );
  if( !copy )
    return "could not copy a ListIterator";

  if( DListItrNext( iterator ) != DListItrNext( copy ) )
    return "the position of the iterator was not the same in the copy as the original";

  DListDestroy( list );
  DListItrDestroy( copy );
  DListItrDestroy( iterator );

  return NULL;
}

const char *
TestDestroy
( void )
{
  DList *list;
  DListItr *iterator;

  list = BuildDList();
  if( !list )
    return "could not build a List";

  iterator = DListBegin( list );
  if( !iterator )
    return "could not build a ListIterator";

  DListItrDestroy( iterator );

  DListDestroy( list );

  return NULL;
}

const char *
TestDestroyNullIterator
( void )
{
  DListItrDestroy( NULL );

  return NULL;
}

const char *
TestEndWithEmptyList
( void )
{
  DList *list;
  DListItr *iterator;

  list = DListNew();
  if( !list )
    return "could not build a List";

  iterator = DListEnd( list );
  if( !iterator )
    return "a NULL ListIterator was returned for an empty List";

  if( DListItrPrevious( iterator ) != NULL )
    return "the previous element in the iterator was non-NULL";

  if( DListItrNext( iterator ) != NULL )
    return "the next element in the iterator was non-NULL";

  DListDestroy( list );
  DListItrDestroy( iterator );

  return NULL;
}

const char *
TestEndWithNullList
( void )
{
  if( DListEnd( NULL ) != NULL )
    return "a non-NULL ListIterator was returned for a NULL List";

  return NULL;
}

const char *
TestEndWithPopulatedList
( void )
{
  DList *list;
  DListItr *iterator;
  const void *element;

  list = BuildDList();
  if( !list )
    return "could not build a List";

  iterator = DListEnd( list );
  if( !iterator )
    return "a NULL ListIterator was returned for a populated List";

  if( DListItrNext( iterator ) != NULL )
    return "the next element of the iterator was non-NULL";

  element = DListItrPrevious( iterator );
  if( !element )
    return "the previous element of the iterator was NULL";
  ASSERT_STRINGS_EQUAL( "strings!", element, "the previous element of the iterator was not the last element of the List" )

  DListDestroy( list );
  DListItrDestroy( iterator );

  return NULL;
}

const char *
TestHasNextAtBeginning
( void )
{
  DList *list;
  DListItr *iterator;

  list = BuildDList();
  if( !list )
    return "could not build a List";

  iterator = DListBegin( list );
  if( !iterator )
    return "could not build a ListIterator";

  if( !DListItrHasNext( iterator ) )
    return "a ListIterator at the beginning of a List returned false";

  DListDestroy( list );
  DListItrDestroy( iterator );

  return NULL;
}

const char *
TestHasNextAtEnd
( void )
{
  DList *list;
  DListItr *iterator;

  list = BuildDList();
  if( !list )
    return "could not build a List";

  iterator = DListEnd( list );
  if( !iterator )
    return "could not build a ListIterator";

  if( DListItrHasNext( iterator ) )
    return "a ListIterator at the end of a List returned true";

  DListDestroy( list );
  DListItrDestroy( iterator );

  return NULL;
}

const char *
TestHasNextAtMiddle
( void )
{
  DList *list;
  DListItr *iterator;

  list = BuildDList();
  if( !list )
    return "could not build a List";

  iterator = DListBegin( list );
  if( !iterator )
    return "could not build a ListIterator";

  DListItrNext( iterator );
  DListItrNext( iterator );
  DListItrNext( iterator );

  if( !DListItrHasNext( iterator ) )
    return "a ListIterator in the middle of a List returned false";

  DListDestroy( list );
  DListItrDestroy( iterator );

  return NULL;
}

const char *
TestHasNextWithEmptyList
( void )
{
  DList *list;
  DListItr *iterator;

  list = DListNew();
  if( !list )
    return "could not build a List";

  iterator = DListBegin( list );
  if( !iterator )
    return "could not build a ListIterator";

  if( DListItrHasNext( iterator ) )
    return "an empty List returned true";

  DListDestroy( list );
  DListItrDestroy( iterator );

  return NULL;
}

const char *
TestHasNextWithNullIterator
( void )
{
  if( DListItrHasNext( NULL ) )
    return "a NULL iterator returned true";

  return NULL;
}

const char *
TestHasPreviousAtBeginning
( void )
{
  DList *list;
  DListItr *iterator;

  list = BuildDList();
  if( !list )
    return "could not build a List";

  iterator = DListBegin( list );
  if( !iterator )
    return "could not build a ListIterator";

  if( DListItrHasPrevious( iterator ) )
    return "a ListIterator at the beginning of a List returned true";

  DListDestroy( list );
  DListItrDestroy( iterator );

  return NULL;
}

const char *
TestHasPreviousAtEnd
( void )
{
  DList *list;
  DListItr *iterator;

  list = BuildDList();
  if( !list )
    return "could not build a List";

  iterator = DListEnd( list );
  if( !iterator )
    return "could not build a ListIterator";

  if( !DListItrHasPrevious( iterator ) )
    return "a ListIterator at the end of a List returned false";

  DListDestroy( list );
  DListItrDestroy( iterator );

  return NULL;
}

const char *
TestHasPreviousAtMiddle
( void )
{
  DList *list;
  DListItr *iterator;

  list = BuildDList();
  if( !list )
    return "could not build a List";

  iterator = DListBegin( list );
  if( !iterator )
    return "could not build a ListIterator";

  DListItrNext( iterator );
  DListItrNext( iterator );
  DListItrNext( iterator );

  if( !DListItrHasPrevious( iterator ) )
    return "a ListIterator in the middle of a List returned false";

  DListDestroy( list );
  DListItrDestroy( iterator );

  return NULL;
}

const char *
TestHasPreviousWithEmptyList
( void )
{
  DList *list;
  DListItr *iterator;

  list = DListNew();
  if( !list )
    return "could not build a List";

  iterator = DListBegin( list );
  if( !iterator )
    return "could not build a ListIterator";

  if( DListItrHasPrevious( iterator ) )
    return "an empty List returned true";

  DListDestroy( list );
  DListItrDestroy( iterator );

  return NULL;
}

const char *
TestHasPreviousWithNullIterator
( void )
{
  if( DListItrHasNext( NULL ) )
    return "a NULL iterator returned true";

  return NULL;
}

const char *
TestNextAtBeginning
( void )
{
  DList *list;
  DListItr *iterator;

  list = BuildDList();
  if( !list )
    return "could not build a List";

  iterator = DListBegin( list );
  if( !iterator )
    return "could not build a ListIterator";

  if( DListItrNext( iterator ) != DListFront( list ) )
    return "the first element in the List was not returned by the first call to DListItrNext";

  DListDestroy( list );
  DListItrDestroy( iterator );

  return NULL;
}

const char *
TestNextAtEnd
( void )
{
  DList *list;
  DListItr *iterator;

  list = BuildDList();
  if( !list )
    return "could not build a List";

  iterator = DListEnd( list );
  if( !iterator )
    return "could not build a ListIterator";

  if( DListItrNext( iterator ) )
    return "a non-NULL value was returned by a ListIterator at the end of a List";

  DListDestroy( list );
  DListItrDestroy( iterator );

  return NULL;
}

const char *
TestNextAtMiddle
( void )
{
  DList *list;
  DListItr *iterator;
  const void *element;

  list = BuildDList();
  if( !list )
    return "could not build a List";

  iterator = DListBegin( list );
  if( !iterator )
    return "could not build a ListIterator";

  element = DListItrNext( iterator );
  if( !element )
    return "the List did not have a first element";
  ASSERT_STRINGS_EQUAL( "This", element, "the first element was not returned by the first call" )

  element = DListItrNext( iterator );
  if( !element )
    return "the List did not have a second element";
  ASSERT_STRINGS_EQUAL( "is", element, "the second element was not returned by the second call" )

  element = DListItrNext( iterator );
  if( !element )
    return "the List did not have a third element";
  ASSERT_STRINGS_EQUAL( "a", element, "the third element was not returned by the third call" )

  element = DListItrNext( iterator );
  if( !element )
    return "the List did not have a fourth element";
  ASSERT_STRINGS_EQUAL( "test", element, "the fourth element was not returned by the fourth call" )

  element = DListItrNext( iterator );
  if( !element )
    return "the List did not have a fifth element";
  ASSERT_STRINGS_EQUAL( "List", element, "the fifth element was not returned by the fifth call" )

  element = DListItrNext( iterator );
  if( !element )
    return "the List did not have a sixth element";
  ASSERT_STRINGS_EQUAL( "o'", element, "the sixth element was not returned by the sixth call" )

  element = DListItrNext( iterator );
  if( !element )
    return "the List did not have a seventh element";
  ASSERT_STRINGS_EQUAL( "strings!", element, "the seventh element was not returned by the seventh call" )

  DListDestroy( list );
  DListItrDestroy( iterator );

  return NULL;
}

const char *
TestNextWithEmptyList
( void )
{
  DList *list;
  DListItr *iterator;

  list = DListNew();
  if( !list )
    return "could not build a List";

  iterator = DListBegin( list );
  if( !iterator )
    return "could not build a ListIterator";

  if( DListItrNext( iterator ) )
    return "an empty List returned a non-NULL value";

  DListDestroy( list );
  DListItrDestroy( iterator );

  return NULL;
}

const char *
TestNextWithNullIterator
( void )
{
  if( DListItrNext( NULL ) != NULL )
    return "calling the function with a NULL ListIterator returned a non-NULL value";

  return NULL;
}

const char *
TestPreviousAtBeginning
( void )
{
  DList *list;
  DListItr *iterator;

  list = BuildDList();
  if( !list )
    return "could not build a List";

  iterator = DListBegin( list );
  if( !iterator )
    return "could not build a ListIterator";

  if( DListItrPrevious( iterator ) != NULL )
    return "a non-NULL value was returned by the first call to DListItrPrevious";

  DListDestroy( list );
  DListItrDestroy( iterator );

  return NULL;
}

const char *
TestPreviousAtEnd
( void )
{
  DList *list;
  DListItr *iterator;

  list = BuildDList();
  if( !list )
    return "could not build a List";

  iterator = DListEnd( list );
  if( !iterator )
    return "could not build a ListIterator";

  if( DListItrPrevious( iterator ) != DListBack( list ) )
    return "the last element was not returned by a ListIterator at the end of a List";

  DListDestroy( list );
  DListItrDestroy( iterator );

  return NULL;
}

const char *
TestPreviousAtMiddle
( void )
{
  DList *list;
  DListItr *iterator;
  const void *element;

  list = BuildDList();
  if( !list )
    return "could not build a List";

  iterator = DListEnd( list );
  if( !iterator )
    return "could not build a ListIterator";

  element = DListItrPrevious( iterator );
  if( !element )
    return "the List did not have a last element";
  ASSERT_STRINGS_EQUAL( "strings!", element, "the last element was not returned by the first call" )

  element = DListItrPrevious( iterator );
  if( !element )
    return "the List did not have a second to last element";
  ASSERT_STRINGS_EQUAL( "o'", element, "the second to last element was not returned by the second call" )

  element = DListItrPrevious( iterator );
  if( !element )
    return "the List did not have a third to last element";
  ASSERT_STRINGS_EQUAL( "List", element, "the third to last element was not returned by the third call" )

  element = DListItrPrevious( iterator );
  if( !element )
    return "the List did not have a fourth to last element";
  ASSERT_STRINGS_EQUAL( "test", element, "the fourth to last element was not returned by the fourth call" )

  element = DListItrPrevious( iterator );
  if( !element )
    return "the List did not have a fifth to last element";
  ASSERT_STRINGS_EQUAL( "a", element, "the fifth to last element was not returned by the fifth call" )

  element = DListItrPrevious( iterator );
  if( !element )
    return "the List did not have a sixth to last element";
  ASSERT_STRINGS_EQUAL( "is", element, "the sixth to last element was not returned by the sixth call" )

  element = DListItrPrevious( iterator );
  if( !element )
    return "the List did not have a seventh to last element";
  ASSERT_STRINGS_EQUAL( "This", element, "the seventh to last element was not returned by the seventh call" )

  DListDestroy( list );
  DListItrDestroy( iterator );

  return NULL;
}

const char *
TestPreviousWithEmptyList
( void )
{
  DList *list;
  DListItr *iterator;

  list = DListNew();
  if( !list )
    return "could not build a List";

  iterator = DListBegin( list );
  if( !iterator )
    return "could not build a ListIterator";

  if( DListItrPrevious( iterator ) )
    return "an empty List returned a non-NULL value";

  DListDestroy( list );
  DListItrDestroy( iterator );

  return NULL;
}

const char *
TestPreviousWithNullIterator
( void )
{
  if( DListItrPrevious( NULL ) != NULL )
    return "calling the function with a NULL ListIterator returned a non-NULL value";

  return NULL;
}

const char *
TestRemoveAfterNext
( void )
{
  DList *list;
  DListItr *iterator;
  const void *element;

  list = BuildDList();
  if( !list )
    return "could not build a List";

  iterator = DListBegin( list );
  if( !iterator )
    return "could not build a ListIterator";

  DListItrNext( iterator );
  element = DListItrNext( iterator );

  if( DListItrRemove( iterator ) != element )
    return "the last element returned by DListItrNext was not returned";

  if( DListGet( list, 1 ) == element )
    return "the element was not removed from the List";

  element = DListFront( list );
  if( !element )
    return "after removal the List did not have a front element";
  ASSERT_STRINGS_EQUAL( "This", element, "the first element of the List changed" )

  element = DListGet( list, 1 );
  if( !element )
    return "after removal the list did not have a second element";
  ASSERT_STRINGS_EQUAL( "a", element, "the second element of the List was not the previous third" )

  if( DListItrNext( iterator ) != element )
    return "the position of the ListIterator changed after a call to DListItrRemove";

  DListDestroy( list );
  DListItrDestroy( iterator );

  return NULL;
}

const char *
TestRemoveAfterNextAndAdd
( void )
{
  DList *list;
  DListItr *iterator;
  void *added = "new element", *first;

  list = BuildDList();
  if( !list )
    return "could not build a List";

  iterator = DListBegin( list );
  if( !iterator )
    return "could not build a ListIterator";

  first = DListItrNext( iterator );
  DListItrAdd( iterator, added );

  if( DListItrRemove( iterator ) != NULL )
    return "a non-NULL value was returned by a call to DListItrRemove after a call to DListItrAdd";

  if( DListFront( list ) != first )
    return "the first element was removed from the List";

  if( DListGet( list, 1 ) != added )
    return "the newly added element was removed from the List";

  if( DListItrNext( iterator ) != DListGet( list,  2 ) )
    return "the position of the ListIterator was changed by the call to DListItrRemove";

  DListDestroy( list );
  DListItrDestroy( iterator );

  return NULL;
}

const char *
TestRemoveAfterPrevious
( void )
{
  DList *list;
  DListItr *iterator;
  const void *element;

  list = BuildDList();
  if( !list )
    return "could not build a List";

  iterator = DListEnd( list );
  if( !iterator )
    return "could not build a ListIterator";

  DListItrPrevious( iterator );
  element = DListItrPrevious( iterator );

  if( DListItrRemove( iterator ) != element )
    return "the last element returned by DListItrPrevious was not returned";

  if( DListGet( list, -2 ) == element )
    return "the element was not removed from the List";

  element = DListBack( list );
  if( !element )
    return "after removal the List did not have a back element";
  ASSERT_STRINGS_EQUAL( "strings!", element, "the last element of the List changed" )

  element = DListGet( list, -2 );
  if( !element )
    return "after removal the list did not have a second element";
  ASSERT_STRINGS_EQUAL( "List", element, "the second to last element of the List was not the previous third to last" )

  if( DListItrPrevious( iterator ) != element )
    return "the position of the ListIterator changed after a call to DListItrRemove";

  DListDestroy( list );
  DListItrDestroy( iterator );

  return NULL;
}

const char *
TestRemoveAfterPreviousAndAdd
( void )
{
  DList *list;
  DListItr *iterator;
  void *added = "new element", *last;

  list = BuildDList();
  if( !list )
    return "could not build a List";

  iterator = DListEnd( list );
  if( !iterator )
    return "could not build a ListIterator";

  last = DListItrPrevious( iterator );
  DListItrAdd( iterator, added );

  if( DListItrRemove( iterator ) != NULL )
    return "a non-NULL value was returned by a call to DListItrRemove after a call to DListItrAdd";

  if( DListBack( list ) != last )
    return "the last element was removed from the List";

  if( DListGet( list, -2 ) != added )
    return "the newly added element was removed from the List";

  if( DListItrPrevious( iterator ) != added )
    return "the position of the ListIterator was changed by the call to DListItrRemove";

  DListDestroy( list );
  DListItrDestroy( iterator );

  return NULL;
}

const char *
TestRemoveAfterRemove
( void )
{
  DList *list;
  DListItr *iterator;
  const void *element, *removed;

  list = BuildDList();
  if( !list )
    return "could not build a List";

  iterator = DListBegin( list );
  if( !iterator )
    return "could not build a ListIterator";

  element = DListItrNext( iterator );
  DListItrNext( iterator );

  removed = DListItrRemove( iterator );

  if( DListItrRemove( iterator ) != NULL )
    return "a second successive call to DListItrRemove returned a non-NULL value";

  if( DListContains( list, removed ) )
    return "the removed element was no longer removed from the List";

  if( DListFront( list ) != element )
    return "the front element of the List changed after the second call to DListItrRemove";

  if( DListItrNext( iterator ) != DListGet( list, 1 ) )
    return "the position of the ListIterator was changed after the second call to DListItrRemove";

  DListDestroy( list );
  DListItrDestroy( iterator );

  return NULL;
}

const char *
TestRemoveBeforeNextOrPrevious
( void )
{
  DList *list;
  DListItr *iterator;

  list = BuildDList();
  if( !list )
    return "could not build a List";

  iterator = DListBegin( list );
  if( !iterator )
    return "could not build a ListIterator";

  if( DListItrRemove( iterator ) != NULL )
    return "a non-NULL value was returned from a premature call to DListItrRemove";

  if( DListItrNext( iterator ) != DListFront( list ) )
    return "the position of the ListIterator was changed after a premature call to DListItrRemove";

  DListDestroy( list );
  DListItrDestroy( iterator );

  return NULL;
}

const char *
TestRemoveFromNullIterator
( void )
{
  if( DListItrRemove( NULL ) != NULL )
    return "a non-NULL value was returned for a NULL ListIterator";

  return NULL;
}