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

#include <woodpile/config.h>

#ifdef TEST_FUNCTION_BUILD
#ifdef TEST_FUNCTION_COPY
#ifdef TEST_FUNCTION_DESTROY
#ifdef TEST_FUNCTION_IS_EMPTY
#ifdef TEST_FUNCTION_NEW
#ifdef TEST_FUNCTION_SIZE
#ifdef TEST_TYPE

struct TEST_TYPE;
typedef struct TEST_TYPE test_struct_t;

#ifdef __WOODPILE_PARAMETER_VALIDATION

/**
 * Tests the Copy function with a NULL structure.
 *
 * @test a NULL structure must return NULL.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestCopyNull
( void );

#endif

/**
 * Tests the Copy function.
 *
 * @test A non-NULL structure must be returned as the copy of a non-NULL
 * structure.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestCopy
( void );

/**
 * Tests the structure returned by the Copy function.
 *
 * @test The copied structure must be a different value than the original.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestCopyDistinct
( void );

/**
 * Tests the size of the structure returned by the Copy function.
 *
 * @test The copy of a populated structure must be the same size as the
 * original.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestCopySize
( void );

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

/**
 * Tests the New function.
 *
 * @test Calling the function must return a non-NULL value.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestNew
( void );

/**
 * Tests the Size function with an empty structure.
 *
 * @test An empty structure must return 0.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestSizeWithEmpty
( void );

/**
 * Tests the Size function with a NULL structure.
 *
 * @test A NULL structure must return 0.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestSizeWithNull
( void );

#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
