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
  SHash *city_hash, *spooky_hash, *woodpile_hash; 

  // opening the dictionary file
  FILE *words = fopen( filename, "r" );
  if( !words ){
    printf( "Could not open the words file %s\n", filename );
    return EXIT_FAILURE;
  }


  // measure the city hash performance
  city_hash = SHashNew( city_hasher, NULL, ( comparator_t ) strcmp );
  if( !city_hash ){
    printf( "Could not build a city hash.\n" );
    return EXIT_FAILURE;
  }
  city_load_time = LoadSHash( city_hash, words );
  rewind( words );
  SHashDestroy( city_hash );


  // measure the spooky hash performance
  spooky_hash = SHashNew( spooky_hasher, NULL, ( comparator_t ) strcmp );
  if( !spooky_hash ){
    printf( "Could not build a spooky hash.\n" );
    return EXIT_FAILURE;
  }
  spooky_load_time = LoadSHash( spooky_hash, words );
  rewind( words );
  SHashDestroy( spooky_hash );


  // measure the woodpile hash performance
  woodpile_hash = SHashNew ( woodpile_hasher, NULL, ( comparator_t ) strcmp );
  if( !woodpile_hash ){
    printf( "Could not build a woodpile hash.\n" );
    return EXIT_FAILURE;
  }
  woodpile_load_time = LoadSHash( woodpile_hash, words );
  rewind( words );
  SHashDestroy( woodpile_hash );
 
 
  // print the results
  printf( "City Hash Load Clock Cycles:     %5d\n", city_load_time );
  printf( "Spooky Hash Load Clock Cycles:   %5d\n", spooky_load_time );
  printf( "Woodpile Hash Load Clock Cycles: %5d\n", woodpile_load_time );


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

  while( !feof( stream ) ){
    fgets( key, 100, stream );
    begin = clock();
    SHashPut( hash, key, "Value" );
    total_clocks = clock() - begin;
  }

  return total_clocks;
}
