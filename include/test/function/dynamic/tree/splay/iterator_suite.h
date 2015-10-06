#ifndef __WOODPILE_TEST_FUNCTION_DYNAMIC_TREE_SPLAY_ITERATOR_SUITE_H
#define __WOODPILE_TEST_FUNCTION_DYNAMIC_TREE_SPLAY_ITERATOR_SUITE_H

/**
 * @file
 * DynamicSplayIterator tests
 */

/**
 * Tests the DSplayBegin function with an empty splay.
 *
 * @test A non-NULL iterator must be returned for an empty splay. The next
 * and previous element must be NULL in the iterator.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestBeginWithEmptyDynamicSplay
( void );

/**
 * Tests the DSplayBegin function with a NULL splay.
 *
 * @test NULL must be returned for a NULL splay.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestBeginWithNullDynamicSplay
( void );

/**
 * Tests the DSplayBegin function with a populated splay.
 *
 * @test A non-NULL iterator must be returned for a populated splay. The
 * previous element must be NULL. The next element must be the first value in
 * the splay.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestBeginWithPopulatedDynamicSplay
( void );

/**
 * Tests the DSplayItrCopy function.
 *
 * @test A non-NULL iterator must be returned as the copy of a non-NULL
 * iterator.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestCopy
( void );

/**
 * Tests the contents of the iterator returned by the DSplayItrCopy
 * function.
 *
 * @test The copied iterator must point at the same splay as the original.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestCopyContents
( void );

/**
 * Tests the iterator returned by the DSplayItrCopy function.
 *
 * @test The copied iterator must be a different value than the original.
 * Advancing to the next element of the copy must not affect the position of the
 * original. Advancing to the previous element of the copy must not affect the
 * original.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestCopyDistinct
( void );

/**
 * Tests the DSplayItrCopy function with a NULL iterator.
 *
 * @test A NULL iterator must return NULL.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestCopyNullIterator
( void );

/**
 * Tests the position of the iterator returned by the DSplayItrCopy
 * function.
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
 * Tests the DSplayItrDestroy function.
 *
 * @test Destroying a iterator must not cause an error.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestDestroy
( void );

/**
 * Tests the DSplayItrDestroy function with a NULL iterator.
 *
 * @test A NULL iterator must not cause an error.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestDestroyNullIterator
( void );

/**
 * Tests the DSplayEnd function with an empty splay.
 *
 * @test A non-NULL iterator must be returned for an empty splay. The
 * next and previous element must be NULL in this iterator.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestEndWithEmptyDynamicSplay
( void );

/**
 * Tests the DSplayEnd function with a NULL splay.
 *
 * @test NULL must be returned for a NULL splay.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestEndWithNullDynamicSplay
( void );

/**
 * Tests the DSplayEnd function with a populated splay.
 *
 * @test A non-NULL iterator must be returned for a populated splay. The next
 * element must be NULL. The previous element must be the last value in the
 * splay.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestEndWithPopulatedDynamicSplay
( void );

/**
 * Tests the DSplayItrHasNext function at the beginning of a splay.
 *
 * @test A iterator at the beginning of a splay must return a value that
 * evaluates to true.
 *
 * @test NULL on success or a string describing the failure
 */
const char *
TestHasNextAtBeginning
( void );

/** 
 * Tests the DSplayItrHasNext function at the end of a splay.
 *
 * @test A iterator at the end of a splay must return a value that evaluates
 * to false.
 *
 * @test NULL on success or a string describing the failure
 */
const char *
TestHasNextAtEnd
( void );

/**
 * Tests the DSplayItrHasNext function at the middle of a splay.
 *
 * @test A iterator at the middle of a splay must return a value that
 * evaluates to true.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestHasNextAtMiddle
( void );

/**
 * Tests the DSplayItrHasNext function with an empty splay.
 *
 * @test Calling the function with a iterator from an empty splay must return
 * a value that evaluates to false.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestHasNextWithEmptyDynamicSplay
( void );

/**
 * Tests the DSplayItrHasNext function with a NULL iterator.
 *
 * @test Calling the function with a NULL iterator must return a value that
 * evaluates to false.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestHasNextWithNullIterator
( void );

/**
 * Tests the DSplayItrHasPrevious function at the beginning of a splay.
 *
 * @test A iterator at the beginning of a splay must return a value that
 * evaluates to false.
 *
 * @test NULL on success or a string describing the failure
 */
const char *
TestHasPreviousAtBeginning
( void );

