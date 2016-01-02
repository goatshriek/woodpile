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

#endif
