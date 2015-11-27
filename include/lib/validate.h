#ifndef __WOODPILE_LIB_VALIDATE_H
#define __WOODPILE_LIB_VALIDATE_H

/**
 * @file
 * Definitions for parameter validation.
 */

#include <assert.h>

/**
 * Performs parameter validation with either the assert macro or conditional
 * and return statements.
 */
#ifdef __CONDITIONAL_VALIDATION
#define VALIDATE( value )                                                      \
if( !(value) )                                                                 \
  return NULL;
#else
#include <assert.h>
#define VALIDATE( value ) assert( value );
#endif

#endif
