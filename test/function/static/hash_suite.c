#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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
  TEST( GetFromEmptyHash )
  TEST( GetFromPopulatedSHash )
  TEST( IsEmptyWithEmptySHash )
  TEST( IsEmptyWithPopulatedSHash )
  TEST( IsEmptyWithNullSHash )
  TEST( NewWithNullHasher )

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

  if( SHashPut( hash, "3RD", value != value )
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
  if( strcmp( SHashContains( common_hash, "3rd" ), "Third" ) != 0 )
    return "the value was not contained in the hash";

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

  DestroySHash( copy );

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
  Shash *hash;

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

  hash = SHashNew( NULL );
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
  ASSERT_SRINGS_EQUAL( "First", value, "the key did not return the correct value" )

  return NULL;
}

const char *
TestIsEmptyWithEmptySHash
( void )
{
  SHash *hash;

  hash = SHashNew( NULL );
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

/**
 * Tests the NewSHash function.
 *
 * @test Calling the function must return a non-NULL value.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestNew
( void );

const char *
TestNewWithNullHasher
( void )
{
  SHash *hash;

  hash = SHashNew( NULL );
  if( !hash )
    return "NULL was returned with a NULL hashing function";

  return NULL;
}

const char *
TestPutIntoNullSHash
( void )
{
  if( SHashPut( NULL, NULL, NULL ) != NULL )
    return "a non-NULL value was returned for a NULL hash, key, and value";

  if( SHashPut( NULL, NULL, "value" ) != NULL )
    return "a non-NULL value was returned for a NULL hash and key"

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

/**
 * Tests the SHashPut function with an empty SHash.
 *
 * @test After putting a value into the hash it should be retrievable using
 * the same key. The retrieved value must be equal to the value placed into the
 * hash.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestPutValueIntoEmptySHash
( void );

/**
 * Tests the SHashPut function with a populated SHash.
 *
 * @test After putting a value into the hash it should be retrievable using
 * the same key. The retrieved value must be equal to the value placed into the
 * hash.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestPutValueIntoPopulatedSHash
( void );

/**
 * Tests the RemoveFromSHash function with a value that exists in the SHash more
 * than once.
 *
 * @test A SHash that has the value twice will have the first occurrence
 * removed and returned, but not the second.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestRemoveDuplicateValues
( void );

/**
 * Tests the RemoveFromSHash function with a NULL SHash.
 *
 * @test Removing from a NULL SHash must return NULL, whether the value
 * supplied is NULL or non-NULL.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestRemoveFromNullSHash
( void );

/**
 * Tests the RemoveFromSHash function when removing the last value from the
 * SHash.
 *
 * @test Removing the only element in a SHash must remove and return the element
 * and leav the SHash empty.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestRemoveLast
( void );

/**
 * Tests the RemoveFromSHash function with a value that does not exist in the
 * SHash.
 *
 * @test Removing a value that is not in the SHash must return NULL.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestRemoveNonExistentValue
( void );

/**
 * Tests the RemoveFromSHash function with a NULL value.
 *
 * @test Removing a NULL value must return NULL, whether the SHash supplied is
 * NULL or non-NULL.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestRemoveNullValue
( void );

/**
 * Tests the RemoveFromSHash function with a value that exists in the SHash
 * exactly once.
 *
 * @test Removing a value that is in the SHash once must return the value from
 * the SHash and remove the only instance of it.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestRemoveUniqueValue
( void );

/**
 * Tests the SHashSize function.
 *
 * @test A populated SHash must return an accurate count of the values.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestSize
( void );

/**
 * Tests the SHashSize function with an empty SHash.
 *
 * @test An empty SHash must return 0.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestSizeWithEmptySHash
( void );

/**
 * Tests the SHashSize function with a NULL SHash.
 *
 * @test A NULL SHash must return 0.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestSizeWithNullSHash
( void );
