#include <stdlib.h>
#include <string.h>
#include <woodpile/comparator.h>
#include <woodpile/hasher.h>
#include <woodpile/static/hash.h>
#include "lib/validate.h"
#include "private/static/hash.h"

size_t
SHashCapacity
( const SHash *hash )
{
  if( SHashIsEmpty( hash ) )
    return 0;

  return hash->capacity;
}

void *
SHashContains
( const SHash *hash, const void *element )
{
  unsigned i;

  VALIDATE_PARAMETERS( element )

  if( SHashIsEmpty( hash ) )
    return NULL;

  for( i=1; i < hash->capacity*2; i+=2 ){
    if( hash->compare_elements( hash->values[i], element ) )
      return hash->values[i-1];
  }

  return NULL;
}

SHash *
SHashCopy
( const SHash *hash )
{
  SHash *copy;

  VALIDATE_PARAMETERS( hash )

  copy = malloc( sizeof( SHash ) );
  VALIDATE_ALLOCATION( copy )

  copy->values = calloc( hash->capacity * 2, sizeof( void * ) );
  VALIDATE_ALLOCATION_AND_FREE( copy->values, copy )

  memcpy( copy->values, hash->values, hash->capacity );
  copy->capacity = hash->capacity;
  copy->compare_keys = hash->compare_keys;
  copy->compare_elements = hash->compare_elements;
  copy->fold = hash->fold;
  copy->hash = hash->hash;
  copy->seed = time( NULL );
  copy->size = hash->size;

  return copy;
}

void
SHashDestroy
( const SHash *hash )
{
  if( hash ){
    free( hash->values );
    free( (void *) hash );
  }

  return;
}

comparator_t
SHashElementComparator
( const SHash *hash )
{
  VALIDATE_PARAMETERS( hash )

  return hash->compare_elements;
}

folder_t
SHashFolder
( const SHash *hash )
{
  VALIDATE_PARAMETERS( hash )

  return hash->fold;
}

void *
SHashGet
( const SHash *hash, const void *key )
{
  unsigned long long start, i;

  VALIDATE_PARAMETERS( hash && key )

  i = start = hash->fold( hash->hash( key, hash->seed ), hash->capacity )*2;
  if( !hash->values[i] )
    return NULL;

  do{
    if( hash->compare_keys( hash->values[i], key ) != 0 ){
      return hash->values[i+1];
    } else {
      i = (i+2)%(hash->capacity*2);
    }
  } while( hash->values[i] && i != start );

  return NULL;
}

unsigned short
SHashIsEmpty
( const SHash *hash )
{
  return hash == NULL || hash->size == 0;
}

comparator_t
SHashKeyComparator
( const SHash *hash ){
  VALIDATE_PARAMETERS( hash )

  return hash->compare_keys;
}

SHash *
SHashNew
( void )
{
  return SHashNewSized( 256 );
}

SHash *
SHashNewDictionary
( void )
{
  SHash *hash;

  hash = SHashNewSized( 256 );
  hash->compare_keys = CompareStrings;
  hash->hash = WoodpileHash;

  return hash;
}

SHash *
SHashNewSized
( size_t capacity )
{
  SHash *hash;

  hash = malloc( sizeof( SHash ) );
  VALIDATE_ALLOCATION( hash )

  hash->values = calloc( capacity * 2, sizeof( void * ) );
  VALIDATE_ALLOCATION_AND_FREE( hash->values, hash )

  hash->capacity = capacity;
  hash->seed = time( NULL );
  hash->size = 0;

  hash->hash = PointerHash;
  hash->fold = XORFold;
  hash->compare_elements = hash->compare_keys = ComparePointers;

  return hash;
}

void *
SHashPut
( SHash *hash, void *key, void *value )
{
  unsigned long long start, i;
  void *result;

  VALIDATE_PARAMETERS( hash && key )

  if( !value )
    return SHashRemove( hash, key );

  if( hash->size == hash->capacity )
    return NULL;

  i = start = hash->fold( hash->hash( key, hash->seed ), hash->capacity )*2;
  while( hash->values[i] ){
    i = (i+2)%(hash->capacity*2);
  }

  result = hash->values[i] ? hash->values[i+1] : value;

  hash->values[i] = key;
  hash->values[i+1] = value;
  hash->size++;

  return result;
}

void *
SHashRemove
( SHash *hash, const void *key )
{
  return NULL;
}

SHash *
SHashSetCapacity
( SHash *hash, size_t capacity )
{
  VALIDATE_PARAMETERS( hash )

  hash->capacity = capacity;

  return SHashRehash( hash );
}

SHash *
SHashSetElementComparator
( SHash *hash, comparator_t comparator )
{
  VALIDATE_PARAMETERS( hash && comparator )

  hash->compare_elements = comparator;

  return hash;
}

SHash *
SHashSetFolder
( SHash *hash, folder_t folder )
{
  VALIDATE_PARAMETERS( hash && folder )

  hash->fold = folder;

  return SHashRehash( hash );
}

SHash *
SHashSetHasher
( SHash *hash, hasher_t hasher )
{
  VALIDATE_PARAMETERS( hash && hasher )

  hash->hash = hasher;

  return SHashRehash( hash );
}

SHash *
SHashSetKeyComparator
( SHash *hash, comparator_t comparator )
{
  VALIDATE_PARAMETERS( hash && comparator )

  hash->compare_keys = comparator;

  return SHashRehash( hash );
}

SHash *
SHashSetSeed
( SHash *hash, unsigned long long seed )
{
  VALIDATE_PARAMETERS( hash )

  hash->seed = seed;

  return SHashRehash( hash );
}

size_t
SHashSize
( const SHash *hash )
{
  if( SHashIsEmpty( hash ) )
    return 0;

  return hash->size;
}

char *
SHashHashToString
( const SHash *hash, char * ( *element_to_string )( const void * ) )
{
  return NULL;
}

static
SHash *
SHashRehash
( SHash *hash )
{


  return hash;
}
