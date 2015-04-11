#ifndef __WOODPILE_TEST_INCLUDE_CHECKER_H
#define __WOODPILE_TEST_INCLUDE_CHECKER_H

/**
 * @file
 * Macros for checking values for accuracy
 */

#include <stdlib.h>

#define ASSERT_STRINGS_EQUAL( expected, actual, message )                      \
if( !actual ){                                                                 \
  printf( "Expected: %s\nInstead was NULL\n", (expected) );                    \
  return (message);                                                            \
}                                                                              \
if( strcmp( (expected), (actual) ) != 0 ){                                     \
  printf( "Expected: %s\nInstead was: %s\n", (expected), (actual) );           \
  return (message);                                                            \
}

#endif
