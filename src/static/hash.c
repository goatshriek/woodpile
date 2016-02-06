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

  VALIDATE_PARAMETERS( hash )

  copy = malloc( sizeof( SHash ) );
  VALIDATE_ALLOCATION( copy )

  copy->values = malloc( sizeof( void * ) * hash->capacity );
  VALIDATE_ALLOCATION_AND_FREE( copy->values, copy )

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
  VALIDATE_PARAMETERS( hash && key )

  return NULL;
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

  hash = SHashNew();
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

  hash->values = malloc( sizeof( void * ) * capacity );
  VALIDATE_ALLOCATION_AND_FREE( hash->values, hash )

  hash->capacity = capacity;
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
  return NULL;
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
  SHash *previous;

  VALIDATE_PARAMETERS( hash )

  previous = memcpy( previous, hash, sizeof( SHash ) );

  hash->capacity = capacity;

  return SHashTransfer( hash, previous );
}

SHash *
SHashSetFolder
( SHash *hash, folder_t folder )
{
  SHash *previous;

  VALIDATE_PARAMETERS( hash && folder )

  previous = memcpy( previous, hash, sizeof( SHash ) );

  hash->fold = folder;

  return SHashTransfer( hash, previous );
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
SHashSetHasher
( SHash *hash, hasher_t hasher )
{
  SHash *previous;

  VALIDATE_PARAMETERS( hash && hasher )

  previous = memcpy( previous, hash, sizeof( SHash ) );

  hash->hash = hasher;

  return SHashTransfer( hash, previous );
}

SHash *
SHashSetKeyComparator
( SHash *hash, comparator_t comparator )
{
  SHash *previous;

  VALIDATE_PARAMETERS( hash && comparator )

  previous = malloc( sizeof( SHash ) );
  VALIDATE_ALLOCATION( previous )

  previous = memcpy( previous, hash, sizeof( SHash ) );

  hash->compare_keys = comparator;

  return SHashTransfer( hash, previous );
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

unsigned short
SHashIsEmpty
( const SHash *hash )
{
  return hash == NULL || hash->size == 0;
}

comparator_t
StaticHashKeyComparator
( const SHash *hash ){
  VALIDATE_PARAMETERS( hash )

  return hash->compare_keys;
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
SHashTransfer
( SHash *hash, const SHash *previous )
{


  return hash;
}
