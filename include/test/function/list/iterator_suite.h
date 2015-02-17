#ifndef __WOODPILE_TEST_FUNCTION_LIST_ITERATOR_SUITE_H
#define __WOODPILE_TEST_FUNCTION_LIST_ITERATOR_SUITE_H

/**
 * @file
 * Tests for the ListIterator functions.
 */

/**
 * Tests the AddToListIterator function.
 *
 * @test A NULL iterator must return NULL. A NULL element must return the
 * iterator, without altering the list. Adding an element to an empty list must
 * make the element be the only one in the list. Adding an element at the
 * beginning of the list must make the element the first in the list. Adding
 * an element at the end of the list must make the element the last in the list.
 * An element added in the middle of the list must be added in the correct
 * place.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestAdd
( void );

/**
 * Tests the BeginList function.
 *
 * @test A NULL list must return NULL. An empty list must return an iterator
 * set to the correct list. The iterator returned for a populated list must
 * be set to the first element of the list.
 * 
 * @return NULL on success or a string describing the failure
 */
const char *
TestBegin
( void );

/**
 * Tests the CopyListIterator function.
 *
 * @test A NULL iterator must return NULL. The copy for an iterator must point
 * to the same list as the original. The copy of an iterator must be set to the
 * same location as the original at the time of the copy. Advancing the position
 * of the copy must not affect the original. Advancing the position of the
 * original must not affect the copy.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestCopy
( void );

/**
 * Tests the DestroyListIterator function.
 *
 * @test A NULL iterator must not cause an error. A valid iterator must not
 * cause an error. Destroying an iterator must not affect the list it was
 * assigned to.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestDestroy
( void );

/**
 * Tests the EndList function.
 *
 * @test A NULL list must return NULL. An empty list must return an iterator
 * set to the correct list. The iterator returned for a populated list must
 * be set after the last element of the list.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestEnd
( void );

/**
 * Tests the ListIteratorHasNext function.
 *
 * @test A NULL iterator must return 0. An iterator at the beginning of an empty
 * list must return 0. An iterator at the beginning of a populated list must
 * return 1. An iterator in the middle of a populated list must return 1. An
 * iterator at the end of a populated list must return 0.
 * 
 * @return NULL on success or a string describing the failure
 */
const char *
TestHasNext
( void );

/**
 * Tests the ListIteratorHasPrevious function.
 *
 * @test A NULL iterator must return 0. An iterator at the beginning of an empty
 * list must return 0. An iterator at the beginning of a populated list must
 * return 0. An iterator in the middle of a populated list must return 1. An
 * iterator at the end of a populated list must return 1.
 * 
 * @return NULL on success or a string describing the failure
 */
const char *
TestHasPrevious
( void );

/**
 * Test the NextInListIterator function.
 *
 * @test A NULL iterator must return NULL. an iterator at the beginning of an
 * empty list must return NULL. An iterator at the beginning of a populated list
 * must return the first element. An iterator in the middle of a populated list
 * must return the next element. An iterator at the end of a populated list must
 * return NULL.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestNext
( void );

/**
 * Test the PreviousInListIterator function.
 *
 * @test A NULL iterator must return NULL. an iterator at the beginning of an
 * empty list must return NULL. An iterator at the beginning of a populated list
 * must return NULL. An iterator in the middle of a populated list must return
 * the previous element. An iterator at the end of a populated list must return
 * NULL.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestPrevious
( void );

/**
 * Test the RemoveFromListIterator function.
 *
 * @test A NULL iterator must return NULL. Calling the function without a
 * previous call to NextInListIterator or PreviousInListIterator must return
 * NULL. Calling the function with a prior call to NextInListIterator must
 * return the previous value returned by NextInListIterator and remove the value
 * from the list leaving the order of the list unchanged. Calling the function
 * with a prior call to PreviousInListIterator must return the previous value
 * returned by PreviousInListIterator and remove the value from the list leaving
 * the order of the list unchanged. Calling the function with a prior call to
 * NextInListIterator but a more recent call to AddToListIterator must return
 * NULL and leave the list unchanged. Calling the function with a prior call to
 * PreviousInListIterator but a more recent call to AddToListIterator must
 * return NULL and leave the list unchanged. Calling the function after a prior
 * call returning non-NULL before a call to NextInListIterator or
 * PreviousInListIterator must return NULL and leave the list unchanged.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestRemove
( void );

#endif
