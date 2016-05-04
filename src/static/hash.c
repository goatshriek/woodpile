#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <woodpile/comparator.h>
#include <woodpile/hasher.h>
#include <woodpile/static/hash.h>
#include "lib/validate.h"
#include "private/static/hash.h"

size_t
SHashCapacity
( const shash_t *hash )
{
  if( SHashIsEmpty( hash ) )
    return 0;

  return hash->capacity;
}

void *
SHashContains
( const shash_t *hash, const void *element )
{
  unsigned long long i;

  VALIDATE_PARAMETERS( element )

  if( SHashIsEmpty( hash ) )
    return NULL;

  for( i=0; i < hash->capacity*2; i+=2 ){
    if( !hash->values[i] )
      continue;

    if( hash->compare_elements( element, hash->values[i+1] ) == 0 )
      return hash->values[i];
  }

  return NULL;
}

shash_t *
SHashCopy
( const shash_t *hash )
{
  shash_t *copy;

  VALIDATE_PARAMETERS( hash )

  copy = malloc( sizeof( shash_t ) );
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
( const shash_t *hash )
{
  if( hash ){
    free( hash->values );
    free( (void *) hash );
  }

  return;
}

comparator_t
SHashElementComparator
( const shash_t *hash )
{
  VALIDATE_PARAMETERS( hash )

  return hash->compare_elements;
}

folder_t
SHashFolder
( const shash_t *hash )
{
  VALIDATE_PARAMETERS( hash )

  return hash->fold;
}

void *
SHashGet
( const shash_t *hash, const void *key )
{
  unsigned long long start, i;

  VALIDATE_PARAMETERS( hash && key )

  i = start = SHashGetIndex( hash, key );
  if( !hash->values[i] )
    return NULL;

  do{
    if( hash->compare_keys( key, hash->values[i] ) == 0 ){
      return hash->values[i+1];
    }

    i = (i+2)%(hash->capacity*2);

  } while( hash->values[i] && i != start );

  return NULL;
}

hasher_t
SHashGetHasher
( const shash_t *hash )
{
  VALIDATE_PARAMETERS( hash )

  return hash->hash;
}

unsigned short
SHashIsEmpty
( const shash_t *hash )
{
  return hash == NULL || hash->size == 0;
}

comparator_t
SHashKeyComparator
( const shash_t *hash ){
  VALIDATE_PARAMETERS( hash )

  return hash->compare_keys;
}

shash_t *
SHashNew
( void )
{
  return SHashNewSized( 256 );
}

shash_t *
SHashNewDictionary
( void )
{
  shash_t *hash;

  hash = SHashNewSized( 256 );
  hash->compare_keys = CompareStrings;
  hash->hash = WoodpileHash;

  return hash;
}

shash_t *
SHashNewSized
( size_t capacity )
{
  shash_t *hash;

  hash = malloc( sizeof( shash_t ) );
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
( shash_t *hash, void *key, void *value )
{
  unsigned long long i, start;
  void *result;

  if( !value )
    return SHashRemove( hash, key );

  VALIDATE_PARAMETERS( hash && key )

  i = start = SHashGetIndex( hash, key );

  do {
    if( !hash->values[i] ){
      hash->size++;
      hash->values[i] = key;
      hash->values[i+1] = value;

      return value;
    }

    if( hash->compare_keys( key, hash->values[i] ) == 0 ){
      result = hash->values[i+1];
      hash->values[i] = key;
      hash->values[i+1] = value;

      return result;
    }

    i = (i+2)%(hash->capacity*2);
  } while( i != start );

  return NULL;
}

void *
SHashRemove
( shash_t *hash, const void *key )
{
  unsigned long long i, start, previous;
  void *result;

  VALIDATE_PARAMETERS( hash && key )

  i = start = hash->fold( hash->hash( key, hash->seed ), hash->capacity )*2;
  if( !hash->values[i] )
    return NULL;

  while( hash->compare_keys( key, hash->values[i] ) != 0 ){
    i = (i+2)%(hash->capacity*2);

    if( !hash->values[i] || i == start )
      return NULL;
  }

  result = hash->values[i+1];
  hash->values[i] = hash->values[i+1] = NULL;
  previous = i;
  i = (i+2)%(hash->capacity*2);

  while( hash->values[i] && SHashGetIndex( hash, key ) == start ){
    hash->values[previous] = hash->values[i];
    hash->values[previous+1] = hash->values[i+1];

    previous = i;
    i = (i+2)%(hash->capacity*2);
  }

  return result;
}

shash_t *
SHashSetCapacity
( shash_t *hash, size_t capacity )
{
  size_t old_capacity;
  unsigned long long i, j, start;
  void **old_values;

  VALIDATE_PARAMETERS( hash )

  old_values = hash->values;
  hash->values = calloc( capacity*2, sizeof( void * ) );
  VALIDATE_ALLOCATION( hash->values )

  old_capacity = hash->capacity;
  hash->capacity = capacity;
  hash->size = 0;
  for( i=0; i < old_capacity*2; i+=2 ){
    if( !old_values[i] )
      continue;

    j = start = SHashGetIndex( hash, old_values[i] );
    do {
      if( !hash->values[j] ){
        hash->size++;
        hash->values[j] = old_values[i];
        hash->values[j+1] = old_values[i+1];

        break;
      }

      j = (j+2)%(capacity*2);
    } while( j != start );
  }

  free( old_values );

  return hash;
}

shash_t *
SHashSetElementComparator
( shash_t *hash, comparator_t comparator )
{
  VALIDATE_PARAMETERS( hash && comparator )

  hash->compare_elements = comparator;

  return hash;
}

shash_t *
SHashSetFolder
( shash_t *hash, folder_t folder )
{
  VALIDATE_PARAMETERS( hash && folder )

  hash->fold = folder;

  return SHashRehash( hash );
}

shash_t *
SHashSetHasher
( shash_t *hash, hasher_t hasher )
{
  VALIDATE_PARAMETERS( hash && hasher )

  hash->hash = hasher;

  return SHashRehash( hash );
}

shash_t *
SHashSetKeyComparator
( shash_t *hash, comparator_t comparator )
{
  VALIDATE_PARAMETERS( hash && comparator )

  hash->compare_keys = comparator;

  return SHashRehash( hash );
}

shash_t *
SHashSetSeed
( shash_t *hash, unsigned long long seed )
{
  VALIDATE_PARAMETERS( hash )

  hash->seed = seed;

  return SHashRehash( hash );
}

size_t
SHashSize
( const shash_t *hash )
{
  if( SHashIsEmpty( hash ) )
    return 0;

  return hash->size;
}

char *
SHashToString
( const shash_t *hash, char * ( *element_to_string )( const void * ) )
{
  return NULL;
}

static
unsigned long long
SHashGetIndex
( const shash_t *hash, const void *key )
{
  return hash->fold( hash->hash( key, hash->seed ), hash->capacity )*2;
}

static
shash_t *
SHashRehash
( shash_t *hash )
{
  unsigned long long i, j, start;
  void **old_values;

  old_values = hash->values;
  hash->values = calloc( hash->capacity*2, sizeof( void * ) );
  VALIDATE_ALLOCATION( hash->values )

  hash->size = 0;
  for( i=0; i < hash->capacity*2; i+=2 ){
    if( !old_values[i] )
      continue;

    j = start = SHashGetIndex( hash, old_values[i] );
    do {
      if( !hash->values[j] ){
        hash->size++;
        hash->values[j] = old_values[i];
        hash->values[j+1] = old_values[i+1];

        break;
      }

      if( hash->compare_keys( hash->values[j], old_values[i] ) == 0 ){
        hash->values[j] = old_values[i];
        hash->values[j+1] = old_values[i+1];

        break;
      }

      j = (j+2)%(hash->capacity*2);
    } while( j != start );
  }

  free( old_values );

  return hash;
}
