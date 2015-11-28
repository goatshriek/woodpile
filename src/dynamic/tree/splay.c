#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <woodpile/dynamic/tree/splay.h>
#include "lib/str.h"
#include "lib/validate.h"
#include "private/dynamic/tree/splay.h"

DSplay *
DSplayAdd
( DSplay *splay, void *element )
{
  int comparison;
  Node *current_node, *new_node, *parent;

  VALIDATE_PARAMETERS( splay )

  if( !element )
    return splay;

  parent = NULL;
  current_node = splay->root;
  while( current_node ){
    comparison = splay->compare( element, current_node->element );
    if( comparison == 0 )
      return splay;

    parent = current_node;
    if( comparison < 0 )
      current_node = current_node->left_child;
    else
      current_node = current_node->right_child;
  }

  new_node = malloc( sizeof( Node ) );
  if( !new_node )
    return NULL;

  if( parent ){
    if( comparison < 0 )
      parent->left_child = new_node;
    else
      parent->right_child = new_node;
  }

  new_node->left_child = NULL;
  new_node->right_child = NULL;
  new_node->element = element;
  new_node->parent = parent;

  Splay( new_node );
  splay->root = new_node;
  return splay;
}

unsigned short
DSplayContains
( DSplay *splay, const void *element )
{
  Node *node;

  if( splay == NULL || element == NULL )
    return 0;

  node = FindNode( splay->root, element, splay->compare );

  if( node ){
    Splay( node );
    splay->root = node;
    return 1;
  } else {
    return 0;
  }
}

DSplay *
DSplayCopy
( const DSplay *splay )
{
  DSplay *copy;

  VALIDATE_PARAMETERS( splay )

  copy = malloc( sizeof( DSplay ) );
  if( !copy )
    return NULL;

  copy->root = CopyTree( splay->root );
  copy->root->parent = NULL;
  copy->compare = splay->compare;

  return copy;
}

void
DSplayDestroy
( const DSplay *splay )
{
  if( !splay )
    return;

  DestroyTree( splay->root );

  free( ( void * ) splay );
}

void *
DSplayFirst
( const DSplay *splay )
{
  Node *node;
  void *element = NULL;

  VALIDATE_PARAMETERS( splay )

  if( !splay->root )
    return NULL;

  node = splay->root;
  while( node->left_child ){
    node = node->left_child;
  }

  return node->element;
}

void *
DSplayLast
( const DSplay *splay )
{
  Node *node;
  void *element = NULL;

  VALIDATE_PARAMETERS( splay )

  if( !splay->root )
    return NULL;

  node = splay->root;
  while( node->right_child ){
    node = node->right_child;
  }

  return node->element;
}

unsigned short
DSplayIsEmpty
( const DSplay *splay )
{
  return ( ( splay == NULL ) || ( splay->root == NULL ) );
}

size_t
DSplaySize
( const DSplay *splay )
{
  if( !splay )
    return 0;
  else
    return TreeSize( splay->root );
}

char *
DSplayToString
( const DSplay *splay, to_string_t element_to_string )
{
  char *str;
  const char *element;
  const Node *current, *next;
  size_t element_length, str_capacity=100, str_length=1;

  VALIDATE_PARAMETERS( splay )

  if( !element_to_string )
    element_to_string = strpointer;

  str = malloc( sizeof( char ) * str_capacity );
  if( !str )
    return NULL;
  str[0] = '[';

  current = NULL;
  next = splay->root;
  while( next ){
    current = next;
    next = next->left_child;
  }

  while( current ){
    element = element_to_string( current->element );
    element_length = strlen( element );

    while( str_capacity < str_length + element_length + 2 ){
      str_capacity *= 2;
      str = realloc( str, str_capacity );
    }

    memcpy( str + str_length, element, element_length * sizeof( char ) );
    str_length += element_length;
    free( ( void * ) element );

    current = ConstNextNode( current );

    if( current ){
      str[str_length++] = ',';
      str[str_length++] = ' ';
    }
  }

  if( str_capacity != str_length + 2 ){
    str = realloc( str, str_length + 2 );
  }

  str[str_length++] = ']';
  str[str_length] = '\0';

  return str;
}

DSplay *
DSplayNew
( comparator_t compare )
{
  DSplay *splay;

  splay = malloc( sizeof( DSplay ) );
  if( !splay )
    return NULL;
 
  splay->root = NULL;
  splay->compare = compare ? compare : DirectCompare;
 
  return splay;
}

void *
DSplayRemove
( DSplay *splay, const void *element )
{
  Node *node, *parent, *root;
  int comparison;
  void *removed;

  VALIDATE_PARAMETERS( splay && element )

  parent = NULL;
  node = splay->root;
  while( node ){
    comparison = splay->compare( element, node->element );
    if( comparison == 0 ){
      removed = node->element;
      if( parent ){
        root = parent;
      } else if( node->left_child ){
        root = node->left_child;
      } else if( node->right_child ){
        root = node->right_child;
      } else {
        DestroyNode( node );
        splay->root = NULL;
        return removed;
      }

      DestroyNode( node );
      Splay( root );
      splay->root = root;
      return removed;
    }

    parent = node;
    if( comparison < 0 )
      node = node->left_child;
    else
      node = node->right_child;
  }

  return NULL;
}

const Node *
ConstNextNode
( const Node *node )
{
  const Node *next, *previous;

  if( node->right_child )
    return TreeMinimum( node->right_child );

  previous = node;
  next = node->parent;

  while( next ){
    if( previous == next->left_child )
      return next;

    previous = next;
    next = next->parent;
  }

  return NULL;
}

