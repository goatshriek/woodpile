#ifndef __WOODPILE_COMPARATOR_H
#define __WOODPILE_COMPARATOR_H

/**
 * @file
 * Comparison functions for use in structures where comparison is needed.
 */

typedef int ( *comparator_t )( const void *, const void * );

/**
 * Directly compares two values by comparing their pointer values.
 *
 * @param first the first value
 * @param second the second value
 *
 * @return a negative value if first is less than second, a positive value if
 * second is less than first, and zero if the two are equal
 */
int
ComparePointers
( const void *first, const void *second );

/**
 * Compares two strings. This is simply a wrapper for strcmp. As an alternative
 * to using this function when creating data structures dealing with strings,
 * casting strcmp to comparator_t will also work. This is largely a matter of
 * preference, although doing so will result in this function not being needed,
 * and thus a smaller binary.
 *
 * @param first the first string
 * @param second the second string
 *
 * @return a negative value if first is lexicographically less than second,
 * a positive value if second is lexicographically less than first, and zero
 * if the two strings are equal.
 */
int
CompareStrings
( const void *first, const void *second );

#endif
