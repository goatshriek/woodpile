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
#define VALIDATE_PARAMETER( value )                                            \
if( !(value) )                                                                 \
  return NULL;
#else
#include <assert.h>
#define VALIDATE_PARAMETER( value ) assert( value );
#endif

#endif
