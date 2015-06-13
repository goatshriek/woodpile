#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <woodpile/dynamic/list.h>

#include "lib/str.h"
#include "test/function/dynamic/list_suite.h"
#include "test/helper.h"

int
main( void )
{
  unsigned failure_count = 0;
  const char *result;

  TEST( AppendAllOfEmptyList )
  TEST( AppendAllOfNullList )
  TEST( AppendAllOfPopulatedList )
  TEST( AppendAllToNullList )
  TEST( AppendNullElement )
  TEST( AppendToEmptyList )
  TEST( AppendToNullList )
  TEST( AppendToPopulatedList )
  TEST( BackOfEmptyList )
  TEST( BackOfNullList )
  TEST( BackOfPopulatedList )
  TEST( ContainsDuplicateElements )
  TEST( ContainsNonExistentElement )
  TEST( ContainsNullElement )
  TEST( ContainsUniqueElement )
  TEST( ContainsWithNullList )
  TEST( Copy )
  TEST( CopyContents )
  TEST( CopyDistinct )
  TEST( CopyNullList )
  TEST( CopySize )
  TEST( DestroyNullList )
  TEST( DestroyPopulatedList )
  TEST( FrontOfEmptyList )
  TEST( FrontOfNullList )
  TEST( FrontOfPopulatedList )
  TEST( GetFromEmptyList )
  TEST( GetFromNullList )
  TEST( GetNegativeIndex )
  TEST( GetNegativeIndexWrap )
  TEST( GetPositiveIndex )
  TEST( GetPositiveIndexWrap )
  TEST( GetZeroIndex )
  TEST( New )
  TEST( NewListIsEmpty )
  TEST( NullListIsEmpty )
  TEST( PopulatedListIsNotEmpty )
  TEST( PrependNullElement )
  TEST( PrependToEmptyList )
  TEST( PrependToNullList )
  TEST( PrependToPopulatedList )
  TEST( SizeOfEmptyList )
  TEST( SizeOfNullList )
  TEST( SizeOfPopulatedList )
  TEST( ToStringWithEmptyList )
  TEST( ToStringWithNullFunction )
  TEST( ToStringWithNullList )
  TEST( ToStringWithPopulatedList )

  if( failure_count > 0 )
    return EXIT_FAILURE;
  else
    return EXIT_SUCCESS;
}

const char *
TestAppendAllOfEmptyList
( void )
{
  const DList *addition;
  DList *target;

  target = BuildDList();
  if( !target )
    return "could not build a populated List";

  addition = DListNew();
  if( !addition )
    return "could build an empty List";

  if( DListAppendAll( target, addition ) != target )
    return "could not append an empty List to a populated List";

  DListDestroy( addition );
  DListDestroy( target );

  return NULL;
}

const char *
TestAppendAllOfNullList
( void )
{
  DList *list;

  list = BuildDList();
  if( !list )
    return "could not build a List";

  if( DListAppendAll( list, NULL ) != list )
    return "could not append a NULL List to a populated List";

  DListDestroy( list );

  return NULL;
}

const char *
TestAppendAllOfPopulatedList
( void )
{
  const DList *addition;
  DList *target;
  size_t addition_size, i, target_size;

  addition = BuildDList();
  if( !addition )
    return "could not build a List";

  target = BuildDList();
  if( !target )
    return "could not build a List twice";

  addition_size = DListSize( addition );
  target_size = DListSize( target );

  if( DListAppendAll( target, addition ) != target )
    return "the target list was not returned from the append action";

  for( i = 0; i < addition_size; i++ ){
    if( DListGet( target, target_size + i ) != DListGet( addition, i ) )
      return "the List items were not appended in their original order";
  }

  DListDestroy( addition );
  DListDestroy( target );

  return NULL;
}

const char *
TestAppendAllToNullList
( void )
{
  const DList *list;

  if( DListAppendAll( NULL, NULL ) )
    return "a non-NULL value was returned when appending NULL to a NULL List";

  list = BuildDList();
  if( !list )
    return "could not build a List";

  if( DListAppendAll( NULL, list ) )
    return "a non-NULL value was returned when appending to a NULL List";

  DListDestroy( list );

  return NULL;
}

