#ifndef __WOODPILE_LIST_H
#define __WOODPILE_LIST_H

/**
 * @file
 * Declaration and functions for the List container.
 */

/**
 * The List data structure is a simple doubly linked list implementation.
 *
 * The List is optimized for insertions and deletions at either end, and
 * sequential walks via the iterators. If random access is needed then the
 * ArrayList structure is more suitable.
 *
 * Memory for this structure is allocated dynamically, allowing it to grow and
 * shrink along with the number of elements it holds. This makes it suitable for
 * use when the size is constantly changing; if a more static list size is
 * needed then the ArrayList structure would be more efficient as its memory
 * overhead is lower.
 *
 * Memory overhead can be calculated as follows:
 * 2 * sizeof( void * ) * ( number_of_elements + 1 )
 */
struct List;
typedef struct List List;

/**
 * Appends all elements in the second list to the end of the first. The second
 * list is not changed as a result of the operation. The elements are appended
 * in the order they exist in the second list.
 *
 * @param first the List to append to
 * @param second the List to append
 *
 * @return first
 */
List *
AppendAllToList
( List *first, const List *second );

/**
 * Adds a single element to the end of a List. If element is NULL then nothing
 * is done.
 *
 * @param list the List to append to
 * @param element the element to append
 * 
 * @return list
 */
List *
AppendToList
( List *list, void *element );

/**
 * Creates a copy of a List. Elements within the List are not reproduced,
 * meaning that changes made to elements in the original List will also change
 * the elements in the copy. Changes made to the original List will not affect
 * the copy.
 *
 * @param list the List to copy
 * 
 * @return a new List that is a copy of the original
 */
List *
CopyList
( const List *list );

/**
 * Destroys a List. Does not affect the elements stored in the List.
 *
 * @param list the List to destroy
 */
void
DestroyList
( List *list );

/**
 * Gets the last element in the List.
 *
 * @param list the List to get the element from
 *
 * @return the last element of list, or NULL if list is empty
 */
void *
GetListBack
( const List *list );

/**
 * Gets the first element in the List.
 *
 * @param list the List to get the element from
 *
 * @return the first element of list, or NULL if list is empty
 */
void *
GetListFront
( const List *list );

/**
 * Gets the number of elements in the List.
 *
 * @param list the List to get the size of
 *
 * @return the number of elements in the List
 */
unsigned
GetListSize
( const List *list );

/**
 * Searches a List for an element.
 *
 * Note that the element is identified using a pointer; if two structures are
 * considered equal but are located at different addresses then they are not
 * considered equal by this function.
 *
 * @param list theList to search
 * @param element the element to search for
 *
 * @return 0 if the List does not contain the given element, or the number of
 * entries of the element in the Stack if it does
 */
unsigned short
ListContains
( const List *list, const void *element );

/**
 * Checks whether or not a List is empty.
 *
 * @param list the List to check
 *
 * @return a positive value if the List is empty, 0 otherwise
 */
unsigned short
ListIsEmpty
( const List *list );

/**
 * Creates a new List.
 * 
 * @return a new List, or NULL if an error occurred
 */
List *
NewList
( void );

/**
 * Adds a single element to the beginning of a List. If element is NULL then
 * nothing is done.
 *
 * @param list the List to prepend to
 * @param element the element to prepend
 * 
 * @return list
 */
List *
PrependToList
( List *list, void *element );

#endif
