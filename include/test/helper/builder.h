#ifndef __WOODPILE_TEST_HELPER_BUILDER_H
#define __WOODPILE_TEST_HELPER_BUILDER_H

/**
 * @file
 * Functions for building test instances
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
 * Creates a Queue. The Queue contains several strings.
 *
 * index | contents
 *   0   | front of Queue
 *   1   | test string
 *   2   | middle string
 *   3   | second test string
 *   4   | end of Queue
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
