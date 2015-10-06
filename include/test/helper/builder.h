#ifndef __WOODPILE_TEST_HELPER_BUILDER_H
#define __WOODPILE_TEST_HELPER_BUILDER_H

/**
 * @file
 * Functions for building test instances
 */

#include <woodpile/dynamic/list.h>
#include <woodpile/dynamic/tree/splay.h>
#include <woodpile/static/queue.h>
#include <woodpile/static/stack.h>

/**
 * Creates a DynamicList. The DynamicList contains several strings.
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
 * @return a new DynamicList or NULL on failure
 */
DList *
BuildDList
( void );

/**
 * Creates a DynamicSplay. The DynamicSplay contains several strings.
 *
 * Alpha
 * Beta
 * Charlie
 * Delta
 * Echo
 * Foxtrot
 * Gamma
 * Hotel
 * India
 * Juliet
 * Kilo
 * Lima
 * Mike
 * November
 * Oscar
 * Papa
 * Quebec
 * Romeo
 * Sierra
 * Tango
 * Uniform
 * Victor
 * Whiskey
 * X-Ray
 * Yankee
 * Zulu
 *
 */
DSplay *
BuildDSplay
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
SQueue *
BuildSQueue
( void );

/**
 * Creates a Stack. The Stack contains several strings.
 *
 * @return a new Stack or NULL on failure
 */
SStack *
BuildSStack
( void );

#endif
