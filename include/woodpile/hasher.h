#ifndef __WOODPILE_HASHER_H
#define __WOODPILE_HASHER_H

/**
 * @file
 * Hasher functions for use in hash structures.
 */

#include <stdlib.h>
#include <woodpile/config.h>

#ifdef __WOODPILE_ALL_HASHERS
# undef __WOODPILE_CITY_HASHER
# define __WOODPILE_CITY_HASHER 1
# undef __WOODPILE_SPOOKY_HASHER
# define __WOODPILE_SPOOKY_HASHER 1
# undef __WOODPILE_WOODPILE_HASHER
# define __WOODPILE_WOODPILE_HASHER 1
#endif

typedef unsigned long long ( *hasher_t )( const void * );

/**
 * Creates a hash from a pointer. This is done by simply converting the pointer
 * to an integer.
 *
 * @param pointer the pointer to hash
 *
 * @return a noncryptographic hash of a pointer
 */
unsigned long long
PointerHash
( const void *pointer );

#ifdef __WOODPILE_CITY_HASHER
/**
 * An adaptation of Google's CityHash. The original code can be found on the
 * github repository for the project at https://github.com/google/cityhash.
 *
 * @param data the data to hash
 * @param length the length of the data block to hash
 *
 * @return a noncryptographic hash of the string
 *
 */
unsigned long long
CityDataHash
( const void *data, size_t length );

/**
 * An adaptation of Google's CityHash. The original code can be found on the
 * github repository for the project at https://github.com/google/cityhash.
 *
 * @param str a NULL-terminated string
 *
 * @return a noncryptographic hash of the string
 *
 */
unsigned long long
CityHash
( const void *str );

/**
 * An adaptation of Google's CityHash. The original code can be found on the
 * github repository for the project at https://github.com/google/cityhash.
 *
 * @param data the data to hash
 * @param length the length of the data block to hash
 * @param seed a seed for the hash
 *
 * @return a noncryptographic hash of the string
 *
 */
unsigned long long
CitySeededHash
( const void *data, size_t length, unsigned long long seed );
#endif

#ifdef __WOODPILE_SPOOKY_HASHER
/**
 * An adaptation of Bob Jenkin's SpookyHashV2. This adaptation was made with 
 * simplicity and brevity in mind. The original code can be found
 * at http://burtleburtle.net/bob/c/SpookyV2.cpp and
 * http://burtleburtle.net/bob/c/SpookyV2.h.
 *
 * @param data the data to hash
 * @param length the length of the data block to hash
 *
 * @return a noncryptographic hash of the string
 *
 */
unsigned long long
SpookyDataHash
( const void *data, size_t length );

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
SpookyHash
( const void *str );

/**
 * An adaptation of Bob Jenkin's SpookyHashV2. This adaptation was made with 
 * simplicity and brevity in mind. The original code can be found
 * at http://burtleburtle.net/bob/c/SpookyV2.cpp and
 * http://burtleburtle.net/bob/c/SpookyV2.h.
 *
 * @param data the data to hash
 * @param length the length of the data block to hash
 * @param seed a seed for the hash
 *
 * @return a noncryptographic hash of the string
 *
 */
unsigned long long
SpookySeededHash
( const void *data, size_t length, unsigned long long seed );
#endif


#ifdef __WOODPILE_WOODPILE_HASHER
/**
 * A simple data hashing function.
 *
 * @param data the data to hash
 * @param length the length of the data block to hash
 *
 * @return a noncryptographic hash of the string
 */
unsigned long long
WoodpileDataHash
( const void *data, size_t length );

/**
 * A simple string hashing function.
 *
 * @param str a NULL-terminated string
 *
 * @return a noncryptographic hash of the string
 */
unsigned long long
WoodpileHash
( const void *str );
/**
 * A simple data hashing function with a seed included.
 *
 * @param data the data to hash
 * @param length the length of the data block to hash
 * @param seed a seed for the hash
 *
 * @return a noncryptographic hash of the string
 */
unsigned long long
WoodpileSeededHash
( const void *data, size_t length, unsigned long long seed );
#endif

#endif
