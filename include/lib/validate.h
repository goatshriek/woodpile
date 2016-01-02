#ifndef __WOODPILE_LIB_VALIDATE_H
#define __WOODPILE_LIB_VALIDATE_H

/**
 * @file
 * Definitions for parameter validation.
 */

#include <woodpile/config.h>

/**
 * Performs parameter validation with either the assert macro or conditional
 * and return statements.
 */
#ifdef __WOODPILE_PARAMETER_VALIDATION
#define VALIDATE_PARAMETERS( parameters )                                      \
if( !(parameters) )                                                            \
  return NULL;
#else
#include <assert.h>
#define VALIDATE_PARAMETERS( parameters ) assert( (parameters) );
#endif

/**
 * Performs memory allocation validation with either the assert macro or
 * conditional and return statements.
 */
#ifdef __WOODPILE_ALLOCATION_VALIDATION
#define VALIDATE_ALLOCATION( allocation )                                      \
if( !(allocation) )                                                            \
  return NULL;
#define VALIDATE_ALLOCATION_AND_FREE( allocation, remainder )                  \
if( !(allocation) ){                                                           \
  free( remainder );                                                           \
  return NULL;                                                                 \
}
#else
#include <assert.h>
#define VALIDATE_ALLOCATION( allocation ) assert( (allocation) );
#define VALIDATE_ALLOCATION_AND_FREE( allocation, remainder ) assert( (allocation) );
#endif

#endif