const char *
TestAppendNullElement
( void )
{
  DList *list;

  if( DListAppend( NULL, NULL ) != NULL )
    return "a non-NULL value was returned when appending NULL to a NULL List";

  list = BuildDList();
  if( !list )
    return "could not build a List";

  if( DListAppend( list, NULL ) != list )
    return "could not append NULL to a populated List";

  DListDestroy( list );

  return NULL;
}

const char *
TestAppendToEmptyList
( void )
{
  DList *list;
  void *element = "test value";

  list = DListNew();
  if( !list )
    return "could not build a List";

  if( DListAppend( list, element ) != list )
    return "could not append to an empty List";

  if( DListFront( list ) != element )
    return "the element was not appended to the front of the list";

  if( DListSize( list ) != 1 )
    return "appending to an empty List did not result in a size of 1";

  DListDestroy( list );

  return NULL;
}

const char *
TestAppendToNullList
( void )
{
  void *element = "test element";

  if( DListAppend( NULL, NULL ) != NULL )
    return "a non-NULL value was returned when appending NULL to a NULL List";

  if( DListAppend( NULL, element ) != NULL )
    return "a non-NULL value was returned when appending to a NULL List";

  return NULL;
}

const char *
TestAppendToPopulatedList
( void )
{
  DList *list;
  unsigned size;
  void *element = "test element to append";

  list = BuildDList();
  if( !list )
    return "could not build a List";

  size = DListSize( list );

  if( DListAppend( list, element ) != list )
    return "could not append to a populated List";

  if( DListBack( list ) != element )
    return "the appended element was not at the end of the List";

  if( DListSize( list ) != ( size + 1 ) )
    return "the List size did not increase by one after appending";

  DListDestroy( list );

  return NULL;
}

const char *
TestBackOfEmptyList
( void )
{
  const DList *list;

  list = DListNew();
  if( !list )
    return "could not build a List";

  if( DListBack( list ) != NULL )
    return "a non-NULL value was returned for an empty List";

  DListDestroy( list );

  return NULL;
}

const char *
TestBackOfNullList
( void )
{
  if( DListBack( NULL ) != NULL )
    return "a non-NULL value was returned for a NULL List";

  return NULL;
}

const char *
TestBackOfPopulatedList
( void )
{
  const DList *list;
  unsigned size;

  list = BuildDList();
  if( !list )
    return "could not build a List";

  size = DListSize( list );

  if( DListBack( list ) != DListGet( list, size - 1 ) )
    return "the last element in the List was not returned";

  DListDestroy( list );

  return NULL;
}

const char *
TestContainsDuplicateElements
( void )
{
  DList *list;
  void *element;

  list = BuildDList();
  if( !list )
    return "could not build a List";

  element = DListFront( list );
  if( !element )
    return "the List did not have any elements";

  DListAppend( list, element );

  if( DListContains( list, element ) != 2 )
    return "2 was not returned with an element existing in the List twice";

  DListAppend( list, element );

  if( DListContains( list, element ) != 3 )
    return "3 was not returned with an element existing in the List three times";

  DListDestroy( list );

  return NULL;
}

const char *
TestContainsNonExistentElement
( void )
{
  const DList *list;
  const void *element = "this element does not exist in the List";

  list = BuildDList();
  if( !list )
    return "could not build a List";

  if( DListContains( list, element ) != 0 )
    return "a non-zero value was returned for a value not existing in the provided List";

  DListDestroy( list );

  return NULL;
}

const char *
TestContainsNullElement
( void )
{
  const DList *list;

  if( DListContains( NULL, NULL ) != 0 )
    return "a NULL element and List did not return 0";

  list = BuildDList();
  if( !list )
    return "could not build a List";

  if( DListContains( list, NULL ) != 0 )
    return "a NULL element and non-NULL List did not return 0";

  DListDestroy( list );

  return NULL;
}

const char *
TestContainsUniqueElement
( void )
{
  DList *list;
  void *element = "the List will not contain this";

  list = BuildDList();
  if( !list )
    return "could not build a List";

  DListAppend( list, element );

  if( DListContains( list, element ) != 1 )
    return "1 was not returned for an element contained exactly once in the List";

  DListDestroy( list );

  return NULL;
}

const char *
TestContainsWithNullList
( void )
{
  const void *element = "test element";

  if( DListContains( NULL, NULL ) )
    return "a NULL List and element did not return 0";

  if( DListContains( NULL, element ) )
    return "a NULL List and non-NULL element did not return 0";

  return NULL;
}

