include(../../../global.pri)

QT += xml widgets

TEMPLATE = lib
CONFIG += plugin

DESTDIR = $$DESTDIR/plugins/tools

links(qrkernel qrutils)

HEADERS = \
	dachassGeneratorPlugin.h \
	generator.h \

SOURCES = \
	dachassGeneratorPlugin.cpp \
	generator.cpp \

win32 {
		QMAKE_POST_LINK = "xcopy templates ..\\..\\..\\bin\\templates /s /e /q /y /i "
}
else {
		QMAKE_POST_LINK = "mkdir ../../../bin/templates/ && cp -r templates ../../../bin/templates/ "
}






