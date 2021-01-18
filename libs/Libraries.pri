#-------------------------------------------------------------------------------
# Definitions to avoid adding DLL imports/exports
#-------------------------------------------------------------------------------

DEFINES += CUTELOGGER_SRC

#-------------------------------------------------------------------------------
# Include *.pri files
#-------------------------------------------------------------------------------

include($$PWD/CuteLogger/CuteLogger.pri)
include($$PWD/QSimpleUpdater/QSimpleUpdater.pri)
