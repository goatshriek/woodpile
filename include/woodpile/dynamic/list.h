#ifndef __WOODPILE_DYNAMIC_LIST_H
#define __WOODPILE_DYNAMIC_LIST_H

/**
 * @file
 * DList declaration and functions
 */

/**
 * @struct dlist_t
 * The DList data structure is a simple doubly linked list implementation.
 *
 * The DList is optimized for insertions and deletions at either end, and
 * sequential walks via the iterators. If random access is needed then the
 * StaticList structure is more suitable.
 *
 * Memory for this structure is allocated dynamically, allowing it to grow and
 * shrink along with the number of elements it holds. This makes it suitable for
 * use when the size is constantly changing; if a more static list size is
 * needed then the StaticList structure would be more efficient as its memory
 * overhead is lower.
 *
 * Memory overhead can be calculated as follows:
 * 2 * sizeof( void * ) * ( number_of_elements + 1 )
 */
struct dlist_t;
typedef struct dlist_t dlist_t;

/**
 * Adds a single element to the end of a DList. If element is NULL then
 * nothing is done.
 *
 * @param list the DList to append to. Must not be NULL.
 * @param element the element to append
 *
 * @return list
 */
dlist_t *
DListAppend
( dlist_t *list, void *element );

/**
 * Appends all elements in the second DList to the end of the first. The
 * second list is not changed as a result of the operation. The elements are
 * appended in the order they exist in the second DList.
 *
 * @param first the DList to append to. Must not be NULL.
 * @param second the DList to append
 *
 * @return first
 */
dlist_t *
DListAppendAll
( dlist_t *first, const dlist_t *second );

/**
 * Gets the last element in the DList.
 *
 * @param list the DList to get the element from. Must not be NULL.
 *
 * @return the last element of list, or NULL if list is empty
 */
void *
DListBack
( const dlist_t *list );

/**
 * Searches a DList for an element.
 *
 * Note that the element is identified using a pointer; if two structures are
 * considered equal but are located at different addresses then they are not
 * considered equal by this function.
 *
 * @param list the DList to search
 * @param element the element to search for
 *
 * @return the number of entries of element in list
 */
size_t
DListContains
( const dlist_t *list, const void *element );

/**
 * Creates a copy of a DList. Elements within the DList are not
 * copied, meaning that changes made to elements in the original DList
 * will also change the elements in the copy. Changes made to the original
 * DList will not affect the copy.
 *
 * @param list the DList to copy. Must not be NULL.
 * 
 * @return a copy of the original DList or NULL on failure
 */
dlist_t *
DListCopy
( const dlist_t *list );

/**
 * Destroys a DList. Does not affect the elements stored within.
 *
 * @param list the DList to destroy
 */
void
DListDestroy
( const dlist_t *list );

/**
 * Gets the first element in the DList.
 *
 * @param list the DList to get the element from. Must not be NULL.
 *
 * @return the first element of list, or NULL if list is empty
 */
void *
DListFront
( const dlist_t *list );

/**
 * Gets the element at the specified position in the DList. If the
 * DList does not have an element at this index then NULL is returned.
 * NULL is returned if list is NULL or empty.
 *
 * Negative indexes count backwards through the list, for example an index of
 * -2 returns the second to last value in the list.
 *
 * Both positive and negative indexes will wrap around if greater than the size
 * of list. For example, if list contains 3 elements, then an index of 4 will
 * return the second element in list. Likewise, an index of -4 will return the
 * last element in list.
 *
 * @param list the DList to get the element from
 * @param index the index of the element to retrieve
 *
 * @return the element of the DList at the given index, or NULL if it does not
 * exist
 */
void *
DListGet
( const dlist_t *list, int index );

/**
 * Checks whether or not a DList is empty. A NULL DList is
 * considered empty.
 *
 * @param list the DList to check
 *
 * @return a positive value if the DList is empty, 0 otherwise
 */
unsigned short
DListIsEmpty
( const dlist_t *list );

/**
 * Creates a new DList.
 *
 * @return a new DList or NULL on failure
 */
dlist_t *
DListNew
( void );

/**
 * Adds a single element to the beginning of a DList. If element is NULL
 * then nothing is done.
 *
 * @param list the DList to prepend to. Must not be NULL.
 * @param element the element to prepend
 *
 * @return list
 */
dlist_t *
DListPrepend
( dlist_t *list, void *element );

/**
 * Gets the number of elements in the DList. An empty DList will
 * return 0.
 *
 * @param list the DList to get the size of
 *
 * @return the number of elements in the DList
 */
unsigned
DListSize
( const dlist_t *list );

/**
 * Creates a string representation of the given DList, using the provided
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
 * @param list the DList to get a representation of. Must not be NULL.
 * @param element_to_string a function returning string representations of
 * elements
 *
 * @return a char buffer holding a string representation of the DList
 */
char *
DListToString
( const dlist_t *list, char * ( *element_to_string )( const void * ) );

#endif
