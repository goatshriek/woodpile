#include <stdlib.h>
#include <woodpile/static/hash.h>
#include "private/static/hash.h"


/**
 * Creates a copy of a SHash. Elements within the hash are not copied, meaning
 * that changes made to elements in the original hash will also change the
 * elements in the copy. Changes made to the original hash will not affect the
 * copy.
 *
 * @param hash the SHash to copy
 *
 * @return the copy of the original SHash or NULL on failure
 */
SHash *
SHashCopy
( const SHash *hash )
{
  return NULL;
}

/**
 * Destroys a SHash. Does not affect the elements stored in the hash.
 *
 * @param hash the SHash to destroy
 */
void
SHashDestroy
( const SHash *hash )
{
  return;
}

/**
 * Retrieves the value mapped to a given key. If the key does not exist in the
 * hash, then NULL is returned.
 *
 * @param hash the SHash to query
 * @param key the key that the requested value is mapped to
 *
 * @return the value mapped to the provided key, or NULL if there is no such
 * value
 */
void *
SHashGet
( const SHash *hash, const void *key )
{
  return NULL;
}

/**
 * Creates a new SHash. The default capacity of the hash is 100. If the hashing
 * function is NULL, then a default function is used based on element's pointer
 * values.
 *
 * @param hasher the hashing function to use on keys
 *
 * @return a new SHash or NULL on failure
 */
SHash *
SHashNew
( const hasher_t hasher )
{
  return NULL;
}

/**
 * Creates a new SHash of the given capacity.
 *
 * @param hasher the hashing function to use on keys
 * @param capacity the capacity to give the SHash
 *
 * @return a new SHash of the provided capacity, or NULL on failure
 */
SHash *
SHashNewSized
( const hasher_t hasher, size_t capacity )
{
  return NULL;
}

/**
 * Adds an element into the provided SHash. The provided key and value pair are
 * assigned. If the key is already associated with the value, then the key is
 * re-associated with the new value, effectively removing the previous value.
 * This previous value is returned if it exists.
 *
 * @param hash the SHash to set the key for
 * @param key the value to use as the key
 * @param value the value to associate with the key
 *
 * @return value, if the key was properly set and no equivalent key was already
 * set. If the key was already associated with a value, that value is returned.
 */
void *
SHashPut
( SHash *hash, void *key, void *value )
{
  return NULL;
}

/**
 * Removes the element mapped to the given key. If there is no such element,
 * then the hash is left unchanged.
 *
 * @param hash the SHash to remove the element from
 * @param key the key mapped to the value to remove
 *
 * @return the removed element, or NULL if there was not an element to remove
 */
void *
SHashRemove
( SHash *hash, const void *key )
{
  return NULL;
}

/**
 * Sets the hashing function for an SHash.
 *
 * @param hash the SHash to set the function for
 * @param hasher the hashing function to use
 */
void
SetStaticHashHasher
( SHash *hash, const hasher_t hasher )
{
  return;
}

/**
 * Gets the current capacity of the SHash.
 *
 * @param hash the SHash to get the capacity of
 *
 * @return the current capacity of the SHash
 */
size_t
SHashCapacity
( const SHash *hash )
{
  return 0;
}

/**
 * Searches a SHash for a given value. If the value exists in the hash, one of
 * the keys mapped to the value is returned. If the value exists in the hash
 * multiple times (therefore with multiple keys), there is no guarantee of which
 * key will be returned or that the same key will be returned each time.
 *
 * @param hash the SHash to search
 * @param value the value to search for
 *
 * @return a key for the value if it is in the hash, or NULL if not
 */
void *
SHashContains
( const SHash *hash, const void *value )
{
  return NULL;
}

/**
 * Checks a SHash to see if it's empty.
 *
 * @param hash the SHash to check
 *
 * @return a positive value if the SHash is empty, 0 otherwise
 */
unsigned short
SHashIsEmpty
( const SHash *hash )
{
  return 0;
}

/**
 * Gets the number of elements in a SHash. An empty hash will return 0.
 *
 * @param hash the SHash to measure
 *
 * @return the number of elements in the SHash
 */
size_t
SHashSize
( const SHash *hash )
{
  return 0;
}

/**
 * Creates a string representation of the given SHash, using the provided
 * function to get the string representation of each element.
 *
 * @param hash the SHash to get a representation of
 * @param element_to_string a function returining string representations of
 * elements
 *
 * @return a char buffer holding a string representation of the SHash
 */
char *
SHashHashToString
( const SHash *hash, char * ( *element_to_string )( const void * ) )
{
  return NULL;
}

/**
 * Changes a SHash's capacity, specifically the number of buckets.
 *
 * @param hash the SHash to resize
 * @param capacity the new capacity of the SHash
 *
 * @return the SHash having been resized
 */
SHash *
SHashSetCapacity
( SHash *hash, size_t capacity )
{
  return NULL;
}
