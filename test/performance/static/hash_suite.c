#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <woodpile/static/hash.h>
#include "test/performance/static/hash_suite.h"

#define HASH_CAPACITY 3000

int
main
( void )
{
  const char *filename = "../../helper/american_english_words.txt";

  FILE *words = fopen( filename, "r" );

  

  fclose( words );
  return EXIT_SUCCESS;
}

static
clock_t
LoadSHash
( SHash *hash, FILE *stream )
{
  clock_t begin, total_clocks=0;
  char key[100];
  const char *value = "Value";

  while( !feof( stream ) ){
    fgets( key, 100, stream );
    begin = clock();
    SHashPut( hash, key, value );
    total_clocks = clock() - begin;
  }

  return total_clocks;
}
