#include <stdlib.h>
#include <woodpile/config.h>
#include "test/function/common_suite.h"
#include "test/helper.h"

const char *
TestIsEmptyWithEmpty
( void )
{
  test_struct_t *structure;

  structure = TEST_FUNCTION_NEW();
  if( !structure )
    return "a new structure could not be created";

  if( !TEST_FUNCTION_IS_EMPTY( structure ) )
    return "a false value was returned for an empty structure";

  TEST_FUNCTION_DESTROY( structure );

  return NULL;
}

const char *
TestIsEmptyWithNull
( void )
{
  if( !TEST_FUNCTION_IS_EMPTY( NULL ) )
    return "a false value was returned for a NULL hash";

  return NULL;
}

const char *
TestIsEmptyWithPopulated
( void )
{
  test_struct_t *structure;

  structure = TEST_FUNCTION_BUILD();
  if( !structure ){
    return "could not build a test structure";
  }

  if( TEST_FUNCTION_IS_EMPTY( structure ) )
    return "a true value was returned for a populated hash";

  return NULL;
}
