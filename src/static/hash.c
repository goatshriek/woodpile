#include <stdlib.h>
#include <string.h>
#include <woodpile/comparator.h>
#include <woodpile/hasher.h>
#include <woodpile/static/hash.h>
#include "lib/validate.h"
#include "private/static/hash.h"


SHash *
SHashCopy
( const SHash *hash )
{
  SHash *copy;

  copy = malloc( sizeof( SHash ) );
  VALIDATE_ALLOCATION( copy );

  copy->values = malloc( sizeof( void * ) * hash->capacity );
  VALIDATE_ALLOCATION_AND_FREE( copy->values, copy );

  memcpy( copy->values, hash->values, hash->capacity );
  copy->capacity = hash->capacity;
  copy->compare_keys = hash->compare_keys;
  copy->fold = hash->fold;
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

void *
SHashGet
( const SHash *hash, const void *key )
{
  return NULL;
}

SHash *
SHashNew
( const hasher_t hasher, const folder_t folder, const comparator_t key_comparator )
{
  return SHashNewSized( hasher, folder, key_comparator, 256 );
}

SHash *
SHashNewSized
( const hasher_t hasher, const folder_t folder, const comparator_t key_comparator, size_t capacity )
{
  SHash *hash;

  hash = malloc( sizeof( SHash ) );
  VALIDATE_ALLOCATION( hash )

  hash->values = malloc( sizeof( void * ) * capacity );
  VALIDATE_ALLOCATION_AND_FREE( hash->values, hash )

  hash->capacity = capacity;
  hash->size = 0;

  hash->hash = hasher ? hasher : PointerHash;
  hash->fold = folder ? folder : XORFold;
  hash->compare_keys = key_comparator ? key_comparator : ComparePointers;
  hash->compare_elements = ComparePointers;

  return hash;
}

void *
SHashPut
( SHash *hash, void *key, void *value )
{
  return NULL;
}

void *
SHashRemove
( SHash *hash, const void *key )
{
  return NULL;
}

void
SetStaticHashHasher
( SHash *hash, const hasher_t hasher )
{
  return;
}

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
  return NULL;
}

unsigned short
SHashIsEmpty
( const SHash *hash )
{
  return hash == NULL || hash->size == 0;
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

SHash *
SHashSetCapacity
( SHash *hash, size_t capacity )
{
  return NULL;
}

SHash *
SHashSetElementComparator
( SHash *hash, comparator_t comparator )
{
  return NULL;
}
