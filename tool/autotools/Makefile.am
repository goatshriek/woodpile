AUTOMAKE_OPTIONS = -Wall subdir-objects parallel-tests color-tests

ACLOCAL_AMFLAGS = -I m4

vpath %.h $(top_srcdir)/../../include
vpath %.c $(top_srcdir)/../../lib $(top_srcdir)/../../src $(top_srcdir)/../../test

# header files
include_HEADERS = woodpile.h

woodpile_includedir = $(includedir)/woodpile

woodpile_include_HEADERS = woodpile/list.h \
                           woodpile/queue.h \
                           woodpile/stack.h

woodpile_dictionary_includedir = $(includedir)/woodpile/dictionary

woodpile_dictionary_include_HEADERS = woodpile/dictionary/const_iterator.h \
                                      woodpile/dictionary/iterator.h

woodpile_list_includedir = $(includedir)/woodpile/list

woodpile_list_include_HEADERS = woodpile/list/const_iterator.h \
                                woodpile/list/iterator.h

noinst_HEADERS = lib/str.h \
                 static/list.h \
                 static/list/const_iterator.h \
                 static/list/iterator.h \
                 static/queue.h \
                 static/stack.h \
                 test/function/dictionary/const_iterator_suite.h \
                 test/function/list_suite.h \
                 test/function/list/const_iterator_suite.h \
                 test/function/list/iterator_suite.h \
                 test/function/queue_suite.h \
                 test/helper.h \
                 test/helper/builder.h \
                 test/helper/checker.h \
                 test/helper/fixture.h \
                 test/helper/runner.h

# source files
AM_CFLAGS = -g -I $(top_srcdir)/../../include -I ./include

lib_LTLIBRARIES = libwoodpile.la

libwoodpile_la_SOURCES = str.c \
                         list.c \
                         list/const_iterator.c \
                         list/iterator.c \
                         queue.c \
                         stack.c 


# test files
check_PROGRAMS = test/function/list_suite \
                 test/function/list/const_iterator_suite \
                 test/function/list/iterator_suite \
                 test/function/queue_suite \
                 test/function/stack_suite

TESTS = $(check_PROGRAMS)

check_LTLIBRARIES = libhelper.la

libhelper_la_SOURCES = helper/builder.c \
                       helper/fixture.c

libhelper_la_LIBADD = libwoodpile.la

test_libraries = libhelper.la \
                 libwoodpile.la

test_function_list_suite_SOURCES = function/list_suite.c
test_function_list_suite_LDADD = $(test_libraries)

test_function_list_const_iterator_suite_SOURCES = function/list/const_iterator_suite.c
test_function_list_const_iterator_suite_LDADD = $(test_libraries)

test_function_list_iterator_suite_SOURCES = function/list/iterator_suite.c
test_function_list_iterator_suite_LDADD = $(test_libraries)

test_function_queue_suite_SOURCES = function/queue_suite.c
test_function_queue_suite_LDADD = $(test_libraries)

test_function_stack_suite_SOURCES = function/stack_suite.c
test_function_stack_suite_LDADD = $(test_libraries)
