#ifndef __WOODPILE_TEST_FUNCTION_LIST_CONST_ITERATOR_SUITE_H
#define __WOODPILE_TEST_FUNCTION_LIST_CONST_ITERATOR_SUITE_H

/**
 * @file
 * Tests for the ListConstIterator functions.
 */

/**
 * Tests the CBeginList function.
 *
 * @test A NULL list must return NULL. An empty list must return an iterator
 * set to the correct list. The iterator returned for a populated list must
 * be set to the first element of the list.
 * 
 * @return NULL on success or a string describing the failure
 */
const char *
TestCBegin
( void );

/**
 * Tests the CEndList function.
 *
 * @test A NULL list must return NULL. An empty list must return an iterator
 * set to the correct list. The iterator returned for a populated list must
 * be set after the last element of the list.
 *
 * @return NULL on success or a string describing the failure
 */
const char *
TestCEnd
( void );

/**
 * Tests the CopyListConstIterator function.
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
 * Tests the ListConstIteratorHasNext function.
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
 * Tests the ListConstIteratorHasPrevious function.
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
 * Test the NextInListConstIterator function.
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
 * Test the PreviousInListConstIterator function.
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

#endif
