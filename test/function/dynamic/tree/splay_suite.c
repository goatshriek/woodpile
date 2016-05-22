#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <woodpile/config.h>
#include <woodpile/dynamic/tree/splay.h>
#include "lib/str.h"
#include "test/function/common_suite.h"
#include "test/function/dynamic/tree/splay_suite.h"
#include "test/helper.h"

int
main( void )
{
  unsigned failure_count = 0;
  const char *result;

  printf( "### Dynamic Splay Tree Functionality Test Suite\n" );

#ifdef __WOODPILE_PARAMETER_VALIDATION
  printf( "\nRunning Parameter Validation Tests\n======\n" );

  TEST( AddToNullDynamicSplay )
  TEST( FirstInNullDynamicSplay )
  TEST( LastInNullDynamicSplay )
  TEST( NewWithNullComparator )
  TEST( RemoveFromNullDynamicSplay )
  TEST( RemoveNullElement )
  TEST( ToStringWithNullDynamicSplay )

#ifdef TEST_FUNCTION_COMMON_SUITE_AVAILABLE
  TEST( CopyNull )
#endif
#endif

#ifdef TEST_FUNCTION_COMMON_SUITE_AVAILABLE
  printf( "\nRunning Common Tests\n======\n" );

  TEST( Copy )
  TEST( CopyDistinct )
  TEST( CopySize )
  TEST( DestroyNull )
  TEST( DestroyPopulated )
  TEST( IsEmptyWithNew )
  TEST( IsEmptyWithNull )
  TEST( IsEmptyWithPopulated )
  TEST( New )
  TEST( SizeWithEmpty )
  TEST( SizeWithNull )
#endif

  printf( "\nRunning Specific Tests\n======\n" );

  TEST( AddDuplicateElement )
  TEST( AddNullElement )
  TEST( AddToEmptyDynamicSplay )
  TEST( AddToPopulatedDynamicSplay )
  TEST( ContainsNonExistentElement )
  TEST( ContainsNullElement )
  TEST( ContainsUniqueElement )
  TEST( ContainsWithNullDynamicSplay )
  TEST( CopyContents )
  TEST( DestroyNullDynamicSplay )
  TEST( DestroyPopulatedDynamicSplay )
  TEST( FirstInEmptyDynamicSplay )
  TEST( FirstInPopulatedDynamicSplay )
  TEST( LastInEmptyDynamicSplay )
  TEST( LastInPopulatedDynamicSplay )
  TEST( NewWithComparator )
  TEST( NewDynamicSplayIsEmpty )
  TEST( NullDynamicSplayIsEmpty )
  TEST( PopulatedDynamicSplayIsNotEmpty )
  TEST( RemoveNonExistentElement )
  TEST( RemoveRootElement )
  TEST( RemoveUniqueElement )
  TEST( SizeOfEmptyDynamicSplay )
  TEST( SizeOfNullDynamicSplay )
  TEST( SizeOfPopulatedDynamicSplay )
  TEST( ToStringWithEmptyDynamicSplay )
  TEST( ToStringWithNullFunction )
  TEST( ToStringWithPopulatedDynamicSplay )

  printf( "\n" );

  if( failure_count > 0 )
    return EXIT_FAILURE;
  else
    return EXIT_SUCCESS;
}

const char *
TestAddDuplicateElement
( void )
{
  dsplay_t *splay;
  size_t size;
  void *element;

  splay = BuildDSplay();
  if( !splay )
    return "could not build a populated splay";

  element = DSplayFirst( splay );
  if( !element )
    return "the splay did not have any elements";

  size = DSplaySize( splay );

  if( DSplayAdd( splay, element ) != splay )
    return "splay was not returned when adding a duplicate element";

  if( DSplaySize( splay ) != size )
    return "the size of the splay changed after adding a duplicate";

  DSplayDestroy( splay );

  return NULL;
}

const char *
TestAddNullElement
( void )
{
  dsplay_t *splay;

  splay = BuildDSplay();
  if( !splay )
    return "could not build a populated splay";

  if( DSplayAdd( splay, NULL ) != splay )
    return "could not append NULL to a populated splay";

  DSplayDestroy( splay );

  return NULL;
}

const char *
TestAddToEmptyDynamicSplay
( void )
{
  dsplay_t *splay;
  void *element = "new element";

  splay = DSplayNewWithComparator( CompareStrings );
  if( !splay )
    return "could not build an empty splay";

  if( DSplayAdd( splay, element ) != splay )
    return "could not add a element to an empty splay";

  if( DSplaySize( splay ) != 1 )
    return "an empty splay did not have a size of 1 after having an element added";

  if( DSplayFirst( splay ) != element )
    return "the first element in the splay was not the only element";

  DSplayDestroy( splay );

  return NULL;
}

