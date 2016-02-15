#include <stdlib.h>
#include <string.h>

#include "lib/str.h"
#include "test/helper/fixture.h"

char *
ElementToString
( const void *element )
{
  char *str;
  unsigned element_length;

  element_length = strlen( element );

  str = malloc( sizeof( char ) * ( element_length + 1 ) );
  if( !str )
    return NULL;

  strcopy( str, element, element_length + 1 );

  return str;
}

unsigned long long
NullHash
( const void *data, unsigned long long seed )
{
  return 0;
}
