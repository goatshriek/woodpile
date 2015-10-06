#ifndef __WOODPILE_TEST_FUNCTION_DYNAMIC_TREE_SPLAY_CONST_ITERATOR_SUITE_H
#define __WOODPILE_TEST_FUNCTION_DYNAMIC_TREE_SPLAY_CONST_ITERATOR_SUITE_H

/**
 * @file
 * DynamicSplayConstIterator tests
 */

/**
 * Tests the DSplayCBegin function with an empty splay.
 *
 * @test A non-NULL DSplayCItr must be returned for an empty splay. The
 * next and previous element must be NULL in this iterator.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestCBeginWithEmptyDynamicSplay
( void );

/**
 * Tests the DSplayCBegin function with a NULL splay.
 *
 * @test NULL must be returned for a NULL splay.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestCBeginWithNullDynamicSplay
( void );

/**
 * Tests the DSplayCBegin function with a populated splay.
 *
 * @test A non-NULL DSplayCItr must be returned for a populated splay. The
 * previous element must be NULL. The next element must be the first value in
 * the splay.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestCBeginWithPopulatedDynamicSplay
( void );

/**
 * Tests the CEndsplay function with an empty splay.
 *
 * @test A non-NULL DSplayCItr must be returned for an empty splay. The
 * next and previous element must be NULL in this DSplayCItr.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestCEndWithEmptyDynamicSplay
( void );

/**
 * Tests the CEndsplay function with a NULL splay.
 *
 * @test NULL must be returned for a NULL splay.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestCEndWithNullDynamicSplay
( void );

/**
 * Tests the CEndsplay function with a populated splay.
 *
 * @test A non-NULL DSplayCItr must be returned for a populated splay. The
 * next element must be NULL. The previous element must be the last value in the
 * splay.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestCEndWithPopulatedDynamicSplay
( void );

/**
 * Tests the CopyDSplayCItr function.
 *
 * @test A non-NULL DSplayCItr must be returned as the copy of a non-NULL
 * DSplayCItr.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestCopy
( void );

/**
 * Tests the contents of the DSplayCItr returned by the
 * CopyDSplayCItr function.
 *
 * @test The copied DSplayCItr must point at the same splay as the
 * original.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestCopyContents
( void );

/**
 * Tests the DSplayCItr returned by the CopyDSplayCItr function.
 *
 * @test The copied DSplayCItr must be a different value than the
 * original. Advancing to the next element of the copy must not affect the
 * position of the original. Advancing to the previous element of the copy must
 * not affect the original.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestCopyDistinct
( void );

/**
 * Tests the CopyDSplayCItr function with a NULL DSplayCItr.
 *
 * @test A NULL DSplayCItr must return NULL.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestCopyNullIterator
( void );

/**
 * Tests the position of the DSplayCItr returned by the
 * CopyDSplayCItr function.
 * 
 * @test The copy must have the same next element as the original. The copy must
 * have the same previous element as the original.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestCopyPosition
( void );

/**
 * Tests the DestroyDSplayCItr function.
 *
 * @test Destroying a DSplayCItr must not cause an error.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestDestroy
( void );

/**
 * Tests the DestroyDSplayCItr function with a NULL DSplayCItr.
 *
 * @test A NULL DSplayCItr must not cause an error.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestDestroyNullIterator
( void );

/**
 * Tests the DSplayCItrHasNext function at the beginning of a splay.
 *
 * @test A DSplayCItr at the beginning of a splay must return a value that
 * evaluates to true.
 *
 * @test NULL on success or a string describing the failure
 */
const char *
TestHasNextAtBeginning
( void );

/** 
 * Tests the DSplayCItrHasNext function at the end of a splay.
 *
 * @test A DSplayCItr at the end of a splay must return a value that
 * evaluates to false.
 *
 * @test NULL on success or a string describing the failure
 */
const char *
TestHasNextAtEnd
( void );