const char *
TestAddToNullDynamicSplay
( void )
{
  void *element = "new element";

  if( DSplayAdd( NULL, NULL ) != NULL )
    return "a NULL splay and element did not return NULL";

  if( DSplayAdd( NULL, element ) != NULL )
    return "a NULL splay and non-NULL element did not return NULL";

  return NULL;
}

const char *
TestAddToPopulatedDynamicSplay
( void )
{
  dsplay_t *splay;
  size_t before_size;
  void *element = "new element";

  splay = BuildDSplay();
  if( !splay )
    return "could not build a populated splay";

  before_size = DSplaySize( splay );

  if( DSplayAdd( splay, element ) != splay )
    return "could not add an element to a populated splay";

  if( !DSplayContains( splay, element ) )
    return "the splay did not contain the added element";

  if( before_size != ( DSplaySize( splay ) - 1 ) )
    return "the splay size was not increased by one by an addition";

  DSplayDestroy( splay );

  return NULL;
}

const char *
TestContainsNonExistentElement
( void )
{
  dsplay_t *splay;
  void *element = "i don't exist";

  splay = BuildDSplay();
  if( !splay )
    return "could not build a populated splay";

  if( DSplayContains( splay, element ) )
    return "true was returned for an element not existing in the splay";

  DSplayDestroy( splay );

  return NULL;
}

const char *
TestContainsNullElement
( void )
{
  dsplay_t *splay;

  splay = BuildDSplay();
  if( !splay )
    return "could not build a populated splay";

  if( DSplayContains( NULL, NULL ) )
    return "a NULL splay returned a true value for a NULL element";

  if( DSplayContains( splay, NULL ) )
    return "a populated splay returned a true value for a NULL element";

  DSplayDestroy( splay );

  return NULL;
}

const char *
TestContainsUniqueElement
( void )
{
  dsplay_t *splay;
  void *element;

  splay = BuildDSplay();
  if( !splay )
    return "could not build a populated splay";

  element = DSplayFirst( splay );
  if( !element )
    return "the splay did not have any elements";

  if( !DSplayContains( splay, element ) )
    return "true was not returned for an element existing exactly once in the splay";

  DSplayDestroy( splay );

  return NULL;
}

const char *
TestContainsWithNullDynamicSplay
( void )
{
  const void *element = "test element";

  if( DSplayContains( NULL, NULL ) )
    return "false was not returned for a NULL splay and element";

  if( DSplayContains( NULL, element ) )
    return "false was not returned for a NULL splay and non-NULL element";

  return NULL;
}

const char *
TestCopyContents
( void )
{
  dsplay_t *copy, *splay;
  void *copy_element, *original_element;

  splay = BuildDSplay();
  if( !splay )
    return "could not build a populated splay";

  copy = DSplayCopy( splay );
  if( !copy )
    return "the copy of the splay was NULL";

  original_element = DSplayFirst( splay );
  copy_element = DSplayFirst( copy );
  while( original_element ){
    if( !copy_element )
      return "the copy did not contain an element where the original did";

    if( original_element != copy_element )
      return "the splay elements were not the same in the copy";
    DSplayRemove( splay, original_element );
    DSplayRemove( copy, copy_element );

    original_element = DSplayFirst( splay );
    copy_element = DSplayFirst( copy );
  }

  DSplayDestroy( copy );
  DSplayDestroy( splay );

  return NULL;
}

const char *
TestDestroyNullDynamicSplay
( void )
{
  DSplayDestroy( NULL );

  return NULL;
}

const char *
TestDestroyPopulatedDynamicSplay
( void )
{
  const dsplay_t *splay;

  splay = BuildDSplay();
  if( !splay )
    return "could not build a populated splay";

  DSplayDestroy( splay );

  return NULL;
}

const char *
TestFirstInEmptyDynamicSplay
( void )
{
  const dsplay_t *splay;

  splay = DSplayNew();
  if( !splay )
    return "could not build an empty splay";

  if( DSplayFirst( splay ) != NULL )
    return "a non-NULL value was returned for an empty splay";

  DSplayDestroy( splay );

  return NULL;
}

const char *
TestFirstInNullDynamicSplay
( void )
{
  if( DSplayFirst( NULL ) != NULL )
    return "NULL was not returned for a NULL splay";

  return NULL;
}

