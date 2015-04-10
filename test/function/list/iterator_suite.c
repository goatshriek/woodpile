#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <woodpile/list/iterator.h>

#include "test/function/list/iterator_suite.h"
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
  List *list;
  ListIterator *iterator;

  if( AddToListIterator( NULL, NULL ) != NULL )
    return "a non-NULL value was returned when adding a NULL element to a NULL ListIterator";

  list = BuildList();
  if( !list )
    return "could not build a List";

  iterator = BeginList( list );
  if( !iterator )
    return "could not build a ListIterator";

  if( AddToListIterator( iterator, NULL ) != iterator )
    return "a NULL element could not be added to a non-NULL ListIterator";

  DestroyList( list );
  DestroyListIterator( iterator );

  return NULL;
}

const char *
TestAddToBeginning
( void )
{
  List *list;
  ListIterator *iterator;
  void *element = "new element";

  list = BuildList();
  if( !list )
    return "could not build a List";

  iterator = BeginList( list );
  if( !iterator )
    return "could not build a ListIterator";

  if( AddToListIterator( iterator, element ) != iterator )
    return "could not add an element to the ListIterator";

  if( ListFront( list ) != element )
    return "the element was not added to the beginning of the List";

  if( !ListIteratorHasNext( iterator ) )
    return "the ListIterator did not have a next element after insertion";

  if( !ListIteratorHasPrevious( iterator ) )
    return "the ListIterator did not have a previous element after insertion";

  if( PreviousInListIterator( iterator ) != element )
    return "the previous element in the ListIterator was not the inserted element";

  DestroyList( list );
  DestroyListIterator( iterator );

  return NULL;
}

const char *
TestAddToEmptyList
( void )
{
  List *list;
  ListIterator *iterator;
  void *element = "new element";

  list = NewList();
  if( !list )
    return "could not build a List";

  iterator = BeginList( list );
  if( !iterator )
    return "could not build a ListIterator";

  if( AddToListIterator( iterator, element ) != iterator )
    return "could not add an element to the ListIterator";

  if( ListIteratorHasNext( iterator ) )
    return "a ListIterator had a next element after insertion";

  if( !ListIteratorHasPrevious( iterator ) )
    return "a ListIterator did not have a previous element after insertion";

  if( PreviousInListIterator( iterator ) != element )
    return "the previous element in a ListIterator was not the inserted element";

  DestroyList( list );
  DestroyListIterator( iterator );

  return NULL;
}

const char *
TestAddToEnd
( void )
{
  List *list;
  ListIterator *iterator;
  void *element = "new element";

  list = BuildList();
  if( !list )
    return "could not build a List";

  iterator = EndList( list );
  if( !iterator )
    return "could not build a ListIterator";

  if( AddToListIterator( iterator, element ) != iterator )
    return "could not add an element to the ListIterator";

  if( ListBack( list ) != element )
    return "the element was not added to the end of the List";

  if( ListIteratorHasNext( iterator ) )
    return "the ListIterator had a next element after insertion";

  if( !ListIteratorHasPrevious( iterator ) )
    return "the ListIterator did not have a previous element after insertion";

  if( PreviousInListIterator( iterator ) != element )
    return "the previous element in the ListIterator was not the inserted element";

  DestroyList( list );
  DestroyListIterator( iterator );

  return NULL;
}

const char *
TestAddToMiddle
( void )
{
  List *list;
  ListIterator *iterator;
  void *element = "new element";

  list = BuildList();
  if( !list )
    return "could not build a List";

  iterator = BeginList( list );
  if( !iterator )
    return "could not build a ListIterator";

  NextInListIterator( iterator );
  NextInListIterator( iterator );

  if( AddToListIterator( iterator, element ) != iterator )
    return "could not add an element to the ListIterator";

  if( !ListIteratorHasNext( iterator ) )
    return "the ListIterator did not have a next element after insertion";

  if( !ListIteratorHasPrevious( iterator ) )
    return "the ListIterator did not have a previous element after insertion";

  if( PreviousInListIterator( iterator ) != element )
    return "the previous element in the ListIterator was not the inserted element";

  if( ListGet( list, 2 ) != element )
    return "the element was not inserted into the proper location";

  DestroyList( list );
  DestroyListIterator( iterator );

  return NULL;
}

