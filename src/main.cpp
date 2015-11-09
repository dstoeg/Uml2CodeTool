#include <iostream>
#include <vector>

#include "uAccess.h"
#include "uParameter.h"
#include "uMethod.h"
#include "uBaseClass.h"
#include "uLanguageCpp.h"
#include "uLanguageJava.h"
#include "uLanguagePython.h"
#include "uCodeGenerationVisitor.h"
#include "uClassDiagram.h"
#include "uClassButton.h"
#include "test/TestMain.h"

// enable/disable testing by commenting/uncommenting following statement
#define TEST

using namespace std;


int main()
{

#ifdef TEST
    // run all test cases first
    cout << "execute tests" << endl;
    TestMain tests;
    tests.execute();
#endif

    // create class diagram
    uClassDiagram classDiagram;

    // create a random method
    TParameters methodParams = {uParameter(uPrivate , "int", "param1"), uParameter(uPrivate , "string", "param2"), uParameter(uPrivate , "float", "param3")};
    uMethod method( uPublic, "void", "draw", methodParams);

    // create a base class
    TParameters parameters = {uParameter(uPrivate , "int", "id"),uParameter(uProtected , "string", "name"), uParameter(uPublic , "float", "size")};
    TMethods methods = {method};
    TReferences references;
    uInheritable * baseClass = uClassButton::getInstance().create(eBaseClass,uPublic,"GraphicObject", parameters, methods, references, NULL);
    classDiagram.addClass(baseClass);

    // create child classes
    TMethods nullMethods;
    TParameters nullParameters;
    uInheritable * childClass1 = uClassButton::getInstance().create(eChildClass, uPublic, "Circle", nullParameters, nullMethods, references, baseClass);
    classDiagram.addClass(childClass1);

    uInheritable * childClass2 = uClassButton::getInstance().create(eChildClass, uPublic, "Rectangle", nullParameters, nullMethods, references, baseClass);
    classDiagram.addClass(childClass2);

    uInheritable * childClass3 = uClassButton::getInstance().create(eChildClass, uPublic, "Triangle", nullParameters, nullMethods, references, baseClass);
    classDiagram.addClass(childClass3);


    // create the code generation visitor
    uCodeGenerationVisitor * generator = &uCodeGenerationVisitor::getInstance();
    generator->setFileAttributes("Carlos, Daniel, Mike", "7/11/15");

    // create the Language Strategies
    uLanguageStrategy * CPP = new uLanguageCPP();
    uLanguageStrategy * Java = new uLanguageJava();
    uLanguageStrategy * Python = new uLanguagePython();

    // generate C++ files
    cout << endl << "generating C++ files" << endl;
    generator->setLanguage(CPP);
    classDiagram.applyVisitor(generator);

    // generate Java class file
    cout << endl << "generating Java files" << endl;
    generator->setLanguage(Java);
    classDiagram.applyVisitor(generator);

    // generate Python class file
    cout << endl << "generating Python files" << endl << endl;
    generator->setLanguage(Python);
    classDiagram.applyVisitor(generator);
   
    // free memory
    delete baseClass; baseClass = NULL;
    delete childClass1; childClass1 = NULL;
    delete childClass2; childClass2 = NULL;
    delete childClass3; childClass3 = NULL;
    delete CPP; CPP = NULL;
    delete Java; Java = NULL;
    delete Python; Python = NULL;

    return 0;

}

