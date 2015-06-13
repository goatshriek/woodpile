#ifndef __WOODPILE_PRIVATE_STATIC_STACK_H
#define __WOODPILE_PRIVATE_STATIC_STACK_H

/**
 * @file
 * Stack definition
 */

#include <woodpile/static/stack.h>

/** the Stack container */
struct StaticStack {
  size_t capacity; /**< the number of elements the Stack can hold */
  size_t top; /**< the index of the top element + 1 */
  void **values; /**< the elements */
};

/**
 * Doubles the capacity of a Stack.
 *
 * @param stack the Stack to enlarge
 *
 * @return stack or NULL if memory is not available
 */
static
SStack *
Resize
( SStack *stack );

#endif
