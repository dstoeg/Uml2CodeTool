#ifndef UPROJECTFILE_H
#define UPROJECTFILE_H

#include <string>
#include "uClassDiagram.h"

class uProjectFile
{
public:
    uProjectFile();
    virtual std::string createFile(uClassDiagram const * const diagram) {}
    virtual std::string getName() {}
};

#endif // UPROJECTFILE_H
