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

#include "test/TestMain.h"
#include "uClassDiagram.h"
#include "uClassButton.h"

using namespace std;


int main()
{
    // run all test cases first
    TestMain tests;
    tests.execute();

    // create class diagram
    uClassDiagram classDiagram;


    // create a random method
    TParameters params;
    params.push_back(uParameter(uPrivate , "int", "param1"));
    params.push_back(uParameter(uPrivate , "string", "param2"));
    params.push_back(uParameter(uPrivate , "float", "param3"));
    uMethod method( uPublic, "void", "draw", params);

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


    // generate C++ header file
    cout << endl << "generating C++ files" << endl;
    uLanguageStrategy * strategy = new uLanguageCPP();
    uCodeGenerationVisitor * generator = &uCodeGenerationVisitor::getInstance();
    generator->setLanguage(strategy);
    generator->setFileAttributes("Carlos, Daniel, Mike", "7/11/15");
    classDiagram.applyVisitor(generator);

    // generate Java class file
    cout << endl << "generating Java files" << endl;
    strategy = new uLanguageJava();
    generator->setLanguage(strategy);
    classDiagram.applyVisitor(generator);

    // generate Python class file
    cout << endl << "generating Python files" << endl;
    strategy = new uLanguagePython();
    generator->setLanguage(strategy);
    classDiagram.applyVisitor(generator);
   
    // free memory
    delete baseClass; baseClass = NULL;
    delete childClass1; childClass1 = NULL;
    delete childClass2; childClass2 = NULL;
    delete childClass3; childClass3 = NULL;
    delete strategy; strategy = NULL;
    //delete generator; generator = NULL;

    return 0;

}

