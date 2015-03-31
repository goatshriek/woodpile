#include <stdlib.h>
#include <string.h>

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

  strncpy( str, element, element_length );
  str[element_length] = '\0';

  return str;
}
