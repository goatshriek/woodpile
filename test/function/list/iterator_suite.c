#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <woodpile/list/iterator.h>

#include "test/function/list/iterator_suite.h"
#include "test/helper.h"

int
main( void )
{
  unsigned failure_count = 0;
  const char *result;

  TEST( Add )
  TEST( Begin )
  TEST( Copy )
  TEST( Destroy )
  TEST( End )
  TEST( HasNext )
  TEST( HasPrevious )
  TEST( Next )
  TEST( Previous )
  TEST( Remove )

  if( failure_count > 0 )
    return EXIT_FAILURE;
  else
    return EXIT_SUCCESS;
}

const char *
TestAdd
( void )
{
  return "implement";
}

const char *
TestBegin
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
TestEnd
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

const char *
TestRemove
 ( void )
{
  return "implement";
}