const Node *
ConstPreviousNode
( const Node *node )
{
  const Node *next, *previous;

  if( node->left_child )
    return TreeMaximum( node->left_child );

  previous = node;
  next = node->parent;

  while( next ){
    if( previous == next->right_child )
      return next;

    previous = next;
    next = next->parent;
  }

  return NULL;
}

static
Node *
CopyTree
( const Node *root )
{
  Node *copy;

  copy = malloc( sizeof( Node ) );
  if( !copy )
    return NULL;

  if( root->left_child ){
    copy->left_child = CopyTree( root->left_child );
    copy->left_child->parent = copy;
  } else {
    copy->left_child = NULL;
  }

  if( root->right_child ){
    copy->right_child = CopyTree( root->right_child );
    copy->right_child->parent = copy;
  } else {
    copy->right_child = NULL;
  }
  copy->element = root->element;

  return copy;
}

static
void
DestroyFullNode
( Node *node )
{
  Node *replacement;

  replacement = TreeMaximum( node->left_child );
  node->element = replacement->element;

  DestroyNode( replacement );
}

static
void
DestroyLeafNode
( Node *node )
{
  if( node->parent ){
    if( node == node->parent->left_child )
      node->parent->left_child = NULL;
    else
      node->parent->right_child = NULL;
  }

  free( node );
}

static
void
DestroyLeftParentNode
( Node *node )
{
  if( node->parent ){
    if( node == node->parent->left_child )
      node->parent->left_child = node->left_child;
    else
      node->parent->right_child = node->left_child;
  }

  node->left_child->parent = node->parent;

  free( node );
}

void
DestroyNode
( Node *node )
{
  if( !node )
    return;

  if( node->left_child && node->right_child )
    DestroyFullNode( node );
  else if( node->left_child )
    DestroyLeftParentNode( node );
  else if( node->right_child )
    DestroyRightParentNode( node );
  else
    DestroyLeafNode( node );
}

static
void
DestroyRightParentNode
( Node *node )
{
  if( node->parent ){
    if( node == node->parent->left_child )
      node->parent->left_child = node->right_child;
    else
      node->parent->right_child = node->right_child;
  }

  node->right_child->parent = node->parent;

  free( node );
}

static
void
DestroyTree
( const Node *root )
{
  if( !root )
    return;

  DestroyTree( root->left_child );
  DestroyTree( root->right_child );

  free( ( void * ) root );
}

static inline
int
DirectCompare
( const void *element_1, const void *element_2 )
{
  return ( int ) ( element_1 - element_2 );
}

static
Node *
FindNode
( Node *node, const void *element, comparator_t compare )
{
  int comparison;

  if( !node || !compare )
    return NULL;

  comparison = compare( element, node->element );

  if( comparison == 0 )
    return node;

  if( comparison < 0 )
    return FindNode( node->left_child, element, compare );
  else
    return FindNode( node->right_child, element, compare );
}

static
void
LeftRotate
( Node *node )
{
  Node *old_right;

  old_right = node->right_child;
  node->right_child = old_right->left_child;

  if( old_right->left_child )
    old_right->left_child->parent = node;

  old_right->parent = node->parent;

  if( node->parent ){
    if( node == node->parent->left_child )
      node->parent->left_child = old_right;
    else
      node->parent->right_child = old_right;
  }

  old_right->left_child = node;
  node->parent = old_right;
}

Node *
NextNode
( Node *node )
{
  Node *next, *previous;

  if( node->right_child )
    return TreeMinimum( node->right_child );

  previous = node;
  next = node->parent;

  while( next ){
    if( previous == next->left_child )
      return next;

    previous = next;
    next = next->parent;
  }

  return NULL;
}

Node *
PreviousNode
( Node *node )
{
  Node *next, *previous;

  if( node->left_child )
    return TreeMaximum( node->left_child );

  previous = node;
  next = node->parent;

  while( next ){
    if( previous == next->right_child )
      return next;

    previous = next;
    next = next->parent;
  }

  return NULL;
}

static
void
RightRotate
( Node *node )
{
  Node *old_left;

  old_left = node->left_child;
  node->left_child = old_left->right_child;

  if( old_left->right_child )
    old_left->right_child->parent = node;

  old_left->parent = node->parent;

  if( node->parent ){
    if( node == node->parent->left_child )
      node->parent->left_child = old_left;
    else
      node->parent->right_child = old_left;
  }

  old_left->right_child = node;
  node->parent = old_left;
}

void
Splay
( Node *node )
{
  if( !node->parent )
    return;

  if( !node->parent->parent ){
    if( node->parent->left_child == node )
      RightRotate( node->parent );
    else
      LeftRotate( node->parent );
  } else if( node->parent->left_child == node
             && node->parent->parent->left_child == node->parent ){
    RightRotate( node->parent->parent );
    RightRotate( node->parent );
  } else if( node->parent->right_child == node
             && node->parent->parent->right_child == node->parent ){
    LeftRotate( node->parent->parent );
    LeftRotate( node->parent );
  } else if( node->parent->left_child == node
             && node->parent->parent->right_child == node->parent ){
    RightRotate( node->parent );
    LeftRotate( node->parent );
  } else {
    LeftRotate( node->parent );
    RightRotate( node->parent );
  }

  Splay( node );
}

static
Node *
TreeMaximum
( Node *root )
{
  if( !root->right_child )
    return root;
  
  return TreeMaximum( root->right_child );
}

static
Node *
TreeMinimum
( Node *root )
{
  if( !root->left_child )
    return root;
  
  return TreeMinimum( root->left_child );
}

static
size_t
TreeSize
( Node *root )
{
  if( !root )
    return 0;
  else
    return 1 + TreeSize( root->left_child ) + TreeSize( root->right_child );
}
