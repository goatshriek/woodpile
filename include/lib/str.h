#ifndef __WOODPILE_LIB_STR_H
#define __WOODPILE_LIB_STR_H

/**
 * @file
 * Functions for working with strings.
 */

#include <stdarg.h>

/**
 * Copies source to destination, to a maximum of length characters (including
 * the NULL terminating character). Source is guaranteed to be NULL terminated.
 *
 * destination and source shall not overlap
 *
 * @param destination the destination array where the content is to be copied
 * @param source string to be copied
 * @param length
 *
 * @return destination
 */
char *
strcopy
( char *destination, const char *source, size_t length );

/**
 * Composes a string with the same text that would be printed if format was used
 * on printf, but instead of being printed, the content is stored as a C string
 * in the buffer pointed by str (taking length as the maximum buffer capacity to
 * fill).
 *
 * @param str pointer to a buffer where the resulting C string is stored. The
 *            buffer should have a size of at least length characters.
 * @param length maximum number of bytes to be used in the buffer. The generated
 *               string has a length of at most length-1, leaving space for the
 *               additional terminating NULL character.
 * @param format C string that contains a format string that follows the same
 *               specifications as format in printf
 * @param ... depending on the format string, the function may expect a sequence
 *            of additional arguments, each containing a value to be used to
 *            replace a format specifier in the format string (or a pointer to a
 *            storage location, for n). There should be at least as many of
 *            these arguments as the number of values specified in the format
 *            specifiers. Additional arguments are ignored by the function.
 *
 * @return a positive non-zero value if no error is encountered, or a value
 *         equal to or less than zero otherwise
 */
int
strprint
( char *str, size_t length, const char *format, ... );

/**
 * Creates a new string holding the address of a pointer.
 *
 * @param pointer the pointer to represent in a string
 *
 * @return a char buffer holding a string representation of the pointer
 */
char *
strpointer
( const void *pointer );

/**
 * Composes a string with the same text that would be printed if format was used
 * on printf, but instead of being printed, the content is stored as a C string
 * in the buffer pointed by str (taking length as the maximum buffer capacity to
 * fill).
 *
 * @param str pointer to a buffer where the resulting C string is stored. The
 *            buffer should have a size of at least length characters.
 * @param length maximum number of bytes to be used in the buffer. The generated
 *               string has a length of at most length-1, leaving space for the
 *               additional terminating NULL character.
 * @param format C string that contains a format string that follows the same
 *               specifications as format in printf
 * @param ... depending on the format string, the function may expect a sequence
 *            of additional arguments, each containing a value to be used to
 *            replace a format specifier in the format string (or a pointer to a
 *            storage location, for n). There should be at least as many of
 *            these arguments as the number of values specified in the format
 *            specifiers. Additional arguments are ignored by the function.
 *
 * @return a positive non-zero value if no error is encountered, or a value
 *         equal to or less than zero otherwise
 */
int
vstrprint
( char *str, size_t length, const char *format, va_list args );

#endif
