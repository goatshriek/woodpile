#ifndef __WOODPILE_TEST_HELPER_FIXTURE_H
#define __WOODPILE_TEST_HELPER_FIXTURE_H

/**
 * @file
 * Functions to use as function pointers
 */

/**
 * Converts the provided element to a string. Does conversion by simply
 * casting the element to a char pointer and returning it.
 *
 * @param element the pointer to convert
 *
 * @return element cast as a char *
 */
char *
ElementToString
( const void *element );

#endif
