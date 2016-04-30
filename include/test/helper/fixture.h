#ifndef __WOODPILE_TEST_HELPER_FIXTURE_H
#define __WOODPILE_TEST_HELPER_FIXTURE_H

/**
 * @file
 * Functions to use as function pointers
 */

/**
 * Guarantees a collision for the two strings "collision" and "crash",
 * regardless of the seed value. Otherwise, the WoodpileHash is used.
 *
 * @param data the string to hash
 * @param seed the seed for the hash
 *
 * @return a hash of data
 */
unsigned long long
CollisionHash
( const void *data, unsigned long long seed );

/**
 * Converts the provided element to a string. Does conversion by simply
 * casting the element to a char pointer and returning it.
 *
 * @param element the pointer to convert
 *
 * @return element cast as a char *
 */
char *
ElementToString
( const void *element );

/**
 * Returns 0 for any data and seed.
 *
 * @param data the data that would be hashed
 * @param seed the seed for the hash
 *
 * @return 0
 */
unsigned long long
NullHash
( const void *data, unsigned long long seed );

#endif