const char *
TestFirstInPopulatedDynamicSplay
( void )
{
  const dsplay_t *splay;
  const char *element;

  splay = BuildDSplay();
  if( !splay )
    return "could not build a populated splay";

  element = DSplayFirst( splay );
  if( !element )
    return "a populated splay did not have a first element";

  ASSERT_STRINGS_EQUAL( "Alpha", element, "the first element was not correct" )

  DSplayDestroy( splay );

  return NULL;
}

const char *
TestLastInEmptyDynamicSplay
( void )
{
  const dsplay_t *splay;

  splay = DSplayNew();
  if( !splay )
    return "could not build an empty splay";

  if( DSplayLast( splay ) != NULL )
    return "a non-NULL value was returned for an empty splay";

  DSplayDestroy( splay );

  return NULL;
}

const char *
TestLastInNullDynamicSplay
( void )
{
  if( DSplayLast( NULL ) != NULL )
    return "NULL was not returned for a NULL splay";

  return NULL;
}

const char *
TestLastInPopulatedDynamicSplay
( void )
{
  const dsplay_t *splay;
  const char *element;

  splay = BuildDSplay();
  if( !splay )
    return "could not build a populated splay";

  element = DSplayLast( splay );
  if( !element )
    return "a populated splay did not have a last element";

  ASSERT_STRINGS_EQUAL( "Zulu", element, "the last element was not correct" )

  DSplayDestroy( splay );

  return NULL;
}

const char *
TestNewWithComparator
( void )
{
  const dsplay_t *splay;

  splay = DSplayNewWithComparator( CompareStrings );
  if( !splay )
    return "a new splay could not be created";

  DSplayDestroy( splay );

  return NULL;
}

const char *
TestNewWithNullComparator
( void )
{
  const dsplay_t *splay;

  splay = DSplayNewWithComparator( NULL );
  if( splay != NULL )
    return "a new splay was created with a NULL comparator";

  return NULL;
}

const char *
TestNewDynamicSplayIsEmpty
( void )
{
  const dsplay_t *splay;

  splay = DSplayNew();
  if( !splay )
    return "could not create a new splay";

  if( !DSplayIsEmpty( splay ) )
    return "a false value was returned for a new splay";

  DSplayDestroy( splay );

  return NULL;
}

const char *
TestNullDynamicSplayIsEmpty
( void )
{
  if( !DSplayIsEmpty( NULL ) )
    return "a false value was returned for a NULL splay";

  return NULL;
}

const char *
TestPopulatedDynamicSplayIsNotEmpty
( void )
{
  const dsplay_t *splay;

  splay = BuildDSplay();
  if( !splay )
    return "could not build a populated splay";

  if( DSplayIsEmpty( splay ) )
    return "a true value was returned for a populated splay";

  DSplayDestroy( splay );

  return NULL;
}

const char *
TestRemoveFromNullDynamicSplay
( void )
{
  void *element = "test element";

  if( DSplayRemove( NULL, NULL ) != NULL )
    return "NULL was not returned for a NULL splay and element";

  if( DSplayRemove( NULL, element ) != NULL )
    return "NULL was not returned for a NULL splay and non-NULL element";

  return NULL;
}

const char *
TestRemoveNonExistentElement
( void )
{
  dsplay_t *splay;
  void *element = "non existent";

  splay = BuildDSplay();
  if( !splay )
    return "could not build a populated splay";

  if( DSplayRemove( splay, element ) != NULL )
    return "NULL was not returned for an element that did not exist in the splay";

  DSplayDestroy( splay );

  return NULL;
}

const char *
TestRemoveNullElement
( void )
{
  dsplay_t *splay;

  if( DSplayRemove( NULL, NULL ) != NULL )
    return "NULL was not returned for a NULL splay and NULL element";

  splay = BuildDSplay();
  if( !splay )
    return "could not build a populated splay";

  if( DSplayRemove( splay, NULL ) != NULL )
    return "NULL was not returned for a non-NULL splay and NULL element";

  DSplayDestroy( splay );

  return NULL;
}

