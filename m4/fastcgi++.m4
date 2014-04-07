AC_DEFUN([FASTCGI],
[
    AC_ARG_WITH([fastcgi],
        AC_HELP_STRING(
            [--with-fastcgi=@<:@ARG@:>@],
            [use SQLite 3 library @<:@default=yes@:>@, optionally specify the prefix for fastcgi library]
        ),
        [
        if test "$withval" = "no"; then
            WANT_FASTCGI="no"
        elif test "$withval" = "yes"; then
            WANT_FASTCGI="yes"
            ac_fastcgi_path=""
        else
            WANT_FASTCGI="yes"
            ac_fastcgi_path="$withval"
        fi
        ],
        [WANT_FASTCGI="yes"]
    )

    FASTCGI_CFLAGS=""
    FASTCGI_LDFLAGS=""
    FASTCGI_VERSION=""

    if test "x$WANT_FASTCGI" = "xyes"; then

        AC_MSG_CHECKING([fastcgi++])

        if test "$ac_fastcgi_path" != ""; then
            ac_fastcgi_ldflags="-L$ac_fastcgi_path/lib"
            ac_fastcgi_cppflags="-I$ac_fastcgi_path/include"
        fi
        ac_fastcgi_ldflags="$ac_fastcgi_ldflags -lfastcgi"

        saved_CPPFLAGS="$CPPFLAGS"
        CPPFLAGS="$CPPFLAGS $ac_fastcgi_cppflags"

        AC_LANG_PUSH(C++)
        AC_COMPILE_IFELSE(
            [
            AC_LANG_PROGRAM([[@%:@include <fastcgi++/http.h>]],
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
            FASTCGI_CFLAGS="$ac_fastcgi_cppflags"
            FASTCGI_LDFLAGS="$ac_fastcgi_ldflags"
            AC_SUBST(FASTCGI_CFLAGS)
            AC_SUBST(FASTCGI_LDFLAGS)
            AC_SUBST(FASTCGI_VERSION)
            AC_DEFINE([HAVE_FASTCGI], [], [fastcgi found])
        fi
    fi
])

