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

uGridClass *uGridObjectFactory::createClass(int mX, int mY, int mWidth, int mHeight, QString mName)
{
    return new uGridClass(mX, mY, mWidth, mHeight, mName);
}

uGridSegment *uGridObjectFactory::createSegment(int mX, int mY, int mWidth, int mHeight)
{
   return new uGridSegment(mX, mY, mWidth, mHeight);
}
