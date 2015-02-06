#ifndef __STUMPLESS_PRIVATE_CONTAINER_QUEUE_H
#define __STUMPLESS_PRIVATE_CONTAINER_QUEUE_H

/**
 * @file
 * Implements a basic Queue data structure. Items can only be pushed to the back
 * of the Queue, and taken from the front.
 *
 * Memory for this structure is allocated in blocks. The initial capacity of the
 * Queue can be set by using the NewSizedQueue constructor function, and can be
 * changed later using the SetQueueCapacity and TrimQueueToSize functions.
 *
 * Memory overhead can be calculated as follows:
 * ( sizeof( size_t ) * 3 ) + ( sizeof( void * ) * ( queue_capacity + 1 ) )
 */

/**
 * Creates a copy of the given Queue. If the supplied Queue is NULL, then a
 * NULL is returned.
 *
 * @param queue the Queue to copy
 *
 * @return the copy of the original Queue, or NULL on failure.
 */
Queue *
CopyQueue
( const Queue *queue );

/**
 * Destroys a Queue
 *
 * @param queue the Queue to destroy
 */
void
DestroyQueue
( Queue *queue );

/**
 * Creates a new Queue. The default capacity of the Queue is 100.
 *
 * @return the new Queue, or NULL on failure
 */
Queue *
NewQueue
( void );

/**
 * Creates a new Queue of the given capcity.
 *
 * @param capacity the capacity to give the Queue
 *
 * @return a new Queue of the provided capacity, or NULL on failure
 */
Queue *
NewSizedQueue
( size_t capacity );

/**
 * Gets the front element of the Queue, but does not remove it.
 *
 * @param queue the Queue to get the front element of
 *
 * @return the front element of the Queue
 */
void *
PeekAtQueue
( const Queue *queue );

/**
 * Removes the front element from the Queue and returns it.
 *
 * @param queue the Queue to pull the front value from
 *
 * @return the front value of the Queue, or NULL on failure
 */
void *
PopFromQueue
( Queue *queue );

/**
 * Puts an element at the back of the Queue. If the Queue or value passed are
 * NULL then no action is taken and NULL is returned.
 *
 * @param queue the Queue to push to
 * @param value the value to push to the Queue
 *
 * @return the Queue pushed to, or NULL on failure
 */
Queue *
PushToQueue
( Queue *queue, void *value );

/**
 * Gets the maximum number of elements the Queue can hold.
 *
 * @param queue the Queue to check the capacity of
 *
 * @return the maximum number of elements the Queue can hold
 */
size_t
QueueCapacity
( const Queue *queue );

/**
 * Searches a Queue for a specific value.
 *
 * @param queue the Queue to search for the value
 * @param value the value to search for in the Queue
 *
 * @return the number of times the Queue contains the value, and 0 if it does
 * not
 */
size_t
QueueContains
( const Queue *queue, const void *value );

/**
 * Checks a Queue to see if it's empty.
 *
 * @param queue the Queue to check
 *
 * @return a positive value if the Queue is empty, 0 otherwise
 */
unsigned short
QueueIsEmpty
( const Queue *queue );

/**
 * Gets the number of elements in a Queue. If a NULL Queue is provided then the
 * size will be 0.
 *
 * @param queue the Queue to measure
 *
 * @return the number of elements in the Queue
 */
size_t
QueueSize
( const Queue *queue);

/**
 * Removes the first occurrence of a value from the Queue given. If the value
 * exists more than once in the Queue, the closest to the front (the one that
 * would be popped first) is removed.
 *
 * @param queue the Queue to remove the value from
 * @param value the value to remove
 *
 * @return the value removed, or NULL if the value did not exist in the Queue
 */
void *
RemoveFromQueue
( Queue *queue, const void *value );

/**
 * Changes a Queue's capacity to a new value. If the new capacity is smaller
 * than the current number of elements, then the elements at the back of the
 * Queue that no longer have room are dropped.
 *
 * @param queue the Queue to resize
 * @param capacity the new capacity of the Queue
 *
 * @return the Queue having been resized
 */
Queue *
SetQueueCapacity
( Queue *queue, size_t capacity );

/**
 * Shrinks the Queue to its current size. This guarantees that the Queue is
 * using the minimum amount of memory available. If the Queue cannot be resized,
 * then the Queue is left at the original size (which is returned).
 *
 * @param queue the Queue to resize
 *
 * @return the new size of the Queue
 */
size_t
TrimQueueToSize
( Queue *queue );

#endif
