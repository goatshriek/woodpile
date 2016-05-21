#ifndef __WOODPILE_DYNAMIC_LIST_H
#define __WOODPILE_DYNAMIC_LIST_H

/**
 * @file
 * DynamicList declaration and functions
 */

/**
 * @struct DynamicList
 * The DynamicList data structure is a simple doubly linked list implementation.
 *
 * The DynamicList is optimized for insertions and deletions at either end, and
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
 * Adds a single element to the end of a DynamicList. If element is NULL then
 * nothing is done.
 *
 * @param list the DynamicList to append to. Must not be NULL.
 * @param element the element to append
 *
 * @return list
 */
dlist_t *
DListAppend
( dlist_t *list, void *element );

/**
 * Appends all elements in the second DynamicList to the end of the first. The
 * second list is not changed as a result of the operation. The elements are
 * appended in the order they exist in the second DynamicList.
 *
 * @param first the DynamicList to append to. Must not be NULL.
 * @param second the DynamicList to append
 *
 * @return first
 */
dlist_t *
DListAppendAll
( dlist_t *first, const dlist_t *second );

/**
 * Gets the last element in the DynamicList.
 *
 * @param list the DynamicList to get the element from. Must not be NULL.
 *
 * @return the last element of list, or NULL if list is empty
 */
void *
DListBack
( const dlist_t *list );

/**
 * Searches a DynamicList for an element.
 *
 * Note that the element is identified using a pointer; if two structures are
 * considered equal but are located at different addresses then they are not
 * considered equal by this function.
 *
 * @param list the DynamicList to search
 * @param element the element to search for
 *
 * @return the number of entries of element in list
 */
size_t
DListContains
( const dlist_t *list, const void *element );

/**
 * Creates a copy of a DynamicList. Elements within the DynamicList are not
 * copied, meaning that changes made to elements in the original DynamicList
 * will also change the elements in the copy. Changes made to the original
 * DynamicList will not affect the copy.
 *
 * @param list the DynamicList to copy. Must not be NULL.
 * 
 * @return a copy of the original DynamicList or NULL on failure
 */
dlist_t *
DListCopy
( const dlist_t *list );

/**
 * Destroys a DynamicList. Does not affect the elements stored within.
 *
 * @param list the DynamicList to destroy
 */
void
DListDestroy
( const dlist_t *list );

/**
 * Gets the first element in the DynamicList.
 *
 * @param list the DynamicList to get the element from. Must not be NULL.
 *
 * @return the first element of list, or NULL if list is empty
 */
void *
DListFront
( const dlist_t *list );

/**
 * Gets the element at the specified position in the DynamicList. If the
 * DynamicList does not have an element at this index then NULL is returned.
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
 * @param list the DynamicList to get the element from
 * @param index the index of the element to retrieve
 *
 * @return the element of the DynamicList at the given index, or NULL if it does not
 * exist
 */
void *
DListGet
( const dlist_t *list, int index );

/**
 * Checks whether or not a DynamicList is empty. A NULL DynamicList is
 * considered empty.
 *
 * @param list the DynamicList to check
 *
 * @return a positive value if the DynamicList is empty, 0 otherwise
 */
unsigned short
DListIsEmpty
( const dlist_t *list );

/**
 * Creates a new DynamicList.
 *
 * @return a new DynamicList or NULL on failure
 */
dlist_t *
DListNew
( void );

/**
 * Adds a single element to the beginning of a DynamicList. If element is NULL
 * then nothing is done.
 *
 * @param list the DynamicList to prepend to. Must not be NULL.
 * @param element the element to prepend
 *
 * @return list
 */
dlist_t *
DListPrepend
( dlist_t *list, void *element );

/**
 * Gets the number of elements in the DynamicList. An empty DynamicList will
 * return 0.
 *
 * @param list the DynamicList to get the size of
 *
 * @return the number of elements in the DynamicList
 */
unsigned
DListSize
( const dlist_t *list );

/**
 * Creates a string representation of the given DynamicList, using the provided
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
 * @param list the DynamicList to get a representation of. Must not be NULL.
 * @param element_to_string a function returning string representations of
 * elements
 *
 * @return a char buffer holding a string representation of the DynamicList
 */
char *
DListToString
( const dlist_t *list, char * ( *element_to_string )( const void * ) );

#endif