/**
 * Tests the DSplayCItrHasNext function at the middle of a splay.
 *
 * @test A DSplayCItr at the middle of a splay must return a value that
 * evaluates to true.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestHasNextAtMiddle
( void );

/**
 * Tests the DSplayCItrHasNext function with an empty splay.
 *
 * @test Calling the function with a DSplayCItr from an empty splay must
 * return a value that evaluates to false.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestHasNextWithEmptyDynamicSplay
( void );

/**
 * Tests the DSplayCItrHasNext function with a NULL DSplayCItr.
 *
 * @test Calling the function with a NULL DSplayCItr must return a value
 * that evaluates to false.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestHasNextWithNullIterator
( void );

/**
 * Tests the DSplayCItrHasPrevious function at the beginning of a splay.
 *
 * @test A DSplayCItr at the beginning of a splay must return a value that
 * evaluates to false.
 *
 * @test NULL on success or a string describing the failure
 */
const char *
TestHasPreviousAtBeginning
( void );

/** 
 * Tests the DSplayCItrHasPrevious function at the end of a splay.
 *
 * @test A DSplayCItr at the end of a splay must return a value that
 * evaluates to true.
 *
 * @test NULL on success or a string describing the failure
 */
const char *
TestHasPreviousAtEnd
( void );

/**
 * Tests the DSplayCItrHasPrevious function at the middle of a splay.
 *
 * @test A DSplayCItr at the middle of a splay must return a value that
 * evaluates to true.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestHasPreviousAtMiddle
( void );

/**
 * Tests the DSplayCItrHasPrevious function with an empty splay.
 *
 * @test Calling the function with a DSplayCItr from an empty splay must
 * return a value that evaluates to false.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestHasPreviousWithEmptyDynamicSplay
( void );

/**
 * Tests the DSplayCItrHasPrevious function with a NULL DSplayCItr.
 *
 * @test Calling the function with a NULL DSplayCItr must return a value
 * that evaluates to false.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestHasPreviousWithNullIterator
( void );

/**
 * Tests the NextInDSplayCItr function at the beginning of a splay.
 *
 * @test A DSplayCItr that is at the beginning of a splay must return
 * the first value in the splay.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestNextAtBeginning
( void );

/**
 * Tests the NextInDSplayCItr function at the end of a splay.
 *
 * @test A DSplayCItr that is at the end of a splay must return NULL.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestNextAtEnd
( void );

/**
 * Tests the NextInDSplayCItr function in the middle of a splay.
 *
 * @test A DSplayCItr that is in the middle of the splay must return, in
 * order, the elements of the splay.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestNextAtMiddle
( void );

/**
 * Tests the NextInDSplayCItr function with an empty splay.
 *
 * @test Calling the function with an empty splay must return NULL.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestNextWithEmptyDynamicSplay
( void );

/**
 * Tests the NextInDSplayCItr function with a NULL iterator.
 *
 * @test Calling the function with a NULL DSplayCItr must return NULL.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestNextWithNullIterator
( void );

/**
 * Tests the PreviousInDSplayCItr function at the beginning of a splay.
 *
 * @test A DSplayCItr that is at the beginning of a splay must return
 * NULL.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestPreviousAtBeginning
( void );

/**
 * Tests the PreviousInDSplayCItr function at the end of a splay.
 *
 * @test A DSplayCItr that is at the end of a splay must return the last
 * element in the splay.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestPreviousAtEnd
( void );

/**
 * Tests the PreviousInDSplayCItr function in the middle of a splay.
 *
 * @test A DSplayCItr that is in the middle of the splay must return, in
 * reverse order, the elements of the splay.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestPreviousAtMiddle
( void );

/**
 * Tests the PreviousInDSplayCItr function with an empty splay.
 *
 * @test Calling the function with an empty splay must return NULL.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestPreviousWithEmptyDynamicSplay
( void );

/**
 * Tests the PreviousInDSplayCItr function with a NULL iterator.
 *
 * @test Calling the function with a NULL DSplayCItr must return NULL.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestPreviousWithNullIterator
( void );

#endif
