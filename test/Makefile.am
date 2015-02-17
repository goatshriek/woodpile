check_PROGRAMS = test/function/dictionary_suite \
                 test/function/list_suite \
                 test/function/list/const_iterator_suite \
                 test/function/list/iterator_suite \
                 test/function/queue_suite \
                 test/function/stack_suite

TESTS = $(check_PROGRAMS)

test_libraries = libhelper.la \
                 libwoodpile.la

include test/helper/Makefile.am
include test/function/Makefile.am