const char *
TestCopy
( void )
{
  DList *copy, *list;

  list = BuildDList();
  if( !list )
    return "could not build a List";

  copy = DListCopy( list );

  if( !copy )
    return "NULL was returned for a non-NULL List";

  DListDestroy( copy );
  DListDestroy( list );

  return NULL;
}

const char *
TestCopyContents
( void )
{
  DList *copy, *list;
  unsigned i, size;

  list = BuildDList();
  if( !list )
    return "could not build a List";

  copy = DListCopy( list );
  if( !copy )
    return "the copy of the List was NULL";

  size = DListSize( list );

  for( i = 0; i < size; i++ ){
    if( DListGet( list, i ) != DListGet( copy, i ) )
      return "the List items were not the same in the copy";
  }

  DListDestroy( copy );
  DListDestroy( list );

  return NULL;
}

const char *
TestCopyDistinct
( void )
{
  const DList *copy, *list;

  list = BuildDList();
  if( !list )
    return "could not build a List";

  copy = DListCopy( list );

  if( copy == list )
    return "the copy List was the same structure as the original List";

  DListDestroy( copy );
  DListDestroy( list );

  return NULL;
}

const char *
TestCopyNullList
( void )
{
  if( DListCopy( NULL ) != NULL )
    return "NULL was not returned when copying a NULL List";

  return NULL;
}

const char *
TestCopySize
( void )
{
  const DList *copy, *list;

  list = BuildDList();
  if( !list )
    return "could not build a List";

  copy = DListCopy( list );

  if( DListSize( list ) != DListSize( copy ) )
    return "the copy was not the same size as the original";

  DListDestroy( copy );
  DListDestroy( list );

  return NULL;
}

const char *
TestDestroyNullList
( void )
{
  DListDestroy( NULL );

  return NULL;
}

const char *
TestDestroyPopulatedList
( void )
{
  const DList *list;

  list = BuildDList();
  if( !list )
    return "could not build a List";

  DListDestroy( list );

  return NULL;
}

const char *
TestFrontOfEmptyList
( void )
{
  const DList *list;

  list = DListNew();
  if( !list )
    return "could not build a List";

  if( DListFront( list ) != NULL )
    return "a non-NULL value was returned for an empty List";

  DListDestroy( list );

  return NULL;
}

const char *
TestFrontOfNullList
( void )
{
  if( DListFront( NULL ) != NULL )
    return "a non-NULL value was returned for a NULL List";

  return NULL;
}

const char *
TestFrontOfPopulatedList
( void )
{
  const DList *list;

  list = BuildDList();
  if( !list )
    return "could not build a List";

  if( DListFront( list ) != DListGet( list, 0 ) )
    return "the first element in the List was not returned";

  DListDestroy( list );

  return NULL;
}

const char *
TestGetFromEmptyList
( void )
{
  const DList *list;

  list = DListNew();
  if( !list )
    return "could not build a List";

  if( DListGet( list, -1 ) != NULL )
    return "a non-NULL element was returned for an empty List and negative index";

  if( DListGet( list, 0 ) != NULL )
    return "a non-NULL element was returned for an empty List and index of 0";

  if( DListGet( list, 1 ) != NULL )
    return "a non-NULL element was returned for an empty List and positive index";

  DListDestroy( list );

  return NULL;
}

const char *
TestGetFromNullList
( void )
{
  if( DListGet( NULL, -1 ) != NULL )
    return "a non-NULL element was returned for a NULL List and negative index";

  if( DListGet( NULL, 0 ) != NULL )
    return "a non-NULL element was returned for a NULL List and index of 0";

  if( DListGet( NULL, 1 ) != NULL )
    return "a non-NULL element was returned for a NULL List and positive index";

  return NULL;
}

