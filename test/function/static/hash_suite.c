#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <woodpile/config.h>
#include <woodpile/hasher.h>
#include <woodpile/static/hash.h>
#include "lib/validate.h"
#include "test/function/static/hash_suite.h"
#include "test/helper.h"

static const shash_t *common_hash = NULL;

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
  TEST( SetCapacityWithNullSHash)
  TEST( SetElementComparatorToNull )
  TEST( SetElementComparatorWithNullSHash )
  TEST( SetHasherWithNullHasher )
  TEST( SetHasherWithNullSHash )
  TEST( SetKeyComparatorToNull )
  TEST( SetKeyComparatorWithNullSHash )
  TEST( ToStringWithNullSHash )
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
  TEST( GetWithCollidingKeys )
  TEST( IsEmptyWithEmptySHash )
  TEST( IsEmptyWithPopulatedSHash )
  TEST( IsEmptyWithNullSHash )
  TEST( New )
  TEST( PutExistingKeyIntoFullSHash )
  TEST( PutNewKeyIntoFullSHash )
  TEST( PutValueIntoEmptySHash )
  TEST( PutValueIntoPopulatedSHash )
  TEST( PutWithCollidingKeys )
  TEST( Remove )
  TEST( RemoveNonExistentKey )
  TEST( SetCapacity )
  TEST( SetElementComparator )
  TEST( SetHasher )
  TEST( SetHasherWithCollisions )
  TEST( SetKeyComparator )
  TEST( SetKeyComparatorWithEqualKeys )
  TEST( Size )
  TEST( SizeWithEmptySHash )
  TEST( SizeWithNullSHash )
  TEST( ToStringWithEmptySHash )
  TEST( ToStringWithNullFunction )
  TEST( ToStringWithPopulatedSHash )

  SHashDestroy( common_hash );

  if( failure_count > 0 )
    return EXIT_FAILURE;
  else
    return EXIT_SUCCESS;
}