const char *
TestAddWithNullIterator
( void )
{
  void *element = "new element";

  if( AddToListIterator( NULL, NULL ) != NULL )
    return "a non-NULL value was returned when adding a NULL element to a NULL ListIterator";

  if( AddToListIterator( NULL, element ) != NULL )
    return "a non-NULL value was returned when adding a non-NULL element to a NULL ListIterator";

  return NULL;
}

const char *
TestBeginWithEmptyList
( void )
{
  List *list;
  ListIterator *iterator;
  const void *element;

  list = NewList();
  if( !list )
    return "could not build a List";

  iterator = BeginList( list );
  if( !iterator )
    return "a NULL ListIterator was returned for an empty List";

  if( PreviousInListIterator( iterator ) != NULL )
    return "the previous element in the iterator was non-NULL";

  if( NextInListIterator( iterator ) != NULL )
    return "the next element in the iterator was non-NULL";

  DestroyListIterator( iterator );
  DestroyList( list );

  return NULL;
}

const char *
TestBeginWithNullList
( void )
{
  if( BeginList( NULL ) != NULL )
    return "a non-NULL ListIterator was returned for a NULL List";

  return NULL;
}

const char *
TestBeginWithPopulatedList
( void )
{
  List *list;
  ListIterator *iterator;
  const void *element;

  list = BuildList();
  if( !list )
    return "could not build a List";

  iterator = BeginList( list );
  if( !iterator )
    return "a NULL ListIterator was returned for a populated List";

  if( PreviousInListIterator( iterator ) != NULL )
    return "the previous element of the iterator was non-NULL";

  element = NextInListIterator( iterator );
  if( !element )
    return "the next element of the iterator was NULL";
  ASSERT_STRINGS_EQUAL( "This", element, "the next element of the iterator was not the first element of the List" )

  DestroyList( list );
  DestroyListIterator( iterator );

  return NULL;
}

const char *
TestCopy
( void )
{
  List *list;
  ListIterator *copy, *iterator;

  list = BuildList();
  if( !list )
    return "could not build a List"; 

  iterator = BeginList( list );
  if( !iterator )
    return "could not build a ListIterator";

  copy = CopyListIterator( iterator );
  if( copy == NULL )
    return "NULL was returned for a non-NULL ListIterator";

  DestroyList( list );
  DestroyListIterator( copy );
  DestroyListIterator( iterator );

  return NULL;
}

const char *
TestCopyContents
( void )
{
  List *list;
  ListIterator *copy, *iterator;
  const void *element;

  list = BuildList();
  if( !list )
    return "could not build a List";

  iterator = BeginList( list );
  if( !iterator )
    return "could not build a ListIterator";

  copy = CopyListIterator( iterator );
  if( !copy )
    return "could not copy a ListIterator";

  element = NextInListIterator( copy );
  if( !element )
    return "the copied ListIterator did not have a first element";

  if( element != ListFront( list ) )
    return "the first element in the ListIterator was not the first element in the List";

  if( element != NextInListIterator( iterator ) )
    return "the first element in the original did not match the first element of the copy";

  DestroyList( list );
  DestroyListIterator( copy );
  DestroyListIterator( iterator );

  return NULL;
}

const char *
TestCopyDistinct
( void )
{
  List *list;
  ListIterator *copy, *iterator;
  const void *element_1, *element_2, *element_3;

  list = BuildList();
  if( !list )
    return "could not build a List";

  iterator = BeginList( list );
  if( !iterator )
    return "could not build a ListIterator"; 

  copy = CopyListIterator( iterator );
  if( !copy )
    return "could not copy a ListIterator";

  if( copy == iterator )
    return "the copy was the same structure as the original";

  element_1 = NextInListIterator( copy );
  if( !element_1 )
    return "there was no first element";
  element_2 = NextInListIterator( copy );
  if( !element_2 )
    return "there was no second element";
  element_3 = NextInListIterator( copy );
  if( !element_3 )
    return "there was no third element";

  if( NextInListIterator( iterator ) != element_1 )
    return "advancing the pointer of the copy changed the pointer of the original";

  PreviousInListIterator( copy );
  PreviousInListIterator( copy );

  if( PreviousInListIterator( iterator ) != element_1 )
    return "backing up the pointer of the copy changed the pointer of the original";

  DestroyList( list );
  DestroyListIterator( copy );
  DestroyListIterator( iterator );
 
  return NULL;
}

