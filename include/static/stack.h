#ifndef __WOODPILE_STATIC_STACK_H
#define __WOODPILE_STATIC_STACK_H

struct Stack {
  size_t capacity;
  size_t top;
  void **values;
};

#endif