#ifdef __WOODPILE_PARAMETER_VALIDATION

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
TestCopyNullSHash
( void )
{
  if( SHashCopy( NULL ) != NULL )
    return "a non-NULL value was returned for a NULL hash";

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
  shash_t *hash;

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
  shash_t *hash;

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
TestRemoveNullKey
( void )
{
  shash_t *hash;

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
TestSetCapacityWithNullSHash
( void )
{
  shash_t *hash;

  hash = BuildSHash();
  if( !hash )
    return "could not build a populated hash";

  if( SHashSetCapacity( NULL, 512 ) != NULL )
    return "NULL was not returned for a NULL hash";

  SHashDestroy( hash );

  return NULL;
}

const char *
TestSetElementComparatorToNull
( void )
{
  shash_t *hash;
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
TestSetHasherWithNullHasher
( void )
{
  hasher_t hasher;
  shash_t *hash;

  hash = BuildSHash();
  if( !hash )
    return "could not build a populated hash";

  if( SHashSetHasher( NULL, NULL ) != NULL )
    return "NULL was not returned for a NULL hash and hasher";

  hasher = SHashGetHasher( hash );

  if( SHashSetHasher( hash, NULL) != NULL )
    return "NULL was not returned for a NULL hasher";

  if( SHashGetHasher( hash ) != hasher )
    return "the hasher was changed after a call with a NULL hasher";

  SHashDestroy( hash );

  return NULL;
}

const char *
TestSetHasherWithNullSHash
( void )
{
  if( SHashSetHasher( NULL, NULL ) != NULL )
    return "NULL was not returned for a NULL hash and hasher";

  if( SHashSetHasher( NULL, NullHash ) != NULL )
    return "NULL was not returned for a NULL hash and non-NULL hasher";

  return NULL;
}

const char *
TestSetKeyComparatorToNull
( void )
{
  shash_t *hash;
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
TestToStringWithNullSHash
( void )
{
  if( SHashToString( NULL, NULL ) != NULL )
    return "a non-NULL value was returned for a NULL hash and function";

  if( SHashToString( NULL, ElementToString ) )
    return "a non-NULL value was returned for a NULL hash and non-NULL function";

  return NULL;
}

#endif

const char *
TestContainsDuplicateValues
( void )
{
  shash_t *hash;
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
TestCopy
( void )
{
  shash_t *copy;

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
  shash_t *copy;

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
  shash_t *copy;

  copy = SHashCopy( common_hash );

  if( copy == common_hash )
    return "the copy was not distinct from the original";

  SHashDestroy( copy );

  return NULL;
}

const char *
TestCopySize
( void )
{
  shash_t *copy;

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
  shash_t *hash;

  hash = BuildSHash();
  if( !hash )
    return "could not build a populated hash";

  SHashDestroy( hash );

  return NULL;
}

const char *
TestGetFromEmptySHash
( void )
{
  shash_t *hash;

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
TestGetWithCollidingKeys
( void )
{
  shash_t *hash;

  hash = BuildSHash();
  if( !hash )
    return "could not build a populated hash";

  if( SHashSetHasher( hash, CollisionHash ) != hash )
    return "could not update the hashing function";

  SHashPut( hash, "crash", "the value mapped to crash" );
  SHashPut( hash, "collision", "the value mapped to collision" );

  ASSERT_STRINGS_EQUAL( "the value mapped to crash", SHashGet(hash, "crash" ), "the value mapped to crash was not correct" )
  ASSERT_STRINGS_EQUAL( "the value mapped to collision", SHashGet(hash, "collision" ), "the value mapped to collision was not correct" )

  SHashDestroy( hash );

  return NULL;
}

const char *
TestIsEmptyWithEmptySHash
( void )
{
  shash_t *hash;

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
  shash_t *hash;

  hash = SHashNew();
  if( !hash )
    return "NULL was returned with a non-NULL hashing function";

  return NULL;
}

const char *
TestPutExistingKeyIntoFullSHash
( void )
{
  shash_t *hash;
  const char *result;

  hash = BuildFullSHash();
  if( !hash )
    return "could not build a full hash";

  result = SHashPut( hash, "mi", "my name, I call myself" );
  if( !result )
    return "an existing key could not be replaced in a full hash";
  ASSERT_STRINGS_EQUAL( "e", result, "the returned value was not the previous element" )

  result = SHashGet( hash, "mi" );
  if( !result)
    return "the key no longer had an element associated with it";
  ASSERT_STRINGS_EQUAL( "my name, I call myself", result, "the new element was not returned for the key" )

  if( SHashContains( hash, "e" ) )
    return "the previous element was not removed from the hash";

  SHashDestroy( hash );

  return NULL;
}

const char *
TestPutNewKeyIntoFullSHash
( void )
{
  shash_t *hash;

  hash = BuildFullSHash();
  if( !hash )
    return "could not build a full hash";

  if( SHashPut( hash, "key", "value" ) != NULL )
    return "a new key was added to a full hash";

  if( SHashContains( hash, "value" ) )
    return "the new value existed in the hash after a failed put";

  SHashDestroy( hash );

  return NULL;
}

const char *
TestPutValueIntoEmptySHash
( void )
{
  shash_t *hash;
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
  shash_t *hash;
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
TestPutWithCollidingKeys
( void )
{
  char *crash, *collision;
  shash_t *hash;
  size_t previous_size;

  crash = malloc( sizeof( char ) * 7 );
  if( !crash )
    return "could not allocate memory for the crash string";
  crash[0] = 'v';
  crash[1] = 'a';
  crash[2] = 'l';
  crash[3] = 'u';
  crash[4] = 'e';
  crash[5] = '1';
  crash[6] = '\0';

  collision = malloc( sizeof( char ) * 7 );
  if( !collision )
    return "could not allocate memory for the collision string";
  crash[0] = 'v';
  crash[1] = 'a';
  crash[2] = 'l';
  crash[3] = 'u';
  crash[4] = 'e';
  crash[5] = '2';
  crash[6] = '\0';

  hash = BuildSHash();
  if( !hash )
    return "could not build a populated hash";

  if( SHashSetHasher( hash, CollisionHash ) != hash )
    return "could not update the hashing function";

  previous_size = SHashSize( hash );

  if( SHashPut( hash, "crash", crash ) != crash )
    return "could not put the first value into the hash";

  if( previous_size+1 != SHashSize( hash ) )
    return "the size was not increased by one after the first insertion";

  if( SHashPut( hash, "collision", collision ) != collision )
    return "could not put the second value into the hash";

  if( previous_size+2 != SHashSize( hash ) )
    return "the size was not increased by one after the second insertion";

  SHashDestroy( hash );

  return NULL;
}

const char *
TestRemove
( void )
{
  shash_t *hash;
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
TestRemoveNonExistentKey
( void )
{
  shash_t *hash;

  hash = BuildSHash();
  if( !hash )
    return "could not build a populated hash";

  if( SHashRemove( hash, "doesn't exist" ) )
    return "removing a non-existent key did not return NULL";

  SHashDestroy( hash );

  return NULL;
}

const char *
TestSetCapacity
( void )
{
  shash_t *hash;

  hash = BuildSHash();
  if( !hash )
    return "could not build a populated hash";

  SHashSetHasher( hash, WoodpileHash );

  if( SHashSetCapacity( hash, 128 ) != hash )
    return "could not set the capacity on a hash";

  ASSERT_STRINGS_EQUAL( "First", SHashGet( hash, "1st" ), "the first element was no longer accessible" )
  ASSERT_STRINGS_EQUAL( "Second", SHashGet( hash, "2nd" ), "the second element was no longer accessible" )
  ASSERT_STRINGS_EQUAL( "Third", SHashGet( hash, "3rd" ), "the third element was no longer accessible" )
  ASSERT_STRINGS_EQUAL( "Fourth", SHashGet( hash, "4th" ), "the fourth element was no longer accessible" )
  ASSERT_STRINGS_EQUAL( "Fifth", SHashGet( hash, "5th" ), "the fifth element was no longer accessible" )
  ASSERT_STRINGS_EQUAL( "Sixth", SHashGet( hash, "6th" ), "the sixth element was no longer accessible" )
  ASSERT_STRINGS_EQUAL( "Seventh", SHashGet( hash, "7th" ), "the seventh element was no longer accessible" )
  ASSERT_STRINGS_EQUAL( "Eighth", SHashGet( hash, "8th" ), "the eighth element was no longer accessible" )
  ASSERT_STRINGS_EQUAL( "Ninth", SHashGet( hash, "9th" ), "the ninth element was no longer accessible" )
  ASSERT_STRINGS_EQUAL( "Tenth", SHashGet( hash, "10th" ), "the tenth element was no longer accessible" )

  SHashDestroy( hash );

  return NULL;
}

const char *
TestSetElementComparator
( void )
{
  shash_t *hash;
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
TestSetHasher
( void )
{
  shash_t *hash;
  size_t previous_size;

  hash = BuildSHash();
  if( !hash )
    return "could not build a populated hash";

  previous_size = SHashSize( hash );

  if( SHashSetHasher( hash, NullHash ) != hash )
    return "the hasher could not be changed";

  ASSERT_STRINGS_EQUAL( "First", SHashGet( hash, "1st" ), "the key-value mappings were changed" )
  ASSERT_STRINGS_EQUAL( "Second", SHashGet( hash, "2nd" ), "the key-value mappings were changed" )
  ASSERT_STRINGS_EQUAL( "Third", SHashGet( hash, "3rd" ), "the key-value mappings were changed" )
  ASSERT_STRINGS_EQUAL( "Fourth", SHashGet( hash, "4th" ), "the key-value mappings were changed" )
  ASSERT_STRINGS_EQUAL( "Fifth", SHashGet( hash, "5th" ), "the key-value mappings were changed" )
  ASSERT_STRINGS_EQUAL( "Sixth", SHashGet( hash, "6th" ), "the key-value mappings were changed" )
  ASSERT_STRINGS_EQUAL( "Seventh", SHashGet( hash, "7th" ), "the key-value mappings were changed" )
  ASSERT_STRINGS_EQUAL( "Eighth", SHashGet( hash, "8th" ), "the key-value mappings were changed" )
  ASSERT_STRINGS_EQUAL( "Ninth", SHashGet( hash, "9th" ), "the key-value mappings were changed" )
  ASSERT_STRINGS_EQUAL( "Tenth", SHashGet( hash, "10th" ), "the key-value mappings were changed" )

  if( SHashSize( hash ) != previous_size )
    return "the size of the hash changed after changing the hasher";

  SHashDestroy( hash );

  return NULL;
}

const char *
TestSetHasherWithCollisions
( void )
{
  shash_t *hash;
  size_t previous_size;

  hash = SHashNewDictionary();
  if( !hash )
    return "could not build a new hash";

  SHashPut( hash, "crash", "the value for crash" );
  SHashPut( hash, "collision", "the value for collision" );

  previous_size = SHashSize( hash );

  if( SHashSetHasher( hash, CollisionHash ) != hash )
    return "could not change the hashing value";

  ASSERT_STRINGS_EQUAL( "the value for crash", SHashGet( hash, "crash" ), "one of the collided keys no longer returned the correct value" )
  ASSERT_STRINGS_EQUAL( "the value for collision", SHashGet( hash, "collision" ), "one of the collided keys no longer returned the correct value" )

  if( SHashSize( hash )  != previous_size )
    return "the size of the hash changed";

  SHashDestroy( hash );

  return NULL;
}

const char *
TestSetKeyComparator
( void )
{
  shash_t *hash;
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
TestSetKeyComparatorWithEqualKeys
( void )
{
  char *first_string = NULL;
  char *second_string = NULL;
  char *third_string = NULL;
  shash_t *hash = NULL;
  size_t previous_size;

  first_string = malloc( sizeof( char ) * 5 );
  if( !first_string )
    return "could not build the first test string";

  second_string = malloc( sizeof( char ) * 5 );
  if( !second_string )
    return "could not build the second test string";

  first_string[0] = second_string[0] = 'm';
  first_string[1] = second_string[1] = 'e';
  first_string[2] = second_string[2] = 'a';
  first_string[3] = second_string[3] = 't';
  first_string[4] = second_string[4] = '\0';

  third_string = malloc( sizeof( char ) * 7 );
  if( !third_string )
    return "could not build the third test string";

  third_string[0] = 'c';
  third_string[1] = 'h';
  third_string[2] = 'e';
  third_string[3] = 'e';
  third_string[4] = 's';
  third_string[5] = 'e';
  third_string[6] = '\0';

  hash = SHashNew();
  if( !hash )
    return "could not build a new hash";

  SHashSetHasher( hash, WoodpileHash );
  SHashSetKeyComparator( hash, ComparePointers );

  if( !SHashPut( hash, first_string, "first string value" ) )
    return "could not add the first string";

  if( !SHashPut( hash, second_string, "second string value" ) )
    return "could not add the second string";

  if( !SHashPut( hash, third_string, "third string value ") )
    return "could not add the third string";

  previous_size = SHashSize( hash );

  if( SHashSetKeyComparator( hash, CompareStrings ) != hash )
    return "the key comparator could not be changed";

  if( SHashSize( hash ) != previous_size-1 )
    return "the size was not decreased by one after a comparator change";

  if( !SHashGet( hash, first_string ) || !SHashGet( hash, second_string) )
    return "the keys no longer existed in the hash";

  if( strcmp( "first string value", SHashGet( hash, first_string ) ) != 0 ){
    if( strcmp( "second string value", SHashGet( hash, first_string ) ) != 0 )
      return "the value was not mapped to both keys 1";
    if( strcmp( "second string value", SHashGet( hash, second_string ) ) != 0 )
      return "the value was not mapped to both keys 2";
  } else {
    if( strcmp( "first string value", SHashGet( hash, second_string ) ) != 0 )
      return "the value was not mapped to both keys 3";
  }

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
  shash_t *hash;

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

/**
 * Tests the SHashToString function an empty SHash.
 *
 * @test An empty SHash must return a string of "{}";
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestToStringWithEmptySHash
( void )
{
  return NULL;
}

/**
 * Tests the SHashToString function with a NULL element_to_string function.
 *
 * @test The function must return a NULL string, regardless of whether the
 * hash is NULL or non-NULL.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestToStringWithNullFunction
( void )
{
  return NULL;
}

/**
 * Tests the SHashToString function with a populated SHash.
 *
 * @test The function must return a string starting and ending with '{' and '}'
 * respectively. The string representation of each key must exist in the string.
 * The string representation of each value must exist in the string immediately
 * after the key's representation, separated only by an '=' character. A ','
 * immediately followed by a ' ' character must exist between each key and value
 * pair.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestToStringWithPopulatedSHash
( void )
{
  return NULL;
}
