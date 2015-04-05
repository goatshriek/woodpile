#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <woodpile/list.h>

#include "test/function/list_suite.h"
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
  const List *addition;
  List *target;

  target = BuildList();
  if( !target )
    return "could not build a populated List";

  addition = NewList();
  if( !addition )
    return "could build an empty List";

  if( AppendAllToList( target, addition ) != target )
    return "could not append an empty List to a populated List";

  DestroyList( addition );
  DestroyList( target );

  return NULL;
}

const char *
TestAppendAllOfNullList
( void )
{
  List *list;

  list = BuildList();
  if( !list )
    return "could not build a List";

  if( AppendAllToList( list, NULL ) != list )
    return "could not append a NULL List to a populated List";

  DestroyList( list );

  return NULL;
}

const char *
TestAppendAllOfPopulatedList
( void )
{
  const List *addition;
  List *target;
  size_t addition_size, i, target_size;

  addition = BuildList();
  if( !addition )
    return "could not build a List";

  target = BuildList();
  if( !target )
    return "could not build a List twice";

  addition_size = ListSize( addition );
  target_size = ListSize( target );

  if( AppendAllToList( target, addition ) != target )
    return "the target list was not returned from the append action";

  for( i = 0; i < addition_size; i++ ){
    if( ListGet( target, target_size + i ) != ListGet( addition, i ) )
      return "the List items were not appended in their original order";
  }

  DestroyList( addition );
  DestroyList( target );

  return NULL;
}

const char *
TestAppendAllToNullList
( void )
{
  const List *list;

  if( AppendAllToList( NULL, NULL ) )
    return "a non-NULL value was returned when appending NULL to a NULL List";

  list = BuildList();
  if( !list )
    return "could not build a List";

  if( AppendAllToList( NULL, list ) )
    return "a non-NULL value was returned when appending to a NULL List";

  DestroyList( list );

  return NULL;
}

const char *
TestAppendNullElement
( void )
{
  List *list;
  
  if( AppendToList( NULL, NULL ) != NULL )
    return "a non-NULL value was returned when appending NULL to a NULL List";

  list = BuildList();
  if( !list )
    return "could not build a List";

  if( AppendToList( list, NULL ) != list )
    return "could not append NULL to a populated List";

  DestroyList( list );

  return NULL;
}

const char *
TestAppendToEmptyList
( void )
{
  List *list;
  void *element = "test value";
  
  list = NewList();
  if( !list )
    return "could not build a List";

  if( AppendToList( list, element ) != list )
    return "could not append to an empty List";

  if( ListFront( list ) != element )
    return "the element was not appended to the front of the list";

  if( ListSize( list ) != 1 )
    return "appending to an empty List did not result in a size of 1";

  DestroyList( list );

  return NULL;
}

const char *
TestAppendToNullList
( void )
{
  void *element = "test element";

  if( AppendToList( NULL, NULL ) != NULL )
    return "a non-NULL value was returned when appending NULL to a NULL List";

  if( AppendToList( NULL, element ) != NULL )
    return "a non-NULL value was returned when appending to a NULL List";

  return NULL;
}

const char *
TestAppendToPopulatedList
( void )
{
  List *list;
  unsigned size;
  void *element = "test element to append";

  list = BuildList();
  if( !list )
    return "could not build a List";

  size = ListSize( list );

  if( AppendToList( list, element ) != list )
    return "could not append to a populated List";

  if( ListBack( list ) != element )
    return "the appended element was not at the end of the List";

  if( ListSize( list ) != ( size + 1 ) )
    return "the List size did not increase by one after appending";

  DestroyList( list );

  return NULL;
}

const char *
TestBackOfEmptyList
( void )
{
  const List *list;

  list = NewList();
  if( !list )
    return "could not build a List";

  if( ListBack( list ) != NULL )
    return "a non-NULL value was returned for an empty List";

  DestroyList( list );

  return NULL;
}

const char *
TestBackOfNullList
( void )
{
  if( ListBack( NULL ) != NULL )
    return "a non-NULL value was returned for a NULL List";

  return NULL;
}

const char *
TestBackOfPopulatedList
( void )
{
  const List *list;
  unsigned size;

  list = BuildList();
  if( !list )
    return "could not build a List";

  size = ListSize( list );

  if( ListBack( list ) != ListGet( list, size - 1 ) )
    return "the last element in the List was not returned";

  DestroyList( list );

  return NULL;
}

const char *
TestContainsDuplicateElements
( void )
{
  List *list;
  void *element;

  list = BuildList();
  if( !list )
    return "could not build a List";

  element = ListFront( list );
  if( !element )
    return "the List did not have any elements";

  AppendToList( list, element );

  if( ListContains( list, element ) != 2 )
    return "2 was not returned with an element existing in the List twice";

  AppendToList( list, element );

  if( ListContains( list, element ) != 3 )
    return "3 was not returned with an element existing in the List three times";

  DestroyList( list );

  return NULL;
}

