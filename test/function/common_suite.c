#include <stdlib.h>
#include <woodpile/config.h>
#include "test/function/common_suite.h"
#include "test/helper.h"

#ifdef __WOODPILE_PARAMETER_VALIDATION

const char *
TestCopyNull
( void )
{
  if( TEST_FUNCTION_COPY( NULL ) != NULL )
    return "a non-NULL value was returned for a NULL structure";

  return NULL;
}

#endif

const char *
TestCopy
( void )
{
  const test_struct_t *copy, *original;

  original = TEST_FUNCTION_BUILD();
  if( !original )
    return "could not build a populated structure";

  copy = TEST_FUNCTION_COPY( original );
  if( !copy )
    return "NULL was returned for a non-NULL structure";

  TEST_FUNCTION_DESTROY( original );
  TEST_FUNCTION_DESTROY( copy );

  return NULL;
}

const char *
TestCopyDistinct
( void )
{
  const test_struct_t *copy, *original;

  original = TEST_FUNCTION_BUILD();
  if( !original )
    return "could not build a populated structure";

  copy = TEST_FUNCTION_COPY( original );
  if( !copy )
    return "could not copy the original structure";

  if( copy == original )
    return "the copy was not distinct from the original";

  TEST_FUNCTION_DESTROY( original );
  TEST_FUNCTION_DESTROY( copy );

  return NULL;
}

const char *
TestCopySize
( void )
{
  const test_struct_t *copy, *original;

  original = TEST_FUNCTION_BUILD();
  if( !original )
    return "could not build a populated structure";

  copy = TEST_FUNCTION_COPY( original );
  if( !copy )
    return "could not copy the original structure";

  if( TEST_FUNCTION_SIZE( original ) != TEST_FUNCTION_SIZE( copy ) )
    return "the size of the copy was not the same as the original";

  TEST_FUNCTION_DESTROY( original );
  TEST_FUNCTION_DESTROY( copy );

  return NULL;
}

const char *
TestDestroyNull
( void )
{
  TEST_FUNCTION_DESTROY( NULL );

  return NULL;
}

const char *
TestDestroyPopulated
( void )
{
  const test_struct_t *structure;

  structure = TEST_FUNCTION_BUILD();
  if( !structure )
    return "could not build a populated structure";

  TEST_FUNCTION_DESTROY( structure );

  return NULL;
}

const char *
TestIsEmptyWithEmpty
( void )
{
  const test_struct_t *structure;

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
    return "a false value was returned for a NULL structure";

  return NULL;
}

const char *
TestIsEmptyWithPopulated
( void )
{
  const test_struct_t *structure;

  structure = TEST_FUNCTION_BUILD();
  if( !structure ){
    return "could not build a test structure";
  }

  if( TEST_FUNCTION_IS_EMPTY( structure ) )
    return "a true value was returned for a populated structure";

  return NULL;
}

const char *
TestNew
( void )
{
  const test_struct_t *structure;

  structure = TEST_FUNCTION_NEW();
  if( !structure )
    return "NULL was returned instead of a new structure";

  TEST_FUNCTION_DESTROY( structure );

  return NULL;
}
