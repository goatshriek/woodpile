#include <stdint.h>
#include <string.h>

#include <woodpile/comparator.h>

int
ComparePointers
( const void *first, const void *second )
{
  intptr_t value;

  value = ((intptr_t) first) - ((intptr_t) second);
  
  if( value > 0 )
    return 1;
  else if( value < 0)
    return -1;
  else
    return 0;
}

int
CompareStrings
( const void *first, const void *second )
{
  return strcmp( first, second );
}
