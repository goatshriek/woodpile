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
  const hasher_t hasher; /**< the function to use to hash keys */
  void **values; /**< the elements */
};

#endif
