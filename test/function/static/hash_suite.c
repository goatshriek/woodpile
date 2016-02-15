#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <woodpile/hasher.h>
#include <woodpile/static/hash.h>
#include "lib/validate.h"
#include "test/function/static/hash_suite.h"
#include "test/helper.h"

static const SHash *common_hash = NULL;

int
main
( void )
{
  unsigned failure_count = 0;
  const char *result;

  common_hash = BuildSHash();
  if( !common_hash ){
    printf( "Could not build a test SHash" );
    return EXIT_FAILURE;
  }

#ifdef __WOODPILE_PARAMETER_VALIDATION
  TEST( ContainsNullValue )
  TEST( ContainsWithNullSHash )
  TEST( CopyNullSHash )
  TEST( GetFromNullSHash )
  TEST( GetNullKeyFromSHash )
  TEST( PutIntoNullSHash )
  TEST( PutNullKeyIntoSHash )
  TEST( PutNullValueIntoSHash )
  TEST( RemoveFromNullSHash )
  TEST( RemoveNullKey )
  TEST( SetElementComparatorToNull )
  TEST( SetElementComparatorWithNullSHash )
  TEST( SetKeyComparatorToNull )
  TEST( SetKeyComparatorWithNullSHash )
#endif

  TEST( ContainsDuplicateValues )
  TEST( ContainsNonExistentValue )
  TEST( ContainsUniqueValue )
  TEST( Copy )
  TEST( CopyContents )
  TEST( CopyDistinct )
  TEST( CopySize )
  TEST( DestroyNullSHash )
  TEST( DestroyPopulatedSHash )
  TEST( GetFromEmptySHash )
  TEST( GetFromPopulatedSHash )
  TEST( IsEmptyWithEmptySHash )
  TEST( IsEmptyWithPopulatedSHash )
  TEST( IsEmptyWithNullSHash )
  TEST( New )
  TEST( PutValueIntoEmptySHash )
  TEST( PutValueIntoPopulatedSHash )
  TEST( Remove )
  TEST( RemoveNonExistentKey )
  TEST( SetElementComparator )
  TEST( SetKeyComparator )
  TEST( Size )
  TEST( SizeWithEmptySHash )
  TEST( SizeWithNullSHash )

  SHashDestroy( common_hash );

  if( failure_count > 0 )
    return EXIT_FAILURE;
  else
    return EXIT_SUCCESS;
}

const char *
TestContainsDuplicateValues
( void )
{
  SHash *hash;
  void *key, *value;

  hash = BuildSHash();
  if( !hash )
    return "could not build a test hash";

  value = SHashGet( hash, "3rd" );
  if( !value )
    return "could not get an existing value";

  if( SHashPut( hash, "3RD", value ) != value )
    return "a duplicate could not be added to the hash";
  
  key = SHashContains( hash, value );
  if( !key )
    return "true was not returned for a value in the hash twice";

  if( strcmp( key, "3rd" ) != 0 && strcmp( key, "3RD" ) != 0 )
    return "the returned key was not one of the keys mapped to the value";

  SHashDestroy( hash );

  return NULL;
}

const char *
TestContainsNonExistentValue
( void )
{
  if( SHashContains( common_hash, "this doesn't exist" ) != NULL )
    return "NULL was not returned for a value not in the hash";

  return NULL;
}

const char *
TestContainsNullValue
( void )
{
  if( SHashContains( NULL, NULL ) != NULL )
    return "NULL was not returned for a NULL hash and value";

  if( SHashContains( common_hash, NULL ) != NULL )
    return "NULL was not returned for a NULL value";

  return NULL;
}

const char *
TestContainsUniqueValue
( void )
{
  void *value;

  value = SHashContains( common_hash, "Third" );
  if( !value )
    return "a value existing in the hash was not returned";

  ASSERT_STRINGS_EQUAL( "3rd", value, "the correct key was not returned" )

  return NULL;
}

const char *
TestContainsWithNullSHash
( void )
{
  if( SHashContains( NULL, NULL ) != NULL )
    return "NULL was not returned for a NULL hash and value";

  if( SHashContains( NULL, "value" ) != NULL )
    return "NULL was not returned for a NULL hash";

  return NULL;
}

