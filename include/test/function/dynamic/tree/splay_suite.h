#ifndef __WOODPILE_TEST_FUNCTION_DYNAMIC_TREE_SPLAY_SUITE_H
#define __WOODPILE_TEST_FUNCTION_DYNAMIC_TREE_SPLAY_SUITE_H

/**
 * @file
 * DynamicSplay tests
 */

/**
 * Tests the DSplayAdd function with an element already in the splay.
 *
 * @test Adding an element already in the splay must return the splay. The
 * size of the splay must be unchanged.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestAddDuplicateElement
( void );

/**
 * Tests the AddToDynamicSplay function with a NULL element.
 *
 * @test A NULL element must return the DynamicSplay to append to, regardless of
 * whether the DynamicSplay to append to is NULL or non-NULL.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestAddNullElement
( void );

/**
 * Tests the AddToDynamicSplay function with an empty DynamicSplay.
 *
 * @test Appending an element to an empty DynamicSplay must result in the
 * element being at the front of the DynamicSplay and the DynamicSplay having
 * a size of 1.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestAddToEmptyDynamicSplay
( void );

/**
 * Tests the AddToSplay function with a NULL DynamicSplay.
 *
 * @test A NULL DynamicSplay must return NULL, regardless of whether the element
 * to append is NULL or non-NULL.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestAddToNullDynamicSplay
( void );

/**
 * Tests the AddToDynamicSplay function with a populated DynamicSplay.
 *
 * @test Adding an element to the DynamicSplay must result in the element
 * being put in the DynamicSplay, and the size of the structure increasing by
 * one.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestAddToPopulatedDynamicSplay
( void );

/**
 * Tests the DynamicSplayContains function with an element that does not exist
 * in the DynamicSplay.
 *
 * @test An element not existing in the DynamicSplay must return a logically
 * false value.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestContainsNonExistentElement
( void );

/**
 * Tests the DynamicSplayContains function a NULL element supplied.
 *
 * @test A NULL element must return a logically false value, whether the
 * structure supplied is NULL or non-NULL.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestContainsNullElement
( void );

/**
 * Tests the DynamicSplayContains function with elements that exist in the
 * structure exactly once.
 *
 * @test An element existing in the structure must return a logically true
 * value.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestContainsUniqueElement
( void );

/**
 * Tests the DynamicSplayContains function with a NULL DynamicSplay.
 *
 * @test A NULL DynamicSplay must return a logically false value, whether the
 * element supplied is NULL or non-NULL.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestContainsWithNullDynamicSplay
( void );

/**
 * Tests the contents of the DynamicSplay returned by the CopyDynamicSplay
 * function.
 *
 * @test The copied structure must point at the same elements as the original,
 * in the same order as the original.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestCopyContents
( void );

/**
 * Tests the FirstInDynamicSplay function with an empty splay.
 *
 * @test Calling the function with an empty splay must return NULL.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestFirstInEmptyDynamicSplay
( void );

/**
 * Tests the FirstInDynamicSplay function with a NULL splay.
 *
 * @test Calling the function with a NULL splay must return NULL.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestFirstInNullDynamicSplay
( void );

/**
 * Tests the FirstInDynamicSplay function with a populated splay.
 *
 * @test Calling the function with a populated splay must return the first
 * element of the splay.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestFirstInPopulatedDynamicSplay
( void );

/**
 * Tests the LastInDynamicSplay function with an empty splay.
 *
 * @test Calling the function with an empty splay must return NULL.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestLastInEmptyDynamicSplay
( void );

/**
 * Tests the LastInDynamicSplay function with a NULL splay.
 *
 * @test Calling the function with a NULL splay must return NULL.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestLastInNullDynamicSplay
( void );

/**
 * Tests the LastInDynamicSplay function with a populated splay.
 *
 * @test Calling the function with a populated splay must return the last
 * element of the splay.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestLastInPopulatedDynamicSplay
( void );

/**
 * Tests the NewDynamicSplay function with a non-NULL comparator.
 *
 * @test Calling the function with a non-NULL comparator must return a non-NULL
 * value
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestNewWithComparator
( void );

/**
 * Tests the NewDynamicSplay function with a NULL comparator.
 *
 * @test Calling the function with a NULL comparator must return a non-NULL
 * value
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestNewWithNullComparator
( void );

/**
 * Tests the DSplayRemove function with a NULL splay.
 *
 * @test Calling the function with a NULL splay must return NULL, regardless of
 * whether or not the element is NULL.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestRemoveFromNullDynamicSplay
( void );

/**
 * Tests the DSplayRemove function with an element not existing in the splay.
 *
 * @test Calling the function with an element that does not exist in the splay
 * must return NULL.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestRemoveNonExistentElement
( void );

/**
 * Tests the DSplayRemove function with a NULL element.
 *
 * @test Calling the function with a NULL element must return NULL, regardless
 * of whether or not the splay is NULL or non-NULL.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestRemoveNullElement
( void );

/**
 * Tests the DSplayRemove function with an element that is currently the root.
 *
* @test Calling the function with an element that has just been splayed must
 * return the element itself. The element must be removed from the splay after
 * the call. The splay size must decrease by one after the call.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestRemoveRootElement
( void );

/**
 *Tests the DSplayRemove function with an element unique in the splay.
 *
 * @test Calling the function with an element that exists exactly once in the
 * splay must return the element removed. After the function call, the element
 * must no longer exist in the splay. The size of the splay must decrease by
 * one after calling the function.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestRemoveUniqueElement
( void );

/**
 * Tests the DynamicSplaySize function with a populated DynamicSplay.
 *
 * @test The value 26 must be returned for a DynamicSplay containing
 * twenty-six elements.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestSizeOfPopulatedDynamicSplay
( void );

/**
 * Tests the DynamicSplayToString function with an empty DynamicSplay.
 *
 * @test An empty DynamicSplay must result in an string of "[]".
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestToStringWithEmptyDynamicSplay
( void );

/**
 * Tests the DynamicSplayToString function with a NULL element_to_string
 * function.
 *
 * @test A NULL element_to_string function must result in each element in the
 * DynamicSplay being present in the string in pointer form.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestToStringWithNullFunction
( void );

/**
 * Tests the DynamicSplayToString function with a NULL DynamicSplay.
 *
 * @test A NULL DynamicSplay must result in a NULL string, regardless of whether
 * the element_to_string function is NULL or non-NULL.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestToStringWithNullDynamicSplay
( void );

/**
 * Tests the DynamicSplayToString function with a populated DynamicSplay.
 *
 * @test A populated list must return the list contents, transformed by the
 * element_to_string function, in the following format:
 * [element_1, element_2, ..., element_n]
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestToStringWithPopulatedDynamicSplay
( void );

#endif