const char *
TestGetNegativeIndex
( void )
{
  const DList *list;
  const void *element;

  list = BuildDList();
  if( !list )
    return "could not build a List";

  element = DListGet( list, -1 );
  if( !element )
    return "the List did not have a last element";
  if( element != DListBack( list ) )
    return "the last element was not returned with an index of -1";

  element = DListGet( list, -2 );
  if( !element )
    return "the List did not have a second to last element";
  ASSERT_STRINGS_EQUAL( "o'", element, "the second to last element was not returned with an index of -2" )

  element = DListGet( list, -3 );
  if( !element )
    return "the List did not have a third to last element";
  ASSERT_STRINGS_EQUAL( "List", element, "the third to last element was not returned with an index of -3" )

  element = DListGet( list, -4 );
  if( !element )
    return "the List did not have a fourth to last element";
  ASSERT_STRINGS_EQUAL( "test", element, "the fourth to last element was not returned with an index of -4" )

  element = DListGet( list, -5 );
  if( !element )
    return "the List did not have a fifth to last element";
  ASSERT_STRINGS_EQUAL( "a", element, "the fifth to last element was not returned with an index of -5" )

  element = DListGet( list, -6 );
  if( !element )
    return "the List did not have a sixth to last element";
  ASSERT_STRINGS_EQUAL( "is", element, "the sixth to last element was not returned with an index of -6" )

  element = DListGet( list, -7 );
  if( !element )
    return "the List did not have a seventh to last element";
  ASSERT_STRINGS_EQUAL( "This", element, "the seventh to last element was not returned with an index of -7" )

  DListDestroy( list );

  return NULL;
}

const char *
TestGetNegativeIndexWrap
( void )
{
  const DList *list;
  unsigned size;

  list = BuildDList();
  if( !list )
    return "could not build a List";

  size = DListSize( list );

  if( DListGet( list, -( (int) size + 2 ) ) != DListGet( list, -2 ) )
    return "a negative index did not correctly wrap around the List";

  DListDestroy( list );

  return NULL;
}

const char *
TestGetPositiveIndex
( void )
{
  const DList *list;
  const void *element;

  list = BuildDList();
  if( !list )
    return "could not build a List";

  element = DListGet( list, 1 );
  if( !element )
    return "the List did not have a second element";
  ASSERT_STRINGS_EQUAL( "is", element, "the second element was not returned with an index of 1" )

  element = DListGet( list, 2 );
  if( !element )
    return "the List did not have a third element";
  ASSERT_STRINGS_EQUAL( "a", element, "the third element was not returned with an index of 2" )

  element = DListGet( list, 3 );
  if( !element )
    return "the List did not have a fourth element";
  ASSERT_STRINGS_EQUAL( "test", element, "the fourth element was not returned with an index of 3" )

  element = DListGet( list, 4 );
  if( !element )
    return "the List did not have a fifth element";
  ASSERT_STRINGS_EQUAL( "List", element, "the fifth element was not returned with an index of 4" )

  element = DListGet( list, 5 );
  if( !element )
    return "the List did not have a sixth element";
  ASSERT_STRINGS_EQUAL( "o'", element, "the sixth element was not returned with an index of 5" )

  element = DListGet( list, 6 );
  if( !element )
    return "the List did not have a seventh element";
  ASSERT_STRINGS_EQUAL( "strings!", element, "the seventh element was not returned with an index of 6" )

  DListDestroy( list );

  return NULL;
}

const char *
TestGetPositiveIndexWrap
( void )
{
  const DList *list;
  unsigned size;

  list = BuildDList();
  if( !list )
    return "could not build a List";

  size = DListSize( list );

  if( DListGet( list, size + 2 ) != DListGet( list, 2 ) )
    return "a positive index did not correctly wrap around the List";

  DListDestroy( list );

  return NULL;
}

const char *
TestGetZeroIndex
( void )
{
  const DList *list;

  list = BuildDList();
  if( !list )
    return "could not build a List";

  if( DListGet( list, 0 ) != DListFront( list ) )
    return "the front element of the List was not returned with an index of 0";

  DListDestroy( list );

  return NULL;
}

const char *
TestNew
( void )
{
  const DList *list;

  list = DListNew();
  if( !list )
    return "a new List could not be constructed";

  DListDestroy( list );

  return NULL;
}

const char *
TestNewListIsEmpty
( void )
{
  const DList *list;

  list = DListNew();
  if( !list )
    return "could not build a List";

  if( !DListIsEmpty( list ) )
    return "a newly constructed List was not empty";

  DListDestroy( list );

  return NULL;
}

const char *
TestNullListIsEmpty
( void )
{
  if( !DListIsEmpty( NULL ) )
    return "a NULL List was not empty";

  return NULL;
}

const char *
TestPopulatedListIsNotEmpty
( void )
{
  const DList *list;

  list = BuildDList();
  if( !list )
    return "could not build a List";

  if( DListIsEmpty( list ) )
    return "a populated List was empty";

  DListDestroy( list );

  return NULL;
}