/** 
 * Tests the DSplayItrHasPrevious function at the end of a splay.
 *
 * @test A iterator at the end of a splay must return a value that evaluates
 * to true.
 *
 * @test NULL on success or a string describing the failure
 */
const char *
TestHasPreviousAtEnd
( void );

/**
 * Tests the DSplayItrHasPrevious function at the middle of a splay.
 *
 * @test A iterator at the middle of a splay must return a value that
 * evaluates to true.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestHasPreviousAtMiddle
( void );

/**
 * Tests the DSplayItrHasPrevious function with an empty splay.
 *
 * @test Calling the function with a iterator from an empty splay must return
 * a value that evaluates to false.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestHasPreviousWithEmptyDynamicSplay
( void );

/**
 * Tests the DSplayItrHasPrevious function with a NULL iterator.
 *
 * @test Calling the function with a NULL iterator must return a value that
 * evaluates to false.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestHasPreviousWithNullIterator
( void );

/**
 * Tests the DSplayItrNext function at the beginning of a splay.
 *
 * @test A iterator that is at the beginning of a splay must return the first
 * value in the splay.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestNextAtBeginning
( void );

/**
 * Tests the DSplayItrNext function at the end of a splay.
 *
 * @test A iterator that is at the end of a splay must return NULL.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestNextAtEnd
( void );

/**
 * Tests the DSplayItrNext function in the middle of a splay.
 *
 * @test A iterator that is in the middle of the splay must return,
 * order, the elements of the splay.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestNextAtMiddle
( void );

/**
 * Tests the DSplayItrNext function with an empty splay.
 *
 * @test Calling the function with an empty splay must return NULL.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestNextWithEmptyDynamicSplay
( void );

/**
 * Tests the DSplayItrNext function with a NULL iterator.
 *
 * @test Calling the function with a NULL iterator must return NULL.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestNextWithNullIterator
( void );

/**
 * Tests the DSplayItrPrevious function at the beginning of a splay.
 *
 * @test A iterator that is at the beginning of a splay must return NULL.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestPreviousAtBeginning
( void );

/**
 * Tests the DSplayItrPrevious function at the end of a splay.
 *
 * @test A iterator that is at the end of a splay must return the last
 * element in the splay.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestPreviousAtEnd
( void );

/**
 * Tests the DSplayItrPrevious function in the middle of a splay.
 *
 * @test A iterator that is in the middle of the splay must return, in
 * reverse order, the elements of the splay.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestPreviousAtMiddle
( void );

/**
 * Tests the DSplayItrPrevious function with an empty splay.
 *
 * @test Calling the function with an empty splay must return NULL.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestPreviousWithEmptyDynamicSplay
( void );

/**
 * Tests the DSplayItrPrevious function with a NULL iterator.
 *
 * @test Calling the function with a NULL iterator must return NULL.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestPreviousWithNullIterator
( void );

/**
 * Tests the DSplayItrRemove function after a call to DSplayItrNext.
 *
 * @test Calling the function after a call to DSplayItrNext must return the
 * element returned by the previous call to DSplayItrNext. The element must
 * be removed from the splay. The position of the iterator must be the same
 * as before the call to DSplayItrRemove.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestRemoveAfterNext
( void );

/**
 * Tests the DSplayItrRemove function after a call to
 * PreviousInsplayITerator.
 *
 * @test Calling the function after a call to DSplayItrPrevious must return
 * the element returned by the previous call to DSplayItrPrevious.The
 * element must be removed from the splay. The position of the iterator must
 * be the same as before the call to DSplayItrRemove.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestRemoveAfterPrevious
( void );

/**
 * Tests the DSplayItrRemove function when called twice without a call to
 * DSplayItrNext or DSplayItrPrevious made in between.
 *
 * @test Calling the DSplayItrRemove function twice without a call to
 * DSplayItrNext or DSplayItrPrevious in between must return NULL on
 * the second call and leave the splay unchanged. The first call's element must
 * remain removed from the splay. The position of the iterator must not be
 * changed by the second call to DSplayItrRemove.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestRemoveAfterRemove
( void );

/**
 * Tests the DSplayItrRemove function before any calls to
 * DSplayItrNext or DSplayItrPrevious.
 *
 * @test Calling the function before a previous call to DSplayItrNext or
 * DSplayItrPrevious must return NULL and not change the position of the
 * iterator.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestRemoveBeforeNextOrPrevious
( void );

/**
 * Tests the DSplayItrRemove function with a NULL iterator.
 *
 * @test A NULL iterator must return NULL.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestRemoveFromNullIterator
( void );

#endif
