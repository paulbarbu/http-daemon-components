#-------------------------------------------------
#
# Project created by QtCreator 2013-08-04T17:26:34
#
#-------------------------------------------------

QT       -= gui

TARGET = http-daemon-components
TEMPLATE = lib
CONFIG += staticlib

SOURCES += httpresponse.cpp

HEADERS += httpresponse.h \
	httprequest.h \
	httprequesthandler.h \
	iplugin.h
unix:!symbian {
	maemo5 {
		target.path = /opt/usr/lib
	} else {
		target.path = /usr/lib
	}
	INSTALLS += target
}
