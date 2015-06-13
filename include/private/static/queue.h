#ifndef __WOODPILE_PRIVATE_STATIC_QUEUE_H
#define __WOODPILE_PRIVATE_STATIC_QUEUE_H

/**
 * @file
 * StaticQueue definition
 */

/** the Queue container */
struct StaticQueue {
  size_t back; /**< the index of the back element + 1 */
  size_t capacity; /**< the max number of elements held */
  void **elements; /**< the elements */
  size_t front; /**< the index of the front element */
};

#endif
