TEMPLATE = app

QT += qml quick
CONFIG += c++11
QT += testlib

SOURCES += src/main.cpp \
    src/uAggregation.cpp \
    src/uBaseClass.cpp \
    src/uButton.cpp \
    src/uChildClass.cpp \
    src/uClassButton.cpp \
    src/uClassDiagram.cpp \
    src/uClassFactory.cpp \
    src/uCodeGenerationVisitor.cpp \
    src/uComposition.cpp \
    src/uDrawVisitor.cpp \
    src/uInheritable.cpp \
    src/uInterface.cpp \
    src/uInterfaceButton.cpp \
    src/uLanguageCpp.cpp \
    src/uLanguageJava.cpp \
    src/uLanguagePython.cpp \
    src/uMethod.cpp \
    src/uParameter.cpp \
    src/uReference.cpp \
    test/TestMain.cpp \
    test/uAggregationTest.cpp \
    test/uButtonTest.cpp \
    test/uClassButtonTest.cpp \
    test/uCodeGenerationVisitorTest.cpp \
    test/uCompositionTest.cpp \
    test/uInheritableTest.cpp \
    test/uInterfaceButtonTest.cpp \
    test/uLanguageCppTest.cpp \
    test/uMethodTest.cpp \
    test/uParameterTest.cpp \
    test/uReferenceTest.cpp \
    src/UiEventDispatcher.cpp \
    src/uStringConverter.cpp \
    src/uDebugPrinter.cpp \
    src/uGridLayout.cpp \
    src/uChildButton.cpp \
    src/uProjectFileCreator.cpp \
    src/uProjectFile.cpp \
    src/uProjectFileQT.cpp

RESOURCES += ui/qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH = ui/

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    src/uAccess.h \
    src/uAggregation.h \
    src/uBaseClass.h \
    src/uButton.h \
    src/uChildClass.h \
    src/uClassButton.h \
    src/uClassDiagram.h \
    src/uClassFactory.h \
    src/uClassType.h \
    src/uCodeGenerationVisitor.h \
    src/uComposition.h \
    src/uDrawVisitor.h \
    src/uInheritable.h \
    src/uInterface.h \
    src/uInterfaceButton.h \
    src/uLanguageCpp.h \
    src/uLanguageJava.h \
    src/uLanguagePython.h \
    src/uLanguageStrategy.h \
    src/uMethod.h \
    src/uParameter.h \
    src/uReference.h \
    src/uVisitor.h \
    test/TestMain.h \
    test/uAggregationTest.h \
    test/uButtonTest.h \
    test/uClassButtonTest.h \
    test/uCodeGenerationVisitorTest.h \
    test/uCompositionTest.h \
    test/uInheritableTest.h \
    test/uInterfaceButtonTest.h \
    test/uLanguageCppTest.h \
    test/uMethodTest.h \
    test/uParameterTest.h \
    test/uReferenceTest.h \
    src/UiEventDispatcher.h \
    src/uStringConverter.h \
    src/uDebugPrinter.h \
    src/uGridLayout.h \
    src/uChildButton.h \
    src/uProjectFileCreator.h \
    src/uProjectFile.h \
    src/uProjectFileQT.h