const char *
TestCopy
( void )
{
  SHash *copy;

  copy = SHashCopy( common_hash );
  if( !copy )
    return "NULL was returned for a non-NULL hash";

  SHashDestroy( copy );

  return NULL;
}

const char *
TestCopyContents
( void )
{
  SHash *copy;

  copy = SHashCopy( common_hash );
  if( !copy )
    return "the hash could not be copied";

  if( SHashGet( common_hash, "1st" ) != SHashGet( copy, "1st" ) )
    return "the copy did not point at the same elements as the original";

  SHashDestroy( copy );

  return NULL;
}

const char *
TestCopyDistinct
( void )
{
  SHash *copy;

  copy = SHashCopy( common_hash );

  if( copy == common_hash )
    return "the copy was not distinct from the original";

  SHashDestroy( copy );

  return NULL;
}

const char *
TestCopyNullSHash
( void )
{
  if( SHashCopy( NULL ) != NULL )
    return "a non-NULL value was returned for a NULL hash";

  return NULL;
}

const char *
TestCopySize
( void )
{
  SHash *copy;

  copy = SHashCopy( common_hash );
  if( !copy )
    return "the hash could not be copied";

  if( SHashSize( common_hash ) != SHashSize( copy ) )
    return "the size of the copy was not the same as the original";

  SHashDestroy( copy );

  return NULL;
}

const char *
TestDestroyNullSHash
( void )
{
  SHashDestroy( NULL );

  return NULL;
}

const char *
TestDestroyPopulatedSHash
( void )
{
  SHash *hash;

  hash = BuildSHash();
  if( !hash )
    return "could not build a populated hash";

  SHashDestroy( hash );

  return NULL;
}

const char *
TestGetFromNullSHash
( void )
{
  if( SHashGet( NULL, NULL ) != NULL )
    return "a non-NULL value was returned for a NULL hash and key";

  if( SHashGet( NULL, "key" ) != NULL )
    return "a non-NULL value was returned for a NULL hash";

  return NULL;
}

const char *
TestGetNullKeyFromSHash
( void )
{
  if( SHashGet( NULL, NULL ) != NULL )
    return "a non-NULL value was returned for a NULL hash and key";

  if( SHashGet( common_hash, NULL ) != NULL )
    return "a non-NULL value was returned for a NULL key";

  return NULL;
}

const char *
TestGetFromEmptySHash
( void )
{
  SHash *hash;

  hash = SHashNewDictionary();
  if( SHashGet( hash, "1st" ) != NULL )
    return "a non-NULL value was returned for an empty hash";

  SHashDestroy( hash );

  return NULL;
}

const char *
TestGetFromPopulatedSHash
( void )
{
  char *value;

  value = SHashGet( common_hash, "1st" );
  ASSERT_STRINGS_EQUAL( "First", value, "the key did not return the correct value" )

  return NULL;
}

const char *
TestIsEmptyWithEmptySHash
( void )
{
  SHash *hash;

  hash = SHashNew();
  if( !hash )
    return "a new hash could not be created";

  if( !SHashIsEmpty( hash ) )
    return "a false value was returned for an empty hash";

  SHashDestroy( hash );

  return NULL;
}

const char *
TestIsEmptyWithPopulatedSHash
( void )
{
  if( SHashIsEmpty( common_hash ) )
    return "a true value was returned for a populated hash";

  return NULL;
}

const char *
TestIsEmptyWithNullSHash
( void )
{
  if( !SHashIsEmpty( NULL ) )
    return "a false value was returned for a NULL hash";

  return NULL;
}

const char *
TestNew
( void )
{
  SHash *hash;

  hash = SHashNew();
  if( !hash )
    return "NULL was returned with a non-NULL hashing function";
    
  return NULL;
}

const char *
TestPutIntoNullSHash
( void )
{
  if( SHashPut( NULL, NULL, NULL ) != NULL )
    return "a non-NULL value was returned for a NULL hash, key, and value";

  if( SHashPut( NULL, NULL, "value" ) != NULL )
    return "a non-NULL value was returned for a NULL hash and key";

  if( SHashPut( NULL, "key", NULL ) != NULL )
    return "a non-NULL value was returned for a NULl hash and value";

  if( SHashPut( NULL, "key", "value" ) != NULL )
    return "a non-NULL value was returned for a NULL hash";

  return NULL;
}

