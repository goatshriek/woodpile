#ifndef __WOODPILE_LIB_HASHER_H
#define __WOODPILE_LIB_HASHER_H

/**
 * @file
 * Functions for hashing data.
 */


/**
 * An adaptation of Bob Jenkin's SpookyHashV2. The original code can be found
 * at http://burtleburtle.net/bob/c/SpookyV2.cpp.
 *
 * @param str a NULL-terminated string
 *
 * @return a noncryptographic hash of the string
 *
 */
unsigned long
spooky_hasher
( const void *str );

#endif
