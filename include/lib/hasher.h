#ifndef __WOODPILE_LIB_HASHER_H
#define __WOODPILE_LIB_HASHER_H

/**
 * @file
 * Functions for hashing data.
 */


/**
 * An adaptation of Bob Jenkin's SpookyHashV2. This adaptation was made with 
 * simplicity and brevity in mind. The original code can be found
 * at http://burtleburtle.net/bob/c/SpookyV2.cpp and
 * http://burtleburtle.net/bob/c/SpookyV2.h.
 *
 * @param str a NULL-terminated string
 *
 * @return a noncryptographic hash of the string
 *
 */
unsigned long long
spooky_hasher
( const void *str );


/**
 * A simple string hashing function.
 *
 * @param str a NULL-terminated string
 *
 * @return a noncryptographic hash of the string
 */
unsigned long long
stumpless_hasher
( const void *str );

#endif