const char *
TestContainsNonExistentElement
( void )
{
  const List *list;
  const void *element = "this element does not exist in the List";

  list = BuildList();
  if( !list )
    return "could not build a List";

  if( ListContains( list, element ) != 0 )
    return "a non-zero value was returned for a value not existing in the provided List";

  DestroyList( list );

  return NULL;
}

const char *
TestContainsNullElement
( void )
{
  const List *list;

  if( ListContains( NULL, NULL ) != 0 )
    return "a NULL element and List did not return 0";

  list = BuildList();
  if( !list )
    return "could not build a List";

  if( ListContains( list, NULL ) != 0 )
    return "a NULL element and non-NULL List did not return 0";

  DestroyList( list );

  return NULL;
}

const char *
TestContainsUniqueElement
( void )
{
  List *list;
  void *element = "the List will not contain this";

  list = BuildList();
  if( !list )
    return "could not build a List";

  AppendToList( list, element );

  if( ListContains( list, element ) != 1 )
    return "1 was not returned for an element contained exactly once in the List";

  DestroyList( list );

  return NULL;
}

const char *
TestContainsWithNullList
( void )
{
  const void *element = "test element";

  if( ListContains( NULL, NULL ) )
    return "a NULL List and element did not return 0";

  if( ListContains( NULL, element ) )
    return "a NULL List and non-NULL element did not return 0";

  return NULL;
}

const char *
TestCopy
( void )
{
  List *copy, *list;

  list = BuildList();
  if( !list )
    return "could not build a List";

  copy = CopyList( list );

  if( !copy )
    return "NULL was returned for a non-NULL List";

  DestroyList( copy );
  DestroyList( list );

  return NULL;
}

const char *
TestCopyContents
( void )
{
  List *copy, *list;
  const void *copy_element, *list_element;
  unsigned i, size;

  list = BuildList();
  if( !list )
    return "could not build a List";

  copy = CopyList( list );
  if( !copy )
    return "the copy of the List was NULL";

  size = ListSize( list );

  for( i = 0; i < size; i++ ){
    if( ListGet( list, i ) != ListGet( copy, i ) )
      return "the List items were not the same in the copy";
  }

  DestroyList( copy );
  DestroyList( list );

  return NULL;
}

const char *
TestCopyDistinct
( void )
{
  const List *copy, *list;

  list = BuildList();
  if( !list )
    return "could not build a List";

  copy = CopyList( list );

  if( copy == list )
    return "the copy List was the same structure as the original List";

  DestroyList( copy );
  DestroyList( list );

  return NULL;
}

const char *
TestCopyNullList
( void )
{
  if( CopyList( NULL ) != NULL )
    return "NULL was not returned when copying a NULL List";

  return NULL;
}

const char *
TestCopySize
( void )
{
  const List *copy, *list;

  list = BuildList();
  if( !list )
    return "could not build a List";

  copy = CopyList( list );

  if( ListSize( list ) != ListSize( copy ) )
    return "the copy was not the same size as the original";

  DestroyList( copy );
  DestroyList( list );

  return NULL;
}

const char *
TestDestroyNullList
( void )
{
  DestroyList( NULL );
  
  return NULL;
}

const char *
TestDestroyPopulatedList
( void )
{
  const List *list;
  
  list = BuildList();
  if( !list )
    return "could not build a List";

  DestroyList( list );

  return NULL;
}

const char *
TestFrontOfEmptyList
( void )
{
  const List *list;

  list = NewList();
  if( !list )
    return "could not build a List";

  if( ListFront( list ) != NULL )
    return "a non-NULL value was returned for an empty List";

  DestroyList( list );

  return NULL;
}

const char *
TestFrontOfNullList
( void )
{
  if( ListFront( NULL ) != NULL )
    return "a non-NULL value was returned for a NULL List";

  return NULL;
}

const char *
TestFrontOfPopulatedList
( void )
{
  const List *list;

  list = BuildList();
  if( !list )
    return "could not build a List";

  if( ListFront( list ) != ListGet( list, 0 ) )
    return "the first element in the List was not returned";

  DestroyList( list );

  return NULL;
}

const char *
TestGetFromEmptyList
( void )
{
  const List *list;

  list = NewList();
  if( !list )
    return "could not build a List";

  if( ListGet( list, -1 ) != NULL )
    return "a non-NULL element was returned for an empty List and negative index";

  if( ListGet( list, 0 ) != NULL )
    return "a non-NULL element was returned for an empty List and index of 0";

  if( ListGet( list, 1 ) != NULL )
    return "a non-NULL element was returned for an empty List and positive index";

  DestroyList( list );

  return NULL;
}

