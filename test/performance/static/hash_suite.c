#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <woodpile/hasher.h>
#include <woodpile/static/hash.h>
#include "test/performance/static/hash_suite.h"

#define HASH_CAPACITY 3000

int
main
( void )
{
  const char *filename = "../../data/american_english_words.txt";
  clock_t city_load_time, spooky_load_time, woodpile_load_time;
  shash_t *city_hash, *spooky_hash, *woodpile_hash; 

  // opening the dictionary file
  FILE *words = fopen( filename, "r" );
  if( !words ){
    printf( "Could not open the words file %s\n", filename );
    return EXIT_FAILURE;
  }


  // measure the city hash performance
  city_hash = SHashNewDictionary();
  SHashSetHasher( city_hash, CityHash );
  if( !city_hash ){
    printf( "Could not build a city hash.\n" );
    return EXIT_FAILURE;
  }
  city_load_time = LoadSHash( city_hash, words );
  rewind( words );
  SHashDestroy( city_hash );


  // measure the spooky hash performance
  spooky_hash = SHashNewDictionary();
  SHashSetHasher( spooky_hash, SpookyHash );
  if( !spooky_hash ){
    printf( "Could not build a spooky hash.\n" );
    return EXIT_FAILURE;
  }
  spooky_load_time = LoadSHash( spooky_hash, words );
  rewind( words );
  SHashDestroy( spooky_hash );


  // measure the woodpile hash performance
  woodpile_hash = SHashNewDictionary();
  SHashSetHasher( woodpile_hash, WoodpileHash );
  if( !woodpile_hash ){
    printf( "Could not build a woodpile hash.\n" );
    return EXIT_FAILURE;
  }
  woodpile_load_time = LoadSHash( woodpile_hash, words );
  rewind( words );
  SHashDestroy( woodpile_hash );
 
 
  // print the results
  printf( "City Hash Load Clock Cycles:     %5d\n", (int)city_load_time );
  printf( "Spooky Hash Load Clock Cycles:   %5d\n", (int)spooky_load_time );
  printf( "Woodpile Hash Load Clock Cycles: %5d\n", (int)woodpile_load_time );


  // cleaning up
  fclose( words );
  return EXIT_SUCCESS;
}

static
clock_t
LoadSHash
( shash_t *hash, FILE *stream )
{
  clock_t begin, total_clocks=0;
  char key[100];

  while( !feof( stream ) ){
    if( !fgets( key, 100, stream ) )
      return 0;
    begin = clock();
    SHashPut( hash, key, "Value" );
    total_clocks = clock() - begin;
  }

  return total_clocks;
}