const char *
TestPutNullKeyIntoSHash
( void )
{
  SHash *hash;

  hash = BuildSHash();
  if( !hash )
    return "could not build a populated hash";

  if( SHashPut( NULL, NULL, NULL ) != NULL )
    return "a non-NULL value was returned for a NULL hash, key, and value";

  if( SHashPut( NULL, NULL, "value" ) != NULL )
    return "a non-NULL value was returned for a NULL hash and key";

  if( SHashPut( hash, NULL, NULL ) != NULL )
    return "a non-NULL value was returned for a NULL key and value";

  if( SHashPut( hash, NULL, "value" ) != NULL )
    return "a non-NULL value was returned for a NULL key";

  SHashDestroy( hash );

  return NULL;
}

const char *
TestPutNullValueIntoSHash
( void )
{
  SHash *hash;

  hash = BuildSHash();
  if( !hash )
    return "could not build a populated hash";

  if( SHashPut( NULL, NULL, NULL ) != NULL )
    return "a non-NULL value was returned for a NULL hash, key, and value";

  if( SHashPut( NULL, "key", NULL ) != NULL )
    return "a non-NULL value was returned for a NULL hash and value";

  if( SHashPut( hash, NULL, NULL ) != NULL )
    return "a non-NULL value was returned for a NULL key and value";

  if( SHashPut( hash, "key", NULL ) != NULL )
    return "a non-NULL value was returned for a NULL value";

  SHashDestroy( hash );

  return NULL;
}

const char *
TestPutValueIntoEmptySHash
( void )
{
  SHash *hash;
  void *key = "Test Key";
  void *value = "Test Value";

  hash = SHashNewDictionary();
  if( !hash )
    return "could not build an empty hash";

  if( SHashPut( hash, key, value ) != value )
    return "could not add a new value to a hash";

  if( SHashGet( hash, key ) != value )
    return "could not retrieve a newly added value";

  SHashDestroy( hash );

  return NULL;
}

const char *
TestPutValueIntoPopulatedSHash
( void )
{
  SHash *hash;
  void *key = "Test Key";
  void *value = "Test Value";

  hash = BuildSHash();
  if( !hash )
    return "could not build a populated hash";

  if( SHashPut( hash, key, value ) != value )
    return "could not add a new value to a hash";

  if( SHashGet( hash, key ) != value )
    return "could not retrieve a newly added value";

  SHashDestroy( hash );

  return NULL;
}

const char *
TestRemove
( void )
{
  SHash *hash;
  void *value;

  hash = BuildSHash();
  if( !hash )
    return "could not build a populated hash";

  value = SHashRemove( hash, "7th" );
  if( !value )
    return "a value could not be removed from the hash";
  ASSERT_STRINGS_EQUAL( "Seventh", value, "the correct value was not returned upon removal" )

  if( SHashContains( hash, value ) )
    return "the value was not removed from the hash";

  SHashDestroy( hash );

  return NULL;
}

const char *
TestRemoveFromNullSHash
( void )
{
  if( SHashRemove( NULL, NULL ) != NULL )
    return "NULL was not returned for a NULL hash and key";

  if( SHashRemove( NULL, "key" ) != NULL )
    return "NULL was not returned for a NULL hash and non-NULL key";

  return NULL;
}

const char *
TestRemoveNonExistentKey
( void )
{
  SHash *hash;

  hash = BuildSHash();
  if( !hash )
    return "could not build a populated hash";

  if( SHashRemove( hash, "doesn't exist" ) )
    return "removing a non-existent key did not return NULL";

  SHashDestroy( hash );

  return NULL;
}

