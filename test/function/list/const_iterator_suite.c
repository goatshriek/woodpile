#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <woodpile/list/const_iterator.h>

#include "test/function/list/const_iterator_suite.h"
#include "test/helper.h"

int
main( void )
{
  unsigned failure_count = 0;
  const char *result;

  TEST( CBegin )
  TEST( CEnd )
  TEST( Copy )
  TEST( Destroy )
  TEST( HasNext )
  TEST( HasPrevious )
  TEST( Next )
  TEST( Previous )

  if( failure_count > 0 )
    return EXIT_FAILURE;
  else
    return EXIT_SUCCESS;
}

const char *
TestCBegin
( void )
{
  return "implement";
}

const char *
TestCEnd
( void )
{
  return "implement";
}

const char *
TestCopy
( void )
{
  return "implement";
}

const char *
TestDestroy
( void )
{
  return "implement";
}

const char *
TestHasNext
( void )
{
  return "implement";
}

const char *
TestHasPrevious
( void )
{
  return "implement";
}

const char *
TestNext
( void )
{
  return "implement";
}

const char *
TestPrevious
( void )
{
  return "implement";
}