const char *
TestRemoveRootElement
( void )
{
  dsplay_t *splay;
  size_t size;
  void *existing_element;
  char *new_element;

  splay = BuildDSplay();
  if( !splay )
    return "could not build a populated splay";

  new_element = malloc( sizeof( char ) * 10 );
  if( !new_element )
    return "could not build an array of ints";
  new_element[0] = 'a';
  new_element[1] = 'b';
  new_element[2] = 'c';
  new_element[3] = 'd';
  new_element[4] = 'e';
  new_element[5] = 'f';
  new_element[6] = 'g';
  new_element[7] = 'h';
  new_element[8] = 'i';
  new_element[9] = '\0';

  existing_element = DSplayFirst( splay );
  if( !DSplayAdd( splay, new_element ) )
    return "could not add a new element to the splay";

  size = DSplaySize( splay );

  if( DSplayRemove( splay, "abcdefghi" ) != new_element )
    return "the element was not returned when removed";

  if( !DSplayContains( splay, existing_element ) )
    return "other elements were removed as well by the removal";

  if( DSplaySize( splay ) != ( size - 1 ) )
    return "the splay size did not decrease by one after the removal";

  return NULL;
}

const char *
TestRemoveUniqueElement
( void )
{
  dsplay_t *splay;
  size_t size;
  void *element;

  splay = BuildDSplay();
  if( !splay )
    return "could not build a populated splay";

  size = DSplaySize( splay );

  element = DSplayFirst( splay );
  if( !element )
    return "the splay did not have any elements";

  if( DSplayRemove( splay, element ) != element )
    return "the element could not be removed from the splay";

  if( DSplayContains( splay, element ) )
    return "the element was not actually removed from the splay";

  if( DSplaySize( splay ) != ( size - 1 ) )
    return "the splay size did not decrease by one after the call";

  DSplayDestroy( splay );

  return NULL;
}

const char *
TestSizeOfEmptyDynamicSplay
( void )
{
  const dsplay_t *splay;

  splay = DSplayNew();

  if( DSplaySize( splay ) != 0 )
    return "a new splay did not have a size of 0";

  DSplayDestroy( splay );

  return NULL;
}

const char *
TestSizeOfNullDynamicSplay
( void )
{
  if( DSplaySize( NULL ) != 0 )
    return "a NULL splay did not have a size of 0";

  return NULL;
}

const char *
TestSizeOfPopulatedDynamicSplay
( void )
{
  const dsplay_t *splay;

  splay = BuildDSplay();
  if( !splay )
    return "could not build a populated splay";

  if( DSplaySize( splay ) != 26 )
    return "a splay with 26 elements did not return 26";

  DSplayDestroy( splay );

  return NULL;
}

const char *
TestToStringWithEmptyDynamicSplay
( void )
{
  char *str;
  const dsplay_t *splay;

  splay = DSplayNew();
  if( !splay )
    return "could not build a new splay";

  str = DSplayToString( splay, NULL );
  if( !str )
    return "a string could not be created for an empty splay";

  ASSERT_STRINGS_EQUAL( "[]", str, "string representation was not correct for an empty splay" )

  free( str );
  DSplayDestroy( splay );

  return NULL;
}

const char *
TestToStringWithNullFunction
( void )
{
  char pointer[100];
  char *str, *element;
  dsplay_t *splay;

  splay = BuildDSplay();
  if( !splay )
    return "could not build a populated splay";

  str = DSplayToString( splay, NULL );
  if( !str )
    return "NULL was returned for a populated splay";

  element = DSplayFirst( splay );
  while( element ){
    strprint( pointer, 100, "%p", element );
    if( !strstr( str, pointer ) )
      return "the string did not contain the pointer address of one of the elements";

    DSplayRemove( splay, element );
    element = DSplayFirst( splay );
  }

  free( str );
  DSplayDestroy( splay );

  return NULL;

}

const char *
TestToStringWithNullDynamicSplay
( void )
{
  const char *str;

  str = DSplayToString( NULL, NULL );
  if( str )
    return "a non-NULL string was returned for a NULL splay and to string function";

  str = DSplayToString( NULL, ElementToString );
  if( str )
    return "a non-NULL string was returned for a NULL splay and non-NULL to string function";

  return NULL;
}

const char *
TestToStringWithPopulatedDynamicSplay
( void )
{
  char *str;
  const dsplay_t *splay;

  splay = BuildDSplay();
  if( !splay )
    return "could not build a populated splay";

  str = DSplayToString( splay, ElementToString );
  if( !str )
    return "a string could not be created for a populated splay";

  ASSERT_STRINGS_EQUAL( "[Alpha, Beta, Charlie, Delta, Echo, Foxtrot, Gamma, Hotel, India, Juliet, Kilo, Lima, Mike, November, Oscar, Papa, Quebec, Romeo, Sierra, Tango, Uniform, Victor, Whiskey, X-Ray, Yankee, Zulu]", str, "the string for a populated splay was not correct" )

  free( str );
  DSplayDestroy( splay );

  return NULL;
}
