prefix=@CMAKE_INSTALL_PREFIX@
exec_prefix=${prefix}
libdir=${prefix}lib
includedir=${prefix}include

Name: @MINUIT_CPP_MONIKER@
Description: @MINUIT_CPP_TITLE@
Version: @MINUIT_CPP_VERSION@
Requires:
Libs: -L${libdir} -l@MINUIT_CPP_MONIKER@
Cflags: -I${includedir}
