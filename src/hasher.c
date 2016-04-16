#include <stdlib.h>
#include <woodpile/config.h>
#include <woodpile/hasher.h>

#ifdef __WOODPILE_CITY_HASHER
unsigned long long
CityDataHash
( const void *data, size_t length, unsigned long long seed )
{
  return 0;
}

unsigned long long
CityHash
( const void *str, unsigned long long seed )
{
  return 0;
}
#endif

unsigned long long
ModFold
( unsigned long long hash, unsigned long long max )
{
  return hash%max;
}

unsigned long long
PointerHash
( const void *pointer, unsigned long long seed )
{
  return (unsigned long long) pointer;
}

#ifdef __WOODPILE_SPOOKY_HASHER
unsigned long long
SpookyDataHash
( const void *data, size_t length, unsigned long long seed )
{
  return 0;
}

unsigned long long
SpookyHash
( const void *str, unsigned long long seed )
{
  return 0;
}
#endif


#ifdef __WOODPILE_WOODPILE_HASHER
unsigned long long
WoodpileDataHash
( const void *data, size_t length, unsigned long long seed )
{
  return 0;
}

unsigned long long
WoodpileHash
( const void *str, unsigned long long seed )
{
  size_t i=0;
  const char *str_cast;
  unsigned long long sum=0;

  str_cast = str;
  while( str_cast[i] != '\0' ){
    sum += str_cast[i++];
  }

  return ((unsigned long long) sum) ^ ((unsigned long long) seed);
}

#endif

unsigned long long
XORFold
( unsigned long long hash, unsigned long long max )
{
  while( hash >= max ){
    hash = (hash & 0xff) ^ (hash >> 8);

    if( (hash >> 8) == 0 )
      return hash%max;
  }

  return hash;
}
