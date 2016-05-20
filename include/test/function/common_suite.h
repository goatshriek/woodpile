#ifndef __WOODPILE_TEST_FUNCTION_COMMON_SUITE_H
#define __WOODPILE_TEST_FUNCTION_COMMON_SUITE_H

/**
 * @file
 * Common functionality tests.
 * This header depends on two #defines: the first is TEST_TYPE, which must be
 * the type of the structure to test. The second is TEST_PREFIX, which is the
 * prefix of the functions to be tested, for example SHash for the static hash
 * functions SHashIsEmpty and SHashNew.
 */

//#define TEST_TYPE shash_t
//#define TEST_PREFIX SHash

# ifdef TEST_TYPE
#  ifdef TEST_FUNCTION_NEW
#   ifdef TEST_FUNCTION_DESTROY
#    ifdef TEST_FUNCTION_IS_EMPTY
#     ifdef TEST_FUNCTION_BUILD

struct TEST_TYPE;
typedef struct TEST_TYPE test_struct_t;

/**
 * Tests the Destroy function with a NULL structure.
 *
 * @test a NULL structure must not cause an error.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestDestroyNull
( void );

/**
 * Tests the Destroy function with a populated structure.
 *
 * @test A populated structure must not cause an error.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestDestroyPopulated
( void );

/**
 * Tests the IsEmpty function with an empty structure.
 *
 * @test A structure with no elements must return a positive value.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestIsEmptyWithEmpty
( void );

/**
 * Tests the IsEmpty function with a NULL structure.
 *
 * @test a NULL structure must return a positive value.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestIsEmptyWithNull
( void );

/**
 * Tests the IsEmpty function with a populated structure.
 *
 * @test A populated structure must return 0.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestIsEmptyWithPopulated
( void );

#     endif
#    endif
#   endif
#  endif
# endif
#endif
