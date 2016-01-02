#ifndef __WOODPILE_PRIVATE_STATIC_HASH_H
#define __WOODPILE_PRIVATE_STATIC_HASH_H

/**
 * @file
 * SHash definition
 */

#include <woodpile/static/hash.h>

/** the Static Stack container */
struct StaticHash {
  size_t capacity; /**< the number of elements the hash can hold */
  comparator_t compare; /**< the key comparison function */
  folder_t fold; /**< the folding function */
  hasher_t hash; /**< the hashing function */
  void **values; /**< the elements */
};

#endif
