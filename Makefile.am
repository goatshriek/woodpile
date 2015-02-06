AUTOMAKE_OPTIONS = -Wall subdir-objects parallel-tests color-tests

ACLOCAL_AMFLAGS = -I m4

vpath %.h include include/woodpile include/static include/test
vpath %.c src test/function test/helper test/performance test/portability

include include/Makefile.am
include src/Makefile.am
include test/Makefile.am
