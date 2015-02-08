#ifndef __WOODPILE_STATIC_STACK_H
#define __WOODPILE_STATIC_STACK_H

/** the Stack container */
struct Stack {
  size_t capacity; /**< the number of elements the Stack can hold */
  size_t top; /**< the index of the top element + 1 */
  void **values; /**< the elements */
};

#endif
