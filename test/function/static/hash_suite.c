#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <woodpile/static/hash.h>

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

  TEST( ContainsDuplicateValues )
  TEST( ContainsNonExistentValue )

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

/**
 * Tests the SHashContains function a NULL value supplied.
 *
 * @test A NULL value must return a logically false value, whether the SHash
 * supplied is NULL or non-NULL.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestContainsNullValue
( void );

/**
 * Tests the SHashContains function with values that exist in the SHash exactly
 * once.
 *
 * @test A value existing exaclty once in the SHash must return 1.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestContainsUniqueValue
( void );

/**
 * Tests the SHashContains function with a NULL SHash.
 *
 * @test A NULL hash must return 0, whether the value supplied is NULL or
 * non-NULL.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestContainsWithNullSHash
( void );

/**
 * Tests the CopySHash function.
 *
 * @test A non-NULL SHash must be returned as the copy of a non-NULL SHash.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestCopy
( void );

/**
 * Tests the contents of the SHash returned by the CopySHash function.
 *
 * @test The copied SHash must point at the same elements as the original.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestCopyContents
( void );

/**
 * Tests the SHash returned by the CopySHash function.
 *
 * @test The copied SHash must be a different value than the original.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestCopyDistinct
( void );

/**
 * Tests the CopySHash function with a NULL SHash.
 *
 * @test a NULL SHash must return NULL.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestCopyNullSHash
( void );

/**
 * Tests the size of the SHash returned by the CopySHash function.
 *
 * @test The copy of a populated SHash must be the same size as the original.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestCopySize
( void );

/**
 * Tests the DestroySHash function with a NULL SHash.
 *
 * @test a NULL SHash must not cause an error.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestDestroyNullSHash
( void );

/**
 * Tests the DestroySHash function with a populated SHash.
 *
 * @test A populated SHash must not cause an error.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestDestroyPopulatedSHash
( void );

/**
 * Tests the SHashGet function with a NULL SHash.
 *
 * @test Calling the function with a NULL SHash must return NULL regardless of
 * key being NULL or non-NULL.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestGetFromNullSHash
( void );

/** 
 * Tests the SHashGet function with a NULL key.
 *
 * @test Calling the function with a NULL key must return NULL regardless of
 * the hash being NULL or non-NULL.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestGetNullKeyFromSHash
( void );

/**
 * Tests the SHashGet function with an empty SHash.
 *
 * @test Calling the function with an empty hash must return NULL, regardless
 * of the key being NULL or non-NULL.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestGetFromEmptySHash
( void );

/**
 * Tests the SHashGet function with a populated SHash.
 *
 * @test The value associated with the key provided must be returned.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestGetFromPopulatedSHash
( void );

/**
 * Tests the SHashIsEmpty function with an empty SHash.
 *
 * @test A SHash with no elements must return a positive value.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestIsEmptyWithEmptySHash
( void );

/**
 * Tests the SHashIsEmpty function with a populated SHash.
 *
 * @test A populated SHash must return 0.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestIsEmptyWithPopulatedSHash
( void );

/**
 * Tests the SHashIsEmpty function with a NULL SHash.
 *
 * @test a NULL SHash must return a positive value.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestIsEmptyWithNullSHash
( void );

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

/**
 * Tests the SHashPut function with a NULL SHash.
 *
 * @test Calling the function with a NULL SHash must return NULL regardless of
 * key or value being NULL or non-NULL.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestPutIntoNullSHash
( void );

/** 
 * Tests the SHashPut function with a NULL key.
 *
 * @test Calling the function with a NULL key must return NULL regardless of
 * the hash or value being NULL or non-NULL.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestPutNullKeyIntoSHash
( void );

/** 
 * Tests the SHashPut function with a NULL value.
 *
 * @test Calling the function with a NULL value must return NULL regardless of
 * the hash or key being NULL or non-NULL.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestPutNullValueIntoSHash
( void );

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


