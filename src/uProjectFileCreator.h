#ifndef UPROJECTFILECREATOR_H
#define UPROJECTFILECREATOR_H

#include "uProjectFile.h"
#include <string>

class uProjectFileCreator
{
public:
    uProjectFileCreator();
    void createFile(uClassDiagram const * const diagram);
    void setDevEnv(uProjectFile * devenv);
    std::string getDevEnvString() const;

private:
    uProjectFile * mDevenv;
    bool generateFile(std::string const& content);
};

#endif // UPROJECTFILECREATOR_H
