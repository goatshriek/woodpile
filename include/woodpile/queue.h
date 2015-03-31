#ifndef __WOODPILE_QUEUE_H
#define __WOODPILE_QUEUE_H

/**
 * @file
 * Declaration and functions for the Queue container.
 */

/**
 * The Queue data structure is a simple array-based implementation of a First In
 * First Out (FIFO) structure. Elements can only be pushed to the back of the
 * Queue and pulled from the front.
 *
 * Memory for this structure is allocated in blocks. The initial capacity of the
 * Queue can be set by using the NewSizedQueue constructor function, and can be
 * changed later using the SetQueueCapacity and TrimQueueToSize functions.
 *
 * Memory overhead can be calculated as follows:
 * sizeof( size_t ) * 3 + sizeof( void * ) * ( queue_capacity + 1 )
 */
struct Queue;
typedef struct Queue Queue;

/**
 * Creates a copy of a Queue. Elements within the Queue are not copied, meaning
 * that changes made to elements in the original Queue will also change the
 * elements in the copy. Changes made to the original Queue will not affect the
 * copy.
 *
 * @param queue the Queue to copy
 *
 * @return the copy of the original Queue or NULL on failure
 */
Queue *
CopyQueue
( const Queue *queue );

/**
 * Destroys a Queue. Does not affect the elements stored in the Queue.
 *
 * @param queue the Queue to destroy
 */
void
DestroyQueue
( const Queue *queue );

/**
 * Creates a new Queue. The default capacity of the Queue is 100.
 *
 * @return a new Queue or NULL on failure
 */
Queue *
NewQueue
( void );

/**
 * Creates a new Queue of the given capacity.
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
 * Gets the current capacity of the Queue.
 *
 * @param queue the Queue to get the capacity of
 *
 * @return the current capacity of the Queue
 */
size_t
QueueCapacity
( const Queue *queue );

/**
 * Searches a Queue for an element.
 *
 * @param queue the Queue to search
 * @param element the element to search for
 *
 * @return the number of entries of element in queue
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
 * Gets the number of elements in a Queue. An empty Queue will return 0.
 *
 * @param queue the Queue to measure
 *
 * @return the number of elements in the Queue
 */
size_t
QueueSize
( const Queue *queue);

/**
 * Creates a string representation of the given Queue, using the provided
 * function to get the string representation of each element.
 *
 * @param queue the Queue to get a representation of
 * @param element_to_string a function returining string representations of
 * elements
 *
 * @return a char buffer holding a string representation of the Queue
 */
char *
QueueToString
( const Queue *queue, char * ( *element_to_string )( const void * ) );

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
