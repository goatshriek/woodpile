#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <woodpile/hasher.h>
#include <woodpile/static/hash.h>
#include "test/performance/static/hash_suite.h"

#define HASH_CAPACITY 3000

int
main
( void )
{
  const char *filename = "../../helper/american_english_words.txt";
  clock_t city_time, spooky_time, woodpile_time;
  SHash *city_hash, *spooky_hash, woodpile_hash; 

  // opening the dictionary file
  FILE *words = fopen( filename, "r" );
  if( !words ){
    printf( "Could not open the words file %s\n", filename );
    return EXIT_FAILURE;
  }


  // measure the city hash performance
  city_hash = SHashNew( city_hasher );


  // measure the spooky hash performance
  spooky_hash = SHashNew( spooky_hasher );


  // measure the woodpile hash performance
  woodpile_hash = SHashNew ( woodpile_hasher );
 
 
  // print the results
  printf( "results" );


  // cleaning up
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
