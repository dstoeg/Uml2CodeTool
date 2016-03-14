#include "uGridObjectFactory.h"
#include "uDebugPrinter.h"

#include <string>

using namespace std;

uGridObjectFactory::uGridObjectFactory()
{

}

uGridObjectFactory &uGridObjectFactory::getInstance()
{
    static uGridObjectFactory instance;
    return instance;
}

uGridClass *uGridObjectFactory::createClass(int mX, int mY, int mX_to, int mY_to, QString mName)
{
    return new uGridClass(mX, mY, mX_to, mY_to, mName);
}

uGridSegment *uGridObjectFactory::createSegment(int mX, int mY, int mX_to, int mY_to)
{
   return new uGridSegment(mX, mY, mX_to, mY_to);
}
