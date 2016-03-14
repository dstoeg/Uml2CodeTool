#include "uGridObject.h"
#include "uDebugPrinter.h"

#include <string>

using namespace std;

uGridObject::uGridObject(int mX, int mY, int mX_to, int mY_to)
{
    //uDebugPrinter::printText("Creating object: " + mName.toStdString() + ", size (" + to_string(mWidth) + "," + to_string(mHeight) + "), position:(" + to_string(mX) + "," + to_string(mY)+")");
    this->mX = mX;
    this->mY = mY;
    this->mY_to = mY_to;
    this->mX_to = mX_to;
}

uGridObject::~uGridObject()
{

}

bool uGridObject::selected(int x, int y) const
{
    return ((this->mX_to) >= x ) && ((mY_to) >= y)
            && mX <=x && mY <= y;
}

int uGridObject::getX() const
{
    return mX;
}

int uGridObject::getY() const
{
    return mY;
}

int uGridObject::getX_to() const
{
    return mX_to;
}

int uGridObject::getY_to() const
{
    return mY_to;
}

int uGridObject::getWidth() const
{
    return mX_to - mX;
}

int uGridObject::getHeight() const
{
    return mY_to - mY;
}


bool uGridObject::setX(int newX)
{
    //TODO add comparison >= with GridLayout max width
    if(newX < 0) return false;
    this->mX = newX;
    return true;
}

bool uGridObject::setY(int newY)
{
    //TODO add comparison >= with GridLayout max height
    if(newY < 0) return false;
    this->mY = newY;
    return true;
}

bool uGridObject::setX_to(int newX)
{
    mX_to = newX;
}

bool uGridObject::setY_to(int newY)
{
    mY_to = newY;
}

void uGridObject::resizeX(double ratio)
{
    mX = (int)((double)mX*ratio + 0.5);
    mX_to = (int)((double)mX_to*ratio + 0.5);
}

void uGridObject::resizeY(double ratio)
{
    mY = (int)((double)mY*ratio + 0.5);
    mY_to = (int)((double)mY_to*ratio + 0.5);
}

