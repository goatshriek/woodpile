#include <stdlib.h>
#include <woodpile/config.h>
#include <woodpile/hasher.h>

unsigned long long
PointerHash
( const void *pointer )
{
  return (unsigned long long) pointer;
}

#ifdef __WOODPILE_CITY_HASHER
unsigned long long
CityDataHash
( const void *data, size_t length )
{
  return CitySeededHash( data, length, 0 );
}

unsigned long long
CityHash
( const void *str )
{
  return 0;
}

unsigned long long
CitySeededHash
( const void *data, size_t length, unsigned long long seed )
{
  return 0;
}
#endif


#ifdef __WOODPILE_SPOOKY_HASHER
unsigned long long
SpookyDataHash
( const void *data, size_t length )
{
  return SpookySeededHash( data, length, 0 );
}

unsigned long long
SpookyHash
( const void *str )
{
  return 0;
}

unsigned long long
SpookySeededHash
( const void *data, size_t length, unsigned long long seed )
{
  return 0;
}
#endif


#ifdef __WOODPILE_WOODPILE_HASHER
unsigned long long
WoodpileDataHash
( const void *data, size_t length )
{
  return WoodpileSeededHash( data, length, 0 );
}

unsigned long long
WoodpileHash
( const void *str )
{
  return 0;
}

unsigned long long
WoodpileSeededHash
( const void *data, size_t length, unsigned long long seed )
{
  return 0;
}
#endif
