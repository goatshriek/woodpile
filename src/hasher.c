#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <woodpile/config.h>
#include <woodpile/hasher.h>
#include "private/hasher.h"

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

#include <limits.h>

unsigned long long
SpookyDataHash
( const void *data, size_t length, unsigned long long seed )
{
  unsigned long long state[12];
  unsigned long long buffer[12];
  size_t remainder;

  // initialize state
  state[0] = state[2] = state[4] = state[6] = state[8] = state[10] = 0xdeadbeefdeadbeefuLL;
  state[1] = state[3] = state[5] = state[7] = state[9] = state[11] = seed;

  // iterate over the data
  while( length >= SPOOKY_CHUNK_SIZE ){
    SpookyMix( data, state );
    data = ((( char * ) data ) + SPOOKY_CHUNK_SIZE );
    length -= SPOOKY_CHUNK_SIZE;
  }

  // deal with the remainder
  if( length > 0 ){
    memcpy( buffer, data, length );
    memset( buffer+length, 0, SPOOKY_CHUNK_SIZE-length );
    SpookyMix( buffer, state );
  }

  // return the final result
  return state[0] ^ state[1] ^ state[2] ^ state[3] ^ state[4] ^ state[5]
       ^ state[6] ^ state[7] ^ state[8] ^ state[9] ^ state[10] ^ state[11];
}

unsigned long long
SpookyHash
( const void *str, unsigned long long seed )
{
  return SpookyDataHash( str, strlen( str ), seed );
}

unsigned long long
SpookyLeftRotate
( unsigned long long value, size_t bits )
{
  return (value << bits) | (value >> ((sizeof( unsigned long long ) * CHAR_BIT) - bits));
}

void
SpookyMix
( const unsigned long long *chunk, unsigned long long *state )
{
  state[0] += chunk[0];
  state[2] ^= state[10];
  state[11] ^= state[0];
  state[0] = SpookyLeftRotate( state[0], 11 );
  state[11] += state[1];

  state[1] += chunk[1];
  state[3] ^= state[11];
  state[0] ^= state[1];
  state[1] = SpookyLeftRotate( state[1], 32 );
  state[0] += state[2];

  state[2] += chunk[2];
  state[4] ^= state[0];
  state[1] ^= state[2];
  state[2] = SpookyLeftRotate( state[2], 43 );
  state[1] += state[3];

  state[3] += chunk[3];
  state[5] ^= state[1];
  state[2] ^= state[3];
  state[3] = SpookyLeftRotate( state[3], 31 );
  state[2] += state[4];

  state[4] += chunk[4];
  state[6] ^= state[2];
  state[3] ^= state[4];
  state[4] = SpookyLeftRotate( state[4], 17 );
  state[3] += state[5];

  state[5] += chunk[5];
  state[7] ^= state[3];
  state[4] ^= state[5];
  state[5] = SpookyLeftRotate( state[5], 28 );
  state[4] += state[6];

  state[6] += chunk[6];
  state[8] ^= state[4];
  state[5] ^= state[6];
  state[6] = SpookyLeftRotate( state[6], 39 );
  state[5] += state[7];

  state[7] += chunk[7];
  state[9] ^= state[5];
  state[6] ^= state[7];
  state[7] = SpookyLeftRotate( state[7], 57 );
  state[6] += state[8];

  state[8] += chunk[8];
  state[10] ^= state[6];
  state[7] ^= state[8];
  state[8] = SpookyLeftRotate( state[8], 55 );
  state[7] += state[9];

  state[9] += chunk[9];
  state[11] ^= state[7];
  state[8] ^= state[9];
  state[9] = SpookyLeftRotate( state[9], 54 );
  state[8] += state[10];

  state[10] += chunk[10];
  state[0] ^= state[8];
  state[9] ^= state[10];
  state[10] = SpookyLeftRotate( state[10], 22 );
  state[9] += state[11];

  state[11] += chunk[11];
  state[1] ^= state[9];
  state[10] ^= state[11];
  state[11] = SpookyLeftRotate( state[11], 46 );
  state[10] += state[0];
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
