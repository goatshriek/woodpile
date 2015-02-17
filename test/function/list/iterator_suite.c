#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "test/function/list/iterator_suite.h"
#include "test/helper.h"

int
main( void )
{
  unsigned failure_count = 0;
  const char *result;

  TEST( Begin )

  if( failure_count > 0 )
    return EXIT_FAILURE;
  else
    return EXIT_SUCCESS;
}

const char *
TestBegin
( void )
{
  return "implement";
}
