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
struct DynamicSplay;

typedef struct DynamicSplay DSplay;
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
DSplay *
AddToDynamicSplay
( DSplay *splay, void *element );
/** shortened AddToDynamicSplay function name */
#define DSplayAdd AddToDynamicSplay

/**
 * Creates a copy of a DynamicSplay. Elements within are not copied, meaning
 * that changes made to elements in the original structure will also change the
 * elements in the copy. Changes made to splay will not affect the copy.
 *
 * @param splay the DynamicSplay to copy. Must not be NULL.
 * 
 * @return a copy of the original DynamicSplay or NULL on failure
 */
DSplay *
CopyDynamicSplay
( const DSplay *splay );
/** shortened CopyDynamicSplay function name */
#define DSplayCopy CopyDynamicSplay

/**
 * Destroys a DynamicSplay. Does not affect the elements stored within.
 *
 * @param splay the DynamicSplay to destroy
 */
void
DestroyDynamicSplay
( const DSplay *splay );
/** shortened DestroyDynamicSplay function name */
#define DSplayDestroy DestroyDynamicSplay

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
DynamicSplayContains
( DSplay *splay, const void *element );
/** shortened DynamicSplayContains function name */
#define DSplayContains DynamicSplayContains

/**
 * Checks whether or not a DynamicSplay is empty. A NULL DynamicSplay is
 * considered empty.
 *
 * @param splay the DynamicSplay to check
 *
 * @return a positive value if the DynamicSplay is empty, 0 otherwise
 */
unsigned short
DynamicSplayIsEmpty
( const DSplay *splay );
/** shortened DynamicSplayIsEmpty function name */
#define DSplayIsEmpty DynamicSplayIsEmpty

/**
 * Gets the number of elements in the DynamicSplay. An empty DynamicSplay will
 * return 0.
 *
 * @param splay the DynamicSplay to get the size of
 *
 * @return the number of elements in the DynamicSplay
 */
size_t
DynamicSplaySize
( const DSplay *splay );
/** shortened DynamicSplaySize function name */
#define DSplaySize DynamicSplaySize

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
DynamicSplayToString
( const DSplay *splay, to_string_t element_to_string );
/** shortened DynamicSplayToString function name */
#define DSplayToString DynamicSplayToString

/**
 * Gets the first element in the DynamicSplay. The element is NOT splayed to the
 * root of the tree, however, as this would guarantee an unbalanced tree.
 *
 * @param splay the DynamicSplay to get the element from. Must not be NULL.
 *
 * @return the first element in the splay, or NULL if the splay is empty
 */
void *
FirstInDynamicSplay
( const DSplay *splay );
/** shortened FirstInDynamicSplay function name */
#define DSplayFirst FirstInDynamicSplay

/**
 * Gets the last element in the DynamicSplay. The element is NOT splayed to the
 * root of the tree, however, as this would guarantee an unbalanced tree.
 *
 * @param splay the DynamicSplay to get the element from. Must not be NULL.
 *
 * @return the last element in the splay, or NULL if the splay is empty
 */
void *
LastInDynamicSplay
( const DSplay *splay );
/** shortened FirstInDynamicSplay function name */
#define DSplayLast LastInDynamicSplay

/**
 * Creates a new DynamicSplay. If comparator is NULL then the elements will be
 * sorted according to their natural order (that is, the order of their
 * pointers).
 * 
 * @param comparator the comparator function for the DynamicSplay
 *
 * @return a new DynamicSplay or NULL on failure
 */
DSplay *
NewDynamicSplay
( comparator_t comparator );
/** shortened NewDynamicSplay function name */
#define DSplayNew NewDynamicSplay

/**
 * Searches for an element in a DynamicSplay and removes it if it is found.
 *
 * @param splay the DynamicSplay to remove from. Must not be NULL.
 * @param element the element to search for and remove. Must not be NULL.
 *
 * @return the removed element, or NULL if it was not found
 */
void *
RemoveFromDynamicSplay
( DSplay *splay, const void *element );
/** shortened RemoveFromDynamicSplay */
#define DSplayRemove RemoveFromDynamicSplay

#endif
