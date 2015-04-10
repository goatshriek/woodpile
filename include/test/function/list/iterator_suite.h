#ifndef __WOODPILE_TEST_FUNCTION_LIST_ITERATOR_SUITE_H
#define __WOODPILE_TEST_FUNCTION_LIST_ITERATOR_SUITE_H

/**
 * @file
 * Tests for the ListIterator functions.
 */

/**
 * Tests the AddToListIterator function with a NULL element.
 *
 * @test Adding a NULL element must return the ListIterator, regardless of
 * whether it was NULL or non-NULL.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestAddNullElement
( void );

/**
 * Tests the AddToListIterator function with a ListIterator at the beginning of
 * a List.
 *
 * @test Adding an element while at the beginning of the List must place it at
 * the beginning of the List. The ListIterator must have a previous element as
 * well as a next. The previous element in the ListIterator must be the newly
 * added element.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestAddToBeginning
( void );

/**
 * Tests the AddToListIterator function with a ListIterator for an empty List.
 *
 * @test Adding an element to an empty List must make the element the only one
 * in the List. The ListIterator must have a previous element, but no next. The
 * previous element in the ListIterator must be the newly added element.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestAddToEmptyList
( void );

/**
 * Tests the AddToListIterator function with a ListIterator at the end of a
 * List.
 *
 * @test Adding an element while at the end of a List must place it at the end
 * of the List. The ListIterator must have a previous element, but no next. The
 * previous element in the ListIterator must be the newly added element.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestAddToEnd
( void );

/**
 * Tests the AddToListIterator function with a ListIterator in the middle of a
 * List.
 *
 * @test Adding an element in the middle of a List must insert it into the List
 * at the appropriate position. The ListIterator must have both a previous and 
 * next element, with the previous being the newly added element.
 * 
 * @return NULL on success or a string describing the failure
 */
const char *
TestAddToMiddle
( void );

/**
 * Tests the AddToListIterator function with a NULL ListIterator.
 *
 * @test A NULL ListIterator must return NULL, regardless of whether the element
 * is NULL or non-NULL.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestAddWithNullIterator
( void );

/**
 * Tests the BeginList function with an empty List.
 *
 * @test A non-NULL ListIterator must be returned for an empty List. The next
 * and previous element must be NULL in this ListIterator.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestBeginWithEmptyList
( void );

/**
 * Tests the BeginList function with a NULL List.
 *
 * @test NULL must be returned for a NULL List.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestBeginWithNullList
( void );

/**
 * Tests the BeginList function with a populated List.
 *
 * @test A non-NULL ListIterator must be returned for a populated List. The
 * previous element must be NULL. The next element must be the first value in
 * the List.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestBeginWithPopulatedList
( void );

/**
 * Tests the CopyListIterator function.
 *
 * @test A non-NULL ListIterator must be returned as the copy of a non-NULL
 * ListIterator.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestCopy
( void );

/**
 * Tests the contents of the ListIterator returned by the CopyListIterator
 * function.
 *
 * @test The copied ListIterator must point at the same List as the
 * original.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestCopyContents
( void );

/**
 * Tests the ListIterator returned by the CopyListIterator function.
 *
 * @test The copied ListIterator must be a different value than the original.
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
 * Tests the CopyListIterator function with a NULL ListIterator.
 *
 * @test A NULL ListIterator must return NULL.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestCopyNullIterator
( void );

/**
 * Tests the position of the ListIterator returned by the CopyListIterator
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
 * Tests the DestroyListIterator function.
 *
 * @test Destroying a ListIterator must not cause an error.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestDestroy
( void );

/**
 * Tests the DestroyListIterator function with a NULL ListIterator.
 *
 * @test A NULL ListIterator must not cause an error.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestDestroyNullIterator
( void );

/**
 * Tests the EndList function with an empty List.
 *
 * @test A non-NULL ListIterator must be returned for an empty List. The
 * next and previous element must be NULL in this ListIterator.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestEndWithEmptyList
( void );

/**
 * Tests the EndList function with a NULL List.
 *
 * @test NULL must be returned for a NULL List.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestEndWithNullList
( void );

/**
 * Tests the EndList function with a populated List.
 *
 * @test A non-NULL ListIterator must be returned for a populated List. The next
 * element must be NULL. The previous element must be the last value in the
 * List.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestEndWithPopulatedList
( void );

/**
 * Tests the ListIteratorHasNext function at the beginning of a List.
 *
 * @test A ListIterator at the beginning of a List must return a value that
 * evaluates to true.
 *
 * @test NULL on success or a string describing the failure
 */
const char *
TestHasNextAtBeginning
( void );

/** 
 * Tests the ListIteratorHasNext function at the end of a List.
 *
 * @test A ListIterator at the end of a List must return a value that evaluates
 * to false.
 *
 * @test NULL on success or a string describing the failure
 */
const char *
TestHasNextAtEnd
( void );

/**
 * Tests the ListIteratorHasNext function at the middle of a List.
 *
 * @test A ListIterator at the middle of a List must return a value that
 * evaluates to true.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestHasNextAtMiddle
( void );

/**
 * Tests the ListIteratorHasNext function with an empty List.
 *
 * @test Calling the function with a ListIterator from an empty List must return
 * a value that evaluates to false.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestHasNextWithEmptyList
( void );

/**
 * Tests the ListIteratorHasNext function with a NULL ListIterator.
 *
 * @test Calling the function with a NULL ListIterator must return a value that
 * evaluates to false.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestHasNextWithNullIterator
( void );

/**
 * Tests the ListIteratorHasPrevious function at the beginning of a List.
 *
 * @test A ListIterator at the beginning of a List must return a value that
 * evaluates to false.
 *
 * @test NULL on success or a string describing the failure
 */
