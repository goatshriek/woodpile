#ifndef __WOODPILE_DYNAMIC_TREE_SPLAY_H
#define __WOODPILE_DYNAMIC_TREE_SPLAY_H

/**
 * @file
 * DynamicSplay Tree declaration and functions
 */

#include <woodpile/comparator.h>

/**
 * @struct DynamicSplay
 * The DynamicSplay data structure is a self-balancing tree structure that
 * allows faster access to recently accessed elements.
 *
 * Elements are sorted using the comparator function. This function must be
 * non-NULL. This function is expected to return a negative number when the
 * first element should come first, a positive number when the second should,
 * and zero when the two are equal. strcmp is an example of such a function.
 *
 * Duplicate elements are not allowed in the structure.
 *
 * The DynamicSplay is optimized for search and retrieval in a data set where
 * certain elements are needed more often than others.
 *
 * Memory for this structure is allocated dynamically, allowing it to grow and
 * shrink along with the number of elements it holds. This makes it suitable for
 * use when the size is constantly changing; if a more static splay size is
 * expected then the array-based implementation should be used as its memory
 * overhead is lower.
 *
 * Memory overhead can be calculated as follows:
 * sizeof( void * ) * ( ( number_of_elements * 4 ) + 2 )
 */
struct dsplay_t;
typedef struct dsplay_t dsplay_t;

typedef char * ( *to_string_t )( const void * );

/**
 * Adds an element to a DynamicSplay. NULL elements are not allowed and are
 * ignored.
 *
 * @param splay the DynamicSplay to add to. Must not be NULL.
 * @param element the element to add
 *
 * @return splay, or NULL on failure
 */
dsplay_t *
DSplayAdd
( dsplay_t *splay, void *element );

/**
 * Searches a DynamicSplay for an element. If found, the element is splayed to
 * the root of the tree.
 *
 * @param splay the DynamicSplay to search
 * @param element the element to search for
 *
 * @return a value that evaluats to true if element exists in splay, otherwise
 * a value that evaluates to false
 */
unsigned short
DSplayContains
( dsplay_t *splay, const void *element );

/**
 * Creates a copy of a DynamicSplay. Elements within are not copied, meaning
 * that changes made to elements in the original structure will also change the
 * elements in the copy. Changes made to splay will not affect the copy.
 *
 * @param splay the DynamicSplay to copy. Must not be NULL.
 *
 * @return a copy of the original DynamicSplay or NULL on failure
 */
dsplay_t *
DSplayCopy
( const dsplay_t *splay );

/**
 * Destroys a DynamicSplay. Does not affect the elements stored within.
 *
 * @param splay the DynamicSplay to destroy
 */
void
DSplayDestroy
( const dsplay_t *splay );

/**
 * Gets the first element in the DynamicSplay. The element is NOT splayed to the
 * root of the tree, however, as this would guarantee an unbalanced tree.
 *
 * @param splay the DynamicSplay to get the element from. Must not be NULL.
 *
 * @return the first element in the splay, or NULL if the splay is empty
 */
void *
DSplayFirst
( const dsplay_t *splay );

/**
 * Checks whether or not a DynamicSplay is empty. A NULL DynamicSplay is
 * considered empty.
 *
 * @param splay the DynamicSplay to check
 *
 * @return a positive value if the DynamicSplay is empty, 0 otherwise
 */
unsigned short
DSplayIsEmpty
( const dsplay_t *splay );

/**
 * Gets the last element in the DynamicSplay. The element is NOT splayed to the
 * root of the tree, however, as this would guarantee an unbalanced tree.
 *
 * @param splay the DynamicSplay to get the element from. Must not be NULL.
 *
 * @return the last element in the splay, or NULL if the splay is empty
 */
void *
DSplayLast
( const dsplay_t *splay );

/**
 * Creates a new DynamicSplay. If comparator is NULL then the elements will be
 * sorted according to their natural order (that is, the order of their
 * pointers).
 *
 * @param comparator the comparator function for the DynamicSplay
 *
 * @return a new DynamicSplay or NULL on failure
 */
dsplay_t *
DSplayNew
( comparator_t comparator );

/**
 * Searches for an element in a DynamicSplay and removes it if it is found.
 *
 * @param splay the DynamicSplay to remove from. Must not be NULL.
 * @param element the element to search for and remove. Must not be NULL.
 *
 * @return the removed element, or NULL if it was not found
 */
void *
DSplayRemove
( dsplay_t *splay, const void *element );

/**
 * Gets the number of elements in the DynamicSplay. An empty DynamicSplay will
 * return 0.
 *
 * @param splay the DynamicSplay to get the size of
 *
 * @return the number of elements in the DynamicSplay
 */
size_t
DSplaySize
( const dsplay_t *splay );

/**
 * Creates a string representation of the given DynamicSplay, using the provided
 * function to get the string representation of each element. If the
 * element_to_string function is NULL, then the element is printed as a void
 * pointer.
 *
 * The splay is enclosed in square brackets, and elements within the splay are
 * separated by a comma and space as shown here:
 * [element_1, element_2, element_3]
 *
 * The element_to_string function must create new strings that can be
 * deallocated with a call to free. For example, if the elements themselves are
 * string literals, then the function must return a copy of the string rather
 * than the string itself.
 *
 * @param splay the DynamicSplay to get a representation of. Must not be NULL.
 * @param element_to_string a function returning string representations of
 * elements
 *
 * @return a char buffer holding a string representation of the DynamicSplay
 */
char *
DSplayToString
( const dsplay_t *splay, to_string_t element_to_string );

#endif
