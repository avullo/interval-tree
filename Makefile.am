# This is the top-level Makefile.am for a non-recursive Autotools setup. In
# fact, in non-recursive structures, this is the only Makefile.am that is
# needed.

# Always set this so that we can just '#include "foo.h"' from anywhere,
# including the tests directory so that tests also find header files.
AM_CFLAGS = -I$(top_srcdir)/src

# AM_CPPFLAGS = -include config.hpp
# AM_CXXFLAGS = -Wall -Wextra -Werror -pedantic
# AM_CFLAGS = -Wall -Wextra -Werror -pedantic

# if DEBUG
#   AM_CFLAGS =-I$(top_srcdir)/src -I$(top_srcdir)/src/lib -Wall -g -O3
# else
#   AM_CFLAGS =-I$(top_srcdir)/src -I$(top_srcdir)/src/lib -Wall -O3
# endif
# AM_CFLAGS += $(GLIB_CFLAGS)
# AM_CFLAGS += $(SQLITE3_CFLAGS)

lib_LIBRARIES = libitree.a
libitree_a_SOURCES = src/interval.c src/interval_list.c src/itree.c
include_HEADERS = src/utils.h src/interval.h src/interval_list.h src/itree.h

# Testing setup. Type 'make check' or 'make recheck' to run the tests.
# TESTS defines a list of tests to run. Define their sources in the usual way.
INTERVAL_TREE_TESTS = tests/utils tests/interval # tests/interval_list tests/interval_tree
TESTS = $(INTERVAL_TREE_TESTS)
check_PROGRAMS = $(INTERVAL_TREE_TESTS)

tests_utils_SOURCES = tests/utils.c
tests_utils_CFLAGS = $(AM_CFLAGS) @CHECK_CFLAGS@ # so that test find the header files
tests_utils_LDADD = @CHECK_LIBS@

tests_interval_SOURCES = tests/interval.c
tests_interval_CFLAGS = $(AM_CFLAGS) @CHECK_CFLAGS@ # so that test find the header files
tests_interval_LDADD = $(top_builddir)/libitree.a @CHECK_LIBS@

# noinst_PROGRAMS = tests/utils tests/interval # tests/interval_list tests/interval_tree
