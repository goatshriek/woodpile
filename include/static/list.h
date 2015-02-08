#ifndef __WOODPILE_STATIC_LIST_H
#define __WOODPILE_STATIC_LIST_H

#include <stdint.h>
#include <woodpile/list.h>

struct Node;
typedef struct Node Node;

#define XORNODES( first, second )                                              \
( ( Node * ) ( ( ( intptr_t ) ( first ) ) ^ ( ( intptr_t ) ( second ) ) ) )

struct List {
  Node * first;
  Node * last;
};

struct Node {
  Node * neighbors;
  void * value;
};

static
void
DestroyNodes
( Node *, Node * );

static
void *
SeparateNodes
( Node *, Node *, void * );

#endif
