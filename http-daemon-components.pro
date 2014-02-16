#-------------------------------------------------
#
# Project created by QtCreator 2013-08-04T17:26:34
#
#-------------------------------------------------

QT       -= gui
QT += network

TARGET = http-daemon-components
TEMPLATE = lib
CONFIG += staticlib

SOURCES += httpresponse.cpp

HEADERS += httpresponse.h \
	httprequest.h \
	httprequesthandler.h \
	iplugin.h

QMAKE_CXXFLAGS += -std=c++11

CONFIG(release, debug|release){
	DEFINES += QT_NO_DEBUG_OUTPUT QT_NO_WARNING_OUTPUT
	message("Release mode: No debug or warning messages from Qt")
	QMAKE_CXXFLAGS += -O3
}

unix {
	target.path = /usr/lib
	INSTALLS += target
}
