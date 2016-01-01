#include <stdlib.h>
#include <woodpile/config.h>
#include <woodpile/hasher.h>

#ifdef __WOODPILE_CITY_HASHER
unsigned long long
city_data_hasher
( const void *data, size_t length )
{
  return city_seeded_hasher( data, length, 0 );
}

unsigned long long
city_hasher
( const void *str )
{
  return 0;
}

unsigned long long
city_seeded_hasher
( const void *data, size_t length, unsigned long long seed )
{
  return 0;
}
#endif


#ifdef __WOODPILE_SPOOKY_HASHER
unsigned long long
spooky_data_hasher
( const void *data, size_t length )
{
  return spooky_seeded_hasher( data, length, 0 );
}

unsigned long long
spooky_hasher
( const void *str )
{
  return 0;
}

unsigned long long
spooky_seeded_hasher
( const void *data, size_t length, unsigned long long seed )
{
  return 0;
}
#endif


#ifdef __WOODPILE_WOODPILE_HASHER
unsigned long long
woodpile_data_hasher
( const void *data, size_t length )
{
  return woodpile_seeded_hasher( data, length, 0 );
}

unsigned long long
woodpile_hasher
( const void *str )
{
  return 0;
}

unsigned long long
woodpile_seeded_hasher
( const void *data, size_t length, unsigned long long seed )
{
  return 0;
}
#endif
