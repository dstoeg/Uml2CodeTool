#ifndef UPROJECTFILEQT_H
#define UPROJECTFILEQT_H

#include "uProjectFile.h"

class uProjectFileQT : public uProjectFile
{
public:
    uProjectFileQT();
    virtual std::string createFile(uClassDiagram const * const diagram);
    virtual std::string getName();
};

#endif // UPROJECTFILEQT_H