const char *
TestCopyNullIterator
( void )
{
  if( CopyListIterator( NULL ) != NULL )
    return "a non-NULL value was returned when copying NULL";

  return NULL;
}

const char *
TestCopyPosition
( void )
{
  List *list;
  ListIterator *copy, *iterator;

  list = BuildList();
  if( !list )
    return "could not build a List";

  iterator = BeginList( list );
  if( !iterator )
    return "could not build a ListIterator";

  NextInListIterator( iterator );
  NextInListIterator( iterator );

  copy = CopyListIterator( iterator );
  if( !copy )
    return "could not copy a ListIterator";

  if( NextInListIterator( iterator ) != NextInListIterator( copy ) )
    return "the position of the iterator was not the same in the copy as the original";

  DestroyList( list );
  DestroyListIterator( copy );
  DestroyListIterator( iterator );

  return NULL;
}

const char *
TestDestroy
( void )
{
  List *list;
  ListIterator *iterator;

  list = BuildList();
  if( !list )
    return "could not build a List";

  iterator = BeginList( list );
  if( !iterator )
    return "could not build a ListIterator";

  DestroyListIterator( iterator );

  DestroyList( list );

  return NULL;
}

const char *
TestDestroyNullIterator
( void )
{
  DestroyListIterator( NULL );

  return NULL;
}

const char *
TestEndWithEmptyList
( void )
{
  List *list;
  ListIterator *iterator;
  const void *element;

  list = NewList();
  if( !list )
    return "could not build a List";

  iterator = EndList( list );
  if( !iterator )
    return "a NULL ListIterator was returned for an empty List";

  if( PreviousInListIterator( iterator ) != NULL )
    return "the previous element in the iterator was non-NULL";

  if( NextInListIterator( iterator ) != NULL )
    return "the next element in the iterator was non-NULL";

  DestroyList( list );
  DestroyListIterator( iterator );

  return NULL;
}

const char *
TestEndWithNullList
( void )
{
  if( EndList( NULL ) != NULL )
    return "a non-NULL ListIterator was returned for a NULL List";

  return NULL;
}

const char *
TestEndWithPopulatedList
( void )
{
  List *list;
  ListIterator *iterator;
  const void *element;

  list = BuildList();
  if( !list )
    return "could not build a List";

  iterator = EndList( list );
  if( !iterator )
    return "a NULL ListIterator was returned for a populated List";

  if( NextInListIterator( iterator ) != NULL )
    return "the next element of the iterator was non-NULL";

  element = PreviousInListIterator( iterator );
  if( !element )
    return "the previous element of the iterator was NULL";
  ASSERT_STRINGS_EQUAL( "strings!", element, "the previous element of the iterator was not the last element of the List" )

  DestroyList( list );
  DestroyListIterator( iterator );

  return NULL;
}

const char *
TestHasNextAtBeginning
( void )
{
  List *list;
  ListIterator *iterator;

  list = BuildList();
  if( !list )
    return "could not build a List";

  iterator = BeginList( list );
  if( !iterator )
    return "could not build a ListIterator";

  if( !ListIteratorHasNext( iterator ) )
    return "a ListIterator at the beginning of a List returned false";

  DestroyList( list );
  DestroyListIterator( iterator );

  return NULL;
}

const char *
TestHasNextAtEnd
( void )
{
  List *list;
  ListIterator *iterator;

  list = BuildList();
  if( !list )
    return "could not build a List";

  iterator = EndList( list );
  if( !iterator )
    return "could not build a ListIterator";

  if( ListIteratorHasNext( iterator ) )
    return "a ListIterator at the end of a List returned true";

  DestroyList( list );
  DestroyListIterator( iterator );

  return NULL;
}

