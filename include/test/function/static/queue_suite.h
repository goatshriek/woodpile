#ifndef __WOODPILE_TEST_FUNCTION_STATIC_QUEUE_SUITE_H
#define __WOODPILE_TEST_FUNCTION_STATIC_QUEUE_SUITE_H

/**
 * @file
 * Queue tests
 */

/**
 * Tests the QueueContains function with a value existing multiple times in the
 * Queue.
 *
 * @test A value existing twice in the Queue must return 2. A value existing
 * three times in the Queue must return 3.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestContainsDuplicateValues
( void );

/**
 * Tests the QueueContains function with a value that does not exist in the
 * Queue.
 *
 * @test A value not existing in the Queue must return 0.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestContainsNonExistentValue
( void );

/**
 * Tests the QueueContains function a NULL value supplied.
 *
 * @test A NULL value must return 0, whether the Queue supplied is NULL or
 * non-NULL.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestContainsNullValue
( void );

/**
 * Tests the QueueContains function with values that exist in the Queue exactly
 * once.
 *
 * @test A value existing exaclty once in the Queue must return 1.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestContainsUniqueValue
( void );

/**
 * Tests the QueueContains function with a NULL Queue.
 *
 * @test A NULL queue must return 0, whether the value supplied is NULL or
 * non-NULL.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestContainsWithNullQueue
( void );

/**
 * Tests the contents of the Queue returned by the CopyQueue function.
 *
 * @test The copied Queue must point at the same elements as the original.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestCopyContents
( void );

/**
 * Tests the PeekAtQueue function with an Empty Queue.
 *
 * @test Peeking at an empty Queue must return NULL.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestPeekAtEmptyQueue
( void );

/**
 * Tests the PeekAtQueue function with a NULL Queue.
 *
 * @test Peeking at a NULL Queue must return NULL.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestPeekAtNullQueue
( void );

/**
 * Tests the PeekAtQueue function with a populated Queue.
 *
 * @test Peeking at a filled Queue must return the value at the front of the
 * Queue.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestPeekAtPopulatedQueue
( void );

/**
 * Tests the PopFromQueue function with an Empty Queue.
 *
 * @test Popping from an empty Queue must return NULL.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestPopFromEmptyQueue
( void );

/**
 * Tests the PopFromQueue function with a NULL Queue.
 *
 * @test Popping from a NULL Queue must return NULL.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestPopFromNullQueue
( void );

/**
 * Tests the PopFromQueue function with a populated Queue.
 *
 * @test Popping from a filled Queue must return the value at the front of the Queue.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestPopFromPopulatedQueue
( void );

/**
 * Tests the PopFromQueue function to make sure it removes the value returned.
 *
 * @test A call to PopFromQueue must return the first value in the Queue. The
 * next call must return the second value. The next call must return the third
 * value. The next must return the fourth, and the next the fifth.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestPopRemovesValue
( void );

/**
 * Tests the PushToQueue function with a NULL value.
 *
 * @test Pushing a NULL value must return NULL, whether the value supplied is
 * NULL or non-NULL.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestPushNullValue
( void );

/**
 * Tests the PushToQueue function with an empty Queue.
 *
 * @test Pushing to an empty Queue must result in the element being in the front
 * of the Queue and the size of the Queue being one.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestPushToEmptyQueue
( void );

/**
 * Tests the PushToQueue function with a NULL Queue.
 *
 * @test Pushing to a NULL Queue must return NULL, whether the value supplied
 * is NULL or non-NULL.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestPushToNullQueue
( void );

/**
 * Tests the PushToQueue function with a populated Queue.
 *
 * @test Pushing to a populated Queue must put the element at the back, and
 * leave the front element unchanged.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestPushToPopulatedQueue
( void );

/**
 * Tests the RemoveFromQueue function with a value that exists in the Queue more
 * than once.
 *
 * @test A Queue that has the value twice will have the first occurrence
 * removed and returned, but not the second.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestRemoveDuplicateValues
( void );

/**
 * Tests the RemoveFromQueue function with a NULL Queue.
 *
 * @test Removing from a NULL Queue must return NULL, whether the value
 * supplied is NULL or non-NULL.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestRemoveFromNullQueue
( void );

/**
 * Tests the RemoveFromQueue function when removing the last value from the
 * Queue.
 *
 * @test Removing the only element in a Queue must remove and return the element
 * and leav the Queue empty.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestRemoveLast
( void );

/**
 * Tests the RemoveFromQueue function with a value that does not exist in the
 * Queue.
 *
 * @test Removing a value that is not in the Queue must return NULL.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestRemoveNonExistentValue
( void );

/**
 * Tests the RemoveFromQueue function with a NULL value.
 *
 * @test Removing a NULL value must return NULL, whether the Queue supplied is
 * NULL or non-NULL.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestRemoveNullValue
( void );

/**
 * Tests the RemoveFromQueue function with a value that exists in the Queue
 * exactly once.
 *
 * @test Removing a value that is in the Queue once must return the value from
 * the Queue and remove the only instance of it.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestRemoveUniqueValue
( void );

/**
 * Tests the QueueSize function.
 *
 * @test A populated Queue must return an accurate count of the values.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestSize
( void );

#endif