const char *
TestSetElementComparator
( void )
{
  SHash *hash;
  char *element;

  element = malloc( sizeof( char ) * 7 );
  if( !element )
    return "could not create a unique element";

  element[0] = 'F';
  element[1] = 'o';
  element[2] = 'u';
  element[3] = 'r';
  element[4] = 't';
  element[5] = 'h';
  element[6] = '\0';

  hash = BuildSHash();
  if( !hash )
    return "could not build a populated hash";

  if( SHashSetElementComparator( hash, CompareStrings ) != hash )
    return "the element comparator could not be updated";

  if( !SHashContains( hash, element ) )
    return "the updated element comparator was not used";

  if( SHashSetElementComparator( hash, ComparePointers ) != hash )
    return "the element comparator could not be updated after being set once";

  if( SHashContains( hash, element ) )
    return "changing the element comparator did not result in different behavior";

  SHashDestroy( hash );

  return NULL;
}

const char *
TestSetElementComparatorToNull
( void )
{
  SHash *hash;
  comparator_t previous;

  hash = BuildSHash();
  if( !hash )
    return "could not build a populated hash";

  previous = SHashElementComparator( hash );

  if( SHashSetElementComparator( hash, NULL ) != NULL )
    return "NULL was not returned for a NULL comparator";

  if( SHashElementComparator( hash ) != previous )
    return "the comparator was changed after a call with a NULL comparator";

  SHashDestroy( hash );

  return NULL;
}

const char *
TestSetElementComparatorWithNullSHash
( void )
{
  if( SHashSetElementComparator( NULL, NULL ) != NULL )
    return "a non-NULL value was not returned for a NULL hash and comparator";

  if( SHashSetElementComparator( NULL, ComparePointers ) != NULL )
    return "a non-NULL value was not returned for a NULL hash";

  return NULL;
}

const char *
TestSetKeyComparator
( void )
{
  SHash *hash;
  char *new_element = "Fourth Place";
  char *new_key = "4th";

  hash = BuildSHash();
  if( !hash )
    return "could not build a populated hash";

  if( SHashSetKeyComparator( hash, CompareStrings ) != hash )
    return "the key comparator could not be set";

  if( SHashPut( hash, new_key, new_element ) == new_element )
    return "the key comparator did not work correctly";

  if( SHashSetKeyComparator( hash, ComparePointers ) != hash )
    return "the element comparator could not be updated after being set once";

  if( SHashPut( hash, new_key, new_element ) != new_element )
    return "the key comparator was not changed after being unset";

  SHashDestroy( hash );

  return NULL;
}

const char *
TestSetKeyComparatorToNull
( void )
{
  SHash *hash;
  comparator_t previous;

  hash = BuildSHash();
  if( !hash )
    return "could not build a populated hash";

  previous = SHashKeyComparator( hash );

  if( SHashSetKeyComparator( hash, NULL ) != NULL )
    return "NULL was not returned for a NULL comparator";

  if( SHashKeyComparator( hash ) != previous )
    return "the comparator was changed after a call with a NULL comparator";

  SHashDestroy( hash );

  return NULL;
}

const char *
TestRemoveNullKey
( void )
{
  SHash *hash;

  hash = BuildSHash();
  if( !hash )
    return "could not build a populated hash";

  if( SHashRemove( hash, NULL ) )
    return "a non-NULL hash and NULL key did not return NULL";

  if( SHashRemove( NULL, NULL ) )
    return "a NULL hash and key did not return NULL";

  SHashDestroy( hash );

  return NULL;
}

const char *
TestSetKeyComparatorWithNullSHash
( void )
{
  if( SHashSetKeyComparator( NULL, NULL ) != NULL )
    return "a non-NULL value was not returned for a NULL hash and comparator";

  if( SHashSetKeyComparator( NULL, ComparePointers ) != NULL )
    return "a non-NULL value was not returned for a NULL hash";

  return NULL;
}

const char *
TestSize
( void )
{
  if( SHashSize( common_hash ) != 10 )
    return "the correct size was not returned for a hash";

  return NULL;
}

const char *
TestSizeWithEmptySHash
( void )
{
  SHash *hash;

  hash = SHashNew();
  if( !hash )
    return "could not create an empty hash";

  if( SHashSize( hash ) != 0 )
    return "the size of an empty hash was not zero";

  SHashDestroy( hash );

  return NULL;
}

const char *
TestSizeWithNullSHash
( void )
{
  if( SHashSize( NULL ) != 0 )
    return "0 was not returned for a NULL hash";

  return NULL;
}