const char *
TestHasNextAtMiddle
( void )
{
  List *list;
  ListIterator *iterator;

  list = BuildList();
  if( !list )
    return "could not build a List";

  iterator = BeginList( list );
  if( !iterator )
    return "could not build a ListIterator";

  NextInListIterator( iterator );
  NextInListIterator( iterator );
  NextInListIterator( iterator );

  if( !ListIteratorHasNext( iterator ) )
    return "a ListIterator in the middle of a List returned false";

  DestroyList( list );
  DestroyListIterator( iterator );

  return NULL;
}

const char *
TestHasNextWithEmptyList
( void )
{
  List *list;
  ListIterator *iterator;

  list = NewList();
  if( !list )
    return "could not build a List";

  iterator = BeginList( list );
  if( !iterator )
    return "could not build a ListIterator";

  if( ListIteratorHasNext( iterator ) )
    return "an empty List returned true";

  DestroyList( list );
  DestroyListIterator( iterator );

  return NULL;
}

const char *
TestHasNextWithNullIterator
( void )
{
  if( ListIteratorHasNext( NULL ) )
    return "a NULL iterator returned true";

  return NULL;
}

const char *
TestHasPreviousAtBeginning
( void )
{
  List *list;
  ListIterator *iterator;

  list = BuildList();
  if( !list )
    return "could not build a List";

  iterator = BeginList( list );
  if( !iterator )
    return "could not build a ListIterator";

  if( ListIteratorHasPrevious( iterator ) )
    return "a ListIterator at the beginning of a List returned true";

  DestroyList( list );
  DestroyListIterator( iterator );

  return NULL;
}

const char *
TestHasPreviousAtEnd
( void )
{
  List *list;
  ListIterator *iterator;

  list = BuildList();
  if( !list )
    return "could not build a List";

  iterator = EndList( list );
  if( !iterator )
    return "could not build a ListIterator";

  if( !ListIteratorHasPrevious( iterator ) )
    return "a ListIterator at the end of a List returned false";

  DestroyList( list );
  DestroyListIterator( iterator );

  return NULL;
}

const char *
TestHasPreviousAtMiddle
( void )
{
  List *list;
  ListIterator *iterator;

  list = BuildList();
  if( !list )
    return "could not build a List";

  iterator = BeginList( list );
  if( !iterator )
    return "could not build a ListIterator";

  NextInListIterator( iterator );
  NextInListIterator( iterator );
  NextInListIterator( iterator );

  if( !ListIteratorHasPrevious( iterator ) )
    return "a ListIterator in the middle of a List returned false";

  DestroyList( list );
  DestroyListIterator( iterator );

  return NULL;
}

const char *
TestHasPreviousWithEmptyList
( void )
{
  List *list;
  ListIterator *iterator;

  list = NewList();
  if( !list )
    return "could not build a List";

  iterator = BeginList( list );
  if( !iterator )
    return "could not build a ListIterator";

  if( ListIteratorHasPrevious( iterator ) )
    return "an empty List returned true";

  DestroyList( list );
  DestroyListIterator( iterator );

  return NULL;
}

const char *
TestHasPreviousWithNullIterator
( void )
{
  if( ListIteratorHasNext( NULL ) )
    return "a NULL iterator returned true";

  return NULL;
}

const char *
TestNextAtBeginning
( void )
{
  List *list;
  ListIterator *iterator;

  list = BuildList();
  if( !list )
    return "could not build a List";

  iterator = BeginList( list );
  if( !iterator )
    return "could not build a ListIterator";

  if( NextInListIterator( iterator ) != ListFront( list ) )
    return "the first element in the List was not returned by the first call to NextInListIterator";

  DestroyList( list );
  DestroyListIterator( iterator );

  return NULL;
}

