AC_PREREQ([2.69])
AC_INIT([libitree], [0.0.1], [killm9m1@yahoo.it])

# Put autotools auxiliary files in a subdir, so they don't clutter top dir.
# I am not actually doing this at the moment because there should be relatively
# little in the top directory anyway.
#AC_CONFIG_AUX_DIR([build-aux])
#AC_CONFIG_MACRO_DIR([m4])

# Safety check - list a source file that wouldn't be in other directories.
AC_CONFIG_SRCDIR([src/interval.c])
AC_CONFIG_HEADERS([config.h])

# Enable "automake" to simplify creating makefiles. foreign relaxes some GNU
# checks. -Wall and -Werror are instructions to Automake, not gcc.
# Because this is a non-recursive automake, we use subdir-objects to tell
# automake to create objects such as .o in sub-directories rather than placing
# all artifacts in the top level directory.
AM_INIT_AUTOMAKE([subdir-objects foreign -Wall -Werror])
PKG_PROG_PKG_CONFIG
AM_PROG_AR
# PKG_PROG_PKG_CONFIG

# Remember externally set CFLAGS
# EXTERNAL_CFLAGS="$CFLAGS"

# Checks for programs. These may set default variables, such as CFLAGS
AC_PROG_CPP
AC_PROG_CC
AC_PROG_CC_C99 # or AC_PROG_CC_89 to force C89 mode or AC_PROG_CC_STDC to go to latest supported standard (currently C99)
AC_PROG_INSTALL
AC_PROG_RANLIB # We're building a static library at the moment

# Reset the externally set CFLAGS after calling AC_PROG*
# CFLAGS="$EXTERNAL_CFLAGS"

# Use the C language and compiler for the following checks
AC_LANG([C])

# Checks for libraries.
# PKG_CHECK_MODULES([GLIB], [glib-2.0], [have_libglib=yes], [have_libglib=no])
# AM_CONDITIONAL([GLIB],  [test "$have_libglib" = "yes"])
# PKG_CHECK_MODULES([SQLITE3], [sqlite3], [have_libsqlite3=yes], [have_libsqlite3=no])
# AM_CONDITIONAL([LIB_SQLITE3],  [test "$have_libsqlite3" = "yes"])
PKG_CHECK_MODULES([CHECK], [check])

# Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([stdio.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_SIZE_T

# Add debug support
dnl AC_ARG_ENABLE(debug,
dnl   AS_HELP_STRING(
dnl     [--enable-debug],
dnl     [enable debugging, default: no]),
dnl     [case "${enableval}" in
dnl       yes) debug=true ;;
dnl       no)  debug=false ;;
dnl       *)   AC_MSG_ERROR([bad value ${enableval} for --enable-debug]) ;;
dnl     esac],
dnl     [debug=false])
dnl AM_CONDITIONAL(DEBUG, test x"$debug" = x"true")
dnl AM_COND_IF(DEBUG,
dnl     AC_DEFINE(DEBUG, 1, [Define to 0 if this is a release build]),
dnl     AC_DEFINE(DEBUG, 0, [Define to 1 or higher if this is a debug build]))


# Checks for library functions.

# These are the files to be generated.
AC_CONFIG_FILES([Makefile])

# Last line: actually generate all required output files.
AC_OUTPUT

dnl AC_MSG_RESULT([
dnl Configure Information:
dnl   Preprocessor      :
dnl     CPPFLAGS        : $CPPFLAGS

dnl   C Compiler        : $CC
dnl     DEFS            :   $DEFS
dnl     CFLAGS          :   $CFLAGS
    
dnl   C++ Compiler      : $CXX
dnl     CXXFLAGS        :   $CXXFLAGS

dnl   Linker            : $LD
dnl     LDFLAGS         :   $LDFLAGS
dnl     LIBS            :   $LIBS

dnl   Python            : $PYTHON
dnl     PY_PREFIX       :   $PY_PREFIX
dnl     PYTHON_LIBS     :   $PYTHON_LIBS
dnl     PYTHON_CFLAGS   :   $PYTHON_CFLAGS
dnl  ])

AC_MSG_RESULT([
Configure Information:
  Preprocessor      :
    CPPFLAGS        : $CPPFLAGS

  C Compiler        : $CC
    DEFS            : $DEFS
    CFLAGS          : $CFLAGS
    
  Linker            : $LD
    LDFLAGS         : $LDFLAGS
    LIBS            : $LIBS
 ])
