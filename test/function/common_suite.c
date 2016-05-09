#include <stdlib.h>
#include <woodpile/config.h>
#include "test/function/common_suite.h"
#include "test/helper.h"

const char *
TestIsEmptyWithEmpty
( void )
{
  test_struct_t *structure;

  structure = SHashNew();
  if( !structure )
    return "a new structure could not be created";

  if( !TYPE_PREFIX##IsEmpty( structure ) )
    return "a false value was returned for an empty structure";

  TYPE_PREFIX##Destroy( structure );

  return NULL;
}

const char *
TestIsEmptyWithNull
( void )
{
  if( !TYPE_PREFIX##IsEmpty( NULL ) )
    return "a false value was returned for a NULL hash";

  return NULL;
}

const char *
TestIsEmptyWithPopulated
( void )
{
  common_structure = Build##TYPE_PREFIX();
  if( !common_structure ){
    return "could not build a test structure";
  }

  if( TYPE_PREFIX##IsEmpty( common_structure ) )
    return "a true value was returned for a populated hash";

  return NULL;
}
