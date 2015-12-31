#ifndef __WOODPILE_TEST_PERFORMANCE_STATIC_HASH_SUITE_H
#define __WOODPILE_TEST_PERFORMANCE_STATIC_HASH_SUITE_H

/**
 * @file
 * Hash performance tests
 */

#include <stdio.h>
#include <time.h>

/**
 * Loads the given SHash with values. The keys are read from the provided
 * stream. Each key is mapped to a string holding "Value".
 *
 * @param hash the SHash to load with key-value pairs
 * @param stream the stream to read the keys from
 *
 * @return the number of clocks used to load the hash. This time does not
 * include stream operations.
 */
static
clock_t
LoadSHash
( SHash *hash, FILE *stream );

#endif
