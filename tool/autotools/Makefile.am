AUTOMAKE_OPTIONS = -Wall subdir-objects parallel-tests color-tests 

ACLOCAL_AMFLAGS = -I m4

woodpile_ROOT_DIR = $(top_srcdir)/../..

vpath %.h $(woodpile_ROOT_DIR)/include
vpath %.c $(woodpile_ROOT_DIR)


# header files
include_HEADERS = $(woodpile_ROOT_DIR)/include/woodpile.h

woodpile_includedir = $(includedir)/woodpile

woodpile_include_HEADERS = $(woodpile_ROOT_DIR)/include/woodpile/comparator.h \
                           $(woodpile_ROOT_DIR)/include/woodpile/hasher.h

woodpile_static_includedir = $(includedir)/woodpile/static

woodpile_static_include_HEADERS = $(woodpile_ROOT_DIR)/include/woodpile/static/hash.h \
                                  $(woodpile_ROOT_DIR)/include/woodpile/static/queue.h \
                                  $(woodpile_ROOT_DIR)/include/woodpile/static/stack.h

woodpile_dynamic_includedir = $(includedir)/woodpile/dynamic

woodpile_dynamic_include_HEADERS = $(woodpile_ROOT_DIR)/include/woodpile/dynamic/list.h

woodpile_dynamic_list_includedir = $(includedir)/woodpile/dynamic/list

woodpile_dynamic_list_include_HEADERS = $(woodpile_ROOT_DIR)/include/woodpile/dynamic/list/const_iterator.h \
                                        $(woodpile_ROOT_DIR)/include/woodpile/dynamic/list/iterator.h

woodpile_dynamic_tree_includedir = $(includedir)/woodpile/dynamic/tree

woodpile_dynamic_tree_include_HEADERS = $(woodpile_ROOT_DIR)/include/woodpile/dynamic/tree/splay.h

woodpile_dynamic_tree_splay_includedir = $(includedir)/woodpile/dynamic/tree/splay

woodpile_dynamic_tree_splay_include_HEADERS = $(woodpile_ROOT_DIR)/include/woodpile/dynamic/tree/splay/const_iterator.h \
                                              $(woodpile_ROOT_DIR)/include/woodpile/dynamic/tree/splay/iterator.h

noinst_HEADERS = lib/str.h \
                 lib/validate.h \
                 private/dynamic/list.h \
                 private/dynamic/list/const_iterator.h \
                 private/dynamic/list/iterator.h \
                 private/static/queue.h \
                 private/static/stack.h \
                 test/function/common_suite.h \
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
AM_CFLAGS = -g -I $(woodpile_ROOT_DIR)/include -I ./include

lib_LTLIBRARIES = libwoodpile.la

libwoodpile_la_SOURCES = src/dynamic/list.c \
                         src/dynamic/list/const_iterator.c \
                         src/dynamic/list/iterator.c \
                         src/dynamic/tree/splay.c \
                         src/dynamic/tree/splay/const_iterator.c \
                         src/dynamic/tree/splay/iterator.c \
                         src/comparator.c \
                         src/hasher.c \
                         src/static/hash.c \
                         src/static/queue.c \
                         src/static/stack.c \
                         lib/str.c


# test files
check_PROGRAMS = test/function/dynamic/list_suite \
                 test/function/dynamic/list/const_iterator_suite \
                 test/function/dynamic/list/iterator_suite \
                 test/function/dynamic/tree/splay_suite \
                 test/function/dynamic/tree/splay/const_iterator_suite \
                 test/function/dynamic/tree/splay/iterator_suite \
                 test/function/static/hash_suite \
                 test/function/static/queue_suite \
                 test/function/static/stack_suite \
                 test/performance/static/hash_suite

TESTS = test/function/dynamic/list_suite \
        test/function/dynamic/list/const_iterator_suite \
        test/function/dynamic/list/iterator_suite \
        test/function/dynamic/tree/splay_suite \
        test/function/dynamic/tree/splay/const_iterator_suite \
        test/function/dynamic/tree/splay/iterator_suite \
        test/function/static/hash_suite \
        test/function/static/queue_suite \
        test/function/static/stack_suite

check_LTLIBRARIES = libhelper.la

libhelper_la_SOURCES = test/helper/builder.c \
                       test/helper/fixture.c

libhelper_la_LIBADD = libwoodpile.la

test_libraries = libhelper.la \
                 libwoodpile.la

test_function_dynamic_list_suite_SOURCES = test/function/dynamic/list_suite.c
test_function_dynamic_list_suite_LDADD = $(test_libraries)

test_function_dynamic_list_const_iterator_suite_SOURCES = test/function/dynamic/list/const_iterator_suite.c
test_function_dynamic_list_const_iterator_suite_LDADD = $(test_libraries)

test_function_dynamic_list_iterator_suite_SOURCES = test/function/dynamic/list/iterator_suite.c
test_function_dynamic_list_iterator_suite_LDADD = $(test_libraries)

test_function_dynamic_tree_splay_suite_SOURCES = test/function/dynamic/tree/splay_suite.c
test_function_dynamic_tree_splay_suite_LDADD = $(test_libraries)

test_function_dynamic_tree_splay_const_iterator_suite_SOURCES = test/function/dynamic/tree/splay/const_iterator_suite.c
test_function_dynamic_tree_splay_const_iterator_suite_LDADD = $(test_libraries)

test_function_dynamic_tree_splay_iterator_suite_SOURCES = test/function/dynamic/tree/splay/iterator_suite.c
test_function_dynamic_tree_splay_iterator_suite_LDADD = $(test_libraries)

test_function_static_hash_suite_SOURCES = test/function/common_suite.c \
                                          test/function/static/hash_suite.c
test_function_static_hash_suite_LDADD = $(test_libraries)
test_function_static_hash_suite_CFLAGS = -D TEST_FUNCTION_BUILD=BuildSHash \
                                         -D TEST_FUNCTION_COPY=SHashCopy \
                                         -D TEST_FUNCTION_DESTROY=SHashDestroy \
                                         -D TEST_FUNCTION_IS_EMPTY=SHashIsEmpty \
                                         -D TEST_FUNCTION_NEW=SHashNew \
                                         -D TEST_TYPE=shash_t \
                                         $(AM_CFLAGS)

test_function_static_queue_suite_SOURCES = test/function/static/queue_suite.c
test_function_static_queue_suite_LDADD = $(test_libraries)

test_function_static_stack_suite_SOURCES = test/function/static/stack_suite.c
test_function_static_stack_suite_LDADD = $(test_libraries)

test_performance_static_hash_suite_SOURCES = test/performance/static/hash_suite.c
test_performance_static_hash_suite_LDADD = $(test_libraries)
