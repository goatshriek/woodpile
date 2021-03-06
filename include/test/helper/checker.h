#ifndef __WOODPILE_TEST_INCLUDE_CHECKER_H
#define __WOODPILE_TEST_INCLUDE_CHECKER_H

/**
 * @file
 * Macros for checking values for accuracy
 */

#include <stdlib.h>
#include <string.h>

#define ASSERT_STRINGS_EQUAL( expected, actual, message )                      \
if( !(actual) ){                                                               \
  printf( "Expected: %s\nInstead was NULL\n", (const char *)(expected) );      \
  return (message);                                                            \
}                                                                              \
if( strcmp( (expected), (actual) ) != 0 ){                                     \
  printf( "Expected: %s\nInstead was: %s\n", (const char *)(expected), (const char *)(actual) );\
  return (message);                                                            \
}

#endif
