#ifndef __WOODPILE_STATIC_HASH_H
#define __WOODPILE_STATIC_HASH_H

/**
 * @file
 * Hash declaration and functions
 */

#include <woodpile/comparator.h>
#include <woodpile/hasher.h>

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

struct SHash;
typedef struct SHash SHash;

/**
 * Gets the current capacity of the SHash.
 *
 * @param hash The SHash to get the capacity of. Must not be NULL.
 *
 * @return the current capacity of the SHash
 */
size_t
SHashCapacity
( const SHash *hash );

/**
 * Searches a SHash for a given element. If the element exists in the hash, one
 * of the keys mapped to the element is returned. If the element exists in the
 * hash multiple times (therefore with multiple keys), there is no guarantee of
 * which key will be returned or that the same key will be returned each time.
 *
 * To modify how this function compares elements use the
 * SetStaticHashElementComparator function with the desired comparator. By
 * default elements are compared using their pointer values.
 *
 * @param hash The SHash to search.
 * @param element The value to search for. Must not be NULL.
 *
 * @return a key for the value if it is in the hash, or NULL if not
 */
void *
SHashContains
( const SHash *hash, const void *element );

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
SHashCopy
( const SHash *hash );

/**
 * Destroys a SHash. Does not affect the elements stored in the hash.
 *
 * @param hash the SHash to destroy
 */
void
SHashDestroy
( const SHash *hash );

/**
 * Gets the comparator used to compare elements in the hash.
 *
 * @param hash the SHash using the comparator. Must not be NULL.
 *
 * @return the comparator the SHash is using
 */
comparator_t
SHashElementComparator
( const SHash *hash );

/**
 * Gets the folding function used in the hash.
 *
 * @param hash the SHash using the folding function. Must not be NULL.
 *
 * @return the folding function of the SHash
 */
folder_t
SHashFolder
( const SHash *hash );

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
SHashGet
( const SHash *hash, const void *key );

/**
 * Checks a SHash to see if it's empty.
 *
 * @param hash the SHash to check
 *
 * @return a positive value if the SHash is empty, 0 otherwise
 */
unsigned short
SHashIsEmpty
( const SHash *hash );

/**
 * Gets the comparator used to compare keys in the hash.
 *
 * @param hash the SHash using the comparator. Must not be NULL.
 *
 * @return the comparator the SHash is using for keys
 */
comparator_t
SHashKeyComparator
( const SHash *hash );

/**
 * Creates a new SHash. The default capacity of the hash is 256. If the hashing
 * function is NULL, then a default function is used based on element's pointer
 * values. If the folding function is NULL, then a simple XOR-based function is
 * used. If the comparator is NULL, then the pointers for keys are directly
 * compared.
 *
 * @return a new SHash or NULL on failure
 */
SHash *
SHashNew
( void );

/**
 * Creates a new SHash with hashing and key comparators set to functions
 * specialized for strings.
 *
 * @return a new SHash or NULL on failure
 */
SHash *
SHashNewDictionary
( void );

/**
 * Creates a new SHash of the given capacity. If the hashing function is NULL,
 * then a default function is used based on element's pointer values. If the
 * folding function is NULL, then a simple XOR-based function is used. If the
 * comparator is NULL, then the pointers for keys are directly compared.
 *
 * @param capacity the capacity to give the SHash
 *
 * @return a new SHash of the provided capacity, or NULL on failure
 */
SHash *
SHashNewSized
( size_t capacity );

/**
 * Adds an element into the provided SHash. The provided key and value pair are
 * assigned. If the key is already associated with the value, then the key is
 * re-associated with the new value, effectively removing the previous value.
 * This previous value is returned if it exists. A NULL value is equivalent to
 * calling the SHashRemove function with the provided key.
 *
 * @param hash The SHash to set the key for. Must not be NULL.
 * @param key The value to use as the key. Must not be NULL.
 * @param value The value to associate with the key.
 *
 * @return value, if the key was properly set and no equivalent key was already
 * set. If the key was already associated with a value, that value is returned.
 */
void *
SHashPut
( SHash *hash, void *key, void *value );

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
SHashRemove
( SHash *hash, const void *key );

/**
 * Changes a SHash's capacity, specifically the number of buckets.
 *
 * @param hash the SHash to resize. Must not be NULL.
 * @param capacity the new capacity of the SHash
 *
 * @return the SHash having been resized
 */
SHash *
SHashSetCapacity
( SHash *hash, size_t capacity );

/**
 * Sets the comparator used to compare elements held in a StaticHash. This
 * comparator is used whenever elements are compared, for things such as calls
 * to the StaticHashContains function.
 *
 * @param hash The SHash to update with the comparator. Must not be NULL.
 * @param comparator The new comparator to use for elements. Must not be NULL.
 *
 * @return the SHash with the updated comparator
 */
SHash *
SHashSetElementComparator
( SHash *hash, comparator_t comparator );

/**
 * Sets the folding function for an SHash.
 *
 * @param hash The SHash to update. Must not be NULL.
 * @param folder The folding function to use. Must not be NULL.
 */
SHash *
SHashSetFolder
( SHash *hash, folder_t folder );

/**
 * Sets the hashing function for an SHash.
 *
 * @param hash The SHash to update. Must not be NULL.
 * @param hasher The hashing function to use. Must not be NULL.
 */
SHash *
SHashSetHasher
( SHash *hash, hasher_t hasher );

/**
 * Sets the comparator used to compare keys in a SHash. This comparator is used
 * to compare keys to check for collisions and confirm that a hash has mapped
 * to the intended element.
 *
 * @param hash The SHash to update with the comparator. Must not be NULL.
 * @param comparator The new comparator to use for keys. Must not be NULL.
 *
 * @return the SHash with the updated comparator
 */
SHash *
SHashSetKeyComparator
( SHash *hash, comparator_t comparator );

/**
 * Sets the seed used for the SHash.
 *
 * @param hash The SHash to update with the seed. Must not be NULL.
 * @param seed the seed to use for the SHash
 *
 * @return the SHash with the updated seed
 */
SHash *
SHashSetSeed
( SHash *hash, unsigned long long seed );

/**
 * Gets the number of elements in a SHash. An empty hash will return 0.
 *
 * @param hash the SHash to measure
 *
 * @return the number of elements in the SHash
 */
size_t
SHashSize
( const SHash *hash );

/**
 * Creates a string representation of the given SHash, using the provided
 * function to get the string representation of each element.
 *
 * @param hash the SHash to get a representation of. Must not be NULL.
 * @param element_to_string a function returning string representations of
 * elements
 *
 * @return a char buffer holding a string representation of the SHash
 */
char *
SHashToString
( const SHash *hash, char * ( *element_to_string )( const void * ) );

#endif
