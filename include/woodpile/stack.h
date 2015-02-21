#ifndef __WOODPILE_STACK_H
#define __WOODPILE_STACK_H

/**
 * @file
 * Declaration and functions for the Stack container.
 */

/**
 * The Stack data structure is a simple array-based implementation of a typical
 * Last In First Out (LIFO) Stack structure, where elements can be pushed onto
 * the top or popped off of it.
 *
 * Memory for this container is allocated in blocks. The initial size of the
 * block can be specified with the NewSizedStack function, and modified later
 * using the SetStackSize function.
 */
struct Stack;
typedef struct Stack Stack;

/**
 * Creates a copy of a Stack. Elements within the Stack are not copied, meaning
 * that changes made to elements in the original Stack will also change the
 * elements in the copy. Changes made to the original Stack will not affect the
 * copy.
 *
 * @param stack the Stack to copy
 *
 * @return a copy of the original Stack or NULL on failure
 */
Stack *
CopyStack
( const Stack *stack );

/**
 * Destroys a Stack. Does not affect the elements stored in the Stack.
 *
 * @param stack the Stack to destroy
 */
void
DestroyStack
( Stack *stack );

/**
 * Gets the current capacity of the Stack.
 *
 * @param stack the Stack to get the capacity of
 *
 * @return the current capacity of the Stack
 */
size_t
GetStackCapacity
( const Stack *stack );

/**
 * Gets the number of elements in the Stack. An empty Stack will return 0.
 *
 * @param stack the Stack to get the size of
 *
 * @return the number of elements in the Stack
 */
size_t
GetStackSize
( const Stack *stack );

/**
 * Creates a new Stack with the provided capacity.
 *
 * @param size the capacity for the stack to have
 *
 * @retun a new Stack of the given size, or NULL if an error occurred
 */
Stack *
NewSizedStack
( size_t size );

/**
 * Creates a new Stack. The initial capacity of this Stack is 100.
 *
 * @return a new Stack, or NULL if an error occurred
 */
Stack *
NewStack
( void );

/**
 * Gets the top element on the Stack without changing it. If there are no
 * elements in the Stack then NULL is returned. This is similar to PopFromStack
 * except that it does not remove the value from the Stack.
 *
 * @param stack the Stack to peek at
 *
 * @return the top element of the Stack
 */
void *
PeekAtStack
( const Stack *stack );

/**
 * Removes the top element from the Stack and returns it. If there are no
 * elements in the Stack then NULL is returned.
 *
 * @param stack the Stack to pop the element from
 *
 * @return the top element of the Stack
 */
void *
PopFromStack
( Stack *stack );

/**
 * Puts an element onto the top of the Stack. If the Stack or value are NULL
 * then no action is taken.
 *
 * @param stack the Stack to push on to
 * @param value the value to push onto the Stack
 *
 * @return the Stack that was pushed to, or NULL on failure
 */
Stack *
PushToStack
( Stack *stack, void *value );

/**
 * Resizes the given Stack to the specified capacity. If the given capacity is 
 * less than the current number of elements, then the extra items at the top of
 * the Stack (those most recently pushed) are discarded.
 *
 * @param stack the Stack to resize
 * @param capacity the new capacity of the Stack
 *
 * @return the Stack after being resized, or NULL if the resize failed
 */
Stack *
SetStackCapacity
( Stack *stack, size_t capacity );

/**
 * Searches a Stack for an element.
 *
 * Note that the element is identified using a pointer; if two structures are
 * considered equal but are located at different addresses then they are not
 * considered equal by this function. 
 *
 * @param stack the Stack to search
 * @param element the element to search for
 *
 * @return the number of entries of element in stack
 */
size_t
StackContains
( const Stack *stack, const void *element );

/**
 * Checks whether or not a Stack is empty. A NULL Stack will be considered
 * empty.
 *
 * @param stack the Stack to check
 *
 * @return a positive value if the Stack is empty, 0 otherwise
 */
unsigned short
StackIsEmpty
( const Stack *stack );

/**
 * Creates a string representation of the given Stack, using the provided
 * function to get the string representation of each element.
 *
 * @param stack the Stack to get a representation of
 * @param element_to_string a function returning string representations of
 * elements
 *
 * @return a char buffer holding a string representation of the Stack
 */
char *
StackToString
( const Stack *stack, char * ( *element_to_string )( const void * ) );

#endif