const char *
TestNextAtEnd
( void )
{
  List *list;
  ListIterator *iterator;

  list = BuildList();
  if( !list )
    return "could not build a List";

  iterator = EndList( list );
  if( !iterator )
    return "could not build a ListIterator";

  if( NextInListIterator( iterator ) )
    return "a non-NULL value was returned by a ListIterator at the end of a List";

  DestroyList( list );
  DestroyListIterator( iterator );

  return NULL;
}

const char *
TestNextAtMiddle
( void )
{
  List *list;
  ListIterator *iterator;
  const void *element;

  list = BuildList();
  if( !list )
    return "could not build a List";

  iterator = BeginList( list );
  if( !iterator )
    return "could not build a ListIterator";

  element = NextInListIterator( iterator );
  if( !element )
    return "the List did not have a first element";
  ASSERT_STRINGS_EQUAL( "This", element, "the first element was not returned by the first call" )

  element = NextInListIterator( iterator );
  if( !element )
    return "the List did not have a second element";
  ASSERT_STRINGS_EQUAL( "is", element, "the second element was not returned by the second call" )

  element = NextInListIterator( iterator );
  if( !element )
    return "the List did not have a third element";
  ASSERT_STRINGS_EQUAL( "a", element, "the third element was not returned by the third call" )

  element = NextInListIterator( iterator );
  if( !element )
    return "the List did not have a fourth element";
  ASSERT_STRINGS_EQUAL( "test", element, "the fourth element was not returned by the fourth call" )

  element = NextInListIterator( iterator );
  if( !element )
    return "the List did not have a fifth element";
  ASSERT_STRINGS_EQUAL( "List", element, "the fifth element was not returned by the fifth call" )

  element = NextInListIterator( iterator );
  if( !element )
    return "the List did not have a sixth element";
  ASSERT_STRINGS_EQUAL( "o'", element, "the sixth element was not returned by the sixth call" )

  element = NextInListIterator( iterator );
  if( !element )
    return "the List did not have a seventh element";
  ASSERT_STRINGS_EQUAL( "strings!", element, "the seventh element was not returned by the seventh call" )

  DestroyList( list );
  DestroyListIterator( iterator );

  return NULL;
}

const char *
TestNextWithEmptyList
( void )
{
  List *list;
  ListIterator *iterator;

  list = NewList();
  if( !list )
    return "could not build a List";

  iterator = BeginList( list );
  if( !iterator )
    return "could not build a ListIterator";

  if( NextInListIterator( iterator ) )
    return "an empty List returned a non-NULL value";

  DestroyList( list );
  DestroyListIterator( iterator );

  return NULL;
}

const char *
TestNextWithNullIterator
( void )
{
  if( NextInListIterator( NULL ) != NULL )
    return "calling the function with a NULL ListIterator returned a non-NULL value";

  return NULL;
}

const char *
TestPreviousAtBeginning
( void )
{
  List *list;
  ListIterator *iterator;

  list = BuildList();
  if( !list )
    return "could not build a List";

  iterator = BeginList( list );
  if( !iterator )
    return "could not build a ListIterator";

  if( PreviousInListIterator( iterator ) != NULL )
    return "a non-NULL value was returned by the first call to PreviousInListIterator";

  DestroyList( list );
  DestroyListIterator( iterator );

  return NULL;
}

const char *
TestPreviousAtEnd
( void )
{
  List *list;
  ListIterator *iterator;

  list = BuildList();
  if( !list )
    return "could not build a List";

  iterator = EndList( list );
  if( !iterator )
    return "could not build a ListIterator";

  if( PreviousInListIterator( iterator ) != ListBack( list ) )
    return "the last element was not returned by a ListIterator at the end of a List";

  DestroyList( list );
  DestroyListIterator( iterator );

  return NULL;
}