const char *
TestHasPreviousAtBeginning
( void );

/** 
 * Tests the ListIteratorHasPrevious function at the end of a List.
 *
 * @test A ListIterator at the end of a List must return a value that evaluates
 * to true.
 *
 * @test NULL on success or a string describing the failure
 */
const char *
TestHasPreviousAtEnd
( void );

/**
 * Tests the ListIteratorHasPrevious function at the middle of a List.
 *
 * @test A ListIterator at the middle of a List must return a value that
 * evaluates to true.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestHasPreviousAtMiddle
( void );

/**
 * Tests the ListIteratorHasPrevious function with an empty List.
 *
 * @test Calling the function with a ListIterator from an empty List must return
 * a value that evaluates to false.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestHasPreviousWithEmptyList
( void );

/**
 * Tests the ListIteratorHasPrevious function with a NULL ListIterator.
 *
 * @test Calling the function with a NULL ListIterator must return a value that
 * evaluates to false.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestHasPreviousWithNullIterator
( void );

/**
 * Tests the NextInListIterator function at the beginning of a List.
 *
 * @test A ListIterator that is at the beginning of a List must return the first
 * value in the List.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestNextAtBeginning
( void );

/**
 * Tests the NextInListIterator function at the end of a List.
 *
 * @test A ListIterator that is at the end of a List must return NULL.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestNextAtEnd
( void );

/**
 * Tests the NextInListIterator function in the middle of a List.
 *
 * @test A ListIterator that is in the middle of the List must return,
 * order, the elements of the List.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestNextAtMiddle
( void );

/**
 * Tests the NextInListIterator function with an empty List.
 *
 * @test Calling the function with an empty List must return NULL.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestNextWithEmptyList
( void );

/**
 * Tests the NextInListIterator function with a NULL iterator.
 *
 * @test Calling the function with a NULL ListIterator must return NULL.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestNextWithNullIterator
( void );

/**
 * Tests the PreviousInListIterator function at the beginning of a List.
 *
 * @test A ListIterator that is at the beginning of a List must return NULL.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestPreviousAtBeginning
( void );

/**
 * Tests the PreviousInListIterator function at the end of a List.
 *
 * @test A ListIterator that is at the end of a List must return the last
 * element in the List.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestPreviousAtEnd
( void );

/**
 * Tests the PreviousInListIterator function in the middle of a List.
 *
 * @test A ListIterator that is in the middle of the List must return, in
 * reverse order, the elements of the List.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestPreviousAtMiddle
( void );

/**
 * Tests the PreviousInListIterator function with an empty List.
 *
 * @test Calling the function with an empty List must return NULL.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestPreviousWithEmptyList
( void );

/**
 * Tests the PreviousInListIterator function with a NULL iterator.
 *
 * @test Calling the function with a NULL ListIterator must return NULL.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestPreviousWithNullIterator
( void );

/**
 * Tests the RemoveFromListIterator function after a call to NextInListIterator.
 *
 * @test Calling the function after a call to NextInListIterator must return the
 * element returned by the previous call to NextInListIterator. The element must
 * be removed from the List. The position of the ListIterator must be the same
 * as before the call to RemoveFromListIterator.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestRemoveAfterNext
( void );

/**
 * Tests the RemoveFromListIterator function after a call to NextInListIterator
 * followed by a call to AddToListIterator.
 *
 * @test Calling the function after a call to NextInListIterator that was
 * followed by a call to AddToListIterator must return NULL and not remove the
 * last value returned by NextInListIterator or the value that was added by the
 * call to AddToListIterator. The position of the ListIterator must not be
 * changed by the call to RemoveFromListIterator.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestRemoveAfterNextAndAdd
( void );

/**
 * Tests the RemoveFromListIterator function after a call to
 * PreviousInListITerator.
 *
 * @test Calling the function after a call to PreviousInListIterator must return
 * the element returned by the previous call to PreviousInListIterator.The
 * element must be removed from the List. The position of the ListIterator must
 * be the same as before the call to RemoveFromListIterator.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestRemoveAfterPrevious
( void );

/**
 * Tests the RemoveFromListIterator function after a call to
 * PreviousInListIterator followed by a call to AddToListIterator.
 *
 * @test Calling the function after a call to PreviousInListIterator that was
 * followed by a call to AddToListIterator must return NULL and not remove the
 * last value returned by PreviousInListIterator or the value that was added by
 * the call to AddToListIterator. The position of the ListIterator must not be
 * changed by the call to RemoveFromListIterator.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestRemoveAfterPreviousAndAdd
( void );

/**
 * Tests the RemoveFromListIterator function when called twice without a call to
 * NextInListIterator or PreviousInListIterator made in between.
 *
 * @test Calling the RemoveFromListIterator function twice without a call to
 * NextInListIterator or PreviousInListIterator in between must return NULL on
 * the second call and leave the List unchanged. The first call's element must
 * remain removed from the List. The position of the ListIterator must not be
 * changed by the second call to RemoveFromListIterator.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestRemoveAfterRemove
( void );

/**
 * Tests the RemoveFromListIterator function before any calls to
 * NextInListIterator or PreviousInListIterator.
 *
 * @test Calling the function before a previous call to NextInListIterator or
 * PreviousInListIterator must return NULL and not change the position of the
 * ListIterator.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestRemoveBeforeNextOrPrevious
( void );

/**
 * Tests the RemoveFromListIterator function with a NULL ListIterator.
 *
 * @test A NULL iterator must return NULL.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestRemoveFromNullIterator
( void );

#endif
