#ifndef __WOODPILE_TEST_INCLUDE_RUNNER_H
#define __WOODPILE_TEST_INCLUDE_RUNNER_H

/**
 * @file
 * Macro to run test functions
 */

#include <stdlib.h>

#define TEST( test )                                                           \
result = Test##test();                                                         \
if( result ){                                                                  \
  printf( "Fail: Test%s - %s\n", #test, result );                              \
  failure_count++;                                                             \
} else {                                                                       \
  printf( "Pass: Test%s\n", #test );                                          \
}

#endif
