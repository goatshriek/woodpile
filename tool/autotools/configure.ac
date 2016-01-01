AC_PREREQ([2.68])

AC_INIT([woodpile], [0.0.1], [stumpless@verizon.net])

AC_CONFIG_AUX_DIR([config])
AC_CONFIG_SRCDIR([../../src/dynamic/list.c])
AC_CONFIG_HEADERS([include/woodpile/config.h:config.h.in])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_FILES([Makefile])
AC_CONFIG_LINKS([test/data/american_english_words.txt:../../test/data/american_english_words.txt])

m4_ifdef([AM_PROG_AR], [AM_PROG_AR])

LT_INIT

AM_INIT_AUTOMAKE
AM_SILENT_RULES([yes])

# Checks for programs.
AC_PROG_CC
AM_PROG_CC_C_O

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADER([limits.h],
  [AC_DEFINE([__WOODPILE_HAVE_LIMITS_H],
    [1],
    [define if <limits.h> is available])])
                           
AC_CHECK_HEADER([pthread.h],
  [AC_DEFINE([__WOODPILE_HAVE_PTHREAD_H],
    [1],
    [define if <pthread.h> is available])])
                           
AC_CHECK_HEADER([stdarg.h],
  [AC_DEFINE([__WOODPILE_HAVE_STDARG_H],
    [1],
    [define if <stdarg.h> is available])])
                           
AC_CHECK_HEADER([unistd.h],
  [AC_DEFINE([__WOODPILE_HAVE_UNISTD_H],
    [1],
    [define if <unistd.h> is available])])
                           
AC_CHECK_HEADER([sys/types.h],
  [AC_DEFINE([__WOODPILE_HAVE_SYS_TYPES_H],
    [1],
    [define if <sys/types.h> is available])])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

# enable arguments
AC_ARG_ENABLE([parameter-validation],
  AS_HELP_STRING([--enable-parameter-validation],
    [parameters are validated via conditional statements rather than assert calls @<:@default=no@:>@]),
  [],
  [enable_parameter_validation=no])

AS_IF([test "x$enable_parameter_validation" = "xyes"],
  AC_DEFINE([__WOODPILE_PARAMETER_VALIDATION],
    [1],
    [define to have parameters validated with conditional expressions rather than assert calls]))


AC_ARG_ENABLE([allocation-validation],
  AS_HELP_STRING([--enable-allocation-validation],
    [memory allocation requests are validated via conditional statements rather than assert calls @<:@default=no@:>@]),
  [],
  [enable_allocation_validation=no])

AS_IF([test "x$enable_allocation_validation" = "xyes"],
  AC_DEFINE([__WOODPILE_ALLOCATION_VALIDATION],
    [1],
    [define to have memory allocation requests validated with conditional expressions rather than assert calls]))


AC_ARG_ENABLE([all-hashers],
  AS_HELP_STRING([--enable-all-hashers],
    [all hashing functions will be included in the library @<:@default=no@:>@]),
  [],
  [enable_all_hashers=no])

AS_IF([test "x$enable_all_hashers" = "xyes"],
  AC_DEFINE([__WOODPILE_ALL_HASHERS],
    [1],
    [define to have all hashing functions included in the library]))


AC_OUTPUT
