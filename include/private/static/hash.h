#ifndef __WOODPILE_PRIVATE_STATIC_HASH_H
#define __WOODPILE_PRIVATE_STATIC_HASH_H

/**
 * @file
 * SHash definition
 */

#include <woodpile/static/hash.h>

/** the Static Hash container */
struct SHash {
  size_t capacity; /**< the number of elements the hash can hold */
  comparator_t compare_keys; /**< the key comparison function */
  comparator_t compare_elements; /**< the element comparison function */
  folder_t fold; /**< the folding function */
  hasher_t hash; /**< the hashing function */
  unsigned long long seed; /**< the seed to use for hashes */
  size_t size; /**< the number of elements currently in the hash */
  void **values; /**< the elements */
};

/**
 * Gets the index of a key.
 *
 * @param hash the SHash to use for the index. Must not be NULL.
 * @param key the key to use for the index. Must not be NULL.
 *
 * @return the index of the key
 */
static
unsigned long long
SHashGetIndex
( const SHash *hash, const void *key );

/**
 * Rehashes the keys in an SHash. This is required whenever changes are made
 * to a hash such that the way in which elements are mapped to keys is changed,
 * for example by a change in hash capacity or the specification of a new
 * new hashing function.
 *
 * This is a costly operation and should be avoided if possible.
 *
  * @param hash the SHash to rehash. Must not be NULL.
  *
  * @return the SHash that was rehashed
 */
static
SHash *
SHashRehash
( SHash *hash );

/**
 * Resolves a collision in the given SHash. Assumes that hash is not full, that
 * is that the hash has enough capacity for a new element.
 *
 * @param hash the SHash with the collision. Must not be NULL.
 * @param key the new key causing the collision. Must not be NULL.
 * @param index the original index of the key
 *
 * @return the index to use for the key that resolves the collision
 */
static
unsigned long long
SHashResolveCollision
( const SHash *hash, const *key, unsigned long long index );

#endif
