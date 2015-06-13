#ifndef __WOODPILE_PRIVATE_DYNAMIC_TREE_SPLAY_H
#define __WOODPILE_PRIVATE_DYNAMIC_TREE_SPLAY_H

/**
 * @file
 * Splay definition
 */

#include <stdint.h>

struct Node;

typedef struct Node Node;

/** the Splay container */
struct Splay {
  Node *root; /**< the root Node of the tree */
};

/**
 * A node in the Splay, representing a single value.
 */
struct Node {
  Node *left_child; /**< the Node's left childe */
  Node *parent; /**< the Node's parent */
  Node *right_child; /**< the Node's right child */
  void *element; /**< the element held by the Node */
};

#endif
