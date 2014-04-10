AC_DEFUN([LIBFCGI],
[
    AC_ARG_WITH([libfcgi],
        AC_HELP_STRING(
            [--with-libfcgi=@<:@ARG@:>@],
            [use SQLite 3 library @<:@default=yes@:>@, optionally specify the prefix for libfcgi library]
        ),
        [
        if test "$withval" = "no"; then
            WANT_LIBFCGI="no"
        elif test "$withval" = "yes"; then
            WANT_LIBFCGI="yes"
            ac_libfcgi_path=""
        else
            WANT_LIBFCGI="yes"
            ac_libfcgi_path="$withval"
        fi
        ],
        [WANT_LIBFCGI="yes"]
    )

    LIBFCGI_CFLAGS=""
    LIBFCGI_LDFLAGS=""
    LIBFCGI_VERSION=""

    if test "x$WANT_LIBFCGI" = "xyes"; then

        AC_MSG_CHECKING([libfcgi])

        if test "$ac_libfcgi_path" != ""; then
            ac_libfcgi_ldflags="-L$ac_libfcgi_path/lib"
            ac_libfcgi_cppflags="-I$ac_libfcgi_path/include"
        fi
        ac_libfcgi_ldflags="$ac_libfcgi_ldflags -lfcgi"

        saved_CPPFLAGS="$CPPFLAGS"
        CPPFLAGS="$CPPFLAGS $ac_libfcgi_cppflags"

        AC_LANG_PUSH(C++)
        AC_COMPILE_IFELSE(
            [
            AC_LANG_PROGRAM([[@%:@include <fcgio.h>]],
                [[
                ]]
            )
            ],
            [
            AC_MSG_RESULT([yes])
            success="yes"
            ],
            [
            AC_MSG_RESULT([not found])
            succees="no"
            ]
        )
        AC_LANG_POP([C++])

        CPPFLAGS="$saved_CPPFLAGS"

        if test "$success" = "yes"; then
            LIBFCGI_CFLAGS="$ac_libfcgi_cppflags"
            LIBFCGI_LDFLAGS="$ac_libfcgi_ldflags"
            AC_SUBST(LIBFCGI_CFLAGS)
            AC_SUBST(LIBFCGI_LDFLAGS)
            AC_SUBST(LIBFCGI_VERSION)
            AC_DEFINE([HAVE_LIBFCGI], [], [libfcgi found])
        fi
    fi
])

