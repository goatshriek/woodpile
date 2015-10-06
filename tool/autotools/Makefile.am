AUTOMAKE_OPTIONS = -Wall subdir-objects parallel-tests color-tests

ACLOCAL_AMFLAGS = -I m4

vpath %.h $(top_srcdir)/../../include
vpath %.c $(top_srcdir)/../../lib $(top_srcdir)/../../src $(top_srcdir)/../../test

# header files
include_HEADERS = woodpile.h

woodpile_static_includedir = $(includedir)/woodpile/static

woodpile_static_include_HEADERS = woodpile/static/queue.h \
                                  woodpile/static/stack.h

woodpile_dynamic_includedir = $(includedir)/woodpile/dynamic

woodpile_dynamic_include_HEADERS = woodpile/dynamic/list.h

woodpile_dynamic_list_includedir = $(includedir)/woodpile/dynamic/list

woodpile_dynamic_list_include_HEADERS = woodpile/dynamic/list/const_iterator.h \
                                        woodpile/dynamic/list/iterator.h

woodpile_dynamic_tree_includedir = $(includedir)/woodpile/dynamic/tree

woodpile_dynamic_tree_include_HEADERS = woodpile/dynamic/tree/splay.h

woodpile_dynamic_tree_splay_includedir = $(includedir)/woodpile/dynamic/tree/splay

woodpile_dynamic_tree_splay_include_HEADERS = woodpile/dynamic/tree/splay/const_iterator.h \
                                              woodpile/dynamic/tree/splay/iterator.h

noinst_HEADERS = lib/str.h \
                 private/dynamic/list.h \
                 private/dynamic/list/const_iterator.h \
                 private/dynamic/list/iterator.h \
                 private/static/queue.h \
                 private/static/stack.h \
                 test/function/dynamic/list_suite.h \
                 test/function/dynamic/list/const_iterator_suite.h \
                 test/function/dynamic/list/iterator_suite.h \
                 test/function/dynamic/tree/splay_suite.h \
                 test/function/dynamic/tree/splay/const_iterator_suite.h \
                 test/function/dynamic/tree/splay/iterator_suite.h \
                 test/function/static/queue_suite.h \
                 test/helper.h \
                 test/helper/builder.h \
                 test/helper/checker.h \
                 test/helper/fixture.h \
                 test/helper/runner.h

# source files
AM_CFLAGS = -g -I $(top_srcdir)/../../include -I ./include

lib_LTLIBRARIES = libwoodpile.la

libwoodpile_la_SOURCES = dynamic/list.c \
                         dynamic/list/const_iterator.c \
                         dynamic/list/iterator.c \
                         dynamic/tree/splay.c \
                         dynamic/tree/splay/const_iterator.c \
                         dynamic/tree/splay/iterator.c \
                         static/queue.c \
                         static/stack.c \
                         str.c


# test files
check_PROGRAMS = test/function/dynamic/list_suite \
                 test/function/dynamic/list/const_iterator_suite \
                 test/function/dynamic/list/iterator_suite \
                 test/function/dynamic/tree/splay_suite \
                 test/function/dynamic/tree/splay/const_iterator_suite \
                 test/function/dynamic/tree/splay/iterator_suite \
                 test/function/static/queue_suite \
                 test/function/static/stack_suite

TESTS = $(check_PROGRAMS)

check_LTLIBRARIES = libhelper.la

libhelper_la_SOURCES = helper/builder.c \
                       helper/fixture.c

libhelper_la_LIBADD = libwoodpile.la

test_libraries = libhelper.la \
                 libwoodpile.la

test_function_dynamic_list_suite_SOURCES = function/dynamic/list_suite.c
test_function_dynamic_list_suite_LDADD = $(test_libraries)

test_function_dynamic_list_const_iterator_suite_SOURCES = function/dynamic/list/const_iterator_suite.c
test_function_dynamic_list_const_iterator_suite_LDADD = $(test_libraries)

test_function_dynamic_list_iterator_suite_SOURCES = function/dynamic/list/iterator_suite.c
test_function_dynamic_list_iterator_suite_LDADD = $(test_libraries)

test_function_dynamic_tree_splay_suite_SOURCES = function/dynamic/tree/splay_suite.c
test_function_dynamic_tree_splay_suite_LDADD = $(test_libraries)

test_function_dynamic_tree_splay_const_iterator_suite_SOURCES = function/dynamic/tree/splay/const_iterator_suite.c
test_function_dynamic_tree_splay_const_iterator_suite_LDADD = $(test_libraries)

test_function_dynamic_tree_splay_iterator_suite_SOURCES = function/dynamic/tree/splay/iterator_suite.c
test_function_dynamic_tree_splay_iterator_suite_LDADD = $(test_libraries)

test_function_static_queue_suite_SOURCES = function/static/queue_suite.c
test_function_static_queue_suite_LDADD = $(test_libraries)

test_function_static_stack_suite_SOURCES = function/static/stack_suite.c
test_function_static_stack_suite_LDADD = $(test_libraries)
