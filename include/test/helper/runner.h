#ifndef __WOODPILE_TEST_INCLUDE_RUNNER_H
#define __WOODPILE_TEST_INCLUDE_RUNNER_H

#include <stdlib.h>

#define TEST( test )                                                           \
result = Test##test();                                                         \
if( result ){                                                                  \
  printf( "Test%s Failed: %s\n", #test, result );                              \
  failure_count++;                                                             \
}

#endif
