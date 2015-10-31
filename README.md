# Uml2CodeTool

qt Project file :

--------------------------------------
TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += qt
QT += testlib


SOURCES += src/main.cpp \
    src/uParameter.cpp \
    src/uMethod.cpp \
    ....
    test/uInheritableTest.cpp \
    test/TestMain.cpp


HEADERS += \
    src/uAccess.h \
    ....
    test/TestMain.h

--------------------------------------
