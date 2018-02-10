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
libitree_a_SOURCES = src/itree.c src/interval.c
include_HEADERS = src/itree.h src/interval.h

# Testing setup. Type 'make check' or 'make recheck' to run the tests.
# TESTS defines a list of tests to run. Define their sources in the usual way.
INTERVAL_TREE_TESTS = tests/interval # tests/interval_list tests/interval_tree
TESTS = $(INTERVAL_TREE_TESTS)
check_PROGRAMS = $(INTERVAL_TREE_TESTS)

tests_interval_SOURCES = tests/interval.c
tests_interval_CFLAGS = $(AM_CFLAGS) # so that test find the header files
tests_interval_LDADD = $(top_builddir)/libitree.a

# noinst_PROGRAMS = tests/interval # tests/interval_list tests/interval_tree
