#include <iostream>
#include <vector>

#include "uAccess.h"
#include "uParameter.h"
#include "uMethod.h"
#include "uBaseClass.h"
#include "uLanguageCpp.h"
#include "uLanguageJava.h"
#include "uCodeGenerationVisitor.h"

using namespace std;

int main()
{
    // create container for class diagram
    vector<uInheritable*> classDiagram;

    // create a random method
    vector<uParameter> params;
    params.push_back(uParameter(uPrivate , "int", "param1"));
    params.push_back(uParameter(uPrivate , "string", "param2"));
    params.push_back(uParameter(uPrivate , "float", "param3"));
    uMethod method( uPublic, "void", "draw", params);

    // create a base class
    uBaseClass * baseClass = new uBaseClass("GraphicObject");
    baseClass->setAccess(uPublic);
    baseClass->addMethod(method);
    baseClass->addAttribute(uParameter(uPrivate , "int", "id"));
    baseClass->addAttribute(uParameter(uProtected , "string", "name"));
    baseClass->addAttribute(uParameter(uPublic , "float", "size"));
    classDiagram.push_back(baseClass);

    // create a child classes
    uInheritable * childClass1 = new uChildClass("Circle", baseClass);
    childClass1->setAccess(uPublic);
    classDiagram.push_back(childClass1);

    uChildClass * childClass2 = new uChildClass("Rectangle", baseClass);
    childClass2->setAccess(uPublic);
    classDiagram.push_back(childClass2);

    uChildClass * childClass3 = new uChildClass("Triangle", baseClass);
    childClass3->setAccess(uPublic);
    classDiagram.push_back(childClass3);


    // generate C++ header file
    cout << endl << "generating C++ files" << endl;
    uLanguageStrategy * strategy = new uLanguageCPP();
    uCodeGenerationVisitor * generator = new uCodeGenerationVisitor(strategy);
    generator->setFileAttributes("daniel stoeger", "21/9/15");
    for (size_t i=0; i<classDiagram.size(); i++) {
        classDiagram[i]->accept(generator);
    }


    // generate Java class file
    cout << endl << "generating Java files" << endl;
    strategy = new uLanguageJava();
    generator->setLanguage(strategy);
    for (size_t i=0; i<classDiagram.size(); i++) {
        classDiagram[i]->accept(generator);
    }


    // free memory
    delete baseClass; baseClass = NULL;
    delete childClass1; childClass1 = NULL;
    delete childClass2; childClass2 = NULL;
    delete childClass3; childClass3 = NULL;
    delete strategy; strategy = NULL;
    delete generator; generator = NULL;

    return 0;
}