const char *
TestPrependNullElement
( void )
{
  DList *list;

  if( DListPrepend( NULL, NULL ) != NULL )
    return "a non-NULL value was returned when prepending NULL to a NULL List";

  list = BuildDList();
  if( !list )
    return "could not build a List";

  if( DListPrepend( list, NULL ) != list )
    return "could not prepend NULL to a populated List";

  DListDestroy( list );

  return NULL;
}

const char *
TestPrependToEmptyList
( void )
{
  DList *list;
  void *element = "test value";

  list = DListNew();
  if( !list )
    return "could not build a List";

  if( DListPrepend( list, element ) != list )
    return "could not append to an empty List";

  if( DListBack( list ) != element )
    return "the element was not prepended to the back of the list";

  if( DListSize( list ) != 1 )
    return "prepending to an empty List did not result in a size of 1";

  DListDestroy( list );

  return NULL;
}

const char *
TestPrependToNullList
( void )
{
  void *element = "test element";

  if( DListPrepend( NULL, NULL ) != NULL )
    return "a non-NULL value was returned when prepending NULL to a NULL List";

  if( DListPrepend( NULL, element ) != NULL )
    return "a non-NULL value was returned when prepending to a NULL List";

  return NULL;
}

const char *
TestPrependToPopulatedList
( void )
{
  DList *list;
  unsigned size;
  void *element = "test element to prepend";

  list = BuildDList();
  if( !list )
    return "could not build a List";

  size = DListSize( list );

  if( DListPrepend( list, element ) != list )
    return "could not prepend to a populated List";

  if( DListFront( list ) != element )
    return "the prepended element was not at the front of the List";

  if( DListSize( list ) != ( size + 1 ) )
    return "the List size did not increase by one after prepending";

  DListDestroy( list );

  return NULL;
}

const char *
TestSizeOfEmptyList
( void )
{
  const DList *list;

  list = DListNew();
  if( !list )
    return "could not build a List";

  if( DListSize( list ) != 0 )
    return "an empty List did not have a size of 0";

  DListDestroy( list );

  return NULL;
}

const char *
TestSizeOfNullList
( void )
{
  if( DListSize( NULL ) != 0 )
    return "a NULL List did not have a size of 0";

  return NULL;
}

const char *
TestSizeOfPopulatedList
( void )
{
  const DList *list;

  list = BuildDList();
  if( !list )
    return "could not build a List";

  if( DListSize( list ) != 7 )
    return "the correct size was not returned for a populated List";

  DListDestroy( list );

  return NULL;
}

const char *
TestToStringWithEmptyList
( void )
{
  const char *str;
  const DList *list;

  list = DListNew();
  if( !list )
    return "could not build a List";

  str = DListToString( list, NULL );
  if( !str )
    return "NULL was returned for an empty List";
  ASSERT_STRINGS_EQUAL( "[]", str, "an empty List did not return an empty pair of square brackets" )

  DListDestroy( list );

  return NULL;
}

const char *
TestToStringWithNullFunction
( void )
{
  char pointer[100];
  char *str;
  const DList *list;
  unsigned i, size;

  list = BuildDList();
  if( !list )
    return "could not build a List";

  str = DListToString( list, NULL );
  if( !str )
    return "NULL was returned for a populated List";

  size = DListSize( list );
  for( i = 0; i < size; i++ ){
    strprint( pointer, 100, "%p", DListGet( list, i ) );
    if( !strstr( str, pointer ) )
      return "the string did not contain the pointer address of one of the elements";
  }

  free( str );
  DListDestroy( list );

  return NULL;
}

const char *
TestToStringWithNullList
( void )
{
  if( DListToString( NULL, NULL ) != NULL )
    return "a non-NULL value was returned for a NULL List and function";

  if( DListToString( NULL, ElementToString ) != NULL )
    return "a non-NULL value was returned for a NULL List and non-NULL function";

  return NULL;
}

const char *
TestToStringWithPopulatedList
( void )
{
  char *str;
  const DList *list;

  list = BuildDList();
  if( !list )
    return "could not build a List";

  str = DListToString( list, ElementToString );
  if( !str )
    return "could not create a string for a populated List";

  ASSERT_STRINGS_EQUAL( "[This, is, a, test, List, o', strings!]", str, "the string for a populated List was not correct" )

  free( str );
  DListDestroy( list );

  return NULL;
}
