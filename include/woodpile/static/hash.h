#ifndef __WOODPILE_STATIC_HASH_H
#define __WOODPILE_STATIC_HASH_H

/**
 * @file
 * Hash declaration and functions
 */

/**
 * @struct Hash
 * The StaticHash data structure is an implementation of a hash map. Elements
 * are mapped from each other in a key-value pair. NULL keys and values are not
 * supported.
 *
 * Memory for the structure is allocated in large blocks, with the number of
 * entries being equal to the number of possible hash values. This means that
 * changing the number of possible hash values (buckets) requires all existing
 * elements to be re-hashed, in addition to the memory re-allocation. This means
 * that this process should be avoided if at all possible.
 *
 * Memory overhead can be calculated as follows:
 * depends on pending implementation
 */

struct StaticHash;
typedef struct StaticHash StaticHash;
typedef struct StaticHash SHash;

typedef unsigned long ( *hasher_t )( const void * );

/**
 * Creates a copy of a SHash. Elements within the hash are not copied, meaning
 * that changes made to elements in the original hash will also change the
 * elements in the copy. Changes made to the original hash will not affect the
 * copy.
 *
 * @param hash the SHash to copy. Must not be NULL.
 *
 * @return the copy of the original SHash or NULL on failure
 */
SHash *
CopyStaticHash
( const SHash *hash );
#define SHashCopy CopyStaticHash

/**
 * Destroys a SHash. Does not affect the elements stored in the hash.
 *
 * @param hash the SHash to destroy
 */
void
DestroyStaticHash
( const SHash *hash );
#define SHashDestroy DestroyStaticHash

/**
 * Retrieves the value mapped to a given key. If the key does not exist in the
 * hash, then NULL is returned.
 *
 * @param hash the SHash to query. Must not be NULL.
 * @param key the key that the requested value is mapped to. Must not be NULL.
 *
 * @return the value mapped to the provided key, or NULL if there is no such
 * value
 */
void *
GetFromStaticHash
( const SHash *hash, const void *key );
#define SHashGet GetFromStaticHash

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
NewStaticHash
( const hasher_t hasher );
#define SHashNew NewStaticHash

/**
 * Creates a new SHash of the given capacity.
 *
 * @param hasher the hashing function to use on keys
 * @param capacity the capacity to give the SHash
 *
 * @return a new SHash of the provided capacity, or NULL on failure
 */
SHash *
NewSizedStaticHash
( const hasher_t hasher, size_t capacity );
#define SHashNewSized NewSizedStaticHash

/**
 * Adds an element into the provided SHash. The provided key and value pair are
 * assigned. If the key is already associated with the value, then the key is
 * re-associated with the new value, effectively removing the previous value.
 * This previous value is returned if it exists. NULL key and value arguments
 * will ignored and the function will return NULL.
 *
 * @param hash The SHash to set the key for. Must not be NULL.
 * @param key The value to use as the key. Must not be NULL.
 * @param value The value to associate with the key. Must not be NULL.
 *
 * @return value, if the key was properly set and no equivalent key was already
 * set. If the key was already associated with a value, that value is returned.
 */
void *
PutIntoStaticHash
( SHash *hash, void *key, void *value );
#define SHashPut PutIntoStaticHash

/**
 * Removes the element mapped to the given key. If there is no such element,
 * then the hash is left unchanged.
 *
 * @param hash The SHash to remove the element from. Must not be NULL.
 * @param key The key mapped to the value to remove. Must not be NULL.
 *
 * @return the removed element, or NULL if there was not an element to remove
 */
void *
RemoveFromStaticHash
( SHash *hash, const void *key );
#define SHashRemove RemoveFromStaticHash

/**
 * Sets the hashing function for an SHash.
 *
 * @param hash The SHash to set the function for. Must not be NULL.
 * @param hasher The hashing function to use. Must not be NULL.
 */
void
SetStaticHashHasher
( SHash *hash, const hasher_t hasher );
#define SHashSetHasher SetStaticHashHasher

/**
 * Gets the current capacity of the SHash.
 *
 * @param hash The SHash to get the capacity of. Must not be NULL.
 *
 * @return the current capacity of the SHash
 */
size_t
StaticHashCapacity
( const SHash *hash );
#define SHashCapacity StaticHashCapacity

/**
 * Searches a SHash for a given value. If the value exists in the hash, one of
 * the keys mapped to the value is returned. If the value exists in the hash
 * multiple times (therefore with multiple keys), there is no guarantee of which
 * key will be returned or that the same key will be returned each time.
 *
 * @param hash The SHash to search. Must not be NULL.
 * @param value The value to search for. Must not be NULL.
 *
 * @return a key for the value if it is in the hash, or NULL if not
 */
void *
StaticHashContains
( const SHash *hash, const void *value );
#define SHashContains StaticHashContains

/**
 * Checks a SHash to see if it's empty.
 *
 * @param hash the SHash to check
 *
 * @return a positive value if the SHash is empty, 0 otherwise
 */
unsigned short
StaticHashIsEmpty
( const SHash *hash );
#define SHashIsEmpty StaticHashIsEmpty

/**
 * Gets the number of elements in a SHash. An empty hash will return 0.
 *
 * @param hash the SHash to measure
 *
 * @return the number of elements in the SHash
 */
size_t
StaticHashSize
( const SHash *hash );
#define SHashSize StaticHashSize

/**
 * Creates a string representation of the given SHash, using the provided
 * function to get the string representation of each element.
 *
 * @param hash the SHash to get a representation of. Must not be NULL.
 * @param element_to_string a function returining string representations of
 * elements
 *
 * @return a char buffer holding a string representation of the SHash
 */
char *
StaticHashToString
( const SHash *hash, char * ( *element_to_string )( const void * ) );
#define SHashToString StaticHashToString

/**
 * Changes a SHash's capacity, specifically the number of buckets.
 *
 * @param hash the SHash to resize. Must not be NULL.
 * @param capacity the new capacity of the SHash
 *
 * @return the SHash having been resized
 */
SHash *
SetStaticHashCapacity
( SHash *hash, size_t capacity );
#define SHashSetCapacity SetStaticHashCapacity

#endif
