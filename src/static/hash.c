#include <stdlib.h>
#include <woodpile/static/hash.h>
#include "private/static/hash.h"


SHash *
SHashCopy
( const SHash *hash )
{
  return NULL;
}

void
SHashDestroy
( const SHash *hash )
{
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
( const hasher_t hasher, const folder_t folder, const comparator_t comparator )
{
  return SHashNewSized( hasher, folder, comparator, 256 );
}

SHash *
SHashNewSized
( const hasher_t hasher, const folder_t folder, const comparator_t comparator, size_t capacity )
{
  return NULL;
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
  return 0;
}

void *
SHashContains
( const SHash *hash, const void *value )
{
  return NULL;
}

unsigned short
SHashIsEmpty
( const SHash *hash )
{
  return 0;
}

size_t
SHashSize
( const SHash *hash )
{
  if( SHashIsEmpty( hash ) )
    return 0;

  return 0;
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
