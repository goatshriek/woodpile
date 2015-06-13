#ifndef __WOODPILE_DYNAMIC_TREE_SPLAY_H
#define __WOODPILE_DYNAMIC_TREE_SPLAY_H

/**
 * @file
 * Splay Tree declaration and functions
 */

/**
 * @struct Splay
 * The Splay data structure is a self-balancing tree structure that allows
 * faster access to recently accessed elements.
 *
 * The Splay is optimized for search and retrieval in a data set where certain
 * elements are needed more than others.
 *
 * Memory for this structure is allocated dynamically, allowing it to grow and
 * shrink along with the number of elements it holds. This makes it suitable for
 * use when the size is constantly changing; if a more static splay size is
 * needed then the array-based implementation should be used as its memory
 * overhead is lower.
 *
 * Memory overhead can be calculated as follows:
 * 2 * sizeof( void * ) * ( number_of_elements + 1 )
 */
struct Splay;
typedef struct Splay Splay;

/**
 * Creates a copy of a Splay. Elements within the Splay are not copied, meaning
 * that changes made to elements in the original Splay will also change the
 * elements in the copy. Changes made to the original Splay will not affect the
 * copy.
 *
 * @param splay the Splay to copy
 * 
 * @return a copy of the original Splay or NULL on failure
 */
Splay *
CopySplay
( const Splay *splay );

/**
 * Destroys a Splay. Does not affect the elements stored in the Splay.
 *
 * @param splay the Splay to destroy
 */
void
DestroySplay
( const Splay *splay );

/**
 * Searches a Splay for an element.
 *
 * Note that the element is identified using a pointer; if two structures are
 * considered equal but are located at different addresses then they are not
 * considered equal by this function.
 *
 * @param splay the Splay to search
 * @param element the element to search for
 *
 * @return the number of entries of element in splay
 */
size_t
SplayContains
( const Splay *splay, const void *element );

/**
 * Checks whether or not a Splay is empty. A NULL Splay is considered empty.
 *
 * @param splay the Splay to check
 *
 * @return a positive value if the Splay is empty, 0 otherwise
 */
unsigned short
SplayIsEmpty
( const Splay *splay );

/**
 * Gets the number of elements in the Splay. An empty Splay will return 0.
 *
 * @param splay the Splay to get the size of
 *
 * @return the number of elements in the Splay
 */
unsigned
SplaySize
( const Splay *splay );

/**
 * Creates a string representation of the given Splay, using the provided
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
 * @param splay the Splay to get a representation of
 * @param element_to_string a function returning string representations of
 * elements
 *
 * @return a char buffer holding a string representation of the Splay
 */
char *
SplayToString
( const Splay *splay, char * ( *element_to_string )( const void * ) );

/**
 * Creates a new Splay.
 * 
 * @return a new Splay or NULL on failure
 */
Splay *
NewSplay
( void );

#endif
