#ifndef __WOODPILE_PRIVATE_HASHER_H
#define __WOODPILE_PRIVATE_HASHER_H

/**
 * @file
 * Hasher support functions.
 */

#include <woodpile/config.h>

#ifdef __WOODPILE_SPOOKY_HASHER

#define SPOOKY_CHUNK_SIZE (sizeof( unsigned long long ) * 12)

/**
 * Rotates a value to the left by a specified number of bits.
 *
 * @param value the value to left rotate
 * @param bits the number of bits to shift by
 *
 * @return value left rotated by bits
 */
unsigned long long
SpookyLeftRotate
( unsigned long long value, size_t bits );

/**
 * Mixes a chunk of the data into the state buffer of the hash.
 *
 * @param chunk the chunk of data to mix into the state
 * @param state the state buffer of the hash
 */
void
SpookyMix
( const unsigned long long *chunk, unsigned long long *state );

#endif

#endif
