#include <woodpile/config.h>
#include "lib/hasher.h"

#ifdef __WOODPILE_HAS_CITY_HASHER
unsigned long long
city_hasher
( const void *str )
{
  return 0;
}
#endif


#ifdef __WOODPILE_HAS_SPOOKY_HASHER
unsigned long long
spooky_hasher
( const void *str )
{
  return 0;
}
#endif


#ifdef __WOODPILE_HAS_WOODPILE_HASHER
unsigned long long
woodpile_hasher
( const void *str )
{
  return 0;
}
#endif
