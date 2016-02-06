#ifndef __WOODPILE_PRIVATE_STATIC_HASH_H
#define __WOODPILE_PRIVATE_STATIC_HASH_H

/**
 * @file
 * SHash definition
 */

#include <woodpile/static/hash.h>

/** the Static Hash container */
struct StaticHash {
  size_t capacity; /**< the number of elements the hash can hold */
  comparator_t compare_keys; /**< the key comparison function */
  comparator_t compare_elements; /**< the element comparison function */
  folder_t fold; /**< the folding function */
  hasher_t hash; /**< the hashing function */
  size_t size; /**< the number of elements currently in the hash */
  void **values; /**< the elements */
};

/**
 * Rehashes the keys in an SHash into a new SHash. This is required whenever
 * changes are made to a hash such that the way in which elements are mapped
 * to keys is changed, for example by a change in hash capacity or the
 * specification of a new hashing function.
 *
 * This is a costly operation and should be avoided if possible.
 *
  * @param hash the SHash to rehash
  * @param previous the previous version of the hash
  *
  * @return the SHash that was rehashed
 */
static
SHash *
SHashTransfer
( SHash *hash, const SHash *previous );

#endif
