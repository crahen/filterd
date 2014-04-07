AC_DEFUN([CRONOLOG],
[
    AC_ARG_WITH([cronolog],
        AC_HELP_STRING(
            [--with-cronolog=@<:@ARG@:>@],
            [Optionally specify the prefix for the cronolog tool, @<:@default=autodetect@:>@]
        ),
        [
        if test "$withval" = "no"; then
            WANT_CRONOLOG="no"
        elif test "$withval" = "yes"; then
            WANT_CRONOLOG="yes"
            ac_cronolog_path=""
        else
            WANT_CRONOLOG="yes"
            ac_cronolog_path="$withval"
        fi
        ],
        [WANT_CRONOLOG="yes"]
    )

    CRONOLOG_CFLAGS=""
    CRONOLOG_LDFLAGS=""
    CRONOLOG_VERSION=""

    if test "x$WANT_CRONOLOG" = "xyes"; then
        AC_MSG_CHECKING([for cronolog])
        export PATH="/sbin:/ffp/sbin:$PATH"
        success=yes
        which cronolog || success=no
        if test "$success" = "yes"; then
          ac_cronolog_path=`which cronolog`
        fi
    fi
])