const char *
TestGetFromNullList
( void )
{
  if( ListGet( NULL, -1 ) != NULL )
    return "a non-NULL element was returned for a NULL List and negative index";

  if( ListGet( NULL, 0 ) != NULL )
    return "a non-NULL element was returned for a NULL List and index of 0";

  if( ListGet( NULL, 1 ) != NULL )
    return "a non-NULL element was returned for a NULL List and positive index";

  return NULL;
}

const char *
TestGetNegativeIndex
( void )
{
  const List *list;
  const void *element;
  
  list = BuildList();
  if( !list )
    return "could not build a List";

  element = ListGet( list, -1 );
  if( !element )
    return "the List did not have a last element";
  if( element != ListBack( list ) )
    return "the last element was not returned with an index of -1";

  element = ListGet( list, -2 );
  if( !element )
    return "the List did not have a second to last element";
  ASSERT_STRINGS_EQUAL( "o'", element, "the second to last element was not returned with an index of -2" )

  element = ListGet( list, -3 );
  if( !element )
    return "the List did not have a third to last element";
  ASSERT_STRINGS_EQUAL( "List", element, "the third to last element was not returned with an index of -3" )

  element = ListGet( list, -4 );
  if( !element )
    return "the List did not have a fourth to last element";
  ASSERT_STRINGS_EQUAL( "test", element, "the fourth to last element was not returned with an index of -4" )

  element = ListGet( list, -5 );
  if( !element )
    return "the List did not have a fifth to last element";
  ASSERT_STRINGS_EQUAL( "a", element, "the fifth to last element was not returned with an index of -5" )

  element = ListGet( list, -6 );
  if( !element )
    return "the List did not have a sixth to last element";
  ASSERT_STRINGS_EQUAL( "is", element, "the sixth to last element was not returned with an index of -6" )

  element = ListGet( list, -7 );
  if( !element )
    return "the List did not have a seventh to last element";
  ASSERT_STRINGS_EQUAL( "This", element, "the seventh to last element was not returned with an index of -7" )

  DestroyList( list );

  return NULL;
}

const char *
TestGetNegativeIndexWrap
( void )
{
  const List *list;
  unsigned size;

  list = BuildList();
  if( !list )
    return "could not build a List";

  size = ListSize( list );

  if( ListGet( list, -( size + 2 ) ) != ListGet( list, -2 ) )
    return "a negative index did not correctly wrap around the List";

  DestroyList( list );

  return NULL;
}

const char *
TestGetPositiveIndex
( void )
{
  const List *list;
  const void *element;
  
  list = BuildList();
  if( !list )
    return "could not build a List";

  element = ListGet( list, 1 );
  if( !element )
    return "the List did not have a second element";
  ASSERT_STRINGS_EQUAL( "is", element, "the second element was not returned with an index of 1" )

  element = ListGet( list, 2 );
  if( !element )
    return "the List did not have a third element";
  ASSERT_STRINGS_EQUAL( "a", element, "the third element was not returned with an index of 2" )

  element = ListGet( list, 3 );
  if( !element )
    return "the List did not have a fourth element";
  ASSERT_STRINGS_EQUAL( "test", element, "the fourth element was not returned with an index of 3" )

  element = ListGet( list, 4 );
  if( !element )
    return "the List did not have a fifth element";
  ASSERT_STRINGS_EQUAL( "List", element, "the fifth element was not returned with an index of 4" )

  element = ListGet( list, 5 );
  if( !element )
    return "the List did not have a sixth element";
  ASSERT_STRINGS_EQUAL( "o'", element, "the sixth element was not returned with an index of 5" )

  element = ListGet( list, 6 );
  if( !element )
    return "the List did not have a seventh element";
  ASSERT_STRINGS_EQUAL( "strings!", element, "the seventh element was not returned with an index of 6" )

  DestroyList( list );

  return NULL;
}

const char *
TestGetPositiveIndexWrap
( void )
{
  const List *list;
  unsigned size;

  list = BuildList();
  if( !list )
    return "could not build a List";

  size = ListSize( list );

  if( ListGet( list, size + 2 ) != ListGet( list, 2 ) )
    return "a positive index did not correctly wrap around the List";

  DestroyList( list );

  return NULL;
}

const char *
TestGetZeroIndex
( void )
{
  const List *list;

  list = BuildList();
  if( !list )
    return "could not build a List";

  if( ListGet( list, 0 ) != ListFront( list ) )
    return "the front element of the List was not returned with an index of 0";

  DestroyList( list );

  return NULL;
}

const char *
TestNew
( void )
{
  const List *list;

  list = NewList();
  if( !list )
    return "a new List could not be constructed";

  DestroyList( list );

  return NULL;
}

const char *
TestNewListIsEmpty
( void )
{
  const List *list;

  list = NewList();
  if( !list )
    return "could not build a List";

  if( !ListIsEmpty( list ) )
    return "a newly constructed List was not empty";

  DestroyList( list );

  return NULL;
}

