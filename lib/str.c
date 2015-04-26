#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "woodpile/config/check.h"
#include "lib/str.h"

char *
strcopy
( char *destination, const char *source, size_t length )
{
  if( !destination || !source || length == 0 )
    return destination;

#ifdef __WOODPILE_HAVE_CRT_SECURE_FUNCTIONS
  strncpy_s( destination, length, source, _TRUNCATE );
#else
  strncpy( destination, source, length - 1 );
  destination[length - 1] = '\0';
#endif

  return destination;
}

int
strprint
( char *str, size_t length, const char *format, ... )
{
  int result;
  va_list args;

  va_start( args, format );
  result = vstrprint( str, length, format, args );
  va_end( args );

  return result;
}

char *
strpointer
( const void *pointer )
{
  char *str;

  str = malloc( sizeof( char ) * 100 );
  if( !str )
    return NULL;

  strprint( str, 100, "%p", pointer );

  return realloc( str, ( strlen( str ) + 1 ) * sizeof( char ) );
}

int
vstrprint
( char *str, size_t length, const char *format, va_list args )
{
  #ifdef __WOODPILE_HAVE_CRT_SECURE_FUNCTIONS
    return vsprintf_s( str, length, format, args );
  #else
    return vsnprintf( str, length, format, args );
  #endif
}
