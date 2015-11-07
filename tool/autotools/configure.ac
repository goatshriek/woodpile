AC_PREREQ([2.68])

AC_INIT([woodpile], [0.0.1], [stumpless@verizon.net]])

AC_CONFIG_AUX_DIR([config])
AC_CONFIG_SRCDIR([../../src/dynamic/list.c])
AC_CONFIG_HEADERS([include/woodpile/config/check.h:check.h.in])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_FILES([Makefile])

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
                [AC_DEFINE([__STUMPLESS_HAVE_LIMITS_H],
                           [1],
                           [define if <limits.h> is available])])
                           
AC_CHECK_HEADER([pthread.h],
                [AC_DEFINE([__STUMPLESS_HAVE_PTHREAD_H],
                           [1],
                           [define if <pthread.h> is available])])
                           
AC_CHECK_HEADER([stdarg.h],
                [AC_DEFINE([__STUMPLESS_HAVE_STDARG_H],
                           [1],
                           [define if <stdarg.h> is available])])
                           
AC_CHECK_HEADER([unistd.h],
                [AC_DEFINE([__STUMPLESS_HAVE_UNISTD_H],
                           [1],
                           [define if <unistd.h> is available])])
                           
AC_CHECK_HEADER([sys/types.h],
                [AC_DEFINE([__STUMPLESS_HAVE_SYS_TYPES_H],
                           [1],
                           [define if <sys/types.h> is available])])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

# enable arguments

AC_OUTPUT