const char *
TestNullListIsEmpty
( void )
{
  if( !ListIsEmpty( NULL ) )
    return "a NULL List was not empty";

  return NULL;
}

const char *
TestPopulatedListIsNotEmpty
( void )
{
  const List *list;

  list = BuildList();
  if( !list )
    return "could not build a List";

  if( ListIsEmpty( list ) )
    return "a populated List was empty";

  DestroyList( list );

  return NULL;
}

const char *
TestPrependNullElement
( void )
{
  List *list;
  
  if( PrependToList( NULL, NULL ) != NULL )
    return "a non-NULL value was returned when prepending NULL to a NULL List";

  list = BuildList();
  if( !list )
    return "could not build a List";

  if( PrependToList( list, NULL ) != list )
    return "could not prepend NULL to a populated List";

  DestroyList( list );

  return NULL;
}

const char *
TestPrependToEmptyList
( void )
{
  List *list;
  void *element = "test value";
  
  list = NewList();
  if( !list )
    return "could not build a List";

  if( PrependToList( list, element ) != list )
    return "could not append to an empty List";

  if( ListBack( list ) != element )
    return "the element was not prepended to the back of the list";

  if( ListSize( list ) != 1 )
    return "prepending to an empty List did not result in a size of 1";

  DestroyList( list );

  return NULL;
}

const char *
TestPrependToNullList
( void )
{
  void *element = "test element";

  if( PrependToList( NULL, NULL ) != NULL )
    return "a non-NULL value was returned when prepending NULL to a NULL List";

  if( PrependToList( NULL, element ) != NULL )
    return "a non-NULL value was returned when prepending to a NULL List";

  return NULL;
}

const char *
TestPrependToPopulatedList
( void )
{
  List *list;
  unsigned size;
  void *element = "test element to prepend";

  list = BuildList();
  if( !list )
    return "could not build a List";

  size = ListSize( list );

  if( PrependToList( list, element ) != list )
    return "could not prepend to a populated List";

  if( ListFront( list ) != element )
    return "the prepended element was not at the front of the List";

  if( ListSize( list ) != ( size + 1 ) )
    return "the List size did not increase by one after prepending";

  DestroyList( list );

  return NULL;
}

const char *
TestSizeOfEmptyList
( void )
{
  const List *list;

  list = NewList();
  if( !list )
    return "could not build a List";

  if( ListSize( list ) != 0 )
    return "an empty List did not have a size of 0";

  DestroyList( list );

  return NULL;
}

const char *
TestSizeOfNullList
( void )
{
  if( ListSize( NULL ) != 0 )
    return "a NULL List did not have a size of 0";

  return NULL;
}

const char *
TestSizeOfPopulatedList
( void )
{
  const List *list;

  list = BuildList();
  if( !list )
    return "could not build a List";

  if( ListSize( list ) != 7 )
    return "the correct size was not returned for a populated List";

  DestroyList( list );

  return NULL;
}

const char *
TestToStringWithEmptyList
( void )
{
  const char *str;
  const List *list;

  list = NewList();
  if( !list )
    return "could not build a List";

  str = ListToString( list, NULL );
  if( !str )
    return "NULL was returned for an empty List";
  ASSERT_STRINGS_EQUAL( "[]", str, "an empty List did not return an empty pair of square brackets" )

  DestroyList( list );

  return NULL;
}

const char *
TestToStringWithNullFunction
( void )
{
  char pointer[100];
  char *str;
  const List *list;
  unsigned i, size;

  list = BuildList();
  if( !list )
    return "could not build a List";

  str = ListToString( list, NULL );
  if( !str )
    return "NULL was returned for a populated List";

  size = ListSize( list );
  for( i = 0; i < size; i++ ){
    sprintf( pointer, "%p", ListGet( list, i ) );
    if( !strstr( str, pointer ) )
      return "the string did not contain the pointer address of one of the elements";
  }

  free( str );
  DestroyList( list );

  return NULL;
}

const char *
TestToStringWithNullList
( void )
{
  if( ListToString( NULL, NULL ) != NULL )
    return "a non-NULL value was returned for a NULL List and function";

  if( ListToString( NULL, ElementToString ) != NULL )
    return "a non-NULL value was returned for a NULL List and non-NULL function";

  return NULL;
}

const char *
TestToStringWithPopulatedList
( void )
{
  char *str;
  const List *list;

  list = BuildList();
  if( !list )
    return "could not build a List";

  str = ListToString( list, ElementToString );
  if( !str )
    return "could not create a string for a populated List";

  ASSERT_STRINGS_EQUAL( "[This, is, a, test, List, o', strings!]", str, "the string for a populated List was not correct" )

  free( str );
  DestroyList( list );

  return NULL;
}
