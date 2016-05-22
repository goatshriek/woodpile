#ifndef __WOODPILE_PRIVATE_DYNAMIC_TREE_SPLAY_H
#define __WOODPILE_PRIVATE_DYNAMIC_TREE_SPLAY_H

/**
 * @file
 * Splay definition
 */

#include <stdint.h>
#include <woodpile/dynamic/tree/splay.h>

struct node_t;

typedef struct node_t node_t;

/** the Splay container */
struct dsplay_t {
  comparator_t compare; /**< the comparator used for elements */
  node_t *root; /**< the root Node of the tree */
};

/**
 * A node in the Splay, representing a single value.
 */
struct node_t {
  node_t *left_child; /**< the Node's left childe */
  node_t *parent; /**< the Node's parent */
  node_t *right_child; /**< the Node's right child */
  void *element; /**< the element held by the Node */
};

/**
 * Gets the next node from the given node.
 *
 * @param node the node to start from
 *
 * @return the next node from the given point
 */
const node_t *
ConstNextNode
( const node_t *node );

/**
 * Gets the previous node from the given node.
 *
 * @param node the node to start from
 *
 * @return the previous node from the given point
 */
const node_t *
ConstPreviousNode
( const node_t *node );

/**
 * Creates a copy of a tree.
 *
 * @param root the root of the tree
 *
 * @return the copy of the original node
 */
static
node_t *
CopyTree
( const node_t *root );

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
( node_t *node );

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
( node_t *node );

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
( node_t *node );

/**
 * Removes the given node from its tree.
 *
 * @param node the node to remove
 */
void
DestroyNode
( node_t *node );

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
( node_t *node );

/**
 * Destroys a tree, including all of its nodes.
 *
 * @param root the root of the tree
 */
static
void
DestroyTree
( const node_t *root );

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
node_t *
FindNode
( node_t *root, const void *element, comparator_t compare );

/**
 * Performs a left rotation about a node.
 *
 * @param node the node to rotate around
 */
static
void
LeftRotate
( node_t *node );

/**
 * Gets the next node from the given node.
 *
 * @param node the node to start from
 *
 * @return the next node from the given point
 */
node_t *
NextNode
( node_t *node );

/**
 * Gets the previous node from the given node.
 *
 * @param node the node to start from
 *
 * @return the previous node from the given point
 */
node_t *
PreviousNode
( node_t *node );

/**
 * Performs a right rotation about a node.
 *
 * @param node the node to rotate around
 */
static
void
RightRotate
( node_t *node );

/**
 * Moves a node to the top of its tree by a series of right and left rotations.
 * Note that this function does not update root of the splay that the node
 * belongs to.
 *
 * @param node the node to splay
 */
void
Splay
( node_t *node );

/**
 * Finds the maximum node of a given tree.
 *
 * @param root the root of the tree
 *
 * @return the maximum node of the tree
 */
static
node_t *
TreeMaximum
( node_t *root );

/**
 * Finds the minimum node of a given tree.
 *
 * @param root the root of the tree
 *
 * @return the minimum node of the tree
 */
static
node_t *
TreeMinimum
( node_t *root );

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
( node_t *root );

#endif
