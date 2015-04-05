#ifndef __WOODPILE_TEST_FUNCTION_LIST_CONST_ITERATOR_SUITE_H
#define __WOODPILE_TEST_FUNCTION_LIST_CONST_ITERATOR_SUITE_H

/**
 * @file
 * Tests for the ListConstIterator functions.
 */

/**
 * Tests the CBeginList function with an empty List.
 *
 * @test A non-NULL ListConstIterator must be returned for an empty List. The
 * next and previous element must be NULL in this ListConstIterator.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestCBeginWithEmptyList
( void );

/**
 * Tests the CBeginList function with a NULL List.
 *
 * @test NULL must be returned for a NULL List.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestCBeginWithNullList
( void );

/**
 * Tests the CBeginList function with a populated List.
 *
 * @test A non-NULL ListConstIterator must be returned for a populated List. The
 * previous element must be NULL. The next element must be the first value in
 * the List.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestCBeginWithPopulatedList
( void );

/**
 * Tests the CEndList function with an empty List.
 *
 * @test A non-NULL ListConstIterator must be returned for an empty List. The
 * next and previous element must be NULL in this ListConstIterator.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestCEndWithEmptyList
( void );

/**
 * Tests the CEndList function with a NULL List.
 *
 * @test NULL must be returned for a NULL List.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestCEndWithNullList
( void );

/**
 * Tests the CEndList function with a populated List.
 *
 * @test A non-NULL ListConstIterator must be returned for a populated List. The
 * next element must be NULL. The previous element must be the last value in the
 * List.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestCEndWithPopulatedList
( void );

/**
 * Tests the CopyListConstIterator function.
 *
 * @test A non-NULL ListConstIterator must be returned as the copy of a non-NULL
 * ListConstIterator.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestCopy
( void );

/**
 * Tests the contents of the ListConstIterator returned by the
 * CopyListConstIterator function.
 *
 * @test The copied ListConstIterator must point at the same List as the
 * original.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestCopyContents
( void );

/**
 * Tests the ListConstIterator returned by the CopyListConstIterator function.
 *
 * @test The copied ListConstIterator must be a different value than the
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
 * Tests the CopyListConstIterator function with a NULL ListConstIterator.
 *
 * @test A NULL ListConstIterator must return NULL.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestCopyNullIterator
( void );

/**
 * Tests the position of the ListConstIterator returned by the
 * CopyListConstIterator function.
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
 * Tests the DestroyListConstIterator function.
 *
 * @test Destroying a ListConstIterator must not cause an error.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestDestroy
( void );

/**
 * Tests the DestroyListConstIterator function with a NULL ListConstIterator.
 *
 * @test A NULL ListConstIterator must not cause an error.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestDestroyNullIterator
( void );

/**
 * Tests the ListConstIteratorHasNext function at the beginning of a List.
 *
 * @test A ListConstIterator at the beginning of a List must return a value that
 * evaluates to true.
 *
 * @test NULL on success or a string describing the failure
 */
const char *
TestHasNextAtBeginning
( void );

/** 
 * Tests the ListConstIteratorHasNext function at the end of a List.
 *
 * @test A ListConstIterator at the end of a List must return a value that
 * evaluates to false.
 *
 * @test NULL on success or a string describing the failure
 */
const char *
TestHasNextAtEnd
( void );

/**
 * Tests the ListConstIteratorHasNext function at the middle of a List.
 *
 * @test A ListConstIterator at the middle of a List must return a value that
 * evaluates to true.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestHasNextAtMiddle
( void );

/**
 * Tests the ListConstIteratorHasNext function with an empty List.
 *
 * @test Calling the function with a ListConstIterator from an empty List must
 * return a value that evaluates to false.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestHasNextWithEmptyList
( void );

/**
 * Tests the ListConstIteratorHasNext function with a NULL ListConstIterator.
 *
 * @test Calling the function with a NULL ListConstIterator must return a value
 * that evaluates to false.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestHasNextWithNullIterator
( void );

/**
 * Tests the ListConstIteratorHasPrevious function at the beginning of a List.
 *
 * @test A ListConstIterator at the beginning of a List must return a value that
 * evaluates to false.
 *
 * @test NULL on success or a string describing the failure
 */
const char *
TestHasPreviousAtBeginning
( void );

/** 
 * Tests the ListConstIteratorHasPrevious function at the end of a List.
 *
 * @test A ListConstIterator at the end of a List must return a value that
 * evaluates to true.
 *
 * @test NULL on success or a string describing the failure
 */
const char *
TestHasPreviousAtEnd
( void );

/**
 * Tests the ListConstIteratorHasPrevious function at the middle of a List.
 *
 * @test A ListConstIterator at the middle of a List must return a value that
 * evaluates to true.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestHasPreviousAtMiddle
( void );

/**
 * Tests the ListConstIteratorHasPrevious function with an empty List.
 *
 * @test Calling the function with a ListConstIterator from an empty List must
 * return a value that evaluates to false.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestHasPreviousWithEmptyList
( void );

/**
 * Tests the ListConstIteratorHasPrevious function with a NULL ListConstIterator.
 *
 * @test Calling the function with a NULL ListConstIterator must return a value
 * that evaluates to false.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestHasPreviousWithNullIterator
( void );

/**
 * Tests the NextInListConstIterator function at the beginning of a List.
 *
 * @test A ListConstIterator that is at the beginning of a List must return
 * the first value in the List.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestNextAtBeginning
( void );

/**
 * Tests the NextInListConstIterator function at the end of a List.
 *
 * @test A ListConstIterator that is at the end of a List must return NULL.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestNextAtEnd
( void );

/**
 * Tests the NextInListConstIterator function in the middle of a List.
 *
 * @test A ListConstIterator that is in the middle of the List must return, in
 * order, the elements of the List.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestNextAtMiddle
( void );

/**
 * Tests the NextInListConstIterator function with an empty List.
 *
 * @test Calling the function with an empty List must return NULL.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestNextWithEmptyList
( void );

/**
 * Tests the NextInListConstIterator function with a NULL iterator.
 *
 * @test Calling the function with a NULL ListConstIterator must return NULL.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestNextWithNullIterator
( void );

/**
 * Tests the PreviousInListConstIterator function at the beginning of a List.
 *
 * @test A ListConstIterator that is at the beginning of a List must return
 * NULL.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestPreviousAtBeginning
( void );

/**
 * Tests the PreviousInListConstIterator function at the end of a List.
 *
 * @test A ListConstIterator that is at the end of a List must return the last
 * element in the List.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestPreviousAtEnd
( void );

/**
 * Tests the PreviousInListConstIterator function in the middle of a List.
 *
 * @test A ListConstIterator that is in the middle of the List must return, in
 * reverse order, the elements of the List.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestPreviousAtMiddle
( void );

/**
 * Tests the PreviousInListConstIterator function with an empty List.
 *
 * @test Calling the function with an empty List must return NULL.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestPreviousWithEmptyList
( void );

/**
 * Tests the PreviousInListConstIterator function with a NULL iterator.
 *
 * @test Calling the function with a NULL ListConstIterator must return NULL.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestPreviousWithNullIterator
( void );

#endif
