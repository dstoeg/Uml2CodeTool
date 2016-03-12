#include "uGridObjectFactory.h"
#include "uDebugPrinter.h"

#include <string>

using namespace std;

uGridObjectFactory::uGridObjectFactory()
{

}

uGridClass *uGridObjectFactory::createClass(int mX, int mY, int mWidth, int mHeight, QString mName)
{
    return new uGridClass(mX, mY, mWidth, mHeight, mName);
}

uGridSegment *uGridObjectFactory::createSegment(int mX, int mY, int mWidth, int mHeight, QString mName)
{
   return new uGridSegment(mX, mY, mWidth, mHeight, mName);
}

uGridObjectFactory &uGridObjectFactory::getInstance()
{
    static uGridObjectFactory instance;
    return instance;
}

uGridObject *uGridObjectFactory::createObject(int mX, int mY, int mWidth, int mHeight, QString mName, uGridObjectType type)
{
    //uDebugPrinter::printText("Creating object: " + mName.toStdString() + ", size (" + to_string(mWidth) + "," + to_string(mHeight) + "), position:(" + to_string(mX) + "," + to_string(mY)+")");
    switch(type){
        default:
            return uGridObjectFactory::getInstance().createClass(mX, mY, mWidth, mHeight, mName);
            break;
    }
}
