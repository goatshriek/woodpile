#ifndef __WOODPILE_STATIC_QUEUE_H
#define __WOODPILE_STATIC_QUEUE_H

/** the Queue container */
struct Queue {
  size_t back; /**< the index of the back element + 1 */
  size_t capacity; /**< the max number of elements held */
  void **elements; /**< the elements */
  size_t front; /**< the index of the front element */
};

#endif
