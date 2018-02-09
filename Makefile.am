# This is the top-level Makefile.am for a non-recursive Autotools setup. In
# fact, in non-recursive structures, this is the only Makefile.am that is
# needed.

# Always set this so that we can just '#include "foo.h"' from anywhere,
# including the tests directory so that tests also find header files.
AM_CPPFLAGS = -I$(top_srcdir)/src

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
libitree_a_SOURCES = src/itree.h src/interval.h src/itree.c src/interval.c
include_HEADERS = src/itreee.h src/interval.h
