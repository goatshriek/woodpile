#include <stdlib.h>
#include <string.h>
#include <woodpile/dynamic/tree/splay.h>
#include "private/dynamic/tree/splay.h"


Splay *
CopySplay
( const Splay *splay )
{
  return NULL;
}

void
DestroySplay
( const Splay *splay )
{
  return;
}

size_t
SplayContains
( const Splay *splay, const void *element )
{
  return 0;
}

unsigned short
SplayIsEmpty
( const Splay *splay )
{
  return 0;
}

unsigned
SplaySize
( const Splay *splay )
{
  return NULL;
}

char *
SplayToString
( const Splay *splay, char * ( *element_to_string )( const void * ) )
{
  return NULL;
}

Splay *
NewSplay
( void )
{
  return NULL;
}
