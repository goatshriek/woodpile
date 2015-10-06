#ifndef __WOODPILE_PRIVATE_DYNAMIC_TREE_SPLAY_H
#define __WOODPILE_PRIVATE_DYNAMIC_TREE_SPLAY_H

/**
 * @file
 * Splay definition
 */

#include <stdint.h>
#include <woodpile/dynamic/tree/splay.h>

struct Node;

typedef struct Node Node;

/** the Splay container */
struct DynamicSplay {
  comparator_t compare; /**< the comparator used for elements */
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

/**
 * Gets the next node from the given node.
 *
 * @param node the node to start from
 *
 * @return the next node from the given point
 */
const Node *
ConstNextNode
( const Node *node );

/**
 * Gets the previous node from the given node.
 *
 * @param node the node to start from
 *
 * @return the previous node from the given point
 */
const Node *
ConstPreviousNode
( const Node *node );

/**
 * Creates a copy of a tree.
 *
 * @param root the root of the tree
 *
 * @return the copy of the original node
 */
static
Node *
CopyTree
( const Node *root );

/**
 * Removes the given node from its tree.
 *
 * @pre the node must have two children
 *
 * @param node the node to remove
 */
static
void
DestroyFullNode
( Node *node );

/**
 * Removes the given node from its tree.
 *
 * @pre the node must not have any children
 *
 * @param node the node to remove
 */
static
void
DestroyLeafNode
( Node *node );

/**
 * Removes the given node from its tree.
 *
 * @pre the node must have only a left child
 *
 * @param node the node to remove
 */
static
void
DestroyLeftParentNode
( Node *node );

/**
 * Removes the given node from its tree.
 *
 * @param node the node to remove
 */
void
DestroyNode
( Node *node );

/**
 * Removes the given node from its tree.
 *
 * @pre the node must have only a right child
 *
 * @param node the node to remove
 */
static
void
DestroyRightParentNode
( Node *node );

/**
 * Destroys a tree, including all of its nodes.
 *
 * @param root the root of the tree
 */
static
void
DestroyTree
( const Node *root );

/**
 * Directly compares two pointers.
 *
 * @param element_1 the first element to compare
 * @param element_2 the second element to compare
 *
 * @return a negative value if element_1 is lower, a positive value if element_2
 * is lower, and 0 if the two are equal.
 */
static inline
int
DirectCompare
( const void *element_1, const void *element_2 );

/**
 * Searches a tree for a node with a value equal to element according to the
 * provided comparator.
 *
 * @param root the root of the tree to search
 * @param element the element to search for
 * @param compare the comparator to use to compare elements
 *
 * @return the child node holding element, or NULL if one does not exist
 */
static
Node *
FindNode
( Node *root, const void *element, comparator_t compare );

/**
 * Performs a left rotation about a node.
 *
 * @param node the node to rotate around
 */
static
void
LeftRotate
( Node *node );

/**
 * Gets the next node from the given node.
 *
 * @param node the node to start from
 *
 * @return the next node from the given point
 */
Node *
NextNode
( Node *node );

/**
 * Gets the previous node from the given node.
 *
 * @param node the node to start from
 *
 * @return the previous node from the given point
 */
Node *
PreviousNode
( Node *node );

/**
 * Performs a right rotation about a node.
 *
 * @param node the node to rotate around
 */
static
void
RightRotate
( Node *node );

/**
 * Moves a node to the top of its tree by a series of right and left rotations.
 * Note that this function does not update root of the splay that the node
 * belongs to.
 *
 * @param node the node to splay
 */
void
Splay
( Node *node );

/**
 * Finds the maximum node of a given tree.
 *
 * @param root the root of the tree
 *
 * @return the maximum node of the tree
 */
static
Node *
TreeMaximum
( Node *root );

/**
 * Finds the minimum node of a given tree.
 *
 * @param root the root of the tree
 *
 * @return the minimum node of the tree
 */
static
Node *
TreeMinimum
( Node *root );

/**
 * Finds the number of nodes in a given tree.
 *
 * @param root the root of the tree
 *
 * @return the number of nodes in the tree
 */
static
size_t
TreeSize
( Node *root );

#endif
