#ifndef __WOODPILE_TEST_HELPER_BUILDER_H
#define __WOODPILE_TEST_HELPER_BUILDER_H

/**
 * @file
 * Functions for building test instances of containers and their iterators.
 */

#include <woodpile/dictionary.h>
#include <woodpile/dictionary/const_iterator.h>
#include <woodpile/dictionary/iterator.h>
#include <woodpile/list.h>
#include <woodpile/list/const_iterator.h>
#include <woodpile/list/iterator.h>
#include <woodpile/queue.h>
#include <woodpile/stack.h>
#include <woodpile/tree.h>

/**
 * Builds a new Dictionary. The Dictionary contains several strings.
 *
 * @return a new Dictionary or NULL on failure
 */
Dictionary *
BuildDictionary
( void );

/**
 * Builds a DictionaryConstIterator. The iterator is created for a new
 * Dictionary that is created using the BuildDictionary function.
 *
 * @return a new DictionaryConstIterator or NULL on failure
 */
DictionaryConstIterator *
BuildDictionaryConstIterator
( void );

/**
 * Creates a List. The List contains several strings.
 *
 * index | contents
 * ----------------
 *   0   | This
 *   1   | is
 *   2   | a
 *   3   | test
 *   4   | List
 *   5   | o'
 *   6   | strings!
 *
 * @return a new List or NULL on failure
 */
List *
BuildList
( void );

/**
 * Creates a ListConstIterator. The iterator is created for a new List created
 * using the BuildList function. The position of the iterator will be such that
 * the next element returned will be that at index 3.
 *
 * @return a ListConstIterator at the beginning of the list or NULL on failure
 */
ListConstIterator *
BuildListConstIterator
( void );

/**
 * Creates a ListIterator. The iterator is created for a new List created using
 * the BuildList function. The position of the iterator will be such that the
 * next element returned will be that at index 3.
 *
 * @return a ListIterator at the beginning of the list or NULL on failure
 */
ListIterator *
BuildListIterator
( void );

/**
 * Creates a Queue. The Queue contains several strings.
 *
 * @return a new Queue or NULL on failure
 */
Queue *
BuildQueue
( void );

/**
 * Creates a Stack. The Stack contains several strings.
 *
 * @return a new Stack or NULL on failure
 */
Stack *
BuildStack
( void );

/**
 * Creates a Tree. The Tree contains several strings.
 *
 * @return a new Tree or NULL on failure
 */
Tree *
BuildTree
( void );

#endif
