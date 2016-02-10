#include <woodpile/comparator.h>

int
ComparePointers
( const void *first, const void *second )
{
  return (int) (first - second);
}

int
CompareStrings
( const void *first, const void *second )
{
  return strcmp( first, second );
}
