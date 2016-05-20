#ifndef __WOODPILE_TEST_FUNCTION_STATIC_HASH_SUITE_H
#define __WOODPILE_TEST_FUNCTION_STATIC_HASH_SUITE_H

/**
 * @file
 * Hash tests
 */

#include <woodpile/config.h>

#ifdef __WOODPILE_PARAMETER_VALIDATION

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
 * Tests the SHashRemove function with a NULL SHash.
 *
 * @test Removing from a NULL SHash must return NULL, whether the key
 * supplied is NULL or non-NULL.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestRemoveFromNullSHash
( void );

/**
 * Tests the SHashRemove function with a NULL key.
 *
 * @test Removing a NULL key must return NULL, whether the SHash supplied is
 * NULL or non-NULL.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestRemoveNullKey
( void );

/**
 * Tests the SHashSetCapacity function with a NULL SHash.
 *
 * @test A NULL SHash must return NULL.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestSetCapacityWithNullSHash
( void );

/**
 * Tests the SHashSetElementComparator function with a NULL comparator.
 *
 * @test Setting to a NULL comparator must return NULL. The hash must have the
 * same element comparator as it did before the call.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestSetElementComparatorToNull
( void );

/**
 * Tests the SHashSetElementComparator function with a NULL SHash.
 *
 * @test Setting the comparator on a NULL SHash must return NULL whether the
 * comparator is NULL or non-NULL.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestSetElementComparatorWithNullSHash
( void );

/**
 * Tests the SHashSetHasher function with a NULL hashing function.
 *
 * @test Setting to a NULL hasher must return NULL, regardless of whether the
 * SHash is NULL or non-NULL. The hash must have the same hashing function as
 * it did before the call.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestSetHasherWithNullHasher
( void );

/**
 * Tests the SHashSetHasher function with a NULL SHash.
 *
 * @test Setting the hasher on a NULL SHash must return NULL whether the hasher
 * is NULL or non-NULL.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestSetHasherWithNullSHash
( void );

/**
 * Tests the SHashSetKeyComparator function with a NULL comparator.
 *
 * @test Setting to a NULL comparator must return NULL. The hash must have the
 * same key comparator as it did before the call.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestSetKeyComparatorToNull
( void );

/**
 * Tests the SHashSetKeyComparator function with a NULL SHash.
 *
 * @test Setting the comaprator on a NULL SHash must return NULL whether the
 * comparator is NULL or non-NULL.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestSetKeyComparatorWithNullSHash
( void );

/**
 * Tests the SHashToString function with a NULL SHash.
 *
 * @test The function must return a NULL string, regardless of whether the
 * element_to_string function is NULL or non-NULL.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestToStringWithNullSHash
( void );

#endif

/**
 * Tests the SHashContains function with a value existing multiple times in the
 * SHash.
 *
 * @test A value existing twice in the SHash must return a logically true value.
 * The returned value must be equal to one of the two keys mapped to the value.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestContainsDuplicateValues
( void );

/**
 * Tests the SHashContains function with a value that does not exist in the
 * SHash.
 *
 * @test A value not existing in the SHash must return a logically false value.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestContainsNonExistentValue
( void );

/**
 * Tests the SHashContains function with values that exist in the SHash exactly
 * once.
 *
 * @test A value existing exactly once in the SHash must return 1.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestContainsUniqueValue
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
 * Tests the SHashGet function with an empty SHash.
 *
 * @test Calling the function with an empty hash must return NULL.
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
 * Tests the SHashGet function with two keys that have a hash collision.
 *
 * @test The value associated with the keys must be returned for both keys that
 * have a collision.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestGetWithCollidingKeys
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
 * Tests the SHashPut function with a full SHash and a key that already exists
 * in the hash.
 *
 * @test Putting a key that already exists in the hash must return the previous
 * value mapped to the key. The new value must exist in the hash and be mapped
 * to the key, and the old value must no longer exist in the hash.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestPutExistingKeyIntoFullSHash
( void );

/**
 * Tests the SHashPut function with a full SHash and a key that does not yet
 * exist in the hash.
 *
 * @test Attempting to put a new key into the hash must return NULL. The new
 * key must not exist in the hash after the call.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestPutNewKeyIntoFullSHash
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
 * Tests the SHashPut function with two keys that have a hash collision.
 *
 * @test Adding a key that has a collision with a key already existing in the
 * hash must return the value place into the hash. The size of the hash must
 * increase by one after the call to the function.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestPutWithCollidingKeys
( void );

/**
 * Tests the SHashRemove function.
 *
 * @test Removing a key that is in the SHash must return the value from
 * the SHash and remove it from the structure.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestRemove
( void );

/**
 * Tests the SHashRemove function with a key that does not exist in the
 * SHash.
 *
 * @test Removing a value that is not in the SHash must return NULL.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestRemoveNonExistentKey
( void );

/**
 * Tests the SHashSetCapacity function.
 *
 * @test Setting the capacity on an SHash must return the SHash. Elements must
 * still be accessible after setting the capacity.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestSetCapacity
( void );

/**
 *  Tests the SHashSetElementComparator function.
 *
 *  @test After setting the comparator to a function comparing equality by a
 *  means other than direct pointer comparison, a call to SHashContains must
 *  return a logically true value. Setting the comparator back to direct pointer
 *  comparison must cause SHashContains to return a logically false value.
 *
 *  @return NULL on completion or a string describing the failure
 */
const char *
TestSetElementComparator
( void );

/**
 * Tests the SHashSetHasher function.
 *
 * @test After setting the hasher function on the hash, the size of the hash
 * must not change. All keys in the hash must still be mapped to the same value
 * as before the change, using the SHashGet function.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestSetHasher
( void );

/**
 * Tests the SHashSetHasher function with a function that has new collisions.
 *
 * @test After setting the hasher function to one that collides for two keys,
 * the size of the hash must not have changed. Each of the keys with colliding
 * hash values must still be mapped to the same value as before the change.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestSetHasherWithCollisions
( void );

/**
 * Tests the SHashSetHasher function with an empty SHash.
 *
 * @test After setting the hash function on the hash, the hash must still be
 * empty.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestSetHasherWithEmptySHash
( void );

/**
 *  Tests the SHashSetKeyComparator function.
 *
 *  @test After setting the comparator to a function comparing equality by a
 *  means other than direct pointer comparison, a call to SHashPut with a key
 *  that already exists in the hash must return the existing element rather than
 *  the new element. Setting the comparator to a function that does not consider
 *  the two keys equal must result in another call to SHashPut returning the new
 *  element.
 *
 *  @return NULL on completion or a string describing the failure
 */
const char *
TestSetKeyComparator
( void );

/**
 * Tests the SHashSetKeyComparator function with an empty SHash
 *
 * @test Changing the key comparator in an empty SHash must return the hash
 * itself. The hash must still be empty after the call.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestSetKeyComparatorWithEmptySHash
( void );

/**
 * Tests the SHashSetKeyComparator function with an SHash having two keys that
 * are considered equal by the new comparator.
 *
 * @test Changing the key comparator in an SHash with two keys that are
 * considered identical by the new comparator must return the SHash. The size
 * of the hash must be reduced by one after the call. Calling SHashGet with one
 * of the keys must return the element mapped to the key. Calling SHashGet with
 * the other key must return NULL.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestSetKeyComparatorWithEqualKeys
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

/**
 * Tests the SHashToString function an empty SHash.
 *
 * @test An empty SHash must return a string of "{}";
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestToStringWithEmptySHash
( void );

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
( void );

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
( void );

#endif
