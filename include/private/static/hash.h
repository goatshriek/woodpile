#ifndef __WOODPILE_PRIVATE_STATIC_HASH_H
#define __WOODPILE_PRIVATE_STATIC_HASH_H

/**
 * @file
 * SHash definition
 */

#include <woodpile/static/hash.h>

/** the Static Stack container */
struct StaticStack {
  size_t capacity; /**< the number of elements the hash can hold */
  const comparator_t compare; /**< the key comparison function */
  const folder_t fold; /**< the folding function */
  const hasher_t hash; /**< the hashing function */
  void **values; /**< the elements */
};

#endif
