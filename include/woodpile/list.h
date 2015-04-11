#ifndef __WOODPILE_LIST_H
#define __WOODPILE_LIST_H

/**
 * @file
 * List declaration and functions
 */

/**
 * @struct List
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
 * Creates a copy of a List. Elements within the List are not copied, meaning
 * that changes made to elements in the original List will also change the
 * elements in the copy. Changes made to the original List will not affect the
 * copy.
 *
 * @param list the List to copy
 * 
 * @return a copy of the original List or NULL on failure
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
( const List *list );

/**
 * Gets the last element in the List.
 *
 * @param list the List to get the element from
 *
 * @return the last element of list, or NULL if list is empty
 */
void *
ListBack
( const List *list );

/**
 * Searches a List for an element.
 *
 * Note that the element is identified using a pointer; if two structures are
 * considered equal but are located at different addresses then they are not
 * considered equal by this function.
 *
 * @param list the List to search
 * @param element the element to search for
 *
 * @return the number of entries of element in list
 */
size_t
ListContains
( const List *list, const void *element );

/**
 * Gets the first element in the List.
 *
 * @param list the List to get the element from
 *
 * @return the first element of list, or NULL if list is empty
 */
void *
ListFront
( const List *list );

/**
 * Gets the element at the specified position in the List. If the list does not
 * have an element at this index then NULL is returned. NULL is returned if
 * list is NULL.
 *
 * Negative indexes count backwards through the list, for example an index of
 * -2 returns the second to last value in the list.
 *
 * Both positive and negative indexes will wrap around if greater than the size
 * of the List. For example, if the List contains 3 elements, then an index of
 * 4 will return the second element in the List. Likewise, an index of -4 will
 * return the last element in the List.
 *
 * @param list the List to get the element from
 * @param index the index of the element to retrieve
 *
 * @return the element of the List at the given index, or NULL if it does not
 * exist
 */
void *
ListGet
( const List *list, int index );

/**
 * Checks whether or not a List is empty. A NULL List is considered empty.
 *
 * @param list the List to check
 *
 * @return a positive value if the List is empty, 0 otherwise
 */
unsigned short
ListIsEmpty
( const List *list );

/**
 * Gets the number of elements in the List. An empty List will return 0.
 *
 * @param list the List to get the size of
 *
 * @return the number of elements in the List
 */
unsigned
ListSize
( const List *list );

/**
 * Creates a string representation of the given List, using the provided
 * function to get the string representation of each element. If the
 * element_to_string function is NULL, then the element is printed as a void
 * pointer.
 *
 * The list is enclosed in square brackets, and elements within the list are
 * separated by a comma and space as shown here:
 * [element_1, element_2, element_3]
 *
 * The element_to_string function must create new strings that can be
 * deallocated with a call to free. For example, if the elements themselves are
 * string literals, then the function must return a copy of the string rather
 * than the string itself.
 *
 * @param list the List to get a representation of
 * @param element_to_string a function returning string representations of
 * elements
 *
 * @return a char buffer holding a string representation of the List
 */
char *
ListToString
( const List *list, char * ( *element_to_string )( const void * ) );

/**
 * Creates a new List.
 * 
 * @return a new List or NULL on failure
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