const char *
TestPreviousAtMiddle
( void )
{
  List *list;
  ListIterator *iterator;
  const void *element;

  list = BuildList();
  if( !list )
    return "could not build a List";

  iterator = EndList( list );
  if( !iterator )
    return "could not build a ListIterator";

  element = PreviousInListIterator( iterator );
  if( !element )
    return "the List did not have a last element";
  ASSERT_STRINGS_EQUAL( "strings!", element, "the last element was not returned by the first call" )

  element = PreviousInListIterator( iterator );
  if( !element )
    return "the List did not have a second to last element";
  ASSERT_STRINGS_EQUAL( "o'", element, "the second to last element was not returned by the second call" )

  element = PreviousInListIterator( iterator );
  if( !element )
    return "the List did not have a third to last element";
  ASSERT_STRINGS_EQUAL( "List", element, "the third to last element was not returned by the third call" )

  element = PreviousInListIterator( iterator );
  if( !element )
    return "the List did not have a fourth to last element";
  ASSERT_STRINGS_EQUAL( "test", element, "the fourth to last element was not returned by the fourth call" )

  element = PreviousInListIterator( iterator );
  if( !element )
    return "the List did not have a fifth to last element";
  ASSERT_STRINGS_EQUAL( "a", element, "the fifth to last element was not returned by the fifth call" )

  element = PreviousInListIterator( iterator );
  if( !element )
    return "the List did not have a sixth to last element";
  ASSERT_STRINGS_EQUAL( "is", element, "the sixth to last element was not returned by the sixth call" )

  element = PreviousInListIterator( iterator );
  if( !element )
    return "the List did not have a seventh to last element";
  ASSERT_STRINGS_EQUAL( "This", element, "the seventh to last element was not returned by the seventh call" )

  DestroyList( list );
  DestroyListIterator( iterator );

  return NULL;
}

const char *
TestPreviousWithEmptyList
( void )
{
  List *list;
  ListIterator *iterator;

  list = NewList();
  if( !list )
    return "could not build a List";

  iterator = BeginList( list );
  if( !iterator )
    return "could not build a ListIterator";

  if( PreviousInListIterator( iterator ) )
    return "an empty List returned a non-NULL value";

  DestroyList( list );
  DestroyListIterator( iterator );

  return NULL;
}

const char *
TestPreviousWithNullIterator
( void )
{
  if( PreviousInListIterator( NULL ) != NULL )
    return "calling the function with a NULL ListIterator returned a non-NULL value";

  return NULL;
}

const char *
TestRemoveAfterNext
( void )
{
  List *list;
  ListIterator *iterator;
  const void *element;

  list = BuildList();
  if( !list )
    return "could not build a List";

  iterator = BeginList( list );
  if( !iterator )
    return "could not build a ListIterator";

  NextInListIterator( iterator );
  element = NextInListIterator( iterator );

  if( RemoveFromListIterator( iterator ) != element )
    return "the last element returned by NextInListIterator was not returned";

  if( ListGet( list, 1 ) == element )
    return "the element was not removed from the List";

  element = ListFront( list );
  if( !element )
    return "after removal the List did not have a front element";
  ASSERT_STRINGS_EQUAL( "This", element, "the first element of the List changed" )

  element = ListGet( list, 1 );
  if( !element )
    return "after removal the list did not have a second element";
  ASSERT_STRINGS_EQUAL( "a", element, "the second element of the List was not the previous third" )

  if( NextInListIterator( iterator ) != element )
    return "the position of the ListIterator changed after a call to RemoveFromListIterator";

  DestroyList( list );
  DestroyListIterator( iterator );

  return NULL;
}

const char *
TestRemoveAfterNextAndAdd
( void )
{
  List *list;
  ListIterator *iterator;
  void *added = "new element", *first;

  list = BuildList();
  if( !list )
    return "could not build a List";

  iterator = BeginList( list );
  if( !iterator )
    return "could not build a ListIterator";

  first = NextInListIterator( iterator );
  AddToListIterator( iterator, added );

  if( RemoveFromListIterator( iterator ) != NULL )
    return "a non-NULL value was returned by a call to RemoveFromListIterator after a call to AddToListIterator";

  if( ListFront( list ) != first )
    return "the first element was removed from the List";

  if( ListGet( list, 1 ) != added )
    return "the newly added element was removed from the List";

  if( NextInListIterator( iterator ) != ListGet( list,  2 ) )
    return "the position of the ListIterator was changed by the call to RemoveFromListIterator";

  DestroyList( list );
  DestroyListIterator( iterator );

  return NULL;
}

const char *
TestRemoveAfterPrevious
( void )
{
  List *list;
  ListIterator *iterator;
  const void *element;

  list = BuildList();
  if( !list )
    return "could not build a List";

  iterator = EndList( list );
  if( !iterator )
    return "could not build a ListIterator";

  PreviousInListIterator( iterator );
  element = PreviousInListIterator( iterator );

  if( RemoveFromListIterator( iterator ) != element )
    return "the last element returned by PreviousInListIterator was not returned";

  if( ListGet( list, -2 ) == element )
    return "the element was not removed from the List";

  element = ListBack( list );
  if( !element )
    return "after removal the List did not have a back element";
  ASSERT_STRINGS_EQUAL( "strings!", element, "the last element of the List changed" )

  element = ListGet( list, -2 );
  if( !element )
    return "after removal the list did not have a second element";
  ASSERT_STRINGS_EQUAL( "List", element, "the second to last element of the List was not the previous third to last" )

  if( PreviousInListIterator( iterator ) != element )
    return "the position of the ListIterator changed after a call to RemoveFromListIterator";

  DestroyList( list );
  DestroyListIterator( iterator );

  return NULL;
}

const char *
TestRemoveAfterPreviousAndAdd
( void )
{
  List *list;
  ListIterator *iterator;
  void *added = "new element", *last;

  list = BuildList();
  if( !list )
    return "could not build a List";

  iterator = EndList( list );
  if( !iterator )
    return "could not build a ListIterator";

  last = PreviousInListIterator( iterator );
  AddToListIterator( iterator, added );

  if( RemoveFromListIterator( iterator ) != NULL )
    return "a non-NULL value was returned by a call to RemoveFromListIterator after a call to AddToListIterator";

  if( ListBack( list ) != last )
    return "the last element was removed from the List";

  if( ListGet( list, -2 ) != added )
    return "the newly added element was removed from the List";

  if( PreviousInListIterator( iterator ) != added )
    return "the position of the ListIterator was changed by the call to RemoveFromListIterator";

  DestroyList( list );
  DestroyListIterator( iterator );

  return NULL;
}

const char *
TestRemoveAfterRemove
( void )
{
  List *list;
  ListIterator *iterator;
  const void *element, *removed;

  list = BuildList();
  if( !list )
    return "could not build a List";

  iterator = BeginList( list );
  if( !iterator )
    return "could not build a ListIterator";

  element = NextInListIterator( iterator );
  NextInListIterator( iterator );

  removed = RemoveFromListIterator( iterator );

  if( RemoveFromListIterator( iterator ) != NULL )
    return "a second successive call to RemoveFromListIterator returned a non-NULL value";

  if( ListContains( list, removed ) )
    return "the removed element was no longer removed from the List";
 
  if( ListFront( list ) != element )
    return "the front element of the List changed after the second call to RemoveFromListIterator";

  if( NextInListIterator( iterator ) != ListGet( list, 1 ) )
    return "the position of the ListIterator was changed after the second call to RemoveFromListIterator";

  DestroyList( list );
  DestroyListIterator( iterator );

  return NULL;
}

const char *
TestRemoveBeforeNextOrPrevious
( void )
{
  List *list;
  ListIterator *iterator;

  list = BuildList();
  if( !list )
    return "could not build a List";

  iterator = BeginList( list );
  if( !iterator )
    return "could not build a ListIterator";

  if( RemoveFromListIterator( iterator ) != NULL )
    return "a non-NULL value was returned from a premature call to RemoveFromListIterator";

  if( NextInListIterator( iterator ) != ListFront( list ) )
    return "the position of the ListIterator was changed after a premature call to RemoveFromListIterator";

  DestroyList( list );
  DestroyListIterator( iterator );

  return NULL;
}

const char *
TestRemoveFromNullIterator
( void )
{
  if( RemoveFromListIterator( NULL ) != NULL )
    return "a non-NULL value was returned for a NULL ListIterator";

  return NULL;
}
